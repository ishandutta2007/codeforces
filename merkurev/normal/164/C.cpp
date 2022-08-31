#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;






struct Edge
{
	int to, cap, flow, rid;
	int cost;
	Edge() : to(), cap(), flow(), rid(), cost() {}
	Edge(int _to, int _cap, int _rid, int _cost) :
		to(_to), cap(_cap), flow(0), rid(_rid), cost(_cost) {}	
};

const int maxn = 2005;
vector <Edge> g[maxn];

void addEdge(int a, int b, int cap, int cost)
{
	int asz = (int) g[a].size();
	int bsz = (int) g[b].size();
	g[a].push_back(Edge(b, cap, bsz, cost) );
	g[b].push_back(Edge(a, 0, asz, -cost) );
}

const int inf = (int) 1e9 + 100;
int dist[maxn];
int pt[maxn];
int prv[maxn];
int pri[maxn];

void fb(int n, int s)
{
	for (int i = 0; i < n; i++)
		dist[i] = inf;
	dist[s] = 0;
	for (int it = 0; it < n; it++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < (int) g[i].size(); j++)
			{
				if (g[i][j].flow == g[i][j].cap)
					continue;
				int cCost = g[i][j].cost;
				int nv = g[i][j].to;
				dist[nv] = min(dist[nv], dist[i] + cCost);
			}
		}
	}
}

priority_queue <pair <int, int> > qu;
void dij(int s)
{
	dist[s] = 0;
	qu.push(make_pair(-dist[s], s) );

	while (!qu.empty() )
	{
		int v = qu.top().second;
		int cd = -qu.top().first;
		qu.pop();
		if (dist[v] != cd)
			continue;
		for (int i = 0; i < (int) g[v].size(); i++)
		{
			if (g[v][i].flow == g[v][i].cap)
				continue;
			int nv = g[v][i].to;
			int nd = cd + g[v][i].cost - pt[nv] + pt[v];
			
			if (nd < dist[nv] )
			{
				dist[nv] = nd;
				prv[nv] = v;
				pri[nv] = i;
				qu.push(make_pair(-dist[nv], nv) );
			}
		}
	}
}

void pushFlow(int s, int t)
{
	int v = t;
	while (v != s)
	{
		int pv = prv[v];
		int pi = pri[v];
		g[pv][pi].flow++;
		g[v][g[pv][pi].rid].flow--;
//		fprintf(stderr, "%d ", v);
		v = pv;
	}
//	fprintf(stderr, "%d\n", v);
}

int minCost(int n, int s, int t, int c)
{
	fb(n, s);
	for (int i = 0; i < n; i++)
		pt[i] = dist[i];
	int ans = 0;
	while (c--)
	{
		for (int i = 0; i < n; i++)
			dist[i] = inf;
		dij(s);
//		fprintf(stderr, "%.10lf\n", dist[t] );
		if (dist[t] + pt[t] > 0)
			break;
		ans += dist[t] + pt[t];
//		fprintf(stderr, "ans = %.5lf\n", ans);
		pushFlow(s, t);
		for (int i = 0; i < n; i++)
			pt[i] += dist[i];
	}
	return ans;
}







int s[maxn];
int t[maxn];
int c[maxn];
int eid[maxn];

vector <int> allt;

int getTId(int ct)
{
	return lower_bound(allt.begin(), allt.end(), ct) - allt.begin();
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &s[i], &t[i], &c[i] );
		allt.push_back(s[i] );
		allt.push_back(s[i] + t[i] );
	}
	sort(allt.begin(), allt.end() );
	allt.resize(unique(allt.begin(), allt.end() ) - allt.begin() );
	
	int S = (int) allt.size();
	int T = S + 1;
	addEdge(S, 0, k, 0);
	addEdge( (int) allt.size() - 1, T, k, 0);
	for (int i = 0; i < (int) allt.size() - 1; i++)
	{
		addEdge(i, i + 1, k, 0);
	}
	for (int i = 0; i < n; i++)
	{
		int a = getTId(s[i] );
		int b = getTId(s[i] + t[i] );
		eid[i] = (int) g[a].size();
		addEdge(a, b, 1, -c[i] );
	}
	int ans = -minCost(T + 1, S, T, k);
	eprintf("%d\n", ans);
	
	for (int i = 0; i < n; i++)
	{
		int a = getTId(s[i] );
		printf("%d ", g[a][eid[i] ].flow);
	}

	return 0;
}