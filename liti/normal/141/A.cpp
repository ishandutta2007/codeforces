//In the name of Allah
#include <iostream>
#include <algorithm>
using namespace std;
int main() { 
 string s1,s2;
 cin >> s1 >> s2;
 s1 += s2;
 cin >> s2;
 sort( s1.begin() , s1.end() ) ; 
 sort( s2.begin() , s2.end() ) ; 
 cout << (s1==s2?"YES":"NO") << endl;
}