#include<bits/stdc++.h>
using namespace std;
struct edge{
	int a, b, cap, flow, cost;
	edge(int a, int b, int cap, int cost):
		a(a),
		b(b),
		cap(cap),
		flow(0),
		cost(cost){};
	int capTo(int v)
	{
		return v == b ? cap - flow : flow;
	}
	int costo(int v)
	{
		return v == b ? cost : -cost;
	}
	int other(int v)
	{
		return v == b ? a : b;
	}
	void addFlow(int v, int fl)
	{
		if(v == b)
		{
			flow += fl; 
		}
		else
		{
			flow -= fl;
		}
	}
};
vector <edge> edges;
vector <vector <int> > g;
vector <int> p, dist, lev;
int build_path(int st, int end)
{
	for(int i = 0; i < p.size(); i++)
	{
		dist[i] = 1e9;
		p[i] = -1;
		lev[i] = 0;
	}
	dist[st] = 0;
	priority_queue <pair <int, int> > q;
	q.push({0, 0});
	while(q.size() != 0)
	{
		int v = q.top().second;
		int d = -q.top().first;
		q.pop();
		if(d != dist[v])
		{
			continue;
		}
		for(int j = 0; j < g[v].size(); j++)
		{
			int e = g[v][j];
			int to = edges[e].other(v);
			int cost = edges[e].costo(to);
			int capto = edges[e].capTo(to);
			if(capto > 0 && dist[to] > dist[v] + cost)
			{
				dist[to] = dist[v] + cost;
				p[to] = e;
				lev[to] = lev[v] + 1;
				q.push({-dist[to], to});
			}
		}
	}
	return dist[end];
}
signed main() {
	int n, q;
	cin >> n >> q;
	vector <int> down(n, 1), up(n, n);
	for(int i = 0; i < q; i++)
	{
		int t, l, r, v;
		cin >> t >> l >> r >> v;
		l--;
		r--;
		for(int j = l; j <= r; j++)
		{
			if(t == 1)
			{
				down[j] = max(down[j], v);
			}
			else
			{
				up[j] = min(up[j], v);
			}
		}
	}
	g.resize(2 * n + 2);
	p.resize(2 * n + 2);
	dist.resize(2 * n + 2);
	lev.resize(2 * n + 2);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 2 * n - 1; j += 2)
		{
			edges.push_back(edge(0, i, 1, j));
			g[0].push_back(edges.size() - 1);
			g[i].push_back(edges.size() - 1);
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = down[i]; j <= up[i]; j++)
		{
			edges.push_back(edge(j, i + 1 + n, 1, 0));
			g[j].push_back(edges.size() - 1);
			g[i + 1 + n].push_back(edges.size() - 1);
		}
		edges.push_back(edge(i + 1 + n, 2 * n + 1, 1, 0));
		g[i + 1 + n].push_back(edges.size() - 1);
		g[2 * n + 1].push_back(edges.size() - 1);
	}
	int sumcost = 0;
	int sumflow = 0;
	int len;
	while((len = build_path(0, 2 * n + 1)) != 1e9)
	{
		int cap = 1e9;
		for(int u = 2 * n + 1; u != 0; u = edges[p[u]].other(u))
		{
			cap = min(cap, edges[p[u]].capTo(u));
		}
		sumcost += len * cap;
		sumflow += cap;
		for(int u = 2 * n + 1; u != 0; u = edges[p[u]].other(u))
		{
			edges[p[u]].addFlow(u, cap);
		}
	}
	if(sumflow < n)
	{
		cout << -1;
		return 0;
	}
	cout << sumcost;
	return 0;
}