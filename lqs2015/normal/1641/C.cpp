#include <bits/stdc++.h>
using namespace std;
int mn[222222], n, q, pa[222222], mnn[222222], tree[888888], l, r, x, tp;
void pushup(int node)
{
	tree[node] = min(tree[node << 1], tree[(node << 1) | 1]);
}
void upd(int x, int l, int r, int node, int y)
{
	if (l == r)
	{
		tree[node] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (x > mid) upd(x, mid + 1, r, (node << 1) | 1, y);
	else upd(x, l, mid, node << 1, y);
	pushup(node);
}
void build(int l, int r, int node)
{
	if (l == r)
	{
		tree[node] = mn[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node << 1);
	build(mid + 1, r, (node << 1) | 1);
	pushup(node);
}
int query(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return 2e9;
	if (l >= beg && r <= en) return tree[node];
	int mid = (l + r) >> 1;
	return min(query(beg, en, l, mid, node << 1), query(beg, en, mid + 1, r, (node << 1) | 1));
}
int root(int x)
{
	if (pa[x] != x) pa[x] = root(pa[x]);
	return pa[x];
}
void uni(int l, int r)
{
	int cur = root(l);
	while(cur < r)
	{
		pa[cur] = cur + 1;
		mnn[root(cur + 1)] = mnn[cur];
		cur = root(cur + 1);
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i <= n; i++) mn[i] = 2e9;
	for (int i = 0; i <= n; i++)
	{
		pa[i] = i;
		mnn[i] = i;
	}
	build(0, n, 1);
	while(q--)
	{
		scanf("%d", &tp);
		if (tp == 0)
		{
			scanf("%d%d%d", &l, &r, &x);
			l--;
			if (!x) uni(l, r);
			else 
			{
				if (mn[l] > r)
				{
					mn[l] = r;
					upd(l, 0, n, 1, r);
				}
			}
		}
		else
		{
			scanf("%d", &x);
			if (root(x - 1) == root(x)) printf("NO\n");
			else if (query(mnn[x - 1], x - 1, 0, n, 1) <= root(x)) printf("YES\n");
			else printf("N/A\n");
		}
	}
	return 0;
}