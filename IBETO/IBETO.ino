
#include <LiquidCrystal.h>
int ledPin= 13;
char state;
int rf =12;
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(rf, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
   lcd.setCursor(0, 5);
  lcd.print("DMD");
  // lcd.setCursor(1, 0);
   //lcd.print("DMD");
  lcd.clear();
}
void loop() {
  if(Serial.available() > 0){ 
    state = Serial.read(); 
 }
 if (state == '1') {
  digitalWrite(ledPin, HIGH); 
  Serial.println("LED: OFF");
   lcd.setCursor(0, 1);
  lcd.print("DMD IS ON");
  digitalWrite(rf, HIGH); 
 }
 else 
 {
  lcd.clear();
  digitalWrite(ledPin, LOW);
  digitalWrite(rf, LOW); 
  Serial.println("LED: ON");
   lcd.setCursor(0, 1);
  lcd.print(" DMD IS OFF");
 } 
}
