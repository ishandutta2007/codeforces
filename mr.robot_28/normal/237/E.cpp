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
	string s;
	cin >> s;
	int n;
	cin >> n;
	p.resize(n * 27 + 28);
	dist.resize(n * 27 + 28);
	lev.resize(27 * n + 28);
	g.resize(26 * n + n + 2 + 26);
	for(int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		int a;
		cin >> a;
		edges.push_back(edge(0, i + 1, a, i + 1));
		g[0].push_back(edges.size() - 1);
		g[i + 1].push_back(edges.size() - 1);
		vector <int> cnt(26);
		for(int j = 0; j < t.size(); j++)
		{
			cnt[t[j] - 'a']++;
		}
		for(int j = 0; j < 26; j++)
		{
			edges.push_back(edge(i + 1, n + i * 26 + (j + 1), cnt[j], 0));
			g[i + 1].push_back(edges.size() - 1);
			g[n + i * 26 + (j + 1)].push_back(edges.size() - 1);
			edges.push_back(edge(n + i * 26 + (j + 1), 27 * n + j + 1, 1e9, 0));
			g[n + i * 26 + (j + 1)].push_back(edges.size() - 1);
			g[27 * n + j + 1].push_back(edges.size() - 1);
		}
	}
	vector <int> cnt(26);
	for(int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 'a']++;
	}
	for(int j = 0; j < 26; j++)
	{
		edges.push_back(edge(27 * n + j + 1, 27 * n + 27, cnt[j], 0));
		g[27 * n + j + 1].push_back(edges.size() - 1);
		g[27 * n + 27].push_back(edges.size() - 1);
	}
	int sumflow = 0, sumcost = 0;
	int len;
	while((len = build_path(0, 27 * n + 27)) != 1e9)
	{
		int cap = 1e9;
		for(int u = 27 * n + 27; u != 0; u = edges[p[u]].other(u))
		{
			cap = min(cap, edges[p[u]].capTo(u));
		}
		sumcost += len * cap;
		sumflow += cap;
		for(int u = 27 * n + 27; u != 0; u = edges[p[u]].other(u))
		{
			edges[p[u]].addFlow(u, cap);
		}
	}
	if(sumflow != s.size())
	{
		cout << -1;
		return 0;
	}
	cout << sumcost;
	return 0;
}