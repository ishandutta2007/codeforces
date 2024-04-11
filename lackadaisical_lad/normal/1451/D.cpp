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

void solve() {
    ll d, k;
    cin >> d >> k;
    ll mx = 0;
    ll dd = d * d;
    for (ll x = 0; x <= d; x += k) {
        ll y = ll(sqrtl(dd - x * x + 0.5));
        y = y / k * k;
        mx = max(mx, x + y);
    }
    mx /= k;
    if (mx % 2) {
        cout << "Ashish\n";
    } else {
        cout << "Utkarsh\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
    return 0;
}