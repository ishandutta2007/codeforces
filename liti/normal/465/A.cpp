//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int main() { 
 int n; cin >> n;
 string s;
 cin >> s;
 int x = 1;
 int ret = 0;
 for( int i = 0 ; i < s.size() ; i++ ) { 
  if( x == 0 ) break;
  ret++;
  if( s[i] == '1' ) x = 1;
  else x = 0;
 }
 cout << ret << endl;
}