#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
const int inf = 1e8 + 7;
ll t;
ll n;
char ac[N];
int se[N];
int dp[N][2][2];
void chm(int &x, int y)
{
	if(x > y) x = y;
	return;
}
int DP(int a, int b)
{
	for(int i = 0; i <= n + 2; i++) dp[i][0][0] = dp[i][1][0] = dp[i][0][1] = dp[i][1][1] = inf;
	dp[2][a][b] = 0;
	for(int i = 2; i <= n + 1; i++)
	{
		for(int j = 0; j <= 1; j++)
		{
			for(int k = 0; k <= 1; k++)
			{
				for(int l = 0; l <= 1; l++)
				{
					if(j == 0 && l == 0)
					{
						if(k == 0) continue;
						else chm(dp[i + 1][k][l], dp[i][j][k] + (se[i + 1] == l));
					}
					else if((j == 1 && l == 0) || (j == 0 && l == 1))
					{
						chm(dp[i + 1][k][l], dp[i][j][k] + (se[i + 1] == l));
					}
					else 
					{
						if(k == 1) continue;
						else chm(dp[i + 1][k][l], dp[i][j][k] + (se[i + 1] == l));
					}
				}
			}
		}
	}
	return dp[n + 2][a][b];
}
int main()
{
	scanf("%lld", &t);
	for(int amo = 1; amo <= t; amo++)
	{
		scanf("%lld", &n);	
		scanf("%s", ac + 1);
		for(int i = 1; i <= n; i++) se[i] = ac[i] == 'R';
		se[n + 1] = se[1], se[n + 2] = se[2];
		int ans = inf;
		for(int i = 0; i <= 1; i++)
		{
			for(int j = 0; j <= 1; j++)
			{
				chm(ans, DP(i,j));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}