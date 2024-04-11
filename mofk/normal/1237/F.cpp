#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int n, m, k;
int r[3605], c[3605];
int f[3605][3605], g[3605][3605];
int ft[3605], in[3605];

int pw(int x, int y) {
    int r = 1;
    while (y) {
        if (y & 1) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return r;
}
int comb(int x, int y) {
    if (y > x) return 0;
    return 1ll * ft[x] * in[x-y] % mod;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m >> k;
    ft[0] = in[0] = 1;
    for (int i = 1; i <= 3600; ++i) ft[i] = 1LL * ft[i-1] * i % mod, in[i] = pw(ft[i], mod - 2);
    for (int i = 1; i <= k; ++i) {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if (x == u) r[x] = c[y] = c[v] = 1;
        else r[x] = r[u] = c[y] = 1;
    }
    int nr = count(r + 1, r + n + 1, 0);
    int nc = count(c + 1, c + m + 1, 0);
    f[0][0] = g[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            f[i][j] = f[i-1][j];
            if (i > 1 && j && r[i] == 0 && r[i-1] == 0)
                f[i][j] = (f[i][j] + f[i-2][j-1]) % mod;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            g[i][j] = g[i-1][j];
            if (i > 1 && j && c[i] == 0 && c[i-1] == 0)
                g[i][j] = (g[i][j] + g[i-2][j-1]) % mod;
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; ++i) if (f[n][i]) {
        for (int j = 0; j <= m; ++j) if (g[m][j]) {
            int add = 1LL * f[n][i] * g[m][j] % mod * comb(nc - 2 * j, i) % mod * comb(nr - 2 * i, j) % mod;
            ans = (ans + add) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}