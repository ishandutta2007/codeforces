#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, dp[222222][2][2], f[2][2][2], nf[2][2][2], nk, nh, np, x, y;
vector<int> g[222222];
void dfs(int i, int fa)
{
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (to == fa) continue;
		dfs(to, i);
	}
	for (int j = 0; j < 2; j++)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int h = 0; h < 2; h++)
			f[j][k][h] = 1e9;
		}
	}
	f[0][0][0] = 0; 
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (to == fa) continue;
		for (int k = 0; k < 2; k++)
		{
			for (int h = 0; h < 2; h++)
			{
				for (int p = 0; p < 2; p++)
				nf[k][h][p] = 1e9;
			}
		}
		for (int k = 0; k < 2; k++)
		{
			for (int h = 0; h < 2; h++)
			{
				for (int p = 0; p < 2; p++)
				{
					for (int r = 0; r < 2; r++)
					{
						for (int s = 0; s < 2; s++)
						{
							if (!r) 
							{
								nk = k + 1;
								nh = h;
							}
							else
							{
								nk = k;
								nh = 1;
							}
							if (nk >= 2) continue;
							if (s == 1 && !h) np = 1;
							else if (r == 1) np = 0;
							else np = p;
							nf[nk][nh][np] = min(nf[nk][nh][np], f[k][h][p] + dp[to][r][s]);
						}
					}
				}
			}
		}
		for (int k = 0; k < 2; k++)
		{
			for (int h = 0; h < 2; h++)
			{
				for (int p = 0; p < 2; p++)
				f[k][h][p] = nf[k][h][p];
			}
		}
	}
	for (int k = 0; k < 2; k++)
	{
		for (int h = 0; h < 2; h++)
		dp[i][k][h] = 1e9;
	}
	for (int k = 0; k < 2; k++)
	{
		for (int h = 0 ; h < 2; h++)
		{
			for (int p = 0; p < 2; p++)
			{
				f[k][1][0] = min(f[k][1][0], f[k][h][p] + 1); 
			}
		}
	}
	for (int k = 0; k < 2; k++)
	{
		for (int h = 0 ; h < 2; h++)
		{
			for (int p = 0; p < 2; p++)
			{
				if (i == 1) dp[i][h][p] = min(dp[i][h][p], f[k][h][p]);
				else dp[i][h][p || k] = min(dp[i][h][p || k], f[k][h][p]);
			}
		}
	}
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if (n == 1)
		{
			printf("0\n");
			continue;
		}
		if (n == 2)
		{
			printf("1\n");
			continue;
		}
		dfs(1, 0);
		printf("%d\n", min(dp[1][0][0], dp[1][1][0]));
	}
	return Accepted;
}