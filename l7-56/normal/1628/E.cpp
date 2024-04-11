#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 3e5 + 10;
int n,q;
struct KruskalTree {
	struct Edge1 {
		int u,v,w;
		friend bool operator < (Edge1 x, Edge1 y) { return x.w < y.w; }
	}e1[maxn];
	int cnt_e, val[maxn << 1], ls[maxn << 1], rs[maxn << 1], tot, fa[maxn << 1];
	void add(int x, int y, int z) { e1[++cnt_e] = {x, y, z}; }
	int get(int x) { return x == fa[x] ? x : fa[x] = get(fa[x]); }
	int dep[maxn << 1], f[maxn << 1][21], dfn[maxn << 1], id[maxn << 1], idx;
	void dfs(int u, int pre) {
		if (!u) return;
		dep[u] = dep[pre] + 1;
		f[u][0] = pre;
		for (int i = 1; i <= 20; ++i) f[u][i] = f[f[u][i - 1]][i - 1];
		dfn[u] = ++idx, id[idx] = u;
		dfs(ls[u], u), dfs(rs[u], u);
	}
	void build() {
		sort(e1 + 1, e1 + cnt_e + 1);
		tot = n;
		for (int i = 1; i <= tot; ++i) fa[i] = i, val[i] = -1;
		for (int i = 1; i <= cnt_e; ++i) {
			int u = e1[i].u, v = e1[i].v, w = e1[i].w;
			u = get(u), v = get(v);
			if (u == v) continue;
			val[++tot] = w;
			ls[tot] = u, rs[tot] = v;
			fa[u] = fa[v] = fa[tot] = tot;
		}
		dfs(tot, 0);
	}
	void print(int u) {
		if (!u) return;
		printf("#%d %d : %d -> %d -> %d\n", dfn[u], u, val[u], ls[u], rs[u]);
		print(ls[u]), print(rs[u]);
	}
	int lca(int x, int y) {
		if (dep[x] < dep[y]) swap(x, y);
		for (int i = 20; i >= 0; --i)
			if (dep[x] - dep[y] >= (1 << i)) x = f[x][i];
		if (x == y) return x;
		for (int i = 20; i >= 0; --i)
			if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
		return f[x][0];
	}
	int query(int x, int y) { return val[lca(x, y)]; }
}T1;

struct SegTree {
	struct node {
		int mx,mn,rmx,rmn,siz,cov;
	}tr[maxn << 2];
	#define mx(x) tr[x].mx
	#define mn(x) tr[x].mn
	#define rmx(x) tr[x].rmx
	#define rmn(x) tr[x].rmn
	#define siz(x) tr[x].siz
	#define cov(x) tr[x].cov
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	void push_up(int rt) {
		mx(rt) = max(mx(ls), mx(rs));
		mn(rt) = min(mn(ls), mn(rs));
		rmx(rt) = max(rmx(ls), rmx(rs));
		rmn(rt) = min(rmn(ls), rmn(rs));
		siz(rt) = siz(ls) + siz(rs);
	}
	void build(int rt, int l, int r) {
		cov(rt) = -1;
		if (l == r) {
			mx(rt) = mn(rt) = T1.dfn[l];
			rmx(rt) = 0, rmn(rt) = T1.idx + 1;
			siz(rt) = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		push_up(rt);
	}
	void tag(int rt, int l, int r, int val) {
		cov(rt) = val;
		siz(rt) = (r - l + 1) * val;
		if (val) rmx(rt) = mx(rt), rmn(rt) = mn(rt);
		else rmx(rt) = 0, rmn(rt) = T1.idx + 1;
	}
	void push_down(int rt, int l, int r) {
		if (cov(rt) == -1) return;
		int mid = (l + r) >> 1;
		tag(ls, l, mid, cov(rt)), tag(rs, mid + 1, r, cov(rt));
		cov(rt) = -1;
	}
	void update(int rt, int l, int r, int L, int R, int val) {
		if (L <= l && r <= R) return tag(rt, l, r, val);
		int mid = (l + r) >> 1; push_down(rt, l, r);
		if (L <= mid) update(ls, l, mid, L, R, val);
		if (R > mid) update(rs, mid + 1, r, L, R, val);
		push_up(rt);
	}
	#undef mx
	#undef mn
	#undef rmx
	#undef rmn
	#undef siz
	#undef cov
	#undef ls
	#undef rs
}T2;

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		T1.add(x, y, z);
	}
	T1.build();
	// T1.print(T1.tot);
	T2.build(1, 1, n);
	while (q--) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int l, r;
			scanf("%d%d", &l, &r);
			T2.update(1, 1, n, l, r, 1);
		}
		else if (op == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			T2.update(1, 1, n, l, r, 0);
		}
		else {
			int x, y = T2.tr[1].rmx, z = T2.tr[1].rmn;
			scanf("%d", &x);
			if (!y) printf("-1\n");
			else printf("%d\n", max(T1.query(T1.id[y], x), T1.query(T1.id[z], x)));
		}
	}
	return 0;
}