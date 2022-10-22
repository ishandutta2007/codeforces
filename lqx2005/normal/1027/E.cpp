#include<bits/stdc++.h>

using namespace std;
const int N = 510;
const int mod = 998244353;
int dp[N][N], g[N][N];
int n, K;
void add(int &x, int y)
{
	if((x += y) >= mod && (x -= mod));
	return;
}
int main()
{
	scanf("%d%d", &n, &K);
	dp[0][0] = 1;
	for(int i = 0; i < n; i++) 
	{
		for(int j = 0; j <= n; j++) 
		{
			for(int k = i + 1; k <= n; k++)
			{
				add(dp[k][max(j, k - i)], dp[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) g[0][i] = dp[n][i];
	int ans = 0;
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = i - 1; j >= 0; j--)
			{
				if((i - j) * k >= K) break;
//				cout << (i - j) <<" "<< k << endl;
				add(g[i][k], g[j][k]);
			}
		}		
		add(ans, g[n][k]);
	}
	printf("%d\n", ans * 2 % mod);
	return 0;
}