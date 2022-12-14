#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, l[111111], r[111111], x, y;
vector<int> g[111111];
long long dp[111111][2];
void dfs(int i, int fa)
{
	dp[i][0] = dp[i][1] = 0;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (to == fa) continue;
		dfs(to, i);
		dp[i][0] += max(dp[to][0] + abs(l[i] - l[to]), dp[to][1] + abs(l[i] - r[to]));
		dp[i][1] += max(dp[to][0] + abs(r[i] - l[to]), dp[to][1] + abs(r[i] - r[to]));
	}
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		dfs(1, 0);
		printf("%lld\n", max(dp[1][0], dp[1][1]));
	} 
	return Accepted;
}