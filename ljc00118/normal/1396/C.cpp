#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline void addmin(ll &x, ll y) { x = min(x, y); }

const int N = 1e6 + 5;

ll dp[N][2];
int a[N], cost[N];
int n, r1, r2, r3, d;

int main() {
    memset(dp, 0x3f, sizeof(dp));
    scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cost[i] = min(1ll * r2, 1ll * r1 * (a[i] + 1));
    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        addmin(dp[i + 1][0], dp[i][0] + min(1ll * a[i] * r1 + r3 + d, cost[i] + r1 + 3ll * d));
        addmin(dp[i + 1][0], dp[i][1] + r1 + d);
        addmin(dp[i + 1][1], dp[i][0] + cost[i] + cost[i + 1] + 3ll * d + r1);
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    printf("%lld\n", min(min(dp[n][0] + min(1ll * a[n] * r1 + r3, cost[n] + r1 + 2ll * d), dp[n][1] + r1), dp[n - 1][0] + cost[n - 1] + 1ll * a[n] * r1 + r3 + 2 * d + r1));
    return 0;
}