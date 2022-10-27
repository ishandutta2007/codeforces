#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> dist, _sz;
void dfs1(int v, int p = -1)
{
	_sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs1(to, v);
			_sz[v] += _sz[to];
		}
	}
}
int n, k;
int centroid(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p && _sz[to] > n / 2)
		{
			return centroid(to, v);
		}
	}
	return v;
}
vector <int> deg;
vector <set <pair <int, int> > > lca;
vector <int> par,top;
vector <vector <int> > g1;
int minfunct = 0, maxfunct = 0;
void dfs2(int v, int p, int t)
{
	dist[v] = dist[p] + 1;
	_sz[v] = 1;
	par[v] = p;
	top[v] = t;
	auto it = find(g[v].begin(), g[v].end(), p);
	g[v].erase(it);
	deg[v] = g[v].size();
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs2(to, v, t);
		_sz[v] += _sz[to];
	}
	if(deg[v] != 0)
	{
	lca[t].insert({dist[v], v});
	}
	minfunct += (_sz[v] & 1);
	maxfunct += _sz[v];
}
void Delete(int v)
{
	v = par[v];
	deg[v]--;
	if(deg[v] == 0)
	{
		lca[top[v]].erase({dist[v] ,v});
	}
}
vector <bool> matched;
vector <int> vec;
int cnt = 0;
void dfs3(int v, int p = -1)
{
	if(!matched[v])
	{
		vec.push_back(v);
	}
	for(int i = 0; i < g1[v].size(); i++)
	{
		int to = g1[v][i];
		if(to == p)
		{
			continue;
		}
		dfs3(to, v);
	}
} 
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> k;
	g.resize(n);
	_sz.resize(n);
	dist.resize(n);
	deg.resize(n);
	lca.resize(n);
	g1.resize(n);
	par.resize(n);
	top.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g1[a].push_back(b);
		g1[b].push_back(a);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(0);
	int c = centroid(0);
	set <pair <int, int> > sizes;
	for(int i = 0; i < g[c].size(); i++)
	{
		int to = g[c][i];
		dfs2(to, c, to);
		sizes.insert({_sz[to], to});
	}
	if(k < minfunct || k > maxfunct || (maxfunct - k) % 2 != 0)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	matched.resize(n, 0);
	while(maxfunct > k)
	{
		int v = sizes.rbegin() -> second;
		sizes.erase(*sizes.rbegin());
		int maxdist = lca[v].rbegin() -> first;
		if(maxfunct - 2 * maxdist <= k)
		{
			int u = lca[v].lower_bound({(maxfunct - k) / 2, -1}) -> second;
			vector <int> mass;
			while(g[u].size() > 0 && mass.size() < 2)
			{
				int to = g[u].back();
				g[u].pop_back();
				if(!matched[to])
				{
					mass.push_back(to);
				}
			}
			if(mass.size() < 2)
			{
				mass.push_back(u);
			}
			cout << mass[0] + 1 << " " << mass[1] + 1 << "\n";
			matched[mass[0]] = 1;
			matched[mass[1]] = 1;
			_sz[v] -= 2;
			Delete(mass[0]);
			Delete(mass[1]);
			break;
		}
		else{
			maxfunct -= 2 * maxdist;
			int u = lca[v].rbegin() -> second;
			vector <int> mass;
			while(g[u].size() > 0 && mass.size() < 2)
			{
				int to = g[u].back();
				g[u].pop_back();
				if(!matched[to])
				{
					mass.push_back(to);
				}
			}
			if(mass.size() < 2)
			{
				mass.push_back(u);
			}
			assert(matched[mass[0]] == 0);
			assert(matched[mass[1]] == 0);
			cout << mass[0] + 1 << " " << mass[1] + 1 << "\n";
			matched[mass[0]] = 1;
			matched[mass[1]] = 1;
			_sz[v] -= 2;
			Delete(mass[0]);
			Delete(mass[1]);
			if(_sz[v])
			{
				sizes.insert({_sz[v], v});
			}
		}
	}
	dfs3(c);
	int h = vec.size() / 2;
	for(int i = 0; i < vec.size() / 2; i++)
	{
		cout << vec[i] + 1 << " " << vec[i + h] + 1 << "\n";
	}
	return 0;
}