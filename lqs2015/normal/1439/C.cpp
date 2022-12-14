#include <bits/stdc++.h>
#define Accepted 0
using namespace std;
int n, q, a[222222], len[888888], tp, x, y, ll, res, lst;
long long tree[888888], lazy[888888];
struct tple
{
	int val, l, r;
	bool operator < (const tple &u) const
	{
		if (val != u.val) return val > u.val;
		return l < u.l;
	}
	bool operator > (const tple &u) const
	{
		if (val != u.val) return val < u.val;
		return l > u.l;
	}
	bool operator == (const tple &u) const
	{
		return (val == u.val && l == u.l && r == u.r);
	}
};
set<tple> s;
set<tple>::iterator it, iter;
vector<tple> to_del;
void pushup(int node)
{
	tree[node] = tree[node << 1] + tree[(node << 1) | 1];
}
void push(int node, long long x)
{
	lazy[node] += x;
	tree[node] += (x * len[node]);
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node << 1, lazy[node]);
		push((node << 1) | 1, lazy[node]);
		lazy[node] = 0;
	}
}
void update(int beg, int en, int l, int r, int node, int x)
{
	if (l > en || r < beg) return;
	if (l >= beg && r <= en)
	{
		push(node, x);
		return;
	}
	pushdown(node);
	int mid = (l + r) >> 1;
	update(beg, en, l, mid, node << 1, x);
	update(beg, en, mid + 1, r, (node << 1) | 1, x);
	pushup(node);
}
void build(int l, int r, int node)
{
	len[node] = r - l + 1;
	if (l == r)
	{
		tree[node] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node << 1);
	build(mid + 1, r, (node << 1) | 1);
	pushup(node);
}
void upd(int x, int y)
{
	it = s.lower_bound((tple){y, 0, 0});
	if (it == s.end()) return;
	to_del.clear();
	ll = (it -> l);
	for (;it != s.end(); it++)
	{
		if ((it -> l) > x) break;
		if ((it -> r) <= x)
		{
			to_del.push_back(*it);
			update(it -> l, it -> r, 1, n, 1, y - (it -> val));
		}
		else
		{
			to_del.push_back(*it);
			update(it -> l, x, 1, n, 1, y - (it -> val));
			s.insert((tple){it -> val, x + 1, it -> r});
		}
	}
	for (int i = 0; i < to_del.size(); i++)
	{
		s.erase(to_del[i]);
	}
	if (ll <= x) s.insert((tple){y, ll, x});
}
int qy(int l, int r, int node)
{
	if (l == r)
	{
		if (tree[node] <= lst)
		{
			lst -= tree[node];
			res ++;
			return l + 1;
		}
		return l;
	}
	pushdown(node);
	int mid = (l + r) >> 1;
	if (tree[node << 1] <= lst)
	{
		lst -= tree[node << 1];
		res += len[node << 1];
		return qy(mid + 1, r, (node << 1) | 1);
	}
	return qy(l, mid, node << 1);
}
int query(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return -1;
	if (l >= beg && r <= en)
	{
		if (lst >= tree[node])
		{
			res += len[node];
			lst -= tree[node];
			return -1;
		}
		return qy(l, r, node);
	} 
	pushdown(node);
	int mid = (l + r) >> 1, rs;
	rs = query(beg, en, l, mid, node << 1);
	if (~rs) return rs;
	return query(beg, en, mid + 1, r, (node << 1) | 1);
}
int qry(int x, int y)
{
	lst = y;
	res = 0;
	while(x <= n)
	{
		it = s.lower_bound((tple){lst, 0, 0});
		if (it == s.end()) break;
		x = query(max(x, it -> l), n, 1, n, 1);
		if (x == -1) break;
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		s.insert((tple){a[i], i, i});
	}
	build(1, n, 1);
	while(q--)
	{
		scanf("%d%d%d", &tp, &x, &y);
		if (tp == 1)
		{
			upd(x, y);
		}
		else
		{
			printf("%d\n", qry(x, y));
		}
	}
	return Accepted;
}