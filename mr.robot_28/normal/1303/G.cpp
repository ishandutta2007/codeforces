#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define double long double
const double eps = 1e-9;
vector <pair <int, int> > tree;
vector <bool> usedt;
int n;
void clear(int v, int l, int r)
{
	if(!usedt[v])
	{
		return;
	}
	usedt[v] = false;
	tree[v] = {0, 0};
	if(l != r)
	{
		int m = (r + l) / 2;
		clear(v * 2, l, m);
		clear(v * 2 + 1, m + 1, r);
	} 
}
int eval(pair <int, int> funct, int x)
{
	return funct.first * x + funct.second;
}
int get(int v, int l, int r, int x)
{
	int ans = eval(tree[v], x);
	if(l != r)
	{
		int midd = (r + l) / 2;
		if(midd >= x)
		{
			ans = max(ans, get(v * 2, l, midd, x));
		}
		else
		{
			ans = max(ans, get(v * 2 + 1, midd + 1, r, x));
		}
	}
	return ans;
}
void update(int v, int l, int r, pair <int, int> funct)
{
	usedt[v] = true;
	int m = (r + l) / 2;
	bool need_swap = eval(funct, m) > eval(tree[v], m);
	if(need_swap)
	{
		swap(tree[v], funct);
	}
	if(l == r)
	{
		return;
	}
	if(eval(funct, l) > eval(tree[v], l))
	{
		update(v * 2, l, m, funct);
	}
	else
	{
		update(v * 2 + 1, m + 1, r, funct);
	}
}
int ans = 0;
void update_ans(vector <vector <pair <int, int> > > heads, vector <vector <pair <int, int> > > tails)
{
	int n = heads.size();
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < heads[i].size(); j++)
		{
			pair <int, int> x = heads[i][j];
			ans = max(ans, get(1, 0, n - 1, x.first) + x.second);
		}
		for(int j = 0; j < tails[i].size(); j++){
			pair <int, int> x = tails[i][j];
			update(1, 0, n - 1, x);
		}
	}
	clear(1, 0, n - 1);
}
vector <int> A;
vector <vector <int> > g;
vector <int> size1;
vector <bool> used;
void dfs1(int v, int p = -1)
{
	if(used[v])
	{
		return;
	}
	size1[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!used[to] && to != p)
		{
			dfs1(to, v);
			size1[v] += size1[to];
		}
	}
}
pair <int, int> c;
int s = 0;
void find_centroid(int v, int p = -1)
{
	if(used[v])
	{
		return;
	}
	int mx = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!used[to] && to != p)
		{
			find_centroid(to, v);
			mx = max(mx, size1[to]);
		}
	}
	if(p != -1)
	{
		mx = max(mx, s - size1[v]);
	}
	c = min(c, make_pair(mx, v));
}
void dfs_heads(int v, int p, int cnt, int cursum, int curadd, vector <pair <int, int> > &sink)
{
	if(used[v])
	{
		return;
	}
	cnt++;
	curadd += A[v];
	cursum += curadd;
	sink.push_back(make_pair(cnt, cursum));
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs_heads(to, v, cnt, cursum, curadd, sink);
		}
	}
}
void dfs_tails(int v, int p, int cnt, int cursum, int curadd, vector <pair <int, int> > &sink)
{
	if(used[v])
	{
		return;
	}
	cnt++;
	curadd += A[v];
	cursum += A[v] * cnt;
	sink.push_back(make_pair(curadd, cursum));
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs_tails(to, v, cnt, cursum, curadd, sink);
		}
	}
}
void centroid(int v)
{
	if(used[v]) return;
	dfs1(v);
	s = size1[v];
	c = make_pair(1e9, -1);
	find_centroid(v);
	int C =c.second;
	used[C] = 1;
	vector <vector <pair <int, int> > > heads, tails;
	for(int i = 0; i < g[C].size(); i++)
	{
		int to = g[C][i];
		if(!used[to])
		{
			heads.push_back(vector<pair <int, int> > ());
			dfs_heads(to, C, 1, A[C], A[C], heads.back());
			tails.push_back(vector <pair <int, int> > ());
			dfs_tails(to, C, 0, 0, 0, tails.back());
		}
	}
	heads.push_back(vector <pair <int, int> > ({{1, A[C]}}));
	tails.push_back(vector <pair <int, int> > ({{0, 0}}));
	update_ans(heads, tails);
	reverse(heads.begin(), heads.end());
	reverse(tails.begin(),tails.end());
	update_ans(heads, tails);
	for(int i = 0; i < g[C].size(); i++)
	{
		int to = g[C][i];
		centroid(to);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	usedt.resize(4 * n);
	tree.resize(4 * n);
	A.resize(n);
	g.resize(n);
	used.resize(n);
	size1.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	centroid(0);
	cout << ans;
	return 0;
}