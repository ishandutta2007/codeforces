#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second

const int maxn = 1e5 + 10;
int n, m, o, fa[maxn], siz[maxn], dep[maxn], hson[maxn], top[maxn], dfn[maxn], id[maxn], idx;
vector <int> son[maxn];
void dfs1(int u) {
	dep[u] = dep[fa[u]] + 1, siz[u] = 1;
	for (int v : son[u]) {
		dfs1(v), siz[u] += siz[v];
		if (siz[hson[u]] < siz[v]) hson[u] = v;
	}
}

void dfs2(int u, int t) {
	top[u] = t;
	id[dfn[u] = ++idx] = u;
	if (hson[u]) dfs2(hson[u], t);
	for (int v : son[u])
		if (v != hson[u]) dfs2(v, v);
}

struct SegTree {
	int cnt[maxn << 5], tot, ls[maxn << 5], rs[maxn << 5];
	#define mid ((l + r) >> 1)
	void push_up(int p) { cnt[p] = cnt[ls[p]] + cnt[rs[p]]; }
	void build(int &p, int l, int r) {
		p = ++tot, cnt[p] = 0;
		if (l == r) return;
		build(ls[p], l, mid), build(rs[p], mid + 1, r);
	}
	void update(int &p, int q, int l, int r, int pos) {
		p = ++tot, ls[p] = ls[q], rs[p] = rs[q];
		if (l == r) return ++cnt[p], void();
		pos <= mid ? update(ls[p], ls[q], l, mid, pos) : update(rs[p], rs[q], mid + 1, r, pos), push_up(p);
	}
	int query(int p, int l, int r, int L, int R) {
		if (!p || L > R || L > r || R < l) return 0;
		if (L <= l && r <= R) return cnt[p];
		return query(ls[p], l, mid, L, R) + query(rs[p], mid + 1, r, L, R);
	}
	#undef mid
} tr;
int rt[maxn];

int query_sum(int el, int er, int l, int r) {
	return r - l + 1 - tr.query(rt[er], 1, n, l, r) + tr.query(rt[el], 1, n, l, r);
}

pii lca(int x, int y, int el, int er) {
	int res = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		res += query_sum(el, er, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	if (dep[x] < dep[y]) swap(x, y);
	res += query_sum(el, er, dfn[y], dfn[x]);
	return make_pair(y, res);
}
int query_chain(int a, int b, int k, int el, int er) {
	int L = dfn[b], R = dfn[a];
	int l = L, r = R, mid, ans = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (query_sum(el, er, mid, R) >= k) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans == -1 ? -1 : id[ans];
}
int query_anc(int a, int b, int k, int el, int er) {
	while (top[a] != top[b]) {
		int sum = query_sum(el, er, dfn[top[a]], dfn[a]);
		if (sum >= k) return query_chain(a, top[a], k, el, er);
		k -= sum, a = fa[top[a]];
	}
	return query_chain(a, b, k, el, er);
}
int query(int a, int b, int k, int el, int er) {
	k += query_sum(el, er, dfn[a], dfn[a]);
	int c = lca(a, b, el, er).fir;
	int sum = lca(a, c, el, er).sec - query_sum(el, er, dfn[c], dfn[c]);
	if (sum >= k) return query_anc(a, c, k, el, er);
	k -= sum, sum = lca(c, b, el, er).sec;
	if (sum - query_sum(el, er, dfn[b], dfn[b]) >= k) return query_anc(b, c, sum + 1 - k, el, er);
	return -1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &fa[i]);
		if (fa[i]) son[fa[i]].push_back(i);
		else o = i;
	}
	dfs1(o), dfs2(o, o);
	tr.build(rt[0], 1, n);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int opt, a, b, k, y;
		scanf("%d%d", &opt, &a);
		if (opt == 1) tr.update(rt[i], rt[i - 1], 1, n, dfn[a]);
		else rt[i] = rt[i - 1], scanf("%d%d%d", &b, &k, &y), printf("%d\n", query(a, b, k, y, i));
	}
	return 0;
}