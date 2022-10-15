#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int MOD = 998244353;

ll binpow(ll a, ll p, int mod = MOD) {
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
    int n, l, r;
    cin >> n >> l >> r;
    int ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < l; i++) {
        int c;
        cin >> c;
        a[c - 1]++;
    }
    for (int i = 0; i < r; i++) {
        int c;
        cin >> c;
        b[c - 1]++;
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int mn = min(a[i], b[i]);
        a[i] -= mn;
        b[i] -= mn;
        x += a[i];
        y += b[i];
    }
    int c = abs(x - y) / 2;
    ans += abs(x - y) / 2;
    ans += (x + y) / 2;

    if (x > y) {
        for (int i = 0; i < n; i++) {
            int mn = min(c, a[i] / 2);
            ans -= mn;
            c -= mn;
        }
    } else {
        for (int i = 0; i < n; i++) {
            int mn = min(c, b[i] / 2);
            ans -= mn;
            c -= mn;
        }
    }
    
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}