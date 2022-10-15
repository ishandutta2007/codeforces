#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

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

const int M = 60;

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> cnt(M);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        for (int j = 0; j < M; j++) {
            if (x[i] >> j & 1) {
                cnt[j]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll pw = 1;
        ll t1 = 0;
        ll t2 = 0;
        for (int j = 0; j < M; j++) {
            if (x[i] >> j & 1) {
                (t1 += pw * n) %= mod;
                (t2 += pw * cnt[j]) %= mod;
            } else {
                (t1 += pw * cnt[j]) %= mod;
            }
            pw = pw * 2 % mod;
        }
        (ans += t1 % mod * t2) %= mod;
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