#include <bits/stdc++.h>

using namespace std;

int n, m, k, mod;

int c[105][105];
int ft[105];
int f[105][105][105];
vector<int> seen[105][105];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k >> mod;
    c[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= n; ++j) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    }
    ft[0] = 1;
    for (int i = 1; i <= n; ++i) ft[i] = 1ll * ft[i-1] * i % mod;
    f[1][0][0] = 1;
    for (int i = 1; i <= n; ++i) f[1][i][1] = ft[i];
    for (int i = 1; i < m; ++i) {
        f[i][0][0] = 1;
        for (int a = 0; a <= n; ++a) for (int p = 0; p <= a; ++p) if (f[i][a][p]) seen[i][a].push_back(p);
        for (int a = 0; a <= n; ++a) {
            for (int b = 0; b + a + 1 <= n; ++b) {
                for (auto p: seen[i][a]) {
                    for (auto q: seen[i][b]) {
                        f[i+1][a+b+1][p+q] = (f[i+1][a+b+1][p+q] + 1ll * f[i][a][p] * f[i][b][q] % mod * c[a+b][a]) % mod;
                            //cout << i+1 << a+b+1 << p+q << endl;
                    }
                }
            }
        }
    }
    cout << f[m][n][k] << endl;
    return 0;
}