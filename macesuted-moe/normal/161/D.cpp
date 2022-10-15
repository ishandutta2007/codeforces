#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;

int dp[maxn][505];
long long ans = 0;
int n, k;
vector<list<int> > graph;

void dfs(int p, int fa)
{
	dp[p][0] = 1;
	for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
		if (*i != fa)
		{
			dfs(*i, p);
			for (int j = 0; j < k; j++)
				ans += (dp[p][j] * dp[*i][k - j - 1]);
			for (int j = 0; j < k; j++)
				dp[p][j + 1] += dp[*i][j];
		}
}
int main()
{
	scanf("%d%d", &n, &k);
	graph.resize(n + 1);
	for (int i = 1, from, to; i < n; i++)
	{
		scanf("%d%d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	dfs(1, -1);
	printf("%lld\n", ans);
	return 0;
}