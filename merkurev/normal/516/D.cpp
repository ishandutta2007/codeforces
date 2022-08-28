#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef long long int int64;

const int N = (int)1e5 + 100;
const int LOGN = 18;

int n;
vector<pair<int, int> > graph[N];

int64 max_down_dist[N];
int64 max_ans[N];

int go[N][LOGN];
//int64 go_dist[N][LOGN];

int tree_ans[N];

int root;
int64 l;

void go_dfs(int v, int p)
{
	go[v][0] = p;
	//go_dist[v][0] = pw;

	for (int i = 1; i < LOGN; i++)
	{
		if (go[v][i - 1] == -1)
			break;
		go[v][i] = go[go[v][i - 1]][i - 1];
		//go_dist[v][i] = go_dist[v][i - 1] + go_dist[go[v][i - 1]][i - 1];
	}

	for (auto pp : graph[v])
	{
		int to = pp.first;
		if (to == p)
			continue;
		go_dfs(to, v);
	}
}

void dfs_dist(int v, int p)
{
	for (auto pp : graph[v])
	{
		int to = pp.first;
		int w = pp.second;
		if (to == p)
			continue;
		dfs_dist(to, v);
		max_down_dist[v] = max(max_down_dist[v], max_down_dist[to] + w);
	}
}

void dfs_ans(int v, int p, int64 max_up)
{
	max_ans[v] = max_up;
	multiset<int64> s;
	for (auto pp : graph[v])
	{
		int to = pp.first;
		int w = pp.second;
		if (to == p)
			continue;
		max_ans[v] = max(max_ans[v], max_down_dist[to] + w);
		s.insert(max_down_dist[to] + w);
	}

	for (auto pp : graph[v])
	{
		int to = pp.first;
		int w = pp.second;
		if (to == p)
			continue;
		auto it = s.find(max_down_dist[to] + w);
		s.erase(it);
		int64 best_s = 0;
		if (!s.empty())
			best_s = *s.rbegin();
		dfs_ans(to, v, max(max_up, best_s) + w);
		s.insert(max_down_dist[to] + w);
	}
}

void calc_max_dist()
{
	dfs_dist(1, -1);
	dfs_ans(1, -1, 0);
	root = 1;
	for (int i = 1; i <= n; i++)
	{
		//printf("max_ans[%d] = %lld\n", i, max_ans[i]);
		if (max_ans[i] < max_ans[root])
			root = i;
	}

	//printf("root = %d\n", root);
}

void dfs_solve(int v, int p)
{
	tree_ans[v] = 1;
	
	int cur_v = v;
	for (int i = LOGN - 1; i >= 0; i--)
	{
		if (go[cur_v][i] == -1)
			continue;
		int next_v = go[cur_v][i];
		if (max_ans[v] - max_ans[next_v] > l)
			continue;
		cur_v = go[cur_v][i];
	}

	cur_v = go[cur_v][0];
	if (cur_v != -1)
		tree_ans[cur_v]--;

	for (auto pp : graph[v])
	{
		int to = pp.first;
		if (to == p)
			continue;
		dfs_solve(to, v);
		tree_ans[v] += tree_ans[to];
	}
}

int solve()
{
	for (int i = 1; i <= n; i++)
		tree_ans[i] = 0;

	dfs_solve(root, -1);

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, tree_ans[i]);
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].emplace_back(b, w);
		graph[b].emplace_back(a, w);
	}
	
	calc_max_dist();
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < LOGN; j++)
		{
			go[i][j] = -1;
			//go_dist[i][j] = 0;
		}
	}

	go_dfs(root, -1);
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%lld", &l);
		int res = solve();
		printf("%d\n", res);
	}

	return 0;
}