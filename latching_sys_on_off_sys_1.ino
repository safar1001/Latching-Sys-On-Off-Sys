
#include <LiquidCrystal.h>

LiquidCrystal mylcd(7,8,9,10,11,12);
volatile int a;
volatile int b;

void setup(){
  mylcd.begin(16,2);
  mylcd.setCursor(1-1, 1-1);
  mylcd.print("SAFAR");
  delay(1000);
  mylcd.clear();
  a = 4;
  b = 0;
  pinMode(4, INPUT);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop(){
  Serial.println(digitalRead(4));
  if (digitalRead(4) == 1 && b == 0) {
    delay(3500);
    if (digitalRead(4) == 1) {
      b = 1;
      a = 1;

    }

  }
  if (a == 1) {
    mylcd.setCursor(1-1, 1-1);
    mylcd.print("power on");
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(13,HIGH);
    a = 0;

  }
  if (digitalRead(4) == 1) {
    delay(3500);
    if (digitalRead(4) == 1 && b == 1) {
      mylcd.setCursor(1-1, 1-1);
      mylcd.print("power off");
      delay(1500);
      a = 0;
      b = 0;
      digitalWrite(13,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      mylcd.clear();

    }

  }

}