#include <bits/stdc++.h>
using namespace std;

const int nil = 2005;
const int Maxm = 4015;
const int Maxn = 10005;
const int Inf = 1000000000;

int T;
int n;
int a[Maxn];
int cur, dp[2][Maxm];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        fill(dp[cur], dp[cur] + Maxm, Inf);
        dp[cur][nil] = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur = !cur;
            fill(dp[cur], dp[cur] + Maxm, Inf);
            for (int j = 0; j < Maxm; j++) if (dp[!cur][j] < Inf) {
                int nj = min(nil, j + a[i]);
                if (nj < Maxm) dp[cur][nj] = min(dp[cur][nj], max(a[i], dp[!cur][j] + a[i]));
                nj = min(nil - a[i], j - a[i]);
                if (nj >= 0) dp[cur][nj] = min(dp[cur][nj], max(0, dp[!cur][j] - a[i]));
            }
        }
        int res = Inf;
        for (int j = 0; j < Maxm; j++)
            res = min(res, dp[cur][j] - (j - nil));
        printf("%d\n", res);
    }
    return 0;
}