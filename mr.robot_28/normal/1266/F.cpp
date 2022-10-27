#include<bits/stdc++.h>
using namespace std;

vector <vector <int> > mass;
vector <int> down, up;
vector <vector <int> > g;
void dfs1(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != p)
		{
			dfs1(g[v][i], v);
			mass[v].push_back(down[g[v][i]] + 1);
			down[v] = max(down[v], down[g[v][i]] + 1);
		}
	}
}
void dfs2(int v, int p = -1)
{
	if(v != 0)
	{
		mass[v].push_back(up[v]);
	}
	int mx1 = -1e9, mx2 = 1e9;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(down[to] + 1 > mx1)
			{
				mx2 = mx1;
				mx1 = down[to] + 1;
			}
			else
			{
				mx2 = max(mx2, down[to] + 1);
			}
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(down[to] + 1 == mx1)
			{
				up[to] = max(up[v] + 1, mx2 + 1);
			}
			else
			{
				up[to] = max(up[v] + 1, mx1 + 1);
			}
			dfs2(to, v);
		}
	}
}
int maxl = 0, maxv = -1;
void findv(int v, int d = 0, int p = -1)
{
	if(d > maxl)
	{
		maxl = d;
		maxv = v;
	}
	for(int i = 0;  i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			findv(to, d + 1, v);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	mass.resize(n);
	down.resize(n);
	up.resize(n);
	vector <pair <int, int> > edges;
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
		edges.push_back({a, b});
	}
	dfs1(0);
	dfs2(0);
	findv(0);
	maxl = 0;
	findv(maxv);
	set <pair <int, int> > values;
	vector <pair <int, int> > allmass;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < mass[i].size(); j++)
		{
			allmass.push_back({mass[i][j], i});
		}
		sort(mass[i].begin(), mass[i].end());
		reverse(mass[i].begin(), mass[i].end());
		values.insert({-mass[i].size(), i});
	}
	sort(allmass.begin(), allmass.end());
	int iter = 0;
	vector <int> delet;
	set <pair <int, int> > :: iterator it;
	it = values.begin();
	cout << -it -> first + 1 << " ";
	vector <bool> used(n);
	for(int i = 0; i < n; i++)
	{
		if(g[i].size() <= 2)
		{
			used[i] = true;
		}
	}
	for(int len = 2; len <= n; len++)
	{
		while(iter < allmass.size() && allmass[iter].first < (len + 1) / 2)
		{
			delet.push_back(allmass[iter].second);
			iter++;
		}
		if(len > maxl)
		{
			cout << 1 << " ";
			continue;
		}
		if(len % 2 == 0)
		{
			for(int i = 0; i < delet.size(); i++)
			{
				int ind = delet[i];
				values.erase({-mass[ind].size(), ind});
				while(mass[ind].size() && mass[ind].back() < (len + 1) / 2)
				{
					mass[ind].pop_back();
				}
				if(mass[ind].size() <= 2)
				{
					used[ind] = true;
				}
				values.insert({-mass[ind].size(), ind});
			}
			int ans = 2;
			it = values.begin();
			ans = max(ans, -it -> first);
			delet.clear();
			int iter1 = 0;
			while(iter1 < edges.size())
			{
				int v1 = edges[iter1].first, v2 = edges[iter1].second;
				if(used[v1] || used[v2])
				{
					swap(edges[iter1], edges.back());
					edges.pop_back();
					continue;
				}
				ans = max(ans, int(mass[v1].size() + mass[v2].size() - 2));
				iter1++;
			}
			cout << ans << " ";
		}
		else
		{
			for(int i = 0; i < delet.size(); i++)
			{
				int ind = delet[i];
				values.erase({-mass[ind].size(), ind});
				while(mass[ind].size() > 1 && mass[ind][mass[ind].size() - 2] < (len + 1) /2 )
				{
					mass[ind].pop_back();
				}
				if(mass[ind].size() <= 2)
				{
					used[ind] = true;
					continue;
				}
				values.insert({-mass[ind].size(), ind});
			}
			it = values.begin();
			int ans = max(2, -it -> first);
			cout << ans << " ";
		}
	}
	return 0;
}