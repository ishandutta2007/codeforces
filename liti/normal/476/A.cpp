//In the name of Allah
#include <iostream>
using namespace std;
int main() { 
 int n,m;
 cin >> n >> m;
 for( int i= 0 ; i <= n ; i++ ) { 
  if( ( n-i ) % 2 == 1 ) continue;
  int x = (n-i)/2;
  if( ( x + i ) % m == 0 ) { cout << x + i << endl; return 0 ; }
 }
 cout << -1 << endl;
}