#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 2005;

int dp[Maxn][Maxn];
int n, m, k;

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    dp[1][0] = m;
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= k; j++) if (dp[i][j]) {
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + ll(dp[i][j]) * (m - 1)) % mod;
        }
    printf("%d\n", dp[n][k]);
    return 0;
}