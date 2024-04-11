#include <bits/stdc++.h>

using namespace std;

int n, m;
char s[21][100100];
int dp[21][1<<20];

int main() {
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s\n", s[i]);

    for (int j = 0; j < m; j++) {
        int x = 0;
        for (int i = 0; i < n; i++)
            if (s[i][j] == '1')
                x |= (1<<i);
        dp[0][x]++;
    }

    for (int i = 0; i < n; i++)
        for (int j = n; j > 0; j--)
            for (int k = 0; k < (1<<n); k++)
                dp[j][k] += dp[j - 1][k ^ (1<<i)];

    int ans = 1e9;
    for (int i = 0; i < (1<<n); i++) {
        int x = 0;
        for (int j = 0; j <= n; j++)
            x += min(j, n - j) * dp[j][i];
        ans = min(ans, x);
    }
    printf("%d\n", ans);
}