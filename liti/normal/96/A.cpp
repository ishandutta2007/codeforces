#include <iostream>
using namespace std;

int main() { 
  string s;
  cin >> s;
  int cnt = 1;
  char ch = s[0];
  for( int i = 1 ; i < s.size() ; i++ ) {
    if( s[i] == ch ) {
       if( (++cnt) >= 7 ) {
        cout << "YES" << endl;
        return 0;
       }
    } else { 
      ch = s[i]; cnt = 1;
    }
  }
  cout << "NO" << endl;
}