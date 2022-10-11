#include <bits/stdc++.h>
using namespace std;

const int MX = 26, N = 105;
long long INF = 1E18 + 7;

int m, n, t, c[MX][MX];
long long f[N][MX][N];
char x, y, s[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> (s + 1) >> m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> t;
        c[x - 'a'][y - 'a'] = t;
    }
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < MX; j++) {
            for (int k = 0; k <= m; k++) {
                f[i][j][k] = -INF;
            }
        }
    }
    for (int i = 0; i < MX; i++) {
        f[1][i][i != s[1] - 'a'] = 0;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < MX; j++) {
            int prv = (j != (s[i] - 'a'));
            for (int k = prv; k <= m; k++) {
                for (int l = 0; l < MX; l++) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][l][k - prv] + c[l][j]);
                }
            }
        }
    }
    long long ans = -INF;
    for (int i = 0; i < MX; i++) {
        for (int j = 0; j <= m; j++) {
            ans = max(ans, f[n][i][j]);
        }
    }
    cout << ans;
}