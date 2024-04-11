#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int test, a[222222], bit[444444], sz, dp[444444], arr[222222], m, ans, lst, n;
int sum1[888888], sum2[888888];
bool tag[888888], used[222222];
vector<int> v[222222];
map<int, int> mp;
void add(int &x, int y)
{
	x += y;
	if (x >= mod) x -= mod;
}
void update(int p, int x)
{
	while(p <= sz)
	{
		add(bit[p], x);
		p += p & (-p);
	}
}
int query(int p)
{
	int res = 0;
	while(p >= 1)
	{
		add(res, bit[p]);
		p -= p & (-p);
	}
	return res;
}
void pushup(int node)
{
	sum1[node] = sum1[node << 1] + sum1[(node << 1) | 1];
	sum2[node] = sum2[node << 1] + sum2[(node << 1) | 1];
	if (sum1[node] >= mod) sum1[node] -= mod;
	if (sum2[node] >= mod) sum2[node] -= mod;
}
void push(int node)
{
	sum1[node] = sum2[node];
	tag[node] = 1;
}
void pushdown(int node)
{
	if (tag[node])
	{
		push(node << 1);
		push((node << 1) | 1);
		tag[node] = 0;
	}
}
void build(int l, int r, int node)
{
	tag[node] = 0;
	if (l == r)
	{
		if (used[l])
		{
			if (l == lst) 
			{
				sum1[node] = 0;
				sum2[node] = 1;
			}
			else sum1[node] = sum2[node] = 1;
		}
		else sum1[node] = sum2[node] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node << 1);
	build(mid + 1, r, (node << 1) | 1);
	pushup(node);
}
int query1(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 0;
	if (l >= beg && r <= en) return sum1[node];
	int mid = (l + r) >> 1;
	pushdown(node);
	return (query1(beg, en, l, mid, node << 1) + query1(beg, en, mid + 1, r, (node << 1) | 1)) % mod;
}
int query2(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 0;
	if (l >= beg && r <= en) return sum2[node];
	int mid = (l + r) >> 1;
	pushdown(node);
	return (query2(beg, en, l, mid, node << 1) + query2(beg, en, mid + 1, r, (node << 1) | 1)) % mod;
}
void upd(int x, int l, int r, int node, int a, int b)
{
	if (l == r)
	{
		sum1[node] = a;
		sum2[node] = b;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(node);
	if (x > mid) upd(x, mid + 1, r, (node << 1) | 1, a, b);
	else upd(x, l, mid, node << 1, a, b);
	pushup(node);
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) arr[i] = a[i];
		sort(arr + 1, arr + n + 1);
		m = unique(arr + 1, arr + n + 1) - arr - 1;
		mp.clear();
		for (int i = 1; i <= m; i++) mp[arr[i]] = i;
		for (int i = 1; i <= n; i++) a[i] = mp[a[i]]; 
		sz = 1;
		while(sz < n) sz <<= 1;
		for (int i = 0; i <= sz; i++) bit[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			dp[i] = (query(a[i] - 1) + 1) % mod;
			update(a[i], dp[i]);
		}
		for (int i = 1; i <= m; i++) v[i].clear();
		for (int i = 1; i <= n; i++) v[a[i]].push_back(i);
		ans = 0;
		for (int i = 1; i <= n; i++) used[i] = 0;
		for (int i = 0; i < v[m].size(); i++)
		{
			used[v[m][i]] = 1;
		}
		lst = v[m].back();
		build(1, n, 1);
		for (int i = m - 1; i >= 1; i--)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				int pos = v[i][j];
				int val = (query1(pos, n, 1, n, 1) + 1) % mod;
				if (pos < lst) ans = (1ll * dp[pos] * val + ans) % mod;
			}
			for (int j = 0; j < v[i].size(); j++)
			{
				int pos = v[i][j];
				int val1 = query1(pos, n, 1, n, 1), val2 = query2(pos, n, 1, n, 1);
				val1 = (val1 + 1) % mod;
				val2 = (val2 + 1) % mod;
				if (pos < lst) 
				{
					upd(pos, 1, n, 1, val1, val2);
				}
				else
				{
					push(1);
					upd(pos, 1, n, 1, 0, 1);
					lst = pos;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}