#include<bits/stdc++.h>
 
using namespace std;

vector <int> p, h;
vector <vector <int> > g;
int ans;
int n, m;
vector <bool> used;
void dfs(int v)
{
	used[v] = 1;
	if(h[v] == (n + 1) / 2 - 1)
	{
		ans = v;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!used[to])
		{
			h[to] = h[v] + 1;
			p[to] = v;
			dfs(to);
		}
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		g.resize(n);
		p.resize(n, -1);
		h.resize(n);
		used.resize(n, 0);
		ans = -1;
		for(int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		ans = -1;
		h[0] = 0;
		dfs(0);
		if(ans != -1)
		{
			cout << "PATH\n";
			cout << (n + 1) / 2 << "\n";
			while(ans != -1)
			{
				cout << ans + 1 << " ";
				ans = p[ans];
			}
		}
		else
		{
			vector <pair <int, int> > mass;
			for(int i = 0; i < n; i++)
			{
				mass.push_back({h[i], i});
			}
			sort(mass.begin(), mass.end());
			vector <pair <int, int> > k;
			for(int i = 0; i < n - 1; i++)
			{
				if(mass[i + 1].first == mass[i].first)
				{
					k.push_back({mass[i].second + 1, mass[i + 1].second + 1});
					i++;
				}
			}
			cout << "PAIRING\n";
			cout << k.size() << "\n";
			for(int i = 0; i < k.size(); i++)
			{
				cout << k[i].first << " " << k[i].second << "\n";
			}
		}
		for(int i = 0; i < n; i++)
		{
			used[i] = 0;
			p[i] = -1;
			h[i] = 0;
			g[i].clear();
		}
		cout << "\n";
	}
	return 0;
}