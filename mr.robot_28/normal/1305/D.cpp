#include<bits/stdc++.h>
using namespace std;
vector <int> turn;
vector <vector <pair <int, int> > > g;
vector <bool> used;
void dfs(int v, int p = -1, int ind = -1)
{
	vector <pair <int, int> > mass;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to= g[v][i].first;
		if(to != p)
		{
			dfs(to, v, g[v][i].second);
			if(!used[to])
			{
				mass.push_back({to, g[v][i].second});
			}
		}
	}
	if(mass.size() % 2 == 1)
	{
		used[v] = 1;
		if(p == -1)
		{
			cout << "? " << mass.back().first + 1 << " " << v + 1 << endl;
			fflush(stdout);
			int a;
			cin >> a;
			assert(a > 0);
			a--;
			if(a == mass.back().first)
			{
				turn[mass.back().second] = 1;
			}
			mass.pop_back();
		}
		else
		{
			mass.push_back({p, ind});
		}
	}
	for(int i = 0; i < mass.size(); i += 2)
	{
		int a = mass[i].first;
		int b = mass[i + 1].first;
		cout << "? " << a + 1 << " " << b + 1 << endl;
		fflush(stdout);
		int t;
		cin >> t;
		assert(t > 0);
		t--;
		if(t == v)
		{
			if(a == p)
			{
				turn[mass[i].second] = 1;
			}
			else if(b == p)
			{
				turn[mass[i + 1].second] = 1;
			}
		}
		else if(t == a)
		{
			if(a == p)
			{
				
			}
			else if(b == p)
			{
				turn[mass[i].second] = 1;
				turn[mass[i + 1].second] = 1;
			}
			else
			{
				turn[mass[i].second] = 1;
			}
		}
		else if(t == b)
		{
			if(b == p)
			{
				
			}
			else if(a == p)
			{
				turn[mass[i].second] = 1;
				turn[mass[i + 1].second] = 1;
			}
			else
			{
				turn[mass[i + 1].second] = 1;
			}
		}
	}
}
void dfs1(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int ind = g[v][i].second;
		if(to != p && turn[ind])
		{
			dfs1(to, v);
		}
	}
	cout << "! " << v + 1 << endl;
	fflush(stdout);
	exit(0);
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	turn.resize(n);
	used.resize(n);
	g.resize(n);
	for(int i = 0; i < n -1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back({y, i});
		g[y].push_back({x, i});
	}
	dfs(0);
	dfs1(0);
	
    return 0;
}