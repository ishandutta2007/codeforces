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
    ll n;
    cin >> n;
    vector<ll> a{2050};
    while (a.back() <= 1e17) {
        a.push_back(a.back() * 10);
    }
    int ans = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        while (n >= a[i]) {
            n -= a[i];
            ans++;
        }
    }
    if (n == 0) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
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