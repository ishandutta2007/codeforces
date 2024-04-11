#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 31607;
int pw(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}
int n;
int inv[mod];

int solve(vector<vector<int>> p) {
    int ret = 0;
    vector<int> r(n, 1);
    vector<vector<int>> c(1 << n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        r[i] = r[i] * p[i][j] % mod;
    }
    for (int i = 0; i < n; ++i) c[0][i] = 1;
    for (int m = 1; m < (1 << n); ++m) {
        int x = log2(m & -m);
        int mx = m - (1 << x);
        for (int i = 0; i < n; ++i) c[m][i] = c[mx][i] * p[x][i] % mod;
    }
    for (int m = 0; m < (1 << n); ++m) {
        int rem = (1 << n) - 1 - m;
        int f0 = 1, f1 = 0;
        for (int i = 0; i < n; ++i) {
            int x = c[rem][i];
            int g0 = (f0 + f1 * x) % mod;
            int g1 = (f1 + f0 * x) % mod;
            f0 = g0, f1 = g1;
        }
        int mul = 1;
        for (int i = 0; i < n; ++i) if (m >> i & 1) mul = mul * r[i] % mod;
        if (__builtin_popcount(m) % 2 == 0) ret = (ret + 1ll * mul * (f0 - f1 + mod)) % mod;
        else ret = (ret + 1ll * mul * (f1 - f0 + mod)) % mod;
    }
    return (mod + 1 - ret) % mod;
}

signed main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 1; i < mod; ++i) inv[i] = pw(i, mod - 2);
    cin >> n;
    vector<vector<int>> p;
    p.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> p[i][j];
        p[i][j] = p[i][j] * inv[10000] % mod;
    }

    int d1 = 1, d2 = 1, d12 = 1;
    vector<vector<int>> p1 = p, p2 = p, p12 = p;
    for (int i = 0; i < n; ++i) {
        d1 = d1 * p[i][i] % mod;
        d2 = d2 * p[i][n-1-i] % mod;
        d12 = d12 * p[i][i] % mod;
        if (n - i - 1 != i) d12 = d12 * p[i][n-1-i] % mod;

        p1[i][i] = 1;
        p2[i][n-1-i] = 1;
        p12[i][i] = 1;
        p12[i][n-1-i] = 1;
    }

    int ans = 0;
    ans = (ans + solve(p)) % mod;
    ans = (ans + d1) % mod;
    ans = (ans + d2) % mod;
    ans = (ans + mod - d12) % mod;
    ans = (ans + mod - d1 * solve(p1) % mod) % mod;
    ans = (ans + mod - d2 * solve(p2) % mod) % mod;
    ans = (ans + d12 * solve(p12)) % mod;
    cout << ans << endl;
    return 0;
}