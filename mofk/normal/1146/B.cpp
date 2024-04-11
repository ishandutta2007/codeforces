#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (auto c: s) if (c == 'a') ++a; else ++b;
    if (b & 1) return cout << ":(" << endl, 0;
    int p = a + b / 2;
    string t;
    for (int i = 0; i < p; ++i) t += s[i];
    string u = t;
    for (int i = 0; i < p; ++i) if (s[i] != 'a') u += s[i];
    if (u != s) return cout << ":(" << endl, 0;
    cout << t << endl;
    return 0;
}