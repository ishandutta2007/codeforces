#include <iostream>
using namespace std;
string s;
int main() { 
 s = "hello";
 string t;
 cin>>t;
 int j = 0;
 for( int i = 0 ; i < t.size() ; i++ ) 
  if( j != 5 && s[j] == t[i] ) j++;
 cout << (j==5?"YES":"NO") << endl;
}