#include<bits/stdc++.h>
 
using namespace std;
int n, m;
vector <vector <pair <int, int> > > g;
vector <pair <int, int> > pr;
vector <int> used;
vector <int> cycle;
vector <int> cnt;
vector <vector <int> > cycles;
vector <int> used1;
struct edge{
	int a, b, cap, flow;
	edge(int a, int b, int cap):
		a(a),
		b(b),
		cap(cap),
		flow(0){};
	int other(int v)
	{
		if(v == a)
		{
			return b;
		}
		return a;
	}
	int capTo(int to)
	{
		if(to == b)
		{
			return cap - flow;
		}
		else
		{
			return flow;
		}
	}
	void addflow(int to, int fl)
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
vector <edge> edges;
vector <vector <int> > g2;
vector <int> dist1, pr1, it;
bool bfs(int st, int end)
{
	for(int i = 0; i < pr1.size(); i++)
	{
		pr1[i] = -1;
		it[i] = 0;
		dist1[i] = 1e9;
	}
	dist1[st] = 0;
	pr1[st] = 0;
	queue <int> q;
	q.push(st);
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		if(v == end)
		{
			return 1;
		}
		for(int i = 0; i < g2[v].size(); i++)
		{
			int e = g2[v][i];
			int to = edges[e].other(v);
			int c = edges[e].capTo(to);
			if(c != 0 && pr1[to] == -1)
			{
				pr1[to] = e;
				dist1[to] = dist1[v] + 1;
				q.push(to);
			}
		}
	}
	return 0;
}
bool dfs1(int v, int end)
{
	if(v == end)
	{
		return 1;
	}
	for(;it[v] < g2[v].size(); it[v]++)
	{
		int e = g2[v][it[v]];
		int to = edges[e].other(v);
		if(dist1[to] == dist1[v] + 1 && edges[e].capTo(to) && dfs1(to, end))
		{
			pr1[to] = e;
			return 1;
		}
	}
	return 0;
}
vector <int> used2;
vector <vector <int> > g1;
void dfs(int v, int p = -1)
{
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to= g[v][i].first;
		if(to == p)
		{
			continue;
		}
		if(!used[to])
		{
			pr[to] = {v, g[v][i].second};
			used1[g[v][i].second]++;
			dfs(to, v);
		}
		else if(used[to] == 1)
		{
			int u1 = v;
			while(u1 != to)
			{
				used1[pr[u1].second]--;
				cycle.push_back(pr[u1].second);
				u1 = pr[u1].first;
			}
			cycle.push_back(g[v][i].second);
			sort(cycle.begin(), cycle.end());
			bool fl = 0;
			for(int j = 0; j < cycle.size(); j++)
			{
				g1[cycle[j]].push_back(cycles.size());
				if(j != 0 && cycle[j] == cycle[j - 1])
				{
					fl = 1;
				}
			}
			if(fl)
			{
				for(int j = 0; j < cycle.size(); j++)
				{
					used1[cycle[j]]++;
				}
				used2[cycles.size()] = 1;
			}
			cycles.push_back(cycle);
			cycle.clear();
		}
	}
	used[v] = 2;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	g.resize(n);
	pr.resize(n);
	used.resize(n);
	used1.resize(m);
	used2.resize(m, 0);
	for(int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--;
		v--;
		c--;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	g1.resize(m);
	dfs(0);
	queue <int> q;
	for(int i = 0; i < m; i++)
	{
		if(used1[i])
		{
			q.push(i);
		}
	}
	while(q.size() != 0)
	{
		int v = q.front();
		q.pop();
		for(int i = 0; i < g1[v].size(); i++)
		{
			if(!used2[g1[v][i]])
			{
				used2[g1[v][i]] = 1;
				for(int j = 0; j < cycles[g1[v][i]].size(); j++)
				{
					int e = cycles[g1[v][i]][j];
					if(!used1[e])
					{
						used1[e] = 1;
						q.push(e);
					}
				}
			}
		}
	}
	g2.resize(cycles.size() + 2 + m);
	pr1.resize(cycles.size() + 2 + m);
	dist1.resize(cycles.size() + 2 + m);
	it.resize(cycles.size() + 2 + m);
	for(int j = 0; j < m; j++)
	{
		if(!used1[j])
		{
		edges.push_back(edge(j + cycles.size() + 1, cycles.size() + 1 + m, 1));
		g2[j + cycles.size() + 1].push_back(edges.size() - 1);
		g2[cycles.size() + 1 + m].push_back(edges.size() - 1);
		}
	}
	for(int i = 0; i < cycles.size(); i++)
	{
		if(!used2[i])
		{
			edges.push_back(edge(0, i + 1, cycles[i].size() - 1));
			g2[0].push_back(edges.size() - 1);
			g2[i + 1].push_back(edges.size() - 1);
			for(int j = 0; j < cycles[i].size(); j++)
			{
				edges.push_back(edge(i + 1, cycles[i][j] + cycles.size() + 1, 1));
				g2[i + 1].push_back(edges.size() - 1);
				g2[cycles[i][j] + cycles.size() + 1].push_back(edges.size() - 1);
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < m; i++)
	{
		if(used1[i])
		{
			sum++;
		}
	}
	while(bfs(0, cycles.size() + 1 + m))
	{
		while(dfs1(0, cycles.size() + 1 + m))
		{
			int allfl = 1e9;
			for(int v = cycles.size() + 1 + m; v != 0; v = edges[pr1[v]].other(v))
			{
				allfl = min(allfl, edges[pr1[v]].capTo(v));
			}
			sum += allfl;
			for(int v = cycles.size() + 1 + m; v != 0; v = edges[pr1[v]].other(v))
			{
				edges[pr1[v]].addflow(v, allfl);
			}
		}
	}
	cout << sum;
	return 0;
}