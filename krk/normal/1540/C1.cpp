#include <bits/stdc++.h>
using namespace std;
 
typedef long double ld;
typedef long long ll;
 
const int mod = 1000000007;
const int Maxn = 105;
const int Maxm = Maxn * Maxn;
const int Maxs = 215;
 
int n;
int c[Maxn];
int b[Maxn];
int dp[Maxn][Maxm];
ll nd[Maxn];
int res[Maxs];

int Solve(int x)
{
    ll sum = 0;
    ll cur = x;
    for (int i = 0; i < n; i++) {
        if (i > 0) cur += b[i - 1];
        sum += cur;
        nd[i] = sum;
    }
    dp[0][0] = 1; dp[0][1] = mod - 1;
    for (int i = 0; i < n; i++) {
        int to = i * Maxn;
        int ways = 0;
        for (int j = 0; j <= to; j++) {
            ways = (ways + dp[i][j]) % mod;
            dp[i][j] = 0;
            if (ways == 0) continue;
            ll k = max(0ll, nd[i] - j);
            if (k > c[i]) continue;
            dp[i + 1][j + k] = (dp[i + 1][j + k] + ways) % mod;
            dp[i + 1][j + c[i] + 1] = (dp[i + 1][j + c[i] + 1] - ways + mod) % mod;
        }
    }
    int res = 0;
    int ways = 0;
    int to = n * Maxn;
    for (int j = 0; j <= to; j++) {
        ways = (ways + dp[n][j]) % mod;
        dp[n][j] = 0;
        res = (res + ways) % mod;
    }
    return res;
}
 
int main()
{
    scanf("%d", &n);
    int all = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        all = ll(all) * (c[i] + 1) % mod;
    }
    for (int i = 0; i < n - 1; i++)
        scanf("%d", &b[i]);
    for (int i = -Maxn; i <= Maxn; i++)
        res[i + Maxn] = Solve(i);
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        printf("%d\n", Solve(x));
      /*  if (-Maxn <= x && x <= Maxn)
            printf("%d\n", res[x + Maxn]);
        else if (x < 0) printf("%d\n", all);
        else printf("0\n");*/
    }
    return 0;
}