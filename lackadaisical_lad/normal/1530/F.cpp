#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 31607;
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

const int N = 21;

int a[N][N], b[N][N];
int row[N], col[N];
int dp[2], ndp[2];
int asd[N][1 << N];

void solve() {
    int n;
    cin >> n;
    int inv = binpow(10000, MOD - 2);
    for (int i = 0; i < n; i++) {
        row[i] = 1;
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            a[i][j] = a[i][j] * inv % MOD;
            b[i][j] = binpow(a[i][j], MOD - 2);
            row[i] = row[i] * a[i][j] % MOD;
        }
    }
    for (int j = 0; j < n; j++) {
        col[j] = 1;
        for (int i = 0; i < n; i++) {
            col[j] = col[j] * a[i][j] % MOD;
        }
    }

    int ans = 0;
    int topkek = 1 << n;
    for (int j = 0; j < n; j++) {
        asd[j][0] = col[j];
    }
    for (int mask = 1; mask < topkek; mask++) {
        int low;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                low = i;
            }
        }
        for (int j = 0; j < n; j++) {
            asd[j][mask] = asd[j][mask ^ (1 << low)] * b[low][j] % MOD;
        }
    }
    for (int f = 0; f < 2; f++)
    for (int g = 0; g < 2; g++)
    for (int mask = 0; mask < topkek; mask++) {
        int prod = 1;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                // for (int j = 0; j < n; j++) {
                //     if ((!f || xyi[i][j]) && (!g || govno[i][j])) {
                //         prod = prod * a[i][j] % MOD;
                //     }
                // }
                prod = prod * row[i] % MOD;
                if (f) {
                    prod = prod * b[i][i] % MOD;
                }
                if (g && (!f || i != n - i - 1)) {
                    prod = prod * b[i][n - i - 1] % MOD;
                }
            }
        }
        if (f) {
            for (int i = 0; i < n; i++) {
                prod = prod * a[i][i] % MOD;
            }
        }
        if (g) {
            for (int i = 0; i < n; i++) {
                if (!f || i != n - i - 1) {
                    prod = prod * a[i][n - i - 1] % MOD;
                }
            }
        }
        dp[0] = prod;
        dp[1] = 0;
        for (int j = 0; j < n; j++) {
            int kek = asd[j][mask];
            if (f && !(mask >> j & 1)) {
                kek = kek * b[j][j] % MOD;
            }
            if (g && (!f || j != n - j - 1) && !(mask >> (n - j - 1) & 1)) {
                kek = kek * b[n - j - 1][j] % MOD;
            }
            // int kek = asd[mask][j];
            // for (int i = 0; i < n; i++) {
            //     if (!(mask >> i & 1) && (!f || xyi[i][j]) && (!g || govno[i][j])) {
            //         kek = kek * a[i][j] % MOD;
            //     }
            // }
            ndp[0] = (dp[0] + dp[1] * kek) % MOD;
            ndp[1] = (dp[1] + dp[0] * kek) % MOD;
            dp[0] = ndp[0];
            dp[1] = ndp[1];
        }
        int heh = __builtin_popcount(mask) + f + g;
        if (heh == 0) {
            dp[0] = (dp[0] - prod + MOD) % MOD;
        }
        for (int cnt = 0; cnt < 2; cnt++) {
            if ((heh + cnt) % 2) {
                (ans = ans + dp[cnt]) %= MOD;
            } else {
                (ans = ans - dp[cnt] + MOD) %= MOD;
            }
        }
    }
    cout << ans << '\n';
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