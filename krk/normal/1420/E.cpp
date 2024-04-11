#include <bits/stdc++.h>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 82;
const int Maxm = 3205;

int n;
vector <int> ones;
int m;
int tot;
int cur, dp[2][Maxn][Maxm];

int main()
{
    scanf("%d", &n); tot = n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        int num; scanf("%d", &num);
        if (num == 1) ones.push_back(i);
        else m++;
    }
    n = ones.size();
    if (n == 0) {
        for (int i = 0; i <= tot; i++)
            printf("0%c", i + 1 <= tot? ' ': '\n');
        return 0;
    }
    fill((int*)dp, (int*)dp + 2 * Maxn * Maxm, -Inf);
    for (int j = 0; j <= m; j++)
        dp[cur][j][abs(j - ones[0])] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++)
            for (int l = 0; l <= tot; l++) if (dp[cur][j][l] >= 0) {
                for (int z = 0; j + z <= m; z++) {
                    int cand = dp[cur][j][l] + j * z;
                    int nj = j + z;
                    int nl = l + (i + 1 < n? abs(nj + i + 1 - ones[i + 1]): 0);
                    dp[!cur][nj][nl] = max(dp[!cur][nj][nl], cand);
                }
                dp[cur][j][l] = -Inf;
            }
        cur = !cur;
    }
    int res = 0;
    for (int i = 0; i <= tot; i++) {
        res = max(res, dp[cur][m][i]);
        printf("%d%c", res, i + 1 <= tot? ' ': '\n');
    }
    return 0;
}