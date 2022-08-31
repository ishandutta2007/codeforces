#include <iostream>
using namespace std;


long long mod = 1e9 + 7;

long long Mod(long long x)
{
    return x % mod;
}
long long C2(int x)
{
    return x * (x - 1) / 2;
}
long long dp[2005][2005];
long long sumP[2005][2005];

long long dp1[2005][2005];
long long sumP1[2005][2005];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);


    for (int h = 1; h <= n; h++)
	{
        long long curSum = 1;
        for (int l = 2; l <= m; l++)
		{
            curSum += sumP1[h - 1][l];

            curSum %= mod;
            dp1[h][l] = curSum;
		}
        curSum = 0;
        for (int i = 0; i <= m; i++)
		{
			curSum += dp1[h][i];
            curSum %= mod;
            sumP1[h][i] = curSum;
		}
	}

    for (int h = 1; h <= n; h++)
	{
        long long curSum = 1;
        for (int l = 2; l <= m; l++)
		{
            curSum += sumP1[h - 1][l - 1];
            curSum += dp1[h - 1][l - 1];

            curSum %= mod;
            dp[h][l] = curSum;
		}
  //      curSum = 0;
  //      for (int i = 0; i <= m; i++)
		//{
		//	curSum += dp[h][i];
  //          curSum %= mod;
  //          sumP[h][i] = curSum;
		//}
	}


   

    long long ans = 0;
    for (int i = 1; i <= n; i++)
	{
        for (int l = 2; l <= m; l++)
		{
            long long cur = dp[i][l] * dp1[n - i + 1][l];
            cur %= mod;
            cur *= m - l + 1;
            cur %= mod;
            ans += cur;
            ans %= mod;
		}
	}
    printf("%I64d", ans);

    return 0;
}