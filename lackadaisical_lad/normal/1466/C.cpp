#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 998244353;

ll binpow(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s += "!!";
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') continue;
        if (s[i] == s[i + 2]) {
            ans++;
            s[i + 2] = '#';
        }
        if (s[i] == s[i + 1]) {
            ans++;
            s[i + 1] = '#';
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}