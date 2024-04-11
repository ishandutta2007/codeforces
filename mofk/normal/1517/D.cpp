#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int n, m, k;
int r[505][505], c[505][505];
int f[505][505], g[505][505];

void op(int &a, int b) { if (a > b) a = b; }

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) for (int j = 1; j < m; ++j) cin >> r[i][j];
    for (int i = 1; i < n; ++i) for (int j = 1; j <= m; ++j) cin >> c[i][j];
    if (k & 1) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) cout << -1 << ' ';
            cout << endl;
        }
        return 0;
    }
    k /= 2;
    for (int s = 1; s <= k; ++s) {
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
            g[i][j] = inf;
            if (i > 1) op(g[i][j], f[i-1][j] + c[i-1][j]);
            if (j > 1) op(g[i][j], f[i][j-1] + r[i][j-1]);
            if (i < n) op(g[i][j], f[i+1][j] + c[i][j]);
            if (j < m) op(g[i][j], f[i][j+1] + r[i][j]);
        }
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) f[i][j] = g[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cout << 2 * f[i][j] << ' ';
        cout << endl;
    }
    return 0;
}