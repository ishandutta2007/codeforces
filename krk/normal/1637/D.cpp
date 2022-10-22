#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 105;
const int Maxm = Maxn * Maxn;
const ll Inf = 1000000000000000000ll;

int T;
int n;
int a[Maxn];
int b[Maxn];
bool dp[Maxn][Maxm];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll res = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            tot += a[i];
            res += ll(n - 2) * a[i] * a[i];
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
            tot += b[i];
            res += ll(n - 2) * b[i] * b[i];
        }
        fill((bool*)dp, (bool*)dp + (n + 1) * Maxm, false);
        dp[0][0] = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i * 100; j++) if (dp[i][j]) {
                dp[i + 1][j + a[i]] = true;
                dp[i + 1][j + b[i]] = true;
            }
        ll mn = Inf;
        for (int j = 0; j < Maxm; j++) if (dp[n][j])
            mn = min(mn, ll(j) * j + ll(tot - j) * (tot - j));
        res += mn;
        printf("%I64d\n", res);
    }
    return 0;
}