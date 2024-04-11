#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005, S = 300005;

int n, m, K, d[S], tot, rt[S];

struct Seg{
	int l, r, id;
	bool operator < (const Seg &b) const {
		return r < b.r;
	}
} e[S];

int idx;

struct T{
	int l, r, v;
} t[S * 18];

void inline pushup(int p) {
	t[p].v = min(t[t[p].l].v, t[t[p].r].v);
}

void update(int p, int &q, int l, int r, int x, int k) {
	t[q = ++idx] = t[p]; 
	if (l == r) { t[q].v = max(t[q].v, k); return; }
	int mid = (l + r) >> 1;
	if (x <= mid) update(t[p].l, t[q].l, l, mid, x, k);
	else update(t[p].r, t[q].r, mid + 1, r, x, k);
	pushup(q);
}

int query(int p, int l, int r, int x, int y) {
	if (!p) return 0;
	if (x <= l && r <= y) return t[p].v;
	int mid = (l + r) >> 1, res = 2e9;
	if (x <= mid) res = min(res, query(t[p].l, l, mid, x, y));
	if (mid < y) res = min(res, query(t[p].r, mid + 1, r, x, y));
	return res;
}

int main() {	
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= K; i++) {
		scanf("%d%d%d", &e[i].l, &e[i].r, &e[i].id);
		d[i] = e[i].r;
	}
	sort(e + 1, e + 1 + K);
	sort(d + 1, d + 1 + K);
	tot = unique(d + 1, d + 1 + K) - d - 1;
	for (int i = 1, j = 1; i <= tot; i++) {
		rt[i] = rt[i - 1];
		while (j <= K && e[j].r <= d[i]) {
			update(rt[i], rt[i], 1, n, e[j].id, e[j].l);
			++j;
		}
	}
	d[++tot] = 2e9;
	while (m--) {
		int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y);
		int v = upper_bound(d + 1, d + 1 + tot, y) - d - 1;
		puts(query(rt[v], 1, n, a, b) >= x ? "yes" : "no");
		fflush(stdout);
	}
	return 0;
}