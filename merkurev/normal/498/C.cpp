#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;





map <int, int> p;
int sz = 0;
const int maxn = 105;
int deg[30 * maxn][maxn];
vector <int> g[maxn];
const int inf = 1e5;


struct Edge
{
	int to, cap, flow, rid;
	Edge() : to(), cap(), flow(), rid() {}
	Edge(int _to, int _cap, int _rid) : to(_to), cap(_cap), flow(0), rid(_rid) {}
};
vector <Edge> G[maxn];
void addEdge(int v, int to, int cap)
{
	G[v].push_back(Edge(to, cap, (int) G[to].size() ) );
	G[to].push_back(Edge(v, 0, (int) G[v].size() - 1) );
}

bool used[maxn];
bool dfs(int v, int t)
{
	if (used[v] )
		return false;
	used[v] = true;
	if (v == t)
		return true;
	for (int i = 0; i < (int) G[v].size(); i++)
	{
		if (G[v][i].cap == G[v][i].flow)
			continue;
		int nv = G[v][i].to;
		if (dfs(nv, t) )
		{
			G[v][i].flow++;
			G[nv][G[v][i].rid].flow--;
			return true;
		}
	}
	return false;
}

int ff(int s, int t)
{
	int ans = 0;
	memset(used, false, sizeof used);
	while (dfs(s, t) )
	{
		memset(used, false, sizeof used);
		ans++;
	}
	return ans;
}

int solve(int id, int n)
{
	int s = n;
	int t = n + 1;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			addEdge(s, i, deg[id][i] );
		else 
			addEdge(i, t, deg[id][i] );
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int) g[i].size(); j++)
			addEdge(i, g[i][j], inf);

	int answer = ff(s, t);

	for (int i = 0; i <= t; i++)
		G[i].clear();
	return answer;
}


int getId(int x)
{
	if (!p.count(x) )
	{
		p[x] = sz++;
	}
	return p[x];
}


int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int a;
		scanf("%d", &a);
		
		for (int j = 2; j * j <= a; j++)
		{
			if (a % j == 0)
			{
				int id = getId(j);
				while (a % j == 0)
				{
					a /= j;
					deg[id][i]++;
				}
			}
		}
		if (a != 1)
		{
			int id = getId(a);
			deg[id][i]++;
		}
	}
	for (int j = 0; j < m; j++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (a % 2 != 0)
			swap(a, b);
		if (a % 2 != 0)
			throw 42;
		g[a].push_back(b);
	}
	int ans = 0;
	for (int i = 0; i < sz; i++)
	{
		ans += solve(i, n);
	}
	printf("%d\n", ans);


	return 0;
}