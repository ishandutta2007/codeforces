#include <bits/stdc++.h>
using namespace std;

const int Maxn = 4005;
const int Inf = 2000000007;

int n;
int a[Maxn];
int sum[Maxn];
int dp[2][Maxn][Maxn], cur;
int mn[Maxn], mx[Maxn];

int Get(int l, int r) { return a[r] - a[l - 1]; }

int main()
{
    scanf("%d", &n);
    int res;
    for (int l = 0; l < n; l++) {
        mn[l] = max(1, (n - 2 * l + 1) / 2);
        mx[l] = (n + 2) / 2;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 2; i < Maxn; i++)
        sum[i] = sum[i - 2] + i;
    for (int len = 90; len >= 1; len--) {
        cur = !cur;
        for (int l = len - 1; l < n; l++)
            for (int i = max(mn[l], sum[len - 1] + 1), j = max(mn[l], sum[len - 1] + 1) + l;
                 i <= mx[l] && j <= n - sum[len - 1]; i++, j++) {
                dp[cur][i][j] = 0;
                if (i - 1 <= n - j) {
                    if (n - j >= sum[len])
                        dp[cur][i][j] = max(-dp[cur][i + len][j] + Get(i, i + len - 1),
                                           l >= len? -dp[!cur][i + len + 1][j] + Get(i, i + len): -Inf);
                } else if (i - 1 >= sum[len])
                        dp[cur][i][j] = max(-dp[cur][i][j - len] + Get(j - len + 1, j),
                                           l >= len? -dp[!cur][i][j - len - 1] + Get(j - len, j): -Inf);
            }
    }
    printf("%d\n", dp[cur][1][n]);
    return 0;
}