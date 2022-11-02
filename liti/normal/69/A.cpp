//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
 int s1,s2,s3;
 s1 = s2 = s3 = 0;
 int n; cin >> n;
 for( int i = 0 ; i < n ; i++ ) { 
  int a,b,c;
  cin >> a >> b >> c;
  s1 += a; s2 += b; s3 += c;
 }
 cout << (s1==s2&&s2==s3&&s3==0? "YES":"NO" ) << endl;
}