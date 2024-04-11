#include <iostream>
#include <algorithm>
using namespace std;
int a[26];

int main() { 
 string s;
 cin >> s;
 for( int i = 0 ; i < s.size() ; i++ ) 
  a[s[i]-'a'] = 1;
 cout << (accumulate( a, a + 26 , 0 ) % 2 == 0 ? "CHAT WITH HER!" : "IGNORE HIM!" ) << endl;
}