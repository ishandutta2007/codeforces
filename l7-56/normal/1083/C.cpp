#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 1e6 + 10;
int n, q, p[maxn], pos[maxn], fa[maxn], dep[maxn], st[maxn], ed[maxn], tim, id[maxn], idx;
struct ST {
	pii mn[maxn][20];
	int lg[maxn];
	void build() {
		lg[0] = -1;
		for (int i = 1; i <= idx; ++i) mn[i][0] = {dep[id[i]], id[i]}, lg[i] = lg[i >> 1] + 1;
		for (int j = 1; j < 20; ++j)
			for (int i = 1; i + (1 << j) <= idx; ++i)
				mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
	}
	pii ask(int l, int r) {
		int i = lg[r - l + 1];
		return min(mn[l][i], mn[r - (1 << i) + 1][i]);
	}
} lolipop;
vi son[maxn];

void dfs(int u) {
	id[++idx] = u;
	st[u] = idx;
	dep[u] = dep[fa[u]] + 1;
	for (int v : son[u]) dfs(v), id[++idx] = u;
	ed[u] = idx;
}

int lca(int x, int y) {
	int l = st[x], r = st[y];
	if (l > r) swap(l, r);
	return lolipop.ask(l, r).sec;
}

bool isanc(int x, int y) { return st[x] <= st[y] && st[y] <= ed[x]; }
int dist(int x, int y) { return dep[x] + dep[y] - dep[lca(x, y)] * 2; }

pii merge(pii p, int z) {
	if (p.fir == -1) return {-1, -1};
	int x = p.fir, y = p.sec, d1 = dist(x, y), d2 = dist(x, z), d3 = dist(y, z);
	if (d1 + d2 == d3) return {y, z};
	if (d1 + d3 == d2) return {x, z};
	if (d2 + d3 == d1) return {x, y};
	return {-1, -1};
}

pii merge(pii pa, pii pb) {
	if (pa.fir == -1 || pb.fir == -1) return {-1, -1};
	if (pa.fir == -2) return pb;
	if (pb.fir == -2) return pa;
	return merge(merge(pb, pa.fir), pa.sec);
}

struct SegTree {
	pii val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt] = merge(val[ls], val[rs]); }
	void build(int rt, int l, int r) {
		if (l == r) return val[rt] = {pos[l], pos[l]}, void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void update(int rt, int l, int r, int p, int v) {
		if (l == r) return val[rt] = {v, v}, void();
		p <= mid ? update(ls, l, mid, p, v) : update(rs, mid + 1, r, p, v); push_up(rt);
	}
	int query(int rt, int l, int r, pii path) {
		if (l == r) return l;
		pii np = merge(path, val[ls]);
		if (np.fir == -1) return query(ls, l, mid, path);
		return query(rs, mid + 1, r, np);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]), pos[p[i]] = i;
	for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]), son[fa[i]].push_back(i);
	dfs(1), lolipop.build();
	pos[n] = -1;
	tr.build(1, 0, n);
	scanf("%d", &q);
	while (q--) {
		int t, x, y;
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d", &x, &y);
			tr.update(1, 0, n, p[x], y);
			tr.update(1, 0, n, p[y], x);
			swap(p[x], p[y]);
		}
		else printf("%d\n", tr.query(1, 0, n, {-2, -2}));
	}
	return 0;
}