#include <bits/stdc++.h>
using namespace std;
vector <int> dsu, rang;
int pred(int a)
{
	if(a == dsu[a]) return a;
	else return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
	a = pred(a);
	b = pred(b);
	if(a != b)
	{
		if(rang[a] < rang[b])
		{
			swap(a, b);
		}
		dsu[b] = a;
		if(rang[a] == rang[b])
		{
			rang[a]++;
		}
	}
}
vector <vector <pair <int, int> > >g;
vector <int> used1;
bool flag1;
void dfs(int v, int p = -1)
{
	used1[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int ind = g[v][i].second;
		if(ind == p)
		{
			continue;
		}
		if(used1[to] == 1)
		{
			flag1 = true;
		}
		else if(used1[to] == 0)
		{
			dfs(to, ind);
		}
	}
	used1[v] = 2;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	dsu.resize(n);
	rang.resize(n);
	g.resize(n);
	used1.resize(n);
	for(int i = 0; i < n; i++)
	{
		dsu[i] = i;
		rang[i] = 1;
	}
	vector <bool> can(m, true);
	vector <pair <int, pair <int, int> > > vec(m);
	vector <pair <int, int> > sorted(m);
	for(int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--;
		b--;
		vec[i] = {w, {a, b}};
		sorted[i] = {w, i};
	}
	sort(sorted.begin(), sorted.end());
	int q;
	cin >> q;
	vector <vector <pair <int, int> > > w(q);
	vector <bool> ans(q, true);
	vector <pair <pair <int, int>, int> > mass;
	for(int i= 0; i < q; i++)
	{
		int k;
		cin >> k;
		w[i].resize(k);
		for(int j = 0; j < k; j++)
		{
			cin >> w[i][j].second;
			w[i][j].second--;
			w[i][j].first = vec[w[i][j].second].first;
			mass.push_back({{w[i][j].first, i}, w[i][j].second});
		}
	}
	sort(mass.begin(), mass.end());
	int j = 0;
	for(int i = 0; i < m; i++)
	{
		if(i == 0 || sorted[i].first > sorted[i - 1].first)
		{
			while(j < mass.size() && mass[j].first.first == sorted[i].first)
			{
				int k = j;
				while(k < mass.size() && mass[k].first == mass[j].first)
				{
					int ind = mass[k].second;
					int a = vec[ind].second.first;
					int b = vec[ind].second.second;
					a = pred(a);
					b = pred(b);
					g[a].push_back({b, ind});
					g[b].push_back({a, ind});
					k++;
				}
				k = j;
				flag1 = false;
				while(k < mass.size() && mass[k].first == mass[j].first)
				{
					int a = vec[mass[k].second].second.first;
					a = pred(a);
					if(used1[a] == 0)
					{
						dfs(a);
					}
					k++;
				}
				if(flag1)
				{
					ans[mass[j].first.second] = false;
				}
				k = j;
				while(k < mass.size() && mass[k].first== mass[j].first)
				{
					int a = vec[mass[k].second].second.first;
					int b = vec[mass[k].second].second.second;
					a = pred(a);
					b = pred(b);
					g[a].pop_back();
					g[b].pop_back();
					used1[a] = used1[b] = 0;
					k++;
				}
				j = k;
			}
		}
		int a = vec[sorted[i].second].second.first;
		int b = vec[sorted[i].second].second.second;
		unite(a, b);
	}
	for(int i= 0; i < q; i++)
	{
		if(ans[i])
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