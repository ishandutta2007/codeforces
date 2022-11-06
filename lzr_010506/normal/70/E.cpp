#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

vector<int> g[310];
int n,k,d[310],dp[310][310],dis[310][310],ans[310];
void dfs(int x, int fa = 0)
{
	rep(i, 1, n) dp[x][i] = d[dis[x][i]];
	int nn = g[x].size() - 1;
	rep(xx, 0, nn)
	{
		int to = g[x][xx];
		if(to != fa)
		{
			dfs(to, x);
			rep(i, 1, n)
			{
				int mn = INF;
				rep(j, 1, n)
					if(dis[x][i] <= dis[x][j] && dis[to][j] <= dis[to][i])
						mn = min(mn, dp[to][j]);
				dp[x][i] += mn;
			}
		}
	}
}
void dfs1(int x, int i, int fa = 0)
{
	if(x == i) ans[x] = x;
	int nn = g[x].size() - 1;
	rep(xx, 0, nn)
	{
		int to = g[x][xx];
		if(to != fa)
		{
			pii mn = mp(INF, 0);
			rep(j, 1, n)
				if(dis[x][i] <= dis[x][j] && dis[to][j] <= dis[to][i])
					mn = min(mn, mp(dp[to][j], j));
			dfs1(to, mn.Y, x);
		}
	}
}
int main()
{
	n = read();
	k = read();
	d[0] = k;
	rep(i, 1, n - 1) d[i] = read();
	rep(i, 1, n)
		rep(j, 1, n)
			dis[i][j] = INF;
	rep(i, 1, n) dis[i][i] = 0;
	rep(i, 1, n - 1)
	{
		int u = read();
		int v = read();
		g[u].pb(v);
		g[v].pb(u);
		dis[u][v] = dis[v][u] = 1;
	}
	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	dfs(1);
	int t = min_element(dp[1] + 1, dp[1] + n + 1) - dp[1];
	dfs1(1, t);
	printf("%d\n", dp[1][t]);
	rep(i, 1, n)
	{
		if(!ans[i])
			rep(j, 1, n)
				if(ans[j] == j && (!ans[i] || dis[ans[i]][i] > dis[j][i]))
					ans[i] = j;
		printf("%d ",ans[i]);
	}
	return 0;
}