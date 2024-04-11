#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const ll Inf = 4000000000000000000ll;

int n;
int r1, r2, r3;
int d;
int a[Maxn];
ll zer[Maxn], best[Maxn];
ll res = Inf;
ll dp[Maxn][3];

int main()
{
    scanf("%d", &n);
    scanf("%d %d %d", &r1, &r2, &r3);
    scanf("%d", &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        zer[i] = ll(a[i]) * r1 + ll(r3);
        best[i] = min(zer[i], min(ll(r2) + ll(r1), ll(a[i] + 2) * r1));
        zer[i] += zer[i - 1];
        best[i] += best[i - 1];
    }
    fill((ll*)dp, (ll*)dp + Maxn * 3, Inf);
    dp[0][0] = -d;
    for (int i = 1; i <= n; i++) {
        dp[i][2] = min(min(dp[i - 1][0], dp[i - 1][2]), dp[i - 1][1] - 2ll * d) + 3ll * ll(d) + best[i] - best[i - 1];
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][2]) + 3ll * ll(d) + best[i] - best[i - 1];
        dp[i][0] = min(min(dp[i - 1][0], dp[i - 1][2]), dp[i - 1][1] - 2ll * ll(d)) + ll(d) + zer[i] - zer[i - 1];
        if (i < n) {
            ll bestend = min(zer[n] - zer[n - 1], best[n] - best[n - 1] + 2ll * (d));
            res = min(res, dp[i - 1][0] + ll(d) + best[n - 1] - best[i - 1] + 2ll * (n - i) * d + bestend);
        }
    }
    res = min(res, min(min(dp[n][0], dp[n][2]), dp[n][1] - 2ll * ll(d)));
    cout << res << endl;
    return 0;
}