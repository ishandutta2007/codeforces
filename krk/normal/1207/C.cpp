#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;
const ll Inf = 9000000000000000000ll;

int T;
int n, a, b;
char str[Maxn];
ll dp[Maxn][2];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &a, &b);
        scanf("%s", str);
        for (int i = 0; i <= n; i++)
            dp[i][0] = dp[i][1] = Inf;
        dp[0][0] = ll(n) * a + ll(n + 1) * b;
        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                if (dp[i][0] < Inf) {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a + b);
                }
                if (dp[i][1] < Inf) {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a);
                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b);
                }
            } else if (dp[i][1] < Inf) {
               // dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b);
            }
        }
        printf("%I64d\n", dp[n][0]);
    }
    return 0;
}