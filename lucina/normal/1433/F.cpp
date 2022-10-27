#include<bits/stdc++.h>
using namespace std;
int const nax = 75;
int n, m, k;
int dp[nax][nax];
int f[nax][nax];
int c[nax];
int d[nax];

/**
dp for each row
choose j element sum remainder k equal to bar
*/


int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    cin >> n >> m >> k;

    memset(c, -1, sizeof(c));
    c[0] = 0;

    for (int __ = 1 ;__ <= n ; ++ __) {
        memset(dp, -1, sizeof(dp));

        dp[0][0] = 0;

        for (int _ = 1 ; _ <= m ; ++ _) {
            int x;
            cin >> x;
            memset(f, -1, sizeof(f));
            for (int i = 0 ; i < _ ; ++ i) {
                for (int j = 0 ; j < k ; ++ j) {
                    if (dp[i][j] == -1) continue;
                    f[i + 1][(j + x) % k] = max(f[i + 1][(j + x) % k], dp[i][j] + x);
                }
            }
            for (int i = 0 ; i <= _ ; ++ i)
            for (int j = 0 ; j < k ; ++ j)
                dp[i][j] = max(dp[i][j], f[i][j]);
        }
        memset(d, -1, sizeof(d));

        for (int fr = 0 ; fr < k ; ++ fr) {
            if (c[fr] == -1) continue;
            for (int i = 0 ; i <= m / 2 ; ++ i)
            for (int j = 0 ; j < k ; ++ j) {
                if (dp[i][j] == -1) continue;
                d[(j + fr) % k] = max(d[(j + fr) % k], c[fr] + dp[i][j]);
            }
        }

        for (int i = 0 ; i < k ; ++ i)
            c[i] = max(c[i], d[i]);
    }

    cout << c[0] << '\n';
}