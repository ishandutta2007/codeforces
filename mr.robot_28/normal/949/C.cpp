#include<bits/stdc++.h>
 
using namespace std;
vector <int> _sz, dsu;
vector <vector <int> > g, g1;
vector <set<int> > g2, g3;
vector <int> u;
vector <int> tout;
vector <int> used;
int timer = 0;
void dfs(int v)
{
	used[v] = 1;
	timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!used[to])
		{
			dfs(to);
		}
	}
	tout[v] = timer++;
}
int pred(int a)
{
	if(a == dsu[a]) return a;
	else return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		if(_sz[a] < _sz[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		_sz[a] += _sz[b];
	}
}
vector <int> comp;
void dfs1(int v)
{
	used[v] = 1;
	comp.push_back(v);
	for(int i = 0; i < g1[v].size(); i++)
	{
		int to = g1[v][i];
		if(!used[to])
		{
			dfs1(to);
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, h;
	cin >> n >> m >> h;
	_sz.resize(n);
	dsu.resize(n);
	for(int i = 0; i < n; i++)
	{
		dsu[i] = i;
		_sz[i] = 1;
	}
	g.resize(n);
	u.resize(n);
	g2.resize(n);
	g3.resize(n);
	used.resize(n);
	g1.resize(n);
	tout.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> u[i];
	}
	vector <pair <int, int> > vec(m);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		vec[i] = {a, b};
		if((u[a] + 1) % h == u[b])
		{
			g[a].push_back(b);
			g1[b].push_back(a);
		}
		if((u[b] + 1) % h == u[a])
		{
			g1[a].push_back(b);
			g[b].push_back(a);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	vector <pair <int, int> > mass;
	for(int i = 0; i < n; i++)
	{
		used[i] = 0;
		mass.push_back({tout[i], i});
	}
	sort(mass.begin(), mass.end());
	for(int i = n - 1; i >= 0; i--)
	{
		if(!used[mass[i].second])
		{
			dfs1(mass[i].second);
			for(int j = 0; j < comp.size() - 1; j++)
			{
				unite(comp[j], comp[j + 1]);
			}
			comp.clear();
		}
	}
	vector <int> cnt(n);
	for(int i = 0; i < m; i++)
	{
		int a1 = vec[i].first;
		int b1 = vec[i].second;
		int a = pred(vec[i].first);
		int b = pred(vec[i].second);
		if(a == b)
		{
			continue;
		}
		if((u[a1] + 1) % h == u[b1])
		{
			g2[a].insert(b);
			g3[b].insert(a);
		}
		if((u[b1] + 1) % h == u[a1])
		{
			g3[a].insert(b);
			g2[b].insert(a);
		}
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++)
	{
		if(g2[pred(i)].size() == 0 && _sz[pred(i)] < ans)
		{
			ans = _sz[pred(i)];
		}
	}
	for(int i = 0; i < n; i++)
	{
		used[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		if(_sz[pred(i)] == ans && g2[pred(i)].size() == 0)
		{
			vector <int> ans;
			queue <int> q1;
			q1.push(i);
			used[i] = 1;
			while(q1.size() != 0)
			{
				int v = q1.front();
				q1.pop();
				ans.push_back(v);
				for(int j = 0; j < g[v].size(); j++)
				{
					if(!used[g[v][j]])
					{
						used[g[v][j]] = 1;
						q1.push(g[v][j]);
					}
				}
			}
			cout << ans.size() << "\n";
			for(int j = 0; j  < ans.size(); j++)
			{
				cout << ans[j] + 1 << " ";
			}
			return 0;
		}
	}
	return 0;
}