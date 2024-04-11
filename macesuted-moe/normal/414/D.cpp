#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

vector<list<int> > graph;

int d[maxn], cnt[maxn];

void dfs(int p, int fa)
{
	d[p] = d[fa] + 1;
	cnt[d[p]]++;
	for (list<int>::iterator i = graph[p].begin(); i != graph[p].end(); i++)
		if (*i != fa)
			dfs(*i, p);
}

int main()
{
	int m, k, p;
	scanf("%d%d%d", &m, &k, &p);
	graph.resize(1e5 + 1);
	for (int i = 1, from, to; i < m; ++i)
	{
		scanf("%d%d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	dfs(1, -1);
	sort(d + 1, d + m + 1);
	int ans = 1;
	for (int l = 2, r = 2, cost = 0; l < m && r < m;)
	{
		if (d[++r] != d[r - 1])
			cost += r - l;
		while (cost > p || r - l + 1 > k)
			cost -= d[r] - d[l++];
		ans = max(ans, r - l + 1);
	}
	printf("%d\n", ans);
	return 0;
}