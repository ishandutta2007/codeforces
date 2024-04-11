#include <iostream>
using namespace std;


int dp[55][1005];
int ans[1005][1005];
int mod = (int)1e9 + 7;
int C[1055][1055];
int fact[55];


void precalc()
{
	dp[0][0] = 1;
	for (int curLen = 1; curLen <= 1000; curLen++)
		for (int sumLen = 1000 - curLen; sumLen >= 0; sumLen--)
			for (int cnt = 0; cnt < 50; cnt++)
			{
				int nLen = curLen + sumLen;
				dp[cnt + 1][nLen] += dp[cnt][sumLen];
				if (dp[cnt + 1][nLen] >= mod)
					dp[cnt + 1][nLen] -= mod;	
			}
                                     
	fact[0] = 1;
	for (int i = 1; i <= 50; i++)
		fact[i] = (fact[i - 1] * 1LL * i) % mod;
	for (int i = 0; i <= 1000; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if (C[i][j] >= mod)
				C[i][j] -= mod;
		}
	}
	for (int sumLen = 1; sumLen <= 1000; sumLen++)
		for (int realLen = 1; realLen <= sumLen; realLen++)
			for (int k = 0; k < 50; k++)
			{
				ans[k][sumLen] += ( (dp[k][realLen] * 1LL * C[sumLen - realLen + k][k] ) % mod * fact[k] ) % mod;
				if (ans[k][sumLen] >= mod)
					ans[k][sumLen] -= mod;
			}  
	
	                        
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif           
	precalc();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		printf("%d\n", ans[k][n] );  
	}



	return 0;
}