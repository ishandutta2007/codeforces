#include<bits/stdc++.h>
using namespace std;
int N;
struct edge{
	int a, b, cap, flow;
	edge(int a, int b, int cap):
		a(a),
		b(b),
		cap(cap),
		flow(0){};
	int other(int v)
	{
		return v == a ? b : a;
	}
	int capTo(int v)
	{
		return v == b ? cap - flow : flow;
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
int n, m;
vector <vector <int> > g;
vector <int> k, h, p;
vector <edge> edges;
bool bfs(int st, int end)
{
	vector <bool> used(N);
	queue <int> Q;
	for(int i = 0; i < N; i++)
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
	for(;k[v] < g[v].size(); k[v]++)
	{
		int e = g[v][k[v]];
		int to = edges[e].other(v);
		int w = edges[e].capTo(to);
		if(h[to] == h[v] + 1 && w && dfs(to, end))
		{
			p[to] = e;
			return 1;
		}
	}
	return 0;
}
void add_edge(int a, int b, int cap)
{
	edges.push_back(edge(a, b, cap));
	g[a].push_back(edges.size() - 1);
	g[b].push_back(edges.size() - 1);
}
signed main() {	
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	cout.tie(NULL);
  	cin >> n >> m;
  	vector <vector <char> > a(n, vector <char> (m));
  	int st = 0;
  	int end = (n - 1) * m + (m - 1) * n + 1;
  	N = end + 1;
  	for(int i = 0; i < n; i++)
  	{
  		for(int j = 0; j < m; j++)
  		{
  			cin >> a[i][j];
		}
	}
  	g.resize(N);
  	h.resize(N);
  	p.resize(N);
  	k.resize(N);
  	int ans = 0;
  	for(int i = 0; i < n; i++)
  	{
  		for(int j = 0; j < m; j++)
  		{
  			if(a[i][j] == '#')
  			{
  				ans++;
  				if(i > 0 && a[i - 1][j] == '#')
  				{
  					add_edge(st, m * (i - 1) + j + 1, 1);
  					ans--;
				}
				if(j > 0 && a[i][j - 1] == '#'){
					add_edge((n - 1) * m + n * (j - 1) + i + 1, end, 1);
					ans--;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(a[i][j] != '#')
			{
				continue;
			}
			if(i < n - 1 && j < m - 1 && a[i + 1][j] == '#' && a[i][j + 1] == '#')
			{
				add_edge(m * i + j + 1, (n - 1) * m + n * j + i + 1, 1);
			}
			if(i > 0 && j < m - 1 && a[i - 1][j] == '#' && a[i][j + 1] == '#')
			{
				add_edge(m * (i - 1) + j + 1, (n - 1) * m + n * j + i + 1, 1);
			}
			if(i < n - 1 && j > 0 && a[i + 1][j] == '#' && a[i][j - 1] == '#')
			{
				add_edge(m * (i) + j + 1, (n - 1) * m + n * (j - 1) + 1 + i, 1);
			}
			if(i > 0 && j > 0 && a[i - 1][j] == '#' && a[i][j - 1] == '#')
			{
				add_edge((i - 1) * m + j + 1, (n - 1) * m + n * (j - 1) + i + 1, 1);
			}
		}
	}
  	while(bfs(st, end))
  	{
  		while(dfs(st, end))
  		{
  			int flow = 1e9;
  			for(int v = end; v != st; v = edges[p[v]].other(v))
  			{
  				flow = min(flow, edges[p[v]].capTo(v));
  			}
  			ans += flow;
  			for(int v = end; v != st; v = edges[p[v]].other(v))
  			{
  				edges[p[v]].addFlow(v, flow);
  			}
  		}
  	}
  	cout << ans << "\n";
    return 0;
}