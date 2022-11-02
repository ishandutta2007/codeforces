#include <iostream>
using namespace std;
int main() { 
 int n;
 cin >> n;
 int ret = 0;
 for( int i = 0 ; i < n ; i++ ) {
  int a,b;
  cin >> a >> b;
  ret += (b-a>=2);
 }
 cout << ret << endl;
}