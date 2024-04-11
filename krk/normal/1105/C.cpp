#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const int Maxd = 3;
const int mod = 1000000007;

int n, l, r;
int has[Maxd];
int dp[Maxn][Maxd];

int Get(int r, int md)
{
    if (r < md) return 0;
    return 1 + (r - md) / 3;
}

int main()
{
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 0; i < Maxd; i++)
        has[i] = Get(r, i) - Get(l - 1, i);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < Maxd; j++) if (dp[i][j])
            for (int k = 0; k < Maxd; k++) {
                int nj = (j + k) % Maxd;
                dp[i + 1][nj] = (dp[i + 1][nj] + ll(dp[i][j]) * has[k]) % mod;
            }
    printf("%d\n", dp[n][0]);
    return 0;
}