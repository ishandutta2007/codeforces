#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <int> colored;
int kol;
void dfs(int v, int pred, int col, int predcol)
{
	colored[v] = col;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			col++;
			if(col == kol + 1)
			{
				col = 1;
			}
			if(col == predcol)
			{
				col++;
			}
			if(col == kol + 1)
			{
				col = 1;
			}
			dfs(g[v][i], v, col, colored[v]);
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
	colored.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	kol = 0;
	for(int i = 0; i < n; i++)
	{
		kol = max(kol, int(g[i].size()) + 1);
	}
	dfs(0, -1, 1, -1);
	cout << kol << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << colored[i] << " ";
	}
    return 0;
}