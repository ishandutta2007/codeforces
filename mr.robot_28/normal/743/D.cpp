#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
vector <vector <int> > g;
vector <int> A;
vector <int> sum;
vector <int> eiler;
vector <int> tin, tout;
int ans = -1e17;
bool flag = false;
void dfs(int v, int p = -1)
{
	eiler.push_back(v);
	tin[v] = eiler.size() - 1;
	for(int i = 0; i< g[v].size(); i++)
	{
		if(g[v][i] != p)
		{
			dfs(g[v][i], v);
			sum[v] += sum[g[v][i]];
		}
	}
	sum[v] += A[v];
	eiler.push_back(v);
	tout[v] = eiler.size() - 1;
}
vector <int> tree;
int s(int v, int l, int r, int al, int ar)
{
	if(l >= al && r <= ar)
	{
		return tree[v];
	}
	else if(l <= ar && r >= al)
	{
		return max(s(v * 2, l, (r + l) / 2, al, ar), s(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
	}
	else
	{
		return -1e17;
	}
}
void update(int v, int l, int r, int ind, int val)
{
	if(l == r)
	{
		tree[v] = val;
		return;
	}
	else if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, val);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, val);
	}
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}
void dfs1(int v, int p = -1, int cnt = 1)
{
	if(tin[v] != 0)
	{
		ans = max(ans, s(1, 0, 2 * n - 1, 0, tin[v] - 1) + sum[v]);
	}
	if(tout[v] != eiler.size() - 1)
	{
		ans = max(ans, s(1, 0, 2 * n - 1, tout[v] + 1, 2 * n - 1) + sum[v]);
	}
	int u = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != p)
		{
			u++;
			dfs1(g[v][i], v, cnt + 1);
		}
	}
	update(1, 0, 2 * n - 1, tin[v], sum[v]);
	if(u == 0 && cnt < n)
	{
		flag = true;
	}
}
signed main()
{
	cin >> n;
	g.resize(n);
	A.resize(n);
	tin.resize(n);
	tout.resize(n);
	sum.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	tree.resize(8 * n, -1e17);
	dfs1(0);
	if(!flag)
	{
		cout <<"Impossible";
		return 0;
	}
	cout << ans;
    return 0;
}