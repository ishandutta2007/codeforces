//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
    string s1,s2;
    cin >> s1 >> s2;
    for( int i = 0 ;i < int(s1.size()) ; i++ ) 
        cout << (s1[i]!=s2[i]) ;
    cout << endl;
}