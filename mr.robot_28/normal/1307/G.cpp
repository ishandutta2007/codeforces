#include<bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int a, b;
	int cost;
	int cap;
	edge(int a, int b, int cap, int cost):
		a(a),
		b(b),
		cap(cap),
		cost(cost){};
	int other(int v)
	{
		return v == a ? b : a;
	}
	int capTo(int v)
	{
		return v == b ? cap : 1 - cap;
	}
	void addflow(int v, int fl)
	{
		if(v == b)
		{
			cap -= fl;
		}
		else
		{
			cap += fl;
		}
	}
	int costTo(int to)
	{
		return to == b ? cost : -cost;
	}
};
vector <edge> edges;
vector <vector <int> > g;
vector <int> dist, p;
int allcost = 0;
int allflow = 0;

signed main() {	
	int n, m;
	cin >> n >> m;
	dist.resize(n);
	p.resize(n);
	g.resize(n);
	int st = 0, end = n - 1;
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		edges.push_back(edge(a, b, 1, c));
		g[a].push_back(edges.size() - 1);
		g[b].push_back(edges.size() - 1);
	}
	vector <pair <int, int> > mass;
	mass.push_back({0, 0});
	while(true)
	{
		for(int i = 0; i < n; i++)
		{
			dist[i] = 1e9;
		}
		dist[0] = 0;
		p[0] = -1;
		queue <int> q;
		q.push(0);
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
	//		cout << v << "\n";
			for(int i = 0; i < g[v].size(); i++)
			{
				int e = g[v][i];
				int to = edges[g[v][i]].other(v);
				if(edges[e].capTo(to))
				{
					if(dist[to] > dist[v] + edges[e].costTo(to))
					{
						dist[to] = dist[v] + edges[e].costTo(to);
						p[to] = e;
						q.push(to);
					}
				}
			}
		}
		mass.push_back({allflow * dist[n - 1] - allcost, dist[n - 1]});
	//	cout << mass[0].first << " " << mass[0].second << "\n";
		if(dist[n - 1] == 1e9)
		{
			break;
		}
	//	cout << dist[n - 1] << "\n";
		int flow = 1e9;
		for(int i = n - 1; i != 0; i = edges[p[i]].other(i))
		{
			flow = min(flow, edges[p[i]].capTo(i));
		}
		for(int i = n - 1; i != 0; i = edges[p[i]].other(i))
		{
			edges[p[i]].addflow(i, flow);
		}
		allflow += flow;
		allcost += flow * dist[n - 1];
	}
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		int ind = lower_bound(mass.begin(), mass.end(), make_pair(x + 1, st)) - mass.begin();
		double D =(long double) ((x - mass[ind - 1].first) * mass[ind].second + (mass[ind].first - x) * (mass[ind - 1].second)) / (mass[ind].first - mass[ind - 1].first);
		cout << fixed << setprecision(10) << D << "\n";
	}
    return 0;
}