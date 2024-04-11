#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n, m;
    cin >> n >> m;
    int cnt1 = 0, cnt2 = 0;
    map<pair<int, int>, char> mp;
    while (m--) {
        char op;
        cin >> op;
        if (op == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            mp[{u, v}] = c;
            if (mp.count({v, u})) {
                cnt1++;
                if (mp[{v, u}] == c) {
                    cnt2++;
                }
            }
        } else if (op == '-') {
            int u, v;
            cin >> u >> v;
            if (mp.count({v, u})) {
                cnt1--;
                if (mp[{v, u}] == mp[{u, v}]) {
                    cnt2--;
                }
            }
            mp.erase({u, v});
        } else {
            int k;
            cin >> k;
            if (k % 2 == 0) {
                cout << (cnt2 ? "YES\n" : "NO\n");
            } else {
                cout << (cnt1 ? "YES\n" : "NO\n");
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";  
        solve();
    }
    return 0;
}