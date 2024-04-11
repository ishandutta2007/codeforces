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
#include <cmath>
#include <queue>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = (int) 2e5 + 100;
vector <pair <int, int> > ig[N];
vector <int> g[N], gr[N], G[N];
long long d[N];
priority_queue <pair <long long, int> > qu;
const long long INF = (long long) 1e18;
vector <int> ord;

int cnt[N];

const int LOG = 20;

int par[N][LOG];
int h[N];

int s;
int answer;
int dfs(int v)
{
	int ans = 1;
	for (int to : G[v] )
		ans += dfs(to);
	if (v != s)
		answer = max(answer, ans);
	return ans;
}

void setDom(int v, int x)
{
	if (v != x)
	{
		G[x].push_back(v);
		h[v] = h[x] + 1;
	}
	par[v][0] = x;
	for (int i = 1; i < LOG; i++)
		par[v][i] = par[par[v][i - 1] ][i - 1];
}

int goUp(int v, int di)
{
	for (int i = 0; i < LOG; i++)
		if (di & (1 << i) )
			v = par[v][i];
	return v;
}

int LCA(int a, int b)
{
	if (h[a] > h[b] ) swap(a, b);
	b = goUp(b, h[b] - h[a] );
	if (a == b) return a;
	for (int i = LOG - 1; i >= 0; i--)
		if (par[a][i] != par[b][i] )
		{
			a = par[a][i];
			b = par[b][i];
		}
	return par[a][0];
}



int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	scanf("%d%d%d", &n, &m, &s);
	s--;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		ig[a].emplace_back(b, c);
		ig[b].emplace_back(a, c);
	}
	for (int i = 0; i < n; i++)
		d[i] = INF;
	d[s] = 0;
	qu.push(make_pair(-d[s], s) );
	while (!qu.empty() )
	{
		int v = qu.top().second;
		long long cur = -qu.top().first;
		qu.pop();
		if (d[v] != cur) continue;
		ord.push_back(v);
		for (auto p : ig[v] )
		{
			int to = p.first;
			long long nd = cur + p.second;
			if (d[to] > nd)
			{
				d[to] = nd;
				qu.push(make_pair(-nd, to) );
			}
		}
	}
	for (int v = 0; v < n; v++)
	{
		if (d[v] == INF) continue;
		for (auto p : ig[v] )
			if (d[p.first] == d[v] + p.second)
			{
//				eprintf("%d -> %d\n", v, p.first);
				g[v].push_back(p.first);
				gr[p.first].push_back(v);
			}
	}
	setDom(s, s);
	for (int v : ord)
	{
		if (v == s) continue;
		int dom = gr[v][0];
		for (int from : gr[v] )
		{
			dom = LCA(dom, from);
		}
//		eprintf("dom(%d) = %d\n", v, dom);
		setDom(v, dom);
	}
	dfs(s);
	printf("%d\n", answer);

	return 0;
}