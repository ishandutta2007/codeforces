#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const long long INF = 1e18;

int n, m, p;
int tab[N];
int paint[N][N];
long long dp[N][N][N], pref[N][N][N], suf[N][N][N];

long long getMin(int i, int j, int k) {
    return min(pref[i][j][k - 1], suf[i][j][k + 1]);
}

void calcMin(int i, int j) {
    pref[i][j][0] = dp[i][j][0];
    for (int k = 1; k <= m; k++) {
        pref[i][j][k] = min(pref[i][j][k - 1], dp[i][j][k]);
    }

    suf[i][j][m + 1] = INF;
    for (int k = m; k >= 1; k--) {
        suf[i][j][k] = min(suf[i][j][k + 1], dp[i][j][k]);
    }
}

int main() {

    scanf("%d %d %d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &paint[i][j]);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= m + 1; k++) {
                dp[i][j][k] = INF;
                pref[i][j][k] = suf[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    calcMin(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (tab[i] != 0) {
                dp[i][j][tab[i]] = min(dp[i - 1][j][tab[i]], getMin(i - 1, j - 1, tab[i]));
            } else {
                for (int k = 1; k <= m; k++) {
                    dp[i][j][k] = min(dp[i - 1][j][k] + paint[i][k], getMin(i - 1, j - 1, k) + paint[i][k]);
                }
            }
            calcMin(i, j);
        }
    }

    long long ans = INF;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dp[n][p][i]);
    }

    if (ans == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", ans);
    }

    return 0;
}