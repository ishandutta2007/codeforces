#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int const1 = 998244353;
vector <vector <int> > g;
vector <int> tin, tout;
int timer = 0;
void dfs(int v)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		dfs(to);
	}
	tout[v] = timer++;
}
vector <int> tree, upd;
void push(int v, int l, int r)
{
	if(l == r)
	{
		return;
	}
	tree[v * 2] += upd[v];
	upd[v * 2] += upd[v];
	tree[v * 2 + 1] += upd[v];
	upd[v * 2 + 1] += upd[v];
	upd[v] = 0;
}
void update(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		upd[v] += val;
		tree[v] += val;
	}
	else if(l <= ar && r >= al)
	{
		push(v, l, r);
		update(v * 2, l, (r + l) / 2, al, ar, val);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		tree[v] = max(tree[v * 2 + 1], tree[v * 2]);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	tin.resize(n + 1);
	tout.resize(n + 1);
	g.resize(n + 1);
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
	}
	stack <int> q;
	for(int i = n - 1; i >= 0; i--)
	{
		while(q.size() > 0 && a[q.top()] <= a[i])
		{
			q.pop();
		}
		if(q.size() == 0)
		{
			g[0].push_back(i + 1);
		}
		else
		{
			g[q.top() + 1].push_back(i + 1);
		}
		q.push(i);
	}
	dfs(0);
	tree.resize(4 * timer);
	upd.resize(4 * timer);
	for(int i = 0; i < n; i++)
	{
		update(1, 0, timer, tin[i + 1], tout[i + 1], 1);
		if(i >= k)
		{
			update(1, 0, timer, tin[i + 1 - k], tout[i + 1 - k], -1);
		}
		if(i >= k -1 )
		{
			cout << tree[1] << " ";
		}
	}
	return 0;
}