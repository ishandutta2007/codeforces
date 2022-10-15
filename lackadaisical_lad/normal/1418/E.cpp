#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

// const int MOD = 1e9 + 7;
const int MOD = 998244353;
 
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

int eulerianPartitions(int n, const vector<vector<int>>& g) {
    int topkek = 1 << n;
    int res = 0;
    for (int mask = 0; mask < topkek; mask++) {
        int ok = 1;
        for (int i = 0; i < n && ok; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (g[i][j]) {
                    cnt += (mask >> i & 1) == (mask >> j & 1);
                }
            }
            ok &= cnt % 2 == 0;
        }
        res += ok;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] + d[i - 1]) % MOD;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        int cntL = lower_bound(d.begin(), d.end(), b) - d.begin();
        int cntR = n - cntL;
        if (cntR < a) {
            cout << "0\n";
            continue;
        }
        ll probL = (cntR - a + 1) * binpow(cntR + 1, MOD - 2) % MOD;
        ll sumL = pref[cntL] * probL % MOD;
        ll probR = (cntR - a) * binpow(cntR, MOD - 2) % MOD;
        ll sumR = (pref[n] - pref[cntL] + MOD) * probR % MOD;
        cout << (sumL + sumR) % MOD << '\n';
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