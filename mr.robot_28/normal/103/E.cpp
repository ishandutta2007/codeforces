#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
int ans = 0;
const int N = 1000;
int n;
int w[N];
struct edge{
	int a, b, cap, flow;
	edge(int a1, int b1, int cap1):a(a1), b(b1), cap(cap1), flow(0){};
	int other(int v)
	{
		return v == a ? b : a;
	}
	int capTo(int v)
	{
		if(v == b)
		{
			return cap - flow;
		}
		return flow;
	}
	void addFlow(int to, int fl)
	{
		if(to == b)
		{
			flow += fl;
		}
		else
		{
			flow -= fl;
		}
	}
};
vector<edge> edges;
vector <int> g[N];
int h[N], p[N], it[N];
void add_edge(int a, int b, int cap)
{
	g[a].push_back(sz(edges));
	g[b].push_back(sz(edges));
	edges.push_back(edge(a, b, cap));
}
const int cst = 1e9;
int s, t;
bool bfs()
{
	for(int i = 0; i < N; i++)
	{
		it[i] = 0;
		h[i] = 1e9;
		p[i] = -1;
	}
	h[s] = 0;
	queue <int> q;
	q.push(s);
	while(sz(q) != 0)
	{
		int v = q.front();
		q.pop();
		for(int i = 0; i < sz(g[v]); i++)
		{
			int e = g[v][i];
			int to = edges[e].other(v);
			if(edges[e].capTo(to) && h[to] == cst)
			{
				h[to] = h[v] + 1;
				p[to] = e;
				q.push(to);
			}
		}
	}
	return h[t] != cst;
}
bool dfs(int v, int end)
{
	if(v == end)
	{
		return 1;
	}
	for(;it[v] < sz(g[v]); it[v]++)
	{
		int e = g[v][it[v]];
		int to = edges[e].other(v);
		if(h[to] == h[v] + 1 && edges[e].capTo(to) && dfs(to, end))
		{
			p[to] = e;
			return 1;
		}
	}
	return 0;
}
int dinic()
{
	int sum = 0;
	while(bfs())
	{
		while(dfs(s, t)){
			int flow = 1e9;
			for(int v = t; v != s; v = edges[p[v]].other(v))
			{
				flow = min(flow, edges[p[v]].capTo(v));
			}
			sum += flow;
			for(int v = t; v != s; v = edges[p[v]].other(v))
			{
				edges[p[v]].addFlow(v, flow);
			}
		}
	}
	return sum;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	s = n * 3;
	t = n * 3 + 1;
	for(int i = 1; i <= n; i++)
	{
		int m;
		cin >> m;
		for(int j = 1; j <= m; j++)
		{
			int u;
			cin >> u;
			add_edge(i, u + n, 1e9);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> w[i];
		w[i] = cst - w[i];
		if(w[i] > 0)
		{
			ans += w[i];
			add_edge(s, i, w[i]);
		}
		else
		{
			add_edge(i, t, -w[i]);
		}
		add_edge(i + n, t, 1e9);
	}
	cout << -ans + dinic();
	return 0;
}