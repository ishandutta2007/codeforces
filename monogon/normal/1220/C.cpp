
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    cout << "Mike" << endl;
    char c = s[0];
    for(int i = 1; i < n; i++) {
        cout << (c < s[i] ? "Ann" : "Mike") << endl;
        c = min(c, s[i]);
    }
}