#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int)1e5 + 100;
const int INF = (int)1e9;

int n, m;
vector<int> g[N];

int l, r;
int q[N];
int dist[N];

int solve(int s)
{
	l = 0;
	r = 0;
	q[r++] = s;
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[s] = 0;
	
	int ans = 0;
	while (l < r)
	{
		int v = q[l++];
		int cur_dist = dist[v];
		ans = max(ans, cur_dist);

		for (int to : g[v])
		{
			if (dist[to] == cur_dist)
				return -1;
	
			if (dist[to] == INF)
			{
				dist[to] = cur_dist + 1;
				q[r++] = to;
			}
		}
	}

	return ans;
}

bool used[N];
vector<int> cur;

void dfs(int v)
{
	used[v] = true;
	cur.push_back(v);
	for (int to : g[v])
	{
		if (!used[to])
			dfs(to);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i])
			continue;
		
		cur.clear();
		cnt++;
		dfs(i);
		
		int cur_ans = -1;
		
		for (int v : cur)
			cur_ans = max(cur_ans, solve(v));
		
		if (cur_ans == -1)
		{
			printf("-1\n");
			return 0;
		}
		ans += cur_ans;
	}

	printf("%d\n", ans);

	return 0;
}