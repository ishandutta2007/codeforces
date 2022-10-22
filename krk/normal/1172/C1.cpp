#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 200005;
const int Maxm = 3005;

int n, m;
int lik[Maxn];
int a[Maxn];
int dp[Maxm][Maxm];
int res[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

int main()
{
    scanf("%d %d", &n, &m);
    int ok = 0, notok = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &lik[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (lik[i]) ok += a[i];
        else notok += a[i];
    }
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
        for (int j = 0; j <= i; j++) if (dp[i][j]) {
            int a = ok + j, b = notok - (i - j);
            dp[i + 1][j + 1] = (dp[i + 1][j + 1] + ll(dp[i][j]) * a % mod * Inv(a + b)) % mod;
            dp[i + 1][j] = (dp[i + 1][j] + ll(dp[i][j]) * b % mod * Inv(a + b)) % mod;
        }
    for (int i = 0; i < n; i++)
        res[i] = a[i];
    int likprob = 0, notlikprob = 0;
    for (int j = 0; j <= m; j++) if (dp[m][j]) {
        likprob = (likprob + ll(j) * dp[m][j]) % mod;
        notlikprob = (notlikprob + ll(m - j) * dp[m][j]) % mod;
    }
    likprob = ll(likprob) * Inv(ok) % mod;
    notlikprob = ll(notlikprob) * Inv(notok) % mod;
    for (int i = 0; i < n; i++) {
        int res = lik[i]? (a[i] + ll(likprob) * a[i]) % mod:
                          (a[i] - ll(notlikprob) * a[i] % mod + mod) % mod;
        printf("%d\n", res);
    }
    return 0;
}