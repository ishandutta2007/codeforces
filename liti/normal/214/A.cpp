// In the name of Allah
#include <iostream>
using namespace std;
int main() { 
 int n,m; cin >> n >> m ; 
 int ret = 0;
 for( int i = 0 ; i <= max(n,m) ; i++ ) 
  for( int j = 0; j <= max(n,m) ; j++ ) 
   if( i*i + j == n && i + j*j == m ) ret++;
 cout << ret << endl;
}