#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> eiler;
vector <bool> used;
void dfs(int v)
{
	used[v] = true;
	eiler.push_back(v);
	for(int i = 0; i < g[v].size(); i++)
	{
		if(!used[g[v][i]])
		{
			dfs(g[v][i]);
			eiler.push_back(v);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	used.resize(n);
	dfs(0);
	int t = (2 * n + k - 1) / k;
	int cnt = 0;
	for(int u = 0; u < k; u++)
	{
		if(cnt == n * 2 - 1)
		{
			cout << 1 << " " << 1 << "\n";
		}
		else 
		{
			cout << min(t, 2 * n - 1 - cnt) << " ";
			for(int j = cnt; j < min(2 * n - 1, cnt + t); j++)
			{
				cout << eiler[j] + 1 << " ";
			}
			cout << "\n";
			cnt = min(2 * n - 1, cnt + t);
		}
	}
    return 0;
}