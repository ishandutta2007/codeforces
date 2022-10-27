#include<bits/stdc++.h>
 
using namespace std;
vector <vector <int> > g;
vector <int> p, h, _sz, _sz1, _sz2;
bool flag;
void dfs(int v, int pr = -1)
{
	int sum = h[v];
	_sz[v] = p[v];
	_sz1[v] = _sz2[v] = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != pr)
		{
			dfs(to, v);
			sum -= h[to];
			_sz[v] += _sz[to];
			_sz1[v] += _sz1[to];
			_sz2[v] += _sz2[to];
		}
	}
	int a = 0, b = 0;
	if(abs(h[v]) % 2 != abs(_sz[v]) % 2 || abs(h[v]) > abs(_sz[v]))
	{
		flag = false;
		return;
	}
	a = (h[v] + _sz[v]) / 2;
	b = (_sz[v] - h[v]) / 2;
	if(a < _sz1[v])
	{
		flag = false;
		return;
	}
	_sz1[v] = a;
	_sz2[v] = b;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		p.resize(n);
		_sz1.resize(n);
		_sz2.resize(n);
		_sz.resize(n);
		for(int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		h.resize(n);
		for(int i = 0; i < n; i++)
		{
			cin >> h[i];
		}
		g.resize(n);
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		flag = true;
		dfs(0);
		for(int i = 0; i < n; i++)
		{
			g[i].clear();
		}
		if(flag)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}