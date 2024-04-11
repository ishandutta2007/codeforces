#include<bits/stdc++.h>
 
using namespace std;

vector <vector <int> > go_to;
int t;
int n;
vector <vector <int> > g;
vector <int> _sz;
vector <int> ans;
void dfs(int v)
{
	int st = v;
	_sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs(g[v][i]);
		_sz[v] += _sz[g[v][i]];
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		if(_sz[g[v][i]] * 2 > _sz[v])
		{
			st = g[v][i];
		}
	}
	if(st == v)
	{
		ans[v] = st;
		for(int i = 0; i < t; i++)
		{
			go_to[i][v] = st;
		}
	}
	else
	{
		go_to[0][v] = st;
		for(int i = 1; i < t; i++){
			go_to[i][v] = go_to[i - 1][go_to[i - 1][v]];
		}
		for(int i = t - 1; i >= 0; i--)
		{
			if(_sz[go_to[i][st]] * 2 > _sz[v])
			{
				st = go_to[i][st];
			}
		}
		ans[v] = st;
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> n >> q;
	t = log2(n) + 1;
	g.resize(n);
	_sz.resize(n);
	ans.resize(n);
	go_to.resize(t, vector <int> (n));
	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
	}
	dfs(0);
	while(q--)
	{
		int v;
		cin >> v;
		v--;
		cout << ans[v] + 1 << "\n";
	}
	return 0;
}