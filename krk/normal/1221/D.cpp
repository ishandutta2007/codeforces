#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 300005;

int T;
int n;
int a[Maxn], b[Maxn];
ll dp[Maxn][3];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
            fill(dp[i], dp[i] + 3, Inf);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &a[i], &b[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++) {
                ll val = j * b[i];
                if (i == 0) dp[1][j] = min(dp[1][j], val);
                else {
                    ll best = Inf;
                    for (int k = 0; k < 3; k++) if (a[i - 1] + k != a[i] + j)
                        best = min(best, dp[i][k]);
                    dp[i + 1][j] = min(dp[i + 1][j], val + best);
                }
            }
        printf("%I64d\n", min(min(dp[n][0], dp[n][1]), dp[n][2]));
    }
    return 0;
}