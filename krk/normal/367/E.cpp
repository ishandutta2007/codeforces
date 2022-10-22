#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1005;

int n, m, x;
int cur, dp[2][Maxn][Maxn];

int main()
{
    scanf("%d %d %d", &n, &m, &x);
    if (n > m) { printf("0\n"); return 0; }
    dp[cur][0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int a = 0; a <= n; a++)
            for (int b = 0; b <= a; b++) if (dp[cur][a][b]) {
                int w = dp[cur][a][b]; dp[cur][a][b] = 0;
                if (i != x) dp[!cur][a][b] = (dp[!cur][a][b] + w) % mod;
                if (i != x && b > 0) dp[!cur][a][b - 1] = (dp[!cur][a][b - 1] + w) % mod;
                if (a < n) dp[!cur][a + 1][b + 1] = (dp[!cur][a + 1][b + 1] + w) % mod;
                if (a < n) dp[!cur][a + 1][b] = (dp[!cur][a + 1][b] + w) % mod;
            }
        cur = !cur;
    }
    int res = dp[cur][n][0];
    for (int i = 1; i <= n; i++)
        res = ll(res) * i % mod;
    cout << res << endl;
    return 0;
}