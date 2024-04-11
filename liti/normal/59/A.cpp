//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
int main() { 
 string s;
 int cnt = 0;
 cin >> s;
 for( int i = 0 ; i < s.size() ; i++ ) 
  if( islower(s[i]) ) cnt++;
  else cnt--;
 if( cnt < 0 ) for( int i = 0 ; i < s.size() ; i++ ) cout << (char)toupper(s[i]);
 else for( int i = 0 ; i < s.size() ; i++ ) cout << (char)tolower(s[i]);
}