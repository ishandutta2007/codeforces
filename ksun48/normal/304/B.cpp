#include<iostream>

using namespace std;
int main(){
char a[15];
char b[15];
cin >> a >> b;
int ya = 1000*(a[0]-'0')+100*(a[1]-'0')+10*(a[2]-'0')+(a[3]-'0');
int yb = 1000*(b[0]-'0')+100*(b[1]-'0')+10*(b[2]-'0')+(b[3]-'0');
int ma = 10*(a[5]-'0')+(a[6]-'0');
int mb = 10*(b[5]-'0')+(b[6]-'0');
int da = 10*(a[8]-'0')+(a[9]-'0');
int db = 10*(b[8]-'0')+(b[9]-'0');
//cout << ya << " " << yb << " " << ma << " " << mb << " " << da  << " " << db;
int na = 0;
for(int i = 1; i < ya; i++){
na += 365;
if(i % 400 == 0) na++;
else if(i % 100 == 0) na += 0;
else if(i % 4 == 0) na++;
}
if(ma >= 2) na += 31;
if(ma >= 3) na += 28;
if(ma >= 3 && (ya % 400 == 0 || (ya % 100 != 0 && ya % 4 == 0))) na ++;
if(ma >= 4) na += 31;
if(ma >= 5) na += 30;
if(ma >= 6) na += 31;
if(ma >= 7) na += 30;
if(ma >= 8) na += 31;
if(ma >= 9) na += 31;
if(ma >= 10) na += 30;
if(ma >= 11) na += 31;
if(ma >= 12) na += 30;
na += da;
int nb = 0;
for(int i = 1; i < yb; i++){
nb += 365;
if(i % 400 == 0) nb++;
else if(i % 100 == 0) nb += 0;
else if(i % 4 == 0) nb++;
}
if(mb >= 2) nb += 31;
if(mb >= 3) nb += 28;
if(mb >= 3 && (yb % 400 == 0 || (yb % 100 != 0 && yb % 4 == 0))) nb ++;
if(mb >= 4) nb += 31;
if(mb >= 5) nb += 30;
if(mb >= 6) nb += 31;
if(mb >= 7) nb += 30;
if(mb >= 8) nb += 31;
if(mb >= 9) nb += 31;
if(mb >= 10) nb += 30;
if(mb >= 11) nb += 31;
if(mb >= 12) nb += 30;
nb += db;
if(na > nb){
cout << (na-nb) << endl;
} else {
cout << (nb-na) << endl;
}
}