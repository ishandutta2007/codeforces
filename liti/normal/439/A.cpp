//In the name of Allah
#include <iostream>
using namespace std;
int main() { 
 int n,d;
 cin >> n >> d;
 for( int i = 0 ; i < n ; i++ ) {
  int tmp; cin >> tmp; d -= tmp;
 }
 int ans = (n-1)*2;
 d -= (n-1)*10;
 if( d < 0 ) { cout << -1 << endl; return 0 ; } 
 cout << ans + d/5 << endl;
}