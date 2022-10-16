#include <bits/stdc++.h>

using namespace std;

int n, m;
string s, t;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    int pos = -1;
    for (int i = 0; i < n; ++i) if (s[i] == '*') pos = i;
    if (pos == -1) return cout << (s == t ? "YES" : "NO") << endl, 0;
    if (n > m + 1) return cout << "NO" << endl, 0;
    for (int i = 0; i < pos; ++i) if (s[i] != t[i]) return cout << "NO" << endl, 0;
    for (int i = pos + 1; i < n; ++i) if (s[i] != t[i-n+m]) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    return 0;
}