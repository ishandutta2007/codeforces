#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const ll Inf = 1000000000000000000ll;
const int Maxn = 505;

int n, k;
lli dp[Maxn][Maxn];

int main()
{
    fill((lli*)dp, (lli*)dp + Maxn * Maxn, lli(-Inf, 0));
    scanf("%d %d", &n, &k);
    dp[0][0] = lli(0, 0);
    for (int i = 0; i < n; i++) {
        int a, b; scanf("%d %d", &a, &b);
        for (int j = 0; j < k; j++) if (dp[i][j].first >= 0)
            for (int z = 0; z < k && z <= a; z++) {
                ll cand = dp[i][j].first + (j + z) / k;
                int nj = (j + z) % k;
                int all = a - z + b;
                cand += all / k; all %= k;
                int myb = dp[i][j].second + min(all, b);
                cand += myb / k; myb %= k;
                dp[i + 1][nj] = max(dp[i + 1][nj], lli(cand, myb));
            }
    }
    lli res = lli(-Inf, 0);
    for (int j = 0; j < k; j++)
        res = max(res, dp[n][j]);
    printf("%I64d\n", res.first);
    return 0;
}