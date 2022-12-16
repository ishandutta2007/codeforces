#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 1e5 + 10, inf = 1e9 + 10;
int n,m,root,a[maxn];
struct Edge {
	int v, nxt;
}e[maxn << 1];
int h[maxn], cnt_e;
void add(int x, int y) { e[++cnt_e] = {y, h[x]}, h[x] = cnt_e; }

struct SegTree {
	struct node {
		int ls, rs, mn;
		node() : mn(inf) {}
	}tr[maxn * 100];
	int rt[maxn],tot;
	#define ls(o) (tr[o].ls)
	#define rs(o) (tr[o].rs)
	#define mn(o) (tr[o].mn)
	#define mid ((l + r) >> 1)
	void push_up(int o) { mn(o) = min(mn(ls(o)), mn(rs(o))); }
	void update(int p, int &q, int l, int r, int pos, int val) {
		tr[q = ++tot] = tr[p];
		if (l == r) return mn(q) = min(mn(q), val), void();
		if (pos <= mid) update(ls(p), ls(q), l, mid, pos, val);
		else update(rs(p), rs(q), mid + 1, r, pos, val);
		push_up(q);
	}
	int query(int o, int l, int r, int L, int R) {
		if (L > r || R < l) return inf;
		if (L <= l && r <= R) return mn(o);
		return min(query(ls(o), l, mid, L, R), query(rs(o), mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mn
	#undef mid
}T;
int dep[maxn],st[maxn],ed[maxn],idx;
vector <int> id[maxn];
void dfs(int u, int pre) {
	dep[u] = dep[pre] + 1;
	st[u] = ++idx;
	id[dep[u]].push_back(u);
	for (int j = h[u]; j; j = e[j].nxt) {
		int v = e[j].v;
		if (v == pre) continue;
		dfs(v, u);
	}
	ed[u] = idx;
}

int main() {
	scanf("%d%d", &n, &root);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i < n; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(root, 0);
	for (int i = 1; i <= n; ++i) {
		T.rt[i] = T.rt[i - 1];
		for (int x : id[i]) T.update(T.rt[i], T.rt[i], 1, n, st[x], a[x]);
	}
	scanf("%d", &m);
	for (int lstans = 0; m--; ) {
		int x, k; scanf("%d%d", &x, &k);
		x = (x + lstans) % n +  1;
		k = (k + lstans) % n;
		printf("%d\n", lstans = T.query(T.rt[min(n, dep[x] + k)], 1, n, st[x], ed[x]));
	}
	return 0;
}