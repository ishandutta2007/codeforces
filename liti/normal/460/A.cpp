#include <iostream>
using namespace std;
int main() { 
 int n,m,i;
 cin >> n >>m;n--;
 for( i = 0 ; ;i++ ) {
  n += ( i % m == 0 ); 
  if( n == 0 ) break; 
  n--;
 }
 cout << i << endl;
}