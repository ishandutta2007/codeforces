#include <iostream>
#include <algorithm>
using namespace std;
int a[101];
int main() { 
 int n;
 cin >> n;
 for( int i= 0 ;i < n ;i++ ) 
  cin >> a[i];
 int mx = *min_element( a , a + n ) ; 
 int mn = *max_element( a ,a + n ) ; 
 int cnt= 0;
 int j;
 for( j = 0 ; a[j] != mn ; j++ ) ;
 for(  ; j ; j-- ) {
  swap( a[j], a[j-1] );
  cnt++;
 }
 for( j = n - 1 ; a[j] != mx ; j-- ) ;
 for( ; j < n - 1 ; j++ ) {
  swap( a[j], a[j+1] ) ;
  cnt++;
 }
 cout << cnt << endl;
}