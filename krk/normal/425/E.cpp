#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 505;
const int mod = 1000000007;

int pw2[Maxn * Maxn];
int n, k;
int dp[Maxn][Maxn];

int main()
{
    pw2[0] = 1;
    for (int i = 1; i < Maxn * Maxn; i++)
        pw2[i] = ll(pw2[i - 1]) * 2ll % mod;
    scanf("%d %d", &n, &k);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++) if (dp[i][j])
            for (int l = i + 1; l <= n; l++) {
                int ours = (pw2[l - i] - 1 + mod) % mod;
                int outs = pw2[(l - i) * (n - l)];
                dp[l][j + 1] = (dp[l][j + 1] + ll(dp[i][j]) * ours % mod * outs) % mod;
            }
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = (res + dp[i][k]) % mod;
    printf("%d\n", res);
    return 0;
}