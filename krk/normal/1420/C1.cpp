#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 300005;

int T;
int n, q;
int a[Maxn];
ll dp[Maxn][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &q);
        for (int i = 0; i <= n; i++)
            fill(dp[i], dp[i] + 2, -Inf);
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            for (int j = 0; j < 2; j++) if (dp[i][j] >= 0) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j == 0) dp[i + 1][1] = max(dp[i + 1][1], dp[i][j] + a);
                else dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] - a);
            }
        }
        printf("%I64d\n", max(dp[n][0], dp[n][1]));
    }
    return 0;
}