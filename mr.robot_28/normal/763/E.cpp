#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> tree;
vector <vector <int> > dsu;
vector <vector <int> > rang;
int pred(int v, int a)
{
	if(dsu[v][a] == a) return a;
	else return dsu[v][a] = pred(v, dsu[v][a]);
}
void unite(int v, int a, int b)
{
	a = pred(v, a);
	b = pred(v, b);
	if(rang[v][a] < rang[v][b])
	{
		swap(a, b);
	}
	dsu[v][b] = a;
	rang[v][a] += rang[v][b];
}
void build(int v, int l, int r)
{
	if(l == r)
	{
		tree[v] = 1;
		dsu[v].resize(1);
		rang[v].resize(1);
		dsu[v][0] = 0;
		rang[v][0] = 1;
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
		dsu[v].resize(r - l + 1);
		rang[v].resize(r - l + 1);
		for(int j = l; j <= (r + l) / 2; j++)
		{
			dsu[v][j - l] = dsu[v * 2][j - l];
			rang[v][j - l] = rang[v * 2][j - l];
		}
		for(int j = (r + l) / 2 + 1; j <= r; j++)
		{
			dsu[v][j - l] = dsu[v * 2 + 1][j - ((r + l) / 2 + 1)] + (r + l) / 2 + 1 - l;
			rang[v][j - l] = rang[v * 2 + 1][j - ((r + l) / 2 + 1)];
		}
		for(int i = (r + l) / 2; i > max((r + l) / 2 - 5, l - 1); i--)
		{
			for(int j = 0; j < g[i].size(); j++)
			{
				if(g[i][j] > (r + l) / 2 && g[i][j] <= r)
				{
					if(pred(v, i - l) != pred(v, g[i][j] - l))
					{
						unite(v, i - l, g[i][j] - l);
						tree[v]--;
					}
				}
			}
		}
	}
}
vector <int> dsuall;
vector <int> rangall;
vector <pair <pair <int, int>, int> > vec;
int go_to(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		vec.push_back({{l, r}, v});
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return go_to(v * 2, l, (r + l) / 2, al, ar) + go_to(v * 2 + 1, (r + l) / 2 + 1, r, al, ar);
	}
	return 0;
}
int pred1(int a)
{
	if(dsuall[a] == a) return a;
	else return dsuall[a] = pred1(dsuall[a]);
}
void unite1(int a, int b)
{
	a = pred1(a);
	b = pred1(b);
	if(rangall[a] < rangall[b])
	{
		swap(a, b);
	}
	dsuall[b] = a;
	rangall[a] += rangall[b];
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	tree.resize(4 * n);
	g.resize(n);
	dsu.resize(4 * n);
	rang.resize(4 * n);
	dsuall.resize(n);
	rangall.resize(n);
	for(int i = 0; i < n; i++)
	{
		dsuall[i] = i;
		rangall[i] = 1;
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if(a > b)
		{
			swap(a, b);
		}
		g[a].push_back(b);
	}
	for(int i = 0; i < n; i++)
	{
		sort(g[i].begin(), g[i].end());
	}
	build(1, 0, n - 1);
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		vector <pair <int, int> > united;
		int ans = go_to(1, 0, n - 1, l, r);
		for(int i = 0; i < vec.size() - 1; i++)
		{
			int l1 = vec[i].first.first;
			int r1 = vec[i].first.second;
			int v1 = vec[i].second;
			for(int j = r1; j > max(r1 - k, l1 - 1); j--)
			{
				int it = i + 1;
				for(int k = 0; k < g[j].size(); k++)
				{
					if(g[j][k] <= r && g[j][k] > r1)
					{
						while(vec[it].first.second < g[j][k])
						{
							it++;
						}
						int l2 = vec[it].first.first;
						int v2 = vec[it].second;
						int a = pred(v1, j - l1) + l1;
						int b = pred(v2, g[j][k] - l2) + l2;
						if(pred1(a) != pred1(b))
						{
							united.push_back({a, b});
							ans--;
							unite1(a, b);
						}
					}
				}
			}
		}
		for(int i = 0; i < united.size(); i++)
		{
			dsuall[united[i].first] = united[i].first;
			rangall[united[i].first] = 1;
			dsuall[united[i].second] = united[i].second;
			rangall[united[i].second] = 1;
		}
		vec.clear();
		cout << ans << "\n";
	}
	return 0;
}