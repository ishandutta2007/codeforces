#include <bits/stdc++.h>

using namespace std;

const int N = 21, MAX_MASK = 1200000, M = 100005;

int n, m;
char row[M];
int val[M];
int dp[N][MAX_MASK];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%s", row);
        for (int j = 0; j < m; j++) {
            val[j] *= 2;
            val[j] += row[j] - 48;
        }
    }

    for (int i = 0; i < m; i++) {
        dp[0][val[i]]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = n; j > 0; j--) {
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[j][mask] += dp[j - 1][mask ^ (1 << i)];
            }
        }
    }

    int ans = n * m;
    for (int mask = 0; mask < (1 << n); mask++) {
        int res = 0;
        for (int i = 0; i <= n; i++) {
            res += min(i, n - i) * dp[i][mask];
        }
        ans = min(ans, res);
    }

    printf("%d\n", ans);

    return 0;
}