#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int n, m, q;
char c[1005][1005];
bool d[1005][1005];
int f[1005][1005];
int g[1005][1005];

bool ok(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) cin >> (c[i] + 1);
    for (int i = 0; i <= n + 1; ++i) for (int j = 0; j <= m + 1; ++j) f[i][j] = g[i][j] = 1000000;
    int fl2 = 0;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        int flg = 0;
        for (int z = 0; z < 4; ++z) {
            int ni = i + dx[z], nj = j + dy[z];
            if (ok(ni, nj) && c[ni][nj] == c[i][j]) flg = 1;
        }
        if (flg) d[i][j] = 1, f[i][j] = 0, fl2 = 1;
    }
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        if (d[i][j]) f[i][j] = 0;
        else f[i][j] = min(f[i-1][j], f[i][j-1]) + 1;
        g[i][j] = min(g[i][j], f[i][j]);
    }
    for (int i = 1; i <= n; ++i) for (int j = m; j >= 1; --j) {
        if (d[i][j]) f[i][j] = 0;
        else f[i][j] = min(f[i-1][j], f[i][j+1]) + 1;
        g[i][j] = min(g[i][j], f[i][j]);
    }
    for (int i = n; i >= 1; --i) for (int j = 1; j <= m; ++j) {
        if (d[i][j]) f[i][j] = 0;
        else f[i][j] = min(f[i+1][j], f[i][j-1]) + 1;
        g[i][j] = min(g[i][j], f[i][j]);
    }
    for (int i = n; i >= 1; --i) for (int j = m; j >= 1; --j) {
        if (d[i][j]) f[i][j] = 0;
        else f[i][j] = min(f[i+1][j], f[i][j+1]) + 1;
        g[i][j] = min(g[i][j], f[i][j]);
    }

    while (q--) {
        int x, y;
        long long t;
        cin >> x >> y >> t;
        if (!fl2) cout << c[x][y] << '\n';
        else {
            int ans = c[x][y] - '0';
            if (t < g[x][y]) ans ^= (t & 1);
            else ans ^= (g[x][y] & 1);
            ans ^= (t & 1);
            cout << ans << '\n';
        }
    }
    return 0;
}