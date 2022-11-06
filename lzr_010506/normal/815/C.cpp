#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
const int INF = 1e9 + 10;
int n, tot;
int val[N], val2[N];
vector<int> mp[N];
int dp[N][N][2], sz[N];

void dfs(int u)
{
	sz[u] = 0;
	for(int i = 1; i <= n; i ++)
		dp[u][i][1] = INF;
	for(int i = 0; i < mp[u].size(); i ++) dfs(mp[u][i]);
	for(int ss = 0; ss < mp[u].size(); ss ++)
	{
		int v = mp[u][ss];
		for(int i = sz[u]; i >= 0; i --)
			for(int j = 1; j <= sz[v]; j ++)
				dp[u][i + j][1] = min(dp[u][i + j][1], dp[u][i][1] + min(dp[v][j][0], dp[v][j][1]));
		sz[u] += sz[v];
	}
	sz[u] ++;
	for(int i = sz[u]; i; i --)
		dp[u][i][1] = dp[u][i - 1][1] + val[u];
	dp[u][0][1] = INF;
	 
	sz[u] = 0;
	for(int i = 1; i <= n; i ++)
		dp[u][i][0] = INF;
	for(int ss = 0; ss < mp[u].size(); ss ++)
	{
		int v = mp[u][ss];
		for(int i = sz[u]; i >= 0; i --)
			for(int j = 1; j <= sz[v]; j ++)
				dp[u][i + j][0] = min(dp[u][i + j][0], dp[u][i][0] + dp[v][j][0]);
		sz[u] += sz[v];
	}
	sz[u] ++;
	for(int i = sz[u]; i; i --)
		dp[u][i][0] = min(dp[u][i][0], dp[u][i - 1][0] + val2[u]);
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	tot = read();
	for(int i = 1; i <= n; i ++)
	{
		int x, y;
		x = read();
		y = read();
		val[i] = x - y;
		val2[i] = x;
		if(i >= 2)
		{
			int t = read();
			mp[t].push_back(i);
		}
	}
	dfs(1);
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		if(dp[1][i][0] <= tot || dp[1][i][1] <= tot)
			ans = i;
    cout << ans;
	return 0;
}