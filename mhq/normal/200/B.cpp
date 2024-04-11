#include <iostream>
#include <math.h>
#include <iomanip>
 using namespace std;
 int main() {
     int n; cin >>  n;
     double s=0;
     double x;
  for( int i = 1 ; i<= n ; i++) { 
       cin >> x;
       s=s+x;
       }
       s=s/n;
       cout.precision(5);
       cout<< fixed << s;  
     return 0;
}