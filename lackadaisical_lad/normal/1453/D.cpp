// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
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
    ll k;
    cin >> k;
    if (k & 1) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    vector<ll> pw{2};
    for (int i = 2; i < 63; i++) {
        pw.push_back(pw.back() + (1LL << i));
    }
    for (int i = pw.size() - 1; i >= 0; i--) {
        while (pw[i] <= k) {
            k -= pw[i];
            ans.push_back(1);
            for (int j = 0; j < i; j++) {
                ans.push_back(0);
            }
        }
    }
    assert(k == 0);
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
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