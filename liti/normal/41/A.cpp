//In the name of Allah
#include <iostream>
#include <algorithm>
using namespace std;
int main() { 
    string s,t;
    cin >> s >> t;
    reverse( t.begin() , t.end() ) ;
    cout << (s==t?"YES":"NO") << endl;
}