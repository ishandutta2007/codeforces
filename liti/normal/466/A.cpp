//In the name of Allah
#include <iostream>
using namespace std;
int main() { 
 int n,m,a,b;
 cin >> n >> m >> a >> b; 
 int ret = n*a;
 for( int i = 1 ; i <= n ; i++ ) 
  ret = min( ret , b*i + max(0,n-i*m)*a ) ; 
 cout << ret << endl;
}