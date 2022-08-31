#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;
const int N = (int)2e5;

struct DSU
{
	int par[N];
	int size[N];

	DSU()
	{
		for (int i = 0; i < N; i++)
		{
			par[i] = i;
			size[i] = 1;
		}
	}

	int get_id(int v)
	{
		if (par[v] == v)
			return v;
		return par[v] = get_id(par[v]);
	}

	void join(int a, int b)
	{
		a = get_id(a);
		b = get_id(b);
		assert(a != b);
		par[a] = b;
		size[b] += size[a];
	}

	int get_size(int a)
	{
		return size[get_id(a)];
	}
};

int n, m;
int cost[N];
vector<int> graph[N];
DSU dsu;

bool cmp(int a, int b)
{
	if (cost[a] != cost[b])
		return cost[a] < cost[b];
	return a < b;
}

void make_graph()
{
	vector<vector<int> > cur_graph(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		cur_graph[a].push_back(b);
		cur_graph[b].push_back(a);
	}

	vector<bool> used(n + 1);
	set<int, decltype(&cmp)> s(&cmp);

	int ind = 1;
	for (int i = 1; i <= n; i++)
		if (cost[i] > cost[ind])
			ind = i;
	
	s.insert(ind);
	used[ind] = true;

	while (!s.empty())
	{
		ind = *s.rbegin();
		s.erase(ind);
		for (int to : cur_graph[ind])
		{
			if (!used[to])
			{
				graph[ind].push_back(to);
				graph[to].push_back(ind);

				s.insert(to);
				used[to] = true;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &cost[i]);
	make_graph();

	vector<int> perm;
	for (int i = 1; i <= n; i++)
		perm.push_back(i);
	sort(perm.rbegin(), perm.rend(), cmp);

	vector<bool> used(n + 1);
	int64 ans = 0;
	for (int ind : perm)
	{
		for (int to : graph[ind])
		{
			int id1 = dsu.get_id(ind);
			int id2 = dsu.get_id(to);
			if (id1 == id2 || !used[to])
				continue;
			ans += (int64)cost[ind] * dsu.get_size(id2) * dsu.get_size(id1);
			dsu.join(id1, id2);
		}

		used[ind] = true;
	}
	
	ans *= 2;
	printf("%.10lf\n", (double)ans / n / (n - 1));

	return 0;
}