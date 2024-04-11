#include <bits/stdc++.h>

using namespace std;

const int mod = 1007050321, base = 256;
string s, t;
int n0, n1;
int suffix[500005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> t;
    for (int i = 0; i < s.size(); ++i) if (s[i] == '0') ++n0; else ++n1;
    int a0 = 0, a1 = 0;
    for (int i = 0; i < t.size(); ++i) if (t[i] == '0') ++a0; else ++a1;
    if (n0 < a0 || n1 < a1) return cout << s << endl, 0;

    int mul = 1;
    for (int i = t.size() - 1; i >= 0; --i) {
        suffix[i] = (suffix[i + 1] + 1ll * mul * t[i]) % mod;
        mul = 1ll * mul * base % mod;
    }
    int id = 0;
    int key = 0;
    for (int i = 0; i + 1 < t.size(); ++i) {
        key = (1ll * key * base + t[i]) % mod;
        if (key == suffix[t.size() - 1 - i]) id = i + 1;
    }

    int b0 = 0, b1 = 0;
    string u = t.substr(id);
    for (int i = 0; i < u.size(); ++i) if (u[i] == '0') ++b0; else ++b1;
    cout << t;
    while (a0 + b0 <= n0 && a1 + b1 <= n1) {
        cout << u;
        a0 += b0;
        a1 += b1;
    }
    while (a0 < n0) cout << '0', ++a0;
    while (a1 < n1) cout << '1', ++a1;
    cout << endl;
    return 0;
}