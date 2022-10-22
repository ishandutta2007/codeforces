#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
const int Maxn = 505;

int C[Maxn][Maxn];
int pw[Maxn][Maxn];
int n, x;
int dp[Maxn][Maxn];

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    for (int i = 1; i < Maxn; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < Maxn; j++)
            pw[i][j] = ll(pw[i][j - 1]) * i % mod;
    }
    scanf("%d %d", &n, &x);
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= x; j++)
            if (j < i) dp[i][j] = pw[j][i];
            else {
                dp[i][j] = pw[i - 1][i];
                for (int k = 2; k <= i; k++)
                    dp[i][j] = (dp[i][j] + ll(pw[i - 1][i - k]) * dp[k][j - (i - 1)] % mod * C[i][k]) % mod;
            }
    printf("%d\n", dp[n][x]);
    return 0;
}