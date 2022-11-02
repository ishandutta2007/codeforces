#include <bits/stdc++.h>

using namespace std;

bool btf(string s) {
    if (s[0] != '1') return 0;
    for (int i = 1; i < s.length(); i++) if (s[i] != '0') return 0;
    return 1;
}

int main() {
    int n;
    string x = "1";
    int numz = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "0") {
            cout << "0\n";
            return 0;
        }
        if (btf(s)) numz += s.length() - 1;
        else x = s;
    }
    cout << x;
    for (int i = 0; i < numz; i++) cout << '0';
}