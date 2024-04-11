#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

string s1, s2, s, t;

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '|') {
            s1 = s.substr(0, i);
            s2 = s.substr(i+1);
            break;
        }
    }

    cin >> t;

    int a = s1.length(), b = s2.length();

    if ((a + b + t.length()) % 2) {
        cout << "Impossible\n";
        return 0;
    }

    if (abs(a - b) > t.length()) {
        cout << "Impossible\n";
        return 0;
    }

    for (int i=0; i<t.length(); i++) {
        if (s1.length() < s2.length()) s1 += t[i];
        else s2 += t[i];
    }

    cout << s1 << '|' << s2 << '\n';
    return 0;
}