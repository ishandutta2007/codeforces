#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int test, n, occ[333333], x, tree[2222222], num, beg[333333], en[333333], cnt, ans;
vector<int> g1[333333], g2[333333];
vector<pair<int, int> > v;
pair<int, int> cc;
void prec(int i)
{
	beg[i] = ++cnt;
	for (int j = 0; j < g2[i].size(); j++)
	{
		int to = g2[i][j];
		prec(to);
	}
	en[i] = cnt;
}
void update(int beg, int en, int l, int r, int node, int x)
{
	if (l > en || r < beg) return;
	if (l >= beg && r <= en)
	{
		v.push_back(make_pair(node, tree[node]));
		tree[node] = x;
		return;
	}
	int mid = (l + r) >> 1;
	update(beg, en, l, mid, node << 1, x);
	update(beg, en, mid + 1, r, (node << 1) | 1, x);
}
int query(int x, int l, int r, int node)
{
	if (l == r) return tree[node];
	int mid = (l + r) >> 1;
	if (x > mid) return max(query(x, mid + 1, r, (node << 1) | 1), tree[node]);
	return max(query(x, l, mid, node << 1), tree[node]);
}
void dfs(int i)
{
	int pr = -1;
	v.push_back(make_pair(-1, -1));
	int nw = query(beg[i], 1, n, 1);
	num++;
	occ[i] = 1;
	if (nw > 0 && occ[nw])
	{
		pr = nw;
		occ[nw] = 0;
		num--;
	} 
	update(beg[i], en[i], 1, n, 1, i);
	ans = max(ans, num);
	for (int j = 0; j < g1[i].size(); j++)
	{
		dfs(g1[i][j]);
	}
	num--;
	occ[i] = 0;
	if (~pr)
	{
		occ[pr] = 1;
		num++;
	}
	while(1)
	{
		cc = v.back();
		v.pop_back();
		if (cc.first == -1) break;
		tree[cc.first] = cc.second;
	}
}
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) 
		{
			g1[i].clear();
			g2[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x);
			g1[x].push_back(i + 1);
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &x);
			g2[x].push_back(i + 1);
		}
		v.clear();
		for (int i = 1; i <= 4 * n; i++) tree[i] = 0;
		for (int i = 1; i <= n; i++) occ[i] = 0;
		num = 0;
		cnt = 0;
		prec(1);
		ans = 0;
		dfs(1);
		printf("%d\n", ans);
	}
	return Accepted;
}