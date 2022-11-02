#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s, t;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n;
    s = "<3";
    for (int i=0; i<n; i++) {
        string str; cin >> str;
        s += str;
        s += "<3";
    }
    cin >> t;
    int ind = 0;
    for (int i=0; i<t.length(); i++) {
        if (ind < s.length() && s[ind] == t[i]) ind++;
    }
    if (ind == s.length()) cout << "yes\n";
    else cout << "no\n";
    return 0;
}