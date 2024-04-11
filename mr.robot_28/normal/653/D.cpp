#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const double eps = 1e-13;
struct edge{
	int a, b;
	int cap, flow;
	edge(int a, int b, int cap):
		a(a),
		b(b),
		cap(cap),
		flow(0){};
	int other(int v)
	{
		return (b == v) ? a : b;
	}
	int capTo(int v)
	{
		return (v == b) ? cap - flow : flow;
	}
	void addFlow(int v, int delta)
	{
		if(v == b)
		{
			flow += delta;
		}
		else
		{
			cap += delta;
		}
	}
};
vector <edge> edges;
int n, m;
vector <vector <int> > g;
vector <int> h, p;
vector <int> k;
bool bfs(int st, int end)
{
	vector <bool> used(n);
	queue <int> Q;
	for(int i = 0; i < n; i++)
	{
		k[i] = h[i] = 0;
		p[i] = 0;
	}
	Q.push(st);
	used[st] = true;
	while(Q.size() != 0)
	{
		int v = Q.front();
		Q.pop();
		if(v == end)
		{
			return 1;
		}
		for(int i = 0; i < g[v].size(); i++)
		{
			int e = g[v][i];
			int to = edges[e].other(v);
			if(!used[to] && edges[e].capTo(to))
			{
				used[to] = true;
				h[to] = h[v] + 1;
				p[to] = e;
				Q.push(to);
			}
		}
	}
	return 0;
}
bool dfs(int v, int end)
{
	if(v == end)
	{
		return 1;
	}
	for(; k[v] < g[v].size(); k[v]++)
	{
		int to = edges[g[v][k[v]]].other(v);
		if(h[to] == h[v] + 1 && edges[g[v][k[v]]].capTo(to) && dfs(to, end))
		{
			p[to] = g[v][k[v]];
			return 1;
		}
	}
	return 0;
}
signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	int x;
  	cin >> n >> m >> x;
  	g.resize(n);
  	p.resize(n);
  	h.resize(n);
  	k.resize(n);
  	vector <pair <pair <int, int>, int> > edges1;
  	for(int i = 0; i < m; i++)
  	{
  		int a, b, cap;
  		cin >> a >> b >> cap;
  		a--;
  		b--;
  		edges1.push_back({{a, b}, cap});
	}
	double l = 0, r = 1e9;
	while(r - l > eps)
	{
		double midd = (r + l) / 2;
		int sumflow = 0;
		for(int i = 0; i < m; i++)
		{
			int a = edges1[i].first.first;
			int b = edges1[i].first.second;
			int cap = edges1[i].second / midd;
  			edges.push_back(edge(a, b, cap));
  			g[a].push_back(edges.size() - 1);
  			g[b].push_back(edges.size() - 1);
		}
		while(bfs(0, n - 1))
		{
			while(dfs(0, n - 1))
			{
				int flow = 1e9;
				for(int u = n - 1; u != 0; u = edges[p[u]].other(u))
				{
					flow = min(edges[p[u]].capTo(u), flow);
				}
				sumflow += flow;
				for(int u = n - 1; u != 0; u = edges[p[u]].other(u))
				{
					edges[p[u]].addFlow(u, flow);
				}
			}
		}
		for(int i = 0; i < n; i++)
		{
			g[i].clear();
		}
		edges.clear();
		if(sumflow >= x)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	cout << fixed << setprecision(10) << l * x;
    return 0;
}