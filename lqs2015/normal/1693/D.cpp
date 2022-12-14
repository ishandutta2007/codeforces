#include <bits/stdc++.h>
using namespace std;
int n, p[222222], pre[222222], nxt1[222222], nxt2[222222], tp[222222], pre1[222222], pre2[222222];
int nxtc[222222], p1, p2, l, r, L, R, ps[222222];
bool isc[222222];
long long ans;
struct hjt1
{
	int rt[222222], ls[4000004], rs[4000004], tree[4000004], sz;
	void update(int pre, int x, int l, int r, int &nw)
	{
		nw = ++sz; tree[nw] = tree[pre] + 1;
		ls[nw] = ls[pre]; rs[nw] = rs[pre];
		if (l == r) return;
		int mid = (l + r) >> 1;
		if (x > mid) update(rs[pre], x, mid + 1, r, rs[nw]);
		else update(ls[pre], x, l, mid, ls[nw]);
	}
	int query(int pre, int nw, int beg, int en, int l, int r)
	{
		if (l > en || r < beg) return 0;
		if (l >= beg && r <= en) return tree[nw] - tree[pre];
		int mid = (l + r) >> 1;
		return query(ls[pre], ls[nw], beg, en, l, mid) + query(rs[pre], rs[nw], beg, en, mid + 1, r);
	}
}tree1;
struct node
{
	bool f;
	int l, r;
	node(bool f = 1, int l = 1e9, int r = -1e9): f(f), l(l), r(r)
	{
		;
	}
};
struct hjt2
{
	int rt[222222], ls[4000004], rs[4000004], sz;
	node tree[4000004];
	node merge(node a, node b)
	{
		node res;
		res.l = min(a.l, b.l);
		res.r = max(a.r, b.r);
		res.f = 1;
		if (!a.f || !b.f) res.f = 0;
		else if (a.l < b.r) res.f = 0;
		return res;
	}
	void pushup(int node)
	{
		tree[node] = merge(tree[ls[node]], tree[rs[node]]);
	}
	void update(int pre, int x, int l, int r, int &nw)
	{
		nw = ++sz;
		ls[nw] = ls[pre]; rs[nw] = rs[pre];
		if (l == r)
		{
			tree[nw] = (node){1, p[x], p[x]};
			return;
		}
		int mid = (l + r) >> 1;
		if (x > mid) update(rs[pre], x, mid + 1, r, rs[nw]);
		else update(ls[pre], x, l, mid, ls[nw]);
		pushup(nw);
	}
	node query(int nw, int beg, int en, int l, int r)
	{
		if (l > en || r < beg) return node();
		if (l >= beg && r <= en) return tree[nw];
		int mid = (l + r) >> 1;
		return merge(query(ls[nw], beg, en, l, mid), query(rs[nw], beg, en, mid + 1, r));
	}
}tree2;
struct hjt3
{
	int rt[222222], ls[4000004], rs[4000004], sz;
	node tree[4000004];
	node merge(node a, node b)
	{
		node res;
		res.l = min(a.l, b.l);
		res.r = max(a.r, b.r);
		res.f = 1;
		if (!a.f || !b.f) res.f = 0;
		else if (a.r > b.l) res.f = 0;
		return res;
	}
	void pushup(int node)
	{
		tree[node] = merge(tree[ls[node]], tree[rs[node]]);
	}
	void update(int pre, int x, int l, int r, int &nw)
	{
		nw = ++sz;
		ls[nw] = ls[pre]; rs[nw] = rs[pre];
		if (l == r)
		{
			tree[nw] = (node){1, p[x], p[x]};
			return;
		}
		int mid = (l + r) >> 1;
		if (x > mid) update(rs[pre], x, mid + 1, r, rs[nw]);
		else update(ls[pre], x, l, mid, ls[nw]);
		pushup(nw);
	}
	node query(int nw, int beg, int en, int l, int r)
	{
		if (l > en || r < beg) return node();
		if (l >= beg && r <= en) return tree[nw];
		int mid = (l + r) >> 1;
		return merge(query(ls[nw], beg, en, l, mid), query(rs[nw], beg, en, mid + 1, r));
	}
}tree3;
bool check(int l, int r)
{
	int k1 = nxt1[l], k2 = nxt2[l];
	if (k1 == -1 || k2 == -1) return 1;
	int pos = nxtc[max(k1, k2)];
	//if (l == 1 && r == 6) cout << "fuck" << k1 << " " << k2 << endl;
	if (pos == -1) return 1;
	L = p[pre1[pos]]; R = p[pre2[pos]];
	if (p[pos] < L) R = p[pos];
	else 
	{
		assert(p[pos] > R);
		L = p[pos];
	}
	if (pos >= r) return 1;    //[pos+1,r]
	if (tree1.query(tree1.rt[pos], tree1.rt[r], R, L, 1, n)) return 0;
	if (tree2.query(tree2.rt[R], pos + 1, r, 1, n).f & tree3.query(tree3.rt[L], pos + 1, r, 1, n).f) return 1;
	return 0;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	tp[n] = 1;
	for (int i = 1; i < n; i++)
	{
		if (p[i] < p[i + 1]) tp[i] = 1;
		else tp[i] = 2;
	}
	p1 = p2 = -1;
	for (int i = 1; i <= n; i++)
	{
		pre1[i] = p1;
		pre2[i] = p2; 
		if (tp[i] == 1) p1 = i;
		else p2 = i;
	}
	p1 = p2 = -1;
	for (int i = n; i >= 1; i--)
	{
		if (tp[i] == 1) p1 = i;
		else p2 = i;
		nxt1[i] = p1;
		nxt2[i] = p2; 
	}
	for (int i = 1; i <= n; i++)
	{
		l = pre1[i];
		r = pre2[i];
		if (l == -1) l = -1e9;
		else l = p[l];
		if (r == -1) r = -1e9;
		else r = p[r];
		if (p[i] >= l && p[i] <= r);
		else isc[i] = 1;
	}
	p1 = -1;
	for (int i = n; i >= 1; i--)
	{
		nxtc[i] = p1;
		if (isc[i]) p1 = i;
	}
	for (int i = 1; i <= n; i++) tree1.update(tree1.rt[i - 1], p[i], 1, n, tree1.rt[i]);
	for (int i = 1; i <= n; i++) ps[p[i]] = i;
	for (int i = 1; i <= n; i++) tree2.update(tree2.rt[i - 1], ps[i], 1, n, tree2.rt[i]);
	for (int i = n; i >= 1; i--) tree3.update(tree3.rt[i + 1], ps[i], 1, n, tree3.rt[i]);
	r = 1;
	for (int i = 1; i <= n; i++)
	{
		if (r < i) r = i;
		while(r <= n) 
		{
			if (!check(i, r)) break;
			r++;
		}
		ans += (r - i);
		//cout << i << " " << r << endl;
	}
	printf("%lld\n", ans);
	return 0;
}