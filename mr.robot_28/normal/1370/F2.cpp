#include <bits/stdc++.h>
                  
using namespace std;
vector <vector <int> > g;
vector <vector <int> > h;
vector <int> hmax;
void dfs(int v, int c = 0, int p = -1)
{
	hmax[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, c + 1, v);
			hmax[v] = max(hmax[v], hmax[to] + 1);
		}
	}
}
int n;
void dfs1(int v, int c = 0, int p = -1)
{
	if(hmax[v] > n / 2)
	{
		return;
	}
	h[c].push_back(v);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs1(to, c + 1, v);
		}
	}
}
void dfs2(int v, int c = 0, int p = -1)
{
	h[c].push_back(v);
	for(int i= 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs2(to, c + 1, v);
		}
	}
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		g.resize(n);
		hmax.resize(n);
		h.resize(n);
		vector <int> pref(n);
		for(int i = 0; i < n - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		cout << "? " << n << endl;
		for(int i = 1; i <= n; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		fflush(stdout);
		int x, d;
		cin >> x >> d;
		x--;
		dfs(x);
		h[0].push_back(x);
		for(int i = 0; i < g[x].size(); i++)
		{
			dfs1(g[x][i], 1, x);
		}
		int l = 0, r = n;
		for(int i = n - 2; i >= 0; i--)
		{
			if(h[i + 1].size() == 0)
			{
				r = i + 1;
			}
		}
		int pr = -1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			cout << "? " << h[midd].size() << " ";
			for(int j = 0; j < h[midd].size(); j++)
			{
				cout << h[midd][j] + 1 << " ";
			}
			cout << endl;
			fflush(stdout);
			int x1, d1;
			cin >> x1 >> d1;
			if(d1 == d)
			{
				l = midd;
				pr = x1;
				pr--;
			}
			else  
			{
				r = midd;
			}
		}
		if(l == 0)
		{
			pr = x;
		}
		int pr1 = -1;
		for(int i = 0; i < n; i++)
		{
			h[i].clear();
		}
		dfs2(pr);
		cout << "? " << h[d].size() << " ";
		for(int i = 0; i < h[d].size(); i++)
		{
			cout << h[d][i] + 1 << " ";
		}
		cout << endl;
		fflush(stdout);
		cin >> pr1 >> d;
		pr1--;
		cout << "! " << pr + 1 << " " << pr1 + 1 << endl;
		fflush(stdout);
		string s;
		cin  >> s;
		for(int i = 0; i < n; i++)
		{
			h[i].clear();
			g[i].clear();
		}
	}
	return 0;
}