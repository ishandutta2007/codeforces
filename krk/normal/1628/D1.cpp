#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int inv2 = (mod + 1) / 2;
const int Maxn = 2005;

int T;
int n, m, k;
int dp[Maxn][Maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &k);
        m = n - m;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = ll(k) * i % mod;
            for (int j = 1; j <= m; j++)
                dp[i][j] = ll(dp[i - 1][j] + dp[i - 1][j - 1]) * inv2 % mod;
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}