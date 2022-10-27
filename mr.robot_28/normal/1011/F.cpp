#include <bits/stdc++.h>
 
using namespace std;
vector <bool> used;
vector <vector <int> > g;
vector <int> type;
vector <int> val;
int ans = 0;
void dfs1(int v)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs1(g[v][i]);
	}
	if(type[v] == 0)
	{
		val[v] = val[g[v][0]] | val[g[v][1]];
	}
	else if(type[v] == 1)
	{
		val[v] = val[g[v][0]] ^ val[g[v][1]];
	}
	else if(type[v] == 2)
	{
		val[v] = val[g[v][0]] & val[g[v][1]];
	}
	else if(type[v] == 3)
	{
		val[v] = 1 - val[g[v][0]];
	}
}
void dfs2(int v)
{
	used[v] = true;
	if(type[v] == 0)
	{
		if(val[g[v][0]] == 0)
		{
			dfs2(g[v][1]);
		}
		if(val[g[v][1]] == 0)
		{
			dfs2(g[v][0]);
		}
	}
	else if(type[v] == 1)
	{
		dfs2(g[v][0]);
		dfs2(g[v][1]);
	}
	else if(type[v] == 2)
	{
		if(val[g[v][0]] == 1)
		{
			dfs2(g[v][1]);
		}
		if(val[g[v][1]] == 1)
		{
			dfs2(g[v][0]);
		}
	}
	else if(type[v] == 3)
	{
		dfs2(g[v][0]);
	}
}
signed main()
{
	int n;
	cin >> n;
	used.resize(n);
	g.resize(n);
	type.resize(n);
	val.resize(n);
	vector <int> ver;
	for(int i = 0; i  < n; i++)
	{
		string t;
		int a, b;
		cin >> t;
		if(t == "OR")
		{
			cin >> a >> b;
			type[i] = 0;
			a--;
			b--;
			g[i].push_back(a);
			g[i].push_back(b);
		}
		else if(t == "XOR")
		{
			cin >> a >> b;
			a--;
			b--;
			type[i] = 1;
			g[i].push_back(a);
			g[i].push_back(b);
		}
		else if(t == "AND")
		{
			cin >> a >> b;
			a--;
			b--;
			type[i] = 2;
			g[i].push_back(a);
			g[i].push_back(b);
		}
		else if(t == "NOT")
		{
			cin >> a;
			a--;
			type[i] = 3;
			g[i].push_back(a);
		}
		else{
			type[i] = 4;
			ver.push_back(i);
			cin >> val[i];
		}
	}
	dfs1(0);
	dfs2(0);
	ans = val[0];
	for(int i = 0; i < ver.size(); i++)
	{
		if(!used[ver[i]])
		{
			cout << ans;
		}
		else
		{
			cout << 1 - ans;
		}
	}
	return 0;
}