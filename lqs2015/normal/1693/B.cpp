#include <bits/stdc++.h>
using namespace std;
int test, n, p[222222], l[222222], r[222222], ans, f[222222];
vector<int> g[222222];
void dfs(int i)
{
	if (g[i].empty())
	{
		ans++;
		f[i] = r[i];
		return;
	}
	long long sum = 0;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		dfs(to);
		sum += f[to];
	}
	if (sum < l[i]) 
	{
		ans++;
		f[i] = r[i];
	}
	else
	{
		if (sum <= r[i]) f[i] = sum;
		else f[i] = r[i];
	}
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 2; i <= n; i++) scanf("%d", &p[i]);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
		}
		for (int i = 2; i <= n; i++) g[p[i]].push_back(i);
		ans = 0;
		dfs(1);
		printf("%d\n", ans);
	}
	return 0;
}