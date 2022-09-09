#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

struct Edge {
	int u, v, next;
}G[N << 1];

int head[N], siz[N], tops[N], pre[N], top[N], fa[N], d[N], wson[N], w[N];
int n, m, root = 1, tot, cnt;

inline void addedge(int u, int v) {
	G[++tot] = (Edge) {u, v, head[u]}, head[u] = tot;
	G[++tot] = (Edge) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int f) {
	siz[u] = 1;
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == f) continue;
		d[v] = d[u] + 1; fa[v] = u;
		dfs1(v, u); siz[u] += siz[v];
		if(siz[v] > siz[wson[u]]) wson[u] = v;
	}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	tops[u] = ++cnt; pre[cnt] = u;
	if(wson[u]) dfs2(wson[u], tp);
	for(int i = head[u]; i; i = G[i].next) {
		int v = G[i].v;
		if(v == wson[u] || v == fa[u]) continue;
		dfs2(v, v);
	}
}

struct Node {
	int l, r;
	ll val, tag;
}p[N << 2];

void mdf(int u, ll x) {
	p[u].val += x * (ll)(p[u].r - p[u].l + 1);
	p[u].tag += x;
}

void update(int u) {
	p[u].val = p[u << 1].val + p[u << 1 | 1].val;
}

void pushdown(int u) {
	if(p[u].tag) {
		mdf(u << 1, p[u].tag);
		mdf(u << 1 | 1, p[u].tag);
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r;
	if(l == r) {
		p[u].val = w[pre[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	update(u);
}

void change(int u, int l, int r, int x) {
	if(l > r) return;
	if(p[u].l >= l && p[u].r <= r) {
		mdf(u, (ll)x);
		return;
	}
	pushdown(u);
	int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) change(u << 1, l, r, x);
	if(mid + 1 <= r) change(u << 1 | 1, l, r, x);
	update(u); 
}

ll query(int u, int l, int r) {
	if(l > r) return 0;
	if(p[u].l >= l && p[u].r <= r) return p[u].val;
	pushdown(u);
	ll ans = 0; int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) ans += query(u << 1, l, r);
	if(mid + 1 <= r) ans += query(u << 1 | 1, l, r);
	return ans;
}

int LCA(int x, int y) {
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return d[x] < d[y] ? x : y; 
}

int jump(int x, int y) {
	while(y) {
		int len = tops[x] - tops[top[x]] + 1;
//		fprintf(stderr, "DEBUG >>> len = %d\n", len);
		if(y <= len) return pre[tops[x] - y + 1];
		y -= len; x = fa[top[x]];
	}
//	throw "error : jump can't find the yth";
}

void mdf1(int x, int y, int val) {
	int t1 = LCA(x, y);
	int t2 = LCA(x, root);
	int t3 = LCA(y, root);
	int maxn = t1;
	maxn = d[maxn] > d[t2] ? maxn : t2;
	maxn = d[maxn] > d[t3] ? maxn : t3;
//	fprintf(stderr, "qwq >>> root = %d, x = %d, y = %d, LCA = %d\n", root, x, y, maxn);
	if(maxn == root) mdf(1, (ll)val);
	else if(LCA(maxn, root) != maxn) change(1, tops[maxn], tops[maxn] + siz[maxn] - 1, val);
	else {
		int t = jump(root, d[root] - d[maxn]);
		int l = tops[t], r = tops[t] + siz[t] - 1;
		change(1, 1, l - 1, val); change(1, r + 1, n, val);
	}
}

ll qry1(int x) {
//	fprintf(stderr, "DEBUG >>> x = %d, root = %d\n", x, root);
	if(x == root) return p[1].val;
	if(LCA(x, root) != x) return query(1, tops[x], tops[x] + siz[x] - 1);
	int t = jump(root, d[root] - d[x]);
//	fprintf(stderr, "DEBUG >>> root = %d, x = %d, jump(%d, %d) = %d\n", root, x, root, d[root] - d[x], t);
	int l = tops[t], r = tops[t] + siz[t] - 1;
//	fprintf(stderr, "DEBUG >>> root = %d, x = %d, t = %d, l = %d, r = %d\n", root, x, t, l, r);
	return query(1, 1, l - 1) + query(1, r + 1, n);
}

int main() {
	read(n); read(m);
	for(register int i = 1; i <= n; i++) read(w[i]);
	for(register int i = 1; i < n; i++) {
		int a, b; read(a); read(b);
		addedge(a, b);
	}
	dfs1(1, 0); dfs2(1, 1); build(1, 1, n);
	while(m--) {
		int opt; read(opt);
		if(opt == 1) read(root);
		if(opt == 2) {
			int a, b, c;
			read(a); read(b); read(c);
			mdf1(a, b, c);
		}
		if(opt == 3) {
			int a; read(a);
			print(qry1(a), '\n');
		}
	}
	return 0;
}