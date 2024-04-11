#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 505;

int C[Maxn][Maxn];
int n;
int dp[Maxn][Maxn];

int Get(int i, int j)
{
    int res = 2 * dp[i - 1][j] % mod;
    for (int a = 1; a <= j; a++) {
        int b = j + 1 - a;
        res = (res + ll(C[j + 1][a]) * dp[i - 1][a - 1] % mod * dp[i - 1][b - 1]) % mod;
    }
    return res;
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= n; j++) {
            if (j == 0) dp[i][j] = 1;
            if (j >= 1)
                dp[i][j] = (dp[i][j] + ll(j + 1) * Get(i, j - 1)) % mod;
            dp[i][j] = (dp[i][j] + ll(2 * j + 3) * Get(i, j)) % mod;
            dp[i][j] = (dp[i][j] + ll(j + 1) * Get(i, j + 1)) % mod;
        }
    cout << dp[n][0] << endl;
    return 0;
}