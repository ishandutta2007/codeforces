#include <iostream>
#include <math.h>
#include <iomanip>
#include<algorithm>
 using namespace std;
int a[200]; 
 int main() {
   int n; cin>> n;
   for (int i = 1 ; i<= n; i++) {
       cin>>a[i];
       }
       sort(a+1, a + n + 1 );
       for (int i=1 ; i <= n; i++) {
           cout << a[i] << " " ;  }
     return 0;
}