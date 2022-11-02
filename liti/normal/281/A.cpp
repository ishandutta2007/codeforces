#include <iostream>
using namespace std;

int main() { 
 string s;
 cin >> s;
 if( s[0] >= 'a' ) 
  s[0] -= 'a' - 'A';
 cout << s << endl;
}