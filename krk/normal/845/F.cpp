#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 252;
const int Maxb = 15;

int n, m;
char B[Maxn][Maxn], nB[Maxn][Maxn];
int cur, dp[2][1 << Maxb][2][2];

void Swap()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nB[j][i] = B[i][j];
    swap(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[i][j] = nB[i][j];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", B[i]);
    if (n < m) Swap();
    dp[cur][0][0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 1 << m; k++)
                for (int fa = 0; fa < 2; fa++)
                    for (int fb = 0; fb < 2; fb++) {
                        int ways = dp[cur][k][fa][fb];
                        dp[cur][k][fa][fb] = 0;
                        if (B[i][j] == 'x') {
                            int nk = k;
                            if (nk & 1 << j) nk ^= 1 << j;
                            dp[!cur][nk][0][fb] = (dp[!cur][nk][0][fb] + ways) % mod;
                        } else {
                            // place guard
                            int nk = (k | 1 << j);
                            dp[!cur][nk][1][fb] = (dp[!cur][nk][1][fb] + ways) % mod;
                            // don't place guard
                            if (fa || bool(k & 1 << j))
                                dp[!cur][k][fa][fb] = (dp[!cur][k][fa][fb] + ways) % mod;
                            else if (fb + 1 < 2)
                                dp[!cur][k][fa][fb + 1] = (dp[!cur][k][fa][fb + 1] + ways) % mod;
                        }
                    }
            cur = !cur;
        }
        for (int k = 0; k < 1 << m; k++)
            for (int fa = 0; fa < 2; fa++)
                for (int fb = 0; fb < 2; fb++) {
                    int ways = dp[cur][k][fa][fb];
                    dp[cur][k][fa][fb] = 0;
                    dp[!cur][k][0][fb] = (dp[!cur][k][0][fb] + ways) % mod;
                }
        cur = !cur;
    }
    int res = 0;
    for (int k = 0; k < 1 << m; k++)
        for (int fa = 0; fa < 2; fa++)
            for (int fb = 0; fb < 2; fb++)
                res = (res + dp[cur][k][fa][fb]) % mod;
    printf("%d\n", res);
    return 0;
}