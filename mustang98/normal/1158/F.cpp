//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")    // WINDOWS ONLY

#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 3011, logn = 12, inf = 1000111222, mod = 998244353;

int dp[max_n][max_n];
int dpc[max_n][max_n];
int cnt[max_n];
int f[max_n];

int dpm[2][max_n][(1 << logn)];

int n, c;
int a[max_n];
int ans[max_n];
int p2[max_n];
int p2m1[max_n];
int p2m1r[max_n];

int powm(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        return powm((1LL * a * a) % mod, b / 2);
    } else {
        return (1LL * a * powm(a, b - 1)) % mod;
    }
}

void solve_dp() {
    for (int i = 0; i < n; ++i) {
        ll cur = 1;
        memset(cnt, 0, sizeof(cnt));
        int chave = 0;
        for (int j = i; j < n; ++j) {
            cnt[a[j]]++;
            if (cnt[a[j]] == 1) {
                ++chave;
            } else {
                cur *= p2m1r[cnt[a[j]] - 1];
                cur %= mod;
                cur *= p2m1[cnt[a[j]]];
                cur %= mod;
            }
            if (chave == c) {
                dpc[i][j] = (cur * p2m1r[cnt[a[j]]]) % mod;
            } else {
                dpc[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[1][i] = dpc[0][i];
        for (int t = 2; t <= ((i + 1) / c); ++t) {
            unsigned long long res = 0;
            for (int j = 0; j < i; ++j) {
                if (dp[t - 1][j] == 0) continue;
                res += 1LL * dp[t - 1][j] * dpc[j + 1][i];
                if (res > 15e18) {
                    dp[t][i] = (res + dp[t][i]) % mod;
                    res = 0;
                }
            }
            dp[t][i] = (res + dp[t][i]) % mod;
        }
    }

    f[0] = p2m1[n];
    for (int t = 1; t <= n; ++t) {
        for (int i = 0; i < n; ++i) {
            f[t] += (1LL * dp[t][i] * p2[n - i - 1]) % mod;
            f[t] %= mod;
        }
    }
    for (int i = 0; i <= n; ++i) {
        ans[i] = (f[i] - f[i + 1] + mod) % mod;
    }
}

void solve_mask() {
    int q1 = 0, q2 = 1;
    dpm[q1][0][0] = 1;
    dpm[q1][0][1 << a[0]] = 1;
    if (c == 1) {
        dpm[q1][1][0] = 1;
        dp[0][1] = 1;
    }

    for (int i = 1; i < n; ++i) {
        for (int t = 0; t <= n / c; ++t) {
            if (t) {
                dp[i][t] = dpm[q1][t - 1][(1 << c) - 1 - (1 << a[i])];
            }
            dpm[q2][t][0] = (dpm[q1][t][0] + dp[i][t]) % mod;
            for (int mask = 1; mask < (1 << c); ++mask) {
                if (mask & (1 << a[i])) {
                    ll res = dpm[q1][t][mask] * 2LL + dpm[q1][t][mask ^ (1 << a[i])];
                    if (res >= mod) res -= mod;
                    if (res >= mod) res -= mod;
                    dpm[q2][t][mask] = res;
                } else {
                    dpm[q2][t][mask] = dpm[q1][t][mask];
                }
            }
        }
        swap(q1, q2);
    }
    f[0] = p2m1[n];
    for (int t = 1; t <= n; ++t) {
        for (int i = 0; i < n; ++i) {
            f[t] += (1LL * dp[i][t] * p2[n - i - 1]) % mod;
            f[t] %= mod;
        }
    }
    for (int i = 0; i <= n; ++i) {
        ans[i] = (f[i] - f[i + 1] + mod) % mod;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < max_n; ++i) {
        p2[i] = powm(2, i);
        p2m1[i] = (p2[i] - 1 + mod) % mod;
        p2m1r[i] = powm(p2m1[i], mod - 2);
    }
    cin >> n >> c;
    //n = 3000, c = 20;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        --a[i];
        //a[i] = i % c;
    }
    if (c < logn) {
        solve_mask();
    } else {
        solve_dp();
    }
    for (int i = 0; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}

// think 2:34