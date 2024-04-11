#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
const int mod = 1000000007;

int dp[Maxn];
int n, m;

int main()
{
    dp[0] = 1;
    for (int i = 0; i + 2 < Maxn; i++) {
        dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
        dp[i + 2] = (dp[i + 2] + dp[i]) % mod;
    }
    scanf("%d %d", &n, &m);
    int res = (dp[n] + dp[m]) % mod;
    res = (res - 1 + mod) % mod;
    res = 2ll * res % mod;
    printf("%d\n", res);
    return 0;
}