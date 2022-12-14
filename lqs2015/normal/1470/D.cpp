#include <bits/stdc++.h>
using namespace std;
int test, n, m, x, y, ord[333333], cnt, flg, res[333333];
vector<int> g[333333], ans;
bool used[333333];
void dfs(int i)
{
	ord[++cnt] = i;
	used[i] = 1;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j];
		if (!used[to]) dfs(to);
	}
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= m; i++) 
		{
			scanf("%d%d", &x, &y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		cnt = 0;
		for (int i = 1; i <= n; i++) used[i] = 0;
		dfs(1);
		if (cnt < n)
		{
			printf("NO\n");
			continue;
		}
		for (int i = 1; i <= n; i++) res[i] = 0;
		ans.clear();
		for (int i = 1; i <= n; i++) 
		{
			x = ord[i];
			res[x] = 1;
			for (int j = 0; j < g[x].size(); j++)
			{
				int to = g[x][j];
				if (res[to]) res[x] = 0;
			}
			if (res[x]) ans.push_back(x);
		}
		printf("YES\n");
		printf("%d\n", (int)ans.size());
		for (int i = 0; i < ans.size(); i++)
		{
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}