#include<bits/stdc++.h>
using namespace std;
string s;
string tar [] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int n;
bool fit (string s, string tar) {
    if (s.size() != tar.size()) return false; 
    for (int i = 0 ; i < (int)s.size() ; ++ i) {
        if (s[i] != '.' && s[i] != tar[i]) {
            return false;
        }
    }
    return true;
}
 
int main () {
    cin >> n;
    cin >> s;
    
    for (int i = 0 ; i < 8 ; ++ i) {
        if (fit(s, tar[i])) {
            cout << tar[i];
            return 0;
        }
    }
    
}