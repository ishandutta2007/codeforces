//In the name of Allah
#include <iostream>
using namespace std;
int a[1001]; 

int main() { 
 int n;
 cin >> n;
 int ret = 0, ans= 0;
 for( int i = 0 ; i < n ; i++ ) {
  int num; cin >> num;
  a[num]++;
  if( a[num] == 1 ) ret ++;
  ans = max( ans, a[num] ) ; 
 }
 cout << ans << ' ' << ret << endl;
}