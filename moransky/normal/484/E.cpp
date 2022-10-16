#include <cstdio>
#include <iostream>
#include <algorithm>
#define ls t[p].l
#define rs t[p].r
using namespace std;

const int N = 100005, INF = 1e9;

int n, a[N], m, tot, rt[N];

struct Node{
	int x, id;
	bool operator < (const Node &b) const {
		return x < b.x;
	}
} e[N];

int idx = 0;

struct Seg{
	int ans, pre, suf, len;
	Seg () {}
	Seg (int x) { ans = pre = suf = x, len = 1; }
};

Seg inline merge(Seg a, Seg b) {
	Seg c; 
	if (a.len == a.pre) c.pre = a.len + b.pre;
	else c.pre = a.pre;
	if (b.len == b.suf) c.suf = b.len + a.suf;
	else c.suf = b.suf;
	c.len = a.len + b.len;
	c.ans = max(a.suf + b.pre, max(a.ans, b.ans));
	return c;
}

struct T{
	int l, r;
	Seg v;
} t[N * 22];

void build(int &p, int l, int r) {
	p = ++idx;
	if (l == r) { t[p].v = Seg(0); return; }
	int mid = (l + r) >> 1;
	build(t[p].l, l, mid);
	build(t[p].r, mid + 1, r);
	t[p].v = merge(t[ls].v, t[rs].v);
}

void update(int p, int &q, int l, int r, int x) {
	t[q = ++idx] = t[p];
	if (l == r) { t[q].v = Seg(1); return; }
	int mid = (l + r) >> 1;
	if (x <= mid) update(t[p].l, t[q].l, l, mid, x);
	else update(t[p].r, t[q].r, mid + 1, r, x);
	t[q].v = merge(t[t[q].l].v, t[t[q].r].v);
}

Seg query(int p, int l, int r, int x, int y) {
	if (x <= l && r <= y) return t[p].v;
	int mid = (l + r) >> 1;
	if (y <= mid) return query(t[p].l, l, mid, x, y);
	else if (x > mid) return query(t[p].r, mid + 1, r, x, y);
	else return merge(query(t[p].l, l, mid, x, y), query(t[p].r, mid + 1, r, x, y));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), e[i].x = a[i], e[i].id = i;
	sort(e + 1, e + 1 + n);
	sort(a + 1, a + 1 + n);
	tot = unique(a + 1, a + 1 + n) - a - 1;
	a[++tot] = INF;
	build(rt[tot], 1, n);
	for (int i = tot - 1, j = n; i; i--) {
		rt[i] = rt[i + 1];
		while (j && e[j].x == a[i]) {
			update(rt[i], rt[i], 1, n, e[j].id);
			j--;
		}
	}
	scanf("%d", &m);
	while (m--) {
		int x, y, k; scanf("%d%d%d", &x, &y, &k);
		int l = 1, r = tot;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (query(rt[mid], 1, n, x, y).ans >= k) l = mid;
			else r = mid - 1;
		}
		printf("%d\n", a[r]);
	}
	return 0;
}