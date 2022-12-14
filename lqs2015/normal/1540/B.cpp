#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, iv = (mod + 1) / 2;
int n, x, y, dp[222][222], cnt, dist[222][222], beg[222], en[222], cc, ln, ans;
vector<int> g[222];
int binpow(int a, int t)
{
	int res = 1, p = a;
	for (int i = t; i; i >>= 1)
	{
		if (i & 1) res = 1ll * res * p % mod;
		p = 1ll * p * p % mod;
	}
	return res;
}
void dfs(int i, int fa)
{
	beg[i] = ++cnt;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (to == fa) continue;
		dfs(to, i);
	}
	en[i] = cnt;
}
bool is_sub(int x, int y)
{
	return (beg[x] <= beg[y] && en[x] >= en[y]);
}
void dft(int i, int fa, int des, int d)
{
	ans = (1ll * cc * dp[d][ln - d] + ans) % mod;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (to == fa) continue;
		if (is_sub(to, des)) dft(to, i, des, d + 1);
		else dft(to, i, des, d);
	}
}
int main()
{
	scanf("%d", &n);
	cc = binpow(n, mod - 2);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = 1e9;
		}
	}
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
		dist[x][y] = dist[y][x] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = (1ll * iv * dp[i - 1][j] + 1ll * iv * dp[i][j - 1]) % mod;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		dfs(i, 0);
		for (int j = 1; j < i; j++)
		{
			ln = dist[i][j];
			dft(i, 0, j, 0);
		}
	}
	printf("%d\n", ans);
	return 0;
}