#include <bits/stdc++.h>

using namespace std;

int n, m;
string a[1000006];
const int mod = 1007050321;
vector <int> f[1000006], g[1000006];


int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i], f[i].assign(m, 0), g[i].assign(m, 0);
    f[0][0] = 1;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if ((i == 0 && j == 0) || a[i][j] == '#') continue;
        if (i == 0) f[i][j] = f[i][j-1];
        else if (j == 0) f[i][j] = f[i-1][j];
        else f[i][j] = (f[i-1][j] + f[i][j-1]) % mod;
    }
    if (f[n-1][m-1] == 0) return cout << 0 << endl, 0;
    g[n-1][m-1] = 1;
    for (int i = n - 1; i >= 0; --i) for (int j = m - 1; j >= 0; --j) {
        if ((i == n - 1 && j == m - 1) || a[i][j] == '#') continue;
        if (i == n - 1) g[i][j] = g[i][j+1];
        else if (j == m - 1) g[i][j] = g[i+1][j];
        else g[i][j] = (g[i+1][j] + g[i][j+1]) % mod;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (i == 0 && j == 0) continue;
        if (i == n - 1 && j == m - 1) continue;
        if (1LL * f[i][j] * g[i][j] % mod == f[n-1][m-1])
            return cout << 1 << endl, 0;
    }
    cout << 2 << endl;
    return 0;
}