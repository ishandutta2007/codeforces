#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const string lets = "hard";
const int Maxd = 4;
const ll Inf = 1000000000000000000ll;

int n;
char str[Maxn];
int a[Maxn];
ll dp[Maxn][Maxd];

int main()
{
    scanf("%d", &n);
    scanf("%s", str);
    fill((ll*)dp, (ll*)dp + Maxn * Maxd, Inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (int j = 0; j < Maxd; j++) if (dp[i][j] < Inf) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
            int nj = j + (str[i] == lets[j]);
            if (nj < Maxd)
                dp[i + 1][nj] = min(dp[i + 1][nj], dp[i][j]);
        }
    }
    ll res = Inf;
    for (int j = 0; j < Maxd; j++)
        res = min(res, dp[n][j]);
    cout << res << endl;
    return 0;
}