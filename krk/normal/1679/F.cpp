#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int Maxn = 50005;
const int Maxd = 10;

int n;
int m;
int forb[Maxd];
int all[Maxd];
int cur, dp[2][1 << Maxd];

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        all[a] |= 1 << b;
        all[b] |= 1 << a;
        forb[b] |= 1 << a;
    }
    dp[cur][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << Maxd; j++) if (dp[cur][j]) {
            int ways = dp[cur][j]; dp[cur][j] = 0;
            for (int k = 0; k < Maxd; k++) if (!(j & 1 << k)) {
                int nj = ((j & all[k]) | forb[k]);
                dp[!cur][nj] = (dp[!cur][nj] + ways) % mod;
            }
        }
        cur = !cur;
    }
    int res = 0;
    for (int j = 0; j < 1 << Maxd; j++)
        res = (res + dp[cur][j]) % mod;
    printf("%d\n", res);
    return 0;
}