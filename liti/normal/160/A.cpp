#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int main() { 
 int n;
 cin >> n;
  int sum = 0;
 for( int i = 0 ; i < n ; i++ ) {
  cin >> a[i];
  sum += a[i];
 }
 sort( a , a + n ) ;
 int x = 0;
 for( int i = n - 1 ; i >= 0 ; i-- ) {
  x += a[i];
  if( x > sum - x ) {
   cout << n - i << endl;
   return 0;
  }
 }
}