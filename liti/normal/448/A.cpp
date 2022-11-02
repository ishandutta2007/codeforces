//In the name of Allah
#include <iostream>
using namespace std;
int req( int x ) { 
 int a,tmp; a =0;
 for( int i = 0 ; i < 3 ; i++ ) { 
  cin >> tmp;
  a += tmp;
 } 
 return (a+x-1)/x;
}
int main() { 
 int x = req(5) + req(10);
 int n; cin >> n;
 cout << (n >= x ? "YES" : "NO" ) << endl;
}