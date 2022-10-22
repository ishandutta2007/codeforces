#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 105;
const int Maxm = 215;

int C[Maxm][Maxm];
int n, m, k;
int cur, dp[2][Maxn][Maxn][Maxn];
int res;

int main()
{
    for (int i = 0; i < Maxm; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = min((C[i - 1][j - 1] + C[i - 1][j]), Maxn);
    }
    scanf("%d %d %d", &n, &m, &k);
    for (int t = 1; t <= m; t++) {
        for (int z = 1; z <= n; z++)
            dp[!cur][z][z][1] = (dp[!cur][z][z][1] + 1) % mod;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= i; j++)
                for (int l = 1; l <= k; l++) if (dp[cur][i][j][l]) {
                    int ways = dp[cur][i][j][l]; dp[cur][i][j][l] = 0;
                    if (j == 0) {
                        res = (res + ways) % mod;
                        continue;
                    }
                    for (int z = j; i + z <= n; z++) {
                        int nl = min(Maxn, C[z - 1][j - 1] * l);
                        if (nl > k) break;
                        dp[!cur][i + z][z - j][nl] = (dp[!cur][i + z][z - j][nl] + ways) % mod;
                    }
                }
        cur = !cur;
    }
    for (int i = 0; i <= n; i++)
        for (int l = 1; l <= k; l++)
            res = (res + dp[cur][i][0][l]) % mod;
    cout << res << endl;
    return 0;
}