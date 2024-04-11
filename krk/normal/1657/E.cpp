#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 255;
const int Maxm = Maxn * Maxn / 2;
const int mod = 998244353;

int C[Maxn][Maxn];
int n, k;
int pw[Maxn][Maxm];
int dp[Maxn][Maxn];

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        pw[i][0] = 1;
        for (int j = 1; j < Maxm; j++)
            pw[i][j] = ll(pw[i][j - 1]) * i % mod;
    }
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    n--;
    dp[0][0] = 1;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= n; j++)
            for (int l = 0; j + l <= n; l++) {
                int hm = l * (l - 1) / 2 + j * l;
                dp[i + 1][j + l] = (dp[i + 1][j + l] + ll(C[n - j][l]) * pw[k - i][hm] % mod * dp[i][j]) % mod;
            }
    printf("%d\n", dp[k][n]);
    return 0;
}