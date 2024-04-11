#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> tin, tout;
vector <int> start;
vector <int> _size;
int timer = 0;
void dfs(int v)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
		_size[v] += _size[to];
	}
	_size[v]++;
	tout[v] = timer++; 
}
bool pred(int a, int b)
{
	return tin[a] <= tin[b] && tout[a] >= tout[b]; 
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	vector <int> last(m, -1);
	g.resize(n);
	tin.resize(n);
	tout.resize(n);
	_size.resize(n);
	start.resize(n, true);
	for(int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		b--;
		a--;
		if(last[b] != -1)
		{
			g[last[b]].push_back(a);
			start[a] = false;
		}
		last[b] = a;
	}
	for(int i = 0; i < n; i++)
	{
		if(start[i])
		{
			dfs(i);
		}
	}
	for(int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		if(last[y] == -1)
		{
			cout << 0 << "\n";
		}
		else
		{
			if(pred(x, last[y]))
			{
				cout << _size[x] << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
	}
	return 0;
}