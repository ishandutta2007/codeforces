#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxn = 2005;

int n, k;
int dp[Maxn][Maxn][4];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < 4; i++)
        if (bool(i & 1) != bool(i & 2))
            dp[1][2][i] = 1;
        else dp[1][1][i] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= k; j++)
            for (int l = 0; l < 4; l++)
                for (int nl = 0; nl < 4; nl++) {
                    int nj = j;
                    if ((l == 0 || l == 3))
                        if (nl != l) nj += 1;
                        else ;
                    else if ((l ^ nl) == 3) nj += 2;
                    dp[i + 1][nj][nl] = (dp[i + 1][nj][nl] + dp[i][j][l]) % mod;
                }
    int res = 0;
    for (int l = 0; l < 4; l++)
        res = (res + dp[n][k][l]) % mod;
    printf("%d\n", res);
    return 0;
}