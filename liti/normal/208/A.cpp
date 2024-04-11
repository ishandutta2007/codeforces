//In the name of Allah
#include <iostream>
using namespace std;
int main() { 
 string s;
 cin >> s;
 bool cfg = 0; 
 for( int i = 0 ; i < s.size() ; i++ ) {
  if( i + 2 < s.size() && s.substr(i,3) == "WUB" ) {
   if( cfg ) { 
    cout << ' ' ;
    cfg = 0;
   }
   i += 2;
  } else {
   cout << s[i] ;
   cfg = 1;
  }
 }
}