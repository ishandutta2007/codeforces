#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 1005;
const int Maxm = 21;

int n, m;
int dp[Maxm][Maxn];
int res;

int main()
{
    scanf("%d %d", &n, &m);
    m *= 2;
    dp[0][1] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= n; j++) if (dp[i][j]) {
            dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
        }
    for (int j = 1; j <= n; j++)
        res = (res + dp[m][j]) % mod;
    printf("%d\n", res);
    return 0;
}