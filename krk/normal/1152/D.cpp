#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
const int mod = 1000000007;

int n;
int dp[Maxn][Maxn];
int res;

int main()
{
    dp[0][0] = 1;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if ((i + j) % 2) res = (res + dp[i][j]) % mod;
            if (i + 1 <= n) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
            if (j < i) dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
        }
    printf("%d\n", res);
    return 0;
}