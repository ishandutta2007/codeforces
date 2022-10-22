#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll lim = 1000000000000ll;
const int Maxn = 105;
const int Maxl = 26;

int n;
ll k;
char str[Maxn];
int nxt[Maxn][Maxl];
ll dp[Maxn][Maxn];

int main()
{
    scanf("%d %I64d", &n, &k);
    scanf("%s", str);
    fill(nxt[n], nxt[n] + Maxl, n);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < Maxl; j++)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][str[i] - 'a'] = i;
    }
    for (int j = 0; j < Maxl; j++)
        if (nxt[0][j] < n) dp[nxt[0][j]][1] = 1;
    dp[n][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i + 1; j++) if (dp[i][j] > 0) {
            dp[n][j] = min(lim, dp[n][j] + dp[i][j]);
            for (int k = 0; k < Maxl; k++) {
                int u = nxt[i + 1][k];
                if (u < n)
                    dp[u][j + 1] = min(lim, dp[u][j + 1] + dp[i][j]);
            }
        }
    ll res = 0;
    for (int j = n; j >= 0; j--) {
        ll tk = min(k, dp[n][j]);
        res += tk * (n - j);
        k -= tk;
    }
    if (k > 0) printf("-1\n");
    else printf("%I64d\n", res);
    return 0;
}