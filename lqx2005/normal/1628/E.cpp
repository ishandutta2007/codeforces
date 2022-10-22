#include <bits/stdc++.h>
#define x first
#define y second
#define sz(a) int((a).size())
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
using namespace std;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10, K = 20;
int top[N], siz[N], par[N], pre[N], dfn[N], id[N], dfc = 0, son[N], fa[N], dep[N];
int f[K][N], p2[K + 1], l2[N];
vector<pair<int, int>> e[N];
int read() {
	int f = 1, x = 0;
	char w = getchar();
	for(; !isdigit(w); w = getchar()) if(w == '-') f = -1;
	for(; isdigit(w); w = getchar()) x = x * 10 + w - '0';
	return f * x;
}
void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x == 0) {
		putchar('0');
		return;
	}
	static int num[38];
	int tot = 0;
	for(; x; num[++tot] = x % 10, x /= 10);
	for(int i = tot; i >= 1; i--) putchar('0' + num[i]);
	return;
}
void dfs1(int u, int fa, int cost) {
	::fa[u] = fa;
	pre[u] = par[u] = cost;
	dep[u] = dep[fa] + 1;
	siz[u] = 1;
	for(auto [v, w] : e[u]) {
		if(v == fa) continue;
		dfs1(v, u, w);
		if(siz[son[u]] < siz[v]) {
			son[u] = v;
		}
		siz[u] += siz[v];
	}
	return;
}
void dfs2(int u, int tp) {
	top[u] = tp;
	dfn[u] = ++dfc, id[dfc] = u;
	if(son[u]) pre[son[u]] = max(pre[son[u]], pre[u]), dfs2(son[u], tp);
	for(auto [v, w] : e[u]) {
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
	return;
}
int qry(int l, int r) {
	if(l > r) return -1;
	int t = l2[r - l + 1];
	return max(f[t][l], f[t][r - p2[t] + 1]);
}
int ask(int u, int v) {
	int mx = -1;
	for(; top[u] != top[v]; ) {
		if(dep[top[u]] < dep[top[v]]) swap(u, v);
		mx = max(mx, pre[u]);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v]) swap(u, v);
	mx = max(mx, qry(dfn[v] + 1, dfn[u]));
	return mx;
}
struct node {
	int l, r, mx;
	node() {l = r = 0, mx = -1; }
	node(int _l, int _r, int _mx) {l = _l, r = _r, mx = _mx; }
	friend node operator + (const node a, const node b) {
		if(!a.l) return b;
		if(!b.l) return a;
		return node(a.l, b.r, max(max(a.mx, b.mx), ask(a.r, b.l)));
	}
};
int n, q;
int tag[N << 1];
node a[N << 1], b[N << 1];
void build(int p, int l, int r) {
	a[p] = node(0, 0, -1);
	if(l == r) return b[p] = node(l, l, -1), void();
	build(ls, l, mid), build(rs, mid + 1, r);
	b[p] = b[ls] + b[rs];
	return;
}
void down(int p, int v) {
	if(v == -1) a[p] = node(0, 0, -1), tag[p] = -1;
	if(v == 1) a[p] = b[p], tag[p] = 1;
	return;
}
void pushd(int p, int l, int r) {
	down(ls, tag[p]), down(rs, tag[p]);
	tag[p] = 0;
}
void modify(int p, int l, int r, int L, int R, int v) {
	if(L <= l && r <= R) {
		down(p, v);
		return;
	}
	pushd(p, l, r);
	if(L <= mid) modify(ls, l, mid, L, R, v);
	if(R > mid) modify(rs, mid + 1, r, L, R, v);
	a[p] = a[ls] + a[rs];
	return;
}
void initST() {
	p2[0] = 1;
	for(int i = 1; i <= K; i++) p2[i] = p2[i - 1] << 1;
	l2[1] = 0;
	for(int i = 2; i <= n; i++) l2[i] = l2[i >> 1] + 1;
	for(int i = 1; i <= n; i++) f[0][i] = par[id[i]];
	for(int i = 1; i < K; i++) {
		for(int j = 1; j + p2[i] - 1 <= n; j++) {
			f[i][j] = max(f[i - 1][j], f[i - 1][j + p2[i - 1]]);
		}
	}
	return;
}
void solve() {
	n = read(), q = read();
	for(int i = 1; i < n; i++) {
		int u = read(), v = read(), w = read();
		e[u].eb(v, w), e[v].eb(u, w);
	}
	dfs1(1, 0, 0);
	dfs2(1, 1);
	initST();
	build(1, 1, n);
	for(int i = 1; i <= q; i++) {
		int opt = read(), l, r;
		if(opt == 1 || opt == 2) {
			l = read(), r = read();
			modify(1, 1, n, l, r, opt == 1 ? 1 : -1);
		} else {
			int x = read();
			node res = a[1];
			int mx = res.mx;
			if(res.l) mx = max(mx, max(ask(res.l, x), ask(res.r, x)));
			write(mx), putchar('\n');
		}
	}
	return;
}
int main() {
	solve();
	return 0;
}