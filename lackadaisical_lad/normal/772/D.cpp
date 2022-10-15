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
    int n;
    cin >> n;
    const int N = 1e6;
    const int M = 6;
    vector<ll> a(n);
    vector<array<ll, 2>> sum(N, {0LL, 0LL});
    vector<ll> cnt(N); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        (sum[a[i]][0] += a[i]) %= MOD;
        (sum[a[i]][1] += a[i] * a[i]) %= MOD;
        cnt[a[i]]++;
    }

    vector<ll> dp(N);
    vector<int> pw(M);
    pw[0] = 1;
    for (int i = 1; i < M; i++) {
        pw[i] = pw[i - 1] * 10;
    }
    int topkek = 1 << M;
    ll ans = 0;

    for (int i = N - 1; i >= 0; i--) {
        vector<int> d(M);
        for (int j = 0; j < M; j++) {
            d[j] = i / pw[j] % 10;
        }
        ll kek = 0;
        for (int mask = 1; mask < topkek; mask++) {
            int bad = 0;
            int nxt = i;
            for (int j = 0; j < M; j++) {
                if (mask >> j & 1) {
                    if (d[j] == 9) {
                        bad = 1;
                        break;
                    }
                    nxt += pw[j];
                }
            }
            if (bad) continue;
            if (__builtin_popcount(mask) & 1) {
                (sum[i][0] += sum[nxt][0]) %= MOD;
                (sum[i][1] += sum[nxt][1]) %= MOD;
                cnt[i] += cnt[nxt];
                (kek += dp[nxt]) %= MOD;
            } else {
                (sum[i][0] += MOD - sum[nxt][0]) %= MOD;
                (sum[i][1] += MOD - sum[nxt][1]) %= MOD;
                cnt[i] -= cnt[nxt];
                (kek += MOD - dp[nxt]) %= MOD;
            }
        }
        if (cnt[i] <= 1) {
            (dp[i] += sum[i][1]) %= MOD;
        } else {
            ll coef = binpow(2, cnt[i] - 2);
            (dp[i] += sum[i][0] * sum[i][0] % MOD * coef) %= MOD;
            (dp[i] += sum[i][1] * coef) %= MOD;
        }
        ans ^= (dp[i] - kek + MOD) % MOD * i;
    }
    cout << ans << endl;
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