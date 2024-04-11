#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
typedef long long LL;
typedef pair<int, int> PII;
 
int n, MOD;
int fac[5005], dp[2505][5005], ifac[5005];
int power(int x, int t)
{
    int ret = 1;
    while(t > 0) {
        if(t & 1) ret = 1ULL * ret * x % MOD;
        x = 1ULL * x * x % MOD;
        t >>= 1;
    }
    return ret;
}
int pw[5005][5005];
int main()
{
    scanf("%d%d", &n, &MOD);
    fac[0] = 1;
    rep1(i, n) fac[i] = 1ULL * fac[i - 1] * i % MOD;
    ifac[n] = power(fac[n], MOD - 2);
    for(int i = n; i >= 1; i --) ifac[i - 1] = 1ULL * ifac[i] * i % MOD;
    pw[0][0] = 1;
    rep1(i, n) {
        pw[i][0] = 1;
        rep1(j, n) pw[i][j] = 1ULL * pw[i][j - 1] * i % MOD;
    }
 
    dp[0][0] = 1;
    rep1(i, n / 2) for(int j = i * 2; j <= n; j ++)
    dp[i][j] = (dp[i - 1][j - 2] + dp[i][j - 1]) % MOD;
    rep1(i, n / 2) for(int j = i * 2; j <= n; j ++) dp[i][j] = 1ULL * dp[i][j] * ifac[i] % MOD * ifac[n - j] % MOD * fac[n] % MOD;
 
    int ans = 0;
    rep1(i, n / 2) for(int j = i * 2; j <= n; j ++) ans = (ans + 1ULL * dp[i][j] * pw[j - i][n - j] % MOD * pw[n - 1][i]) % MOD;
    printf("%d\n", ans);
    return 0;
}