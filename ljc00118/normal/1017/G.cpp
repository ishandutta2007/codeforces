#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
	while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
	f *= fu;
}

template <typename T>
void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 1e5 + 5;

struct ele {
	int sum, maxn;
	ele (int a = 0, int b = 0) : sum(a), maxn(b) {}
};

ele merge(ele a, ele b) { return ele(a.sum + b.sum, max(b.maxn, b.sum + a.maxn)); }

struct Node { int l, r, tag; ele val; } p[N << 2];

vector <int> adj[N];
int tops[N], top[N], fa[N], siz[N], wson[N], d[N], w[N], n, m, dfn;

void dfs1(int u) {
	siz[u] = 1;
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i]; d[v] = d[u] + 1; fa[v] = u; dfs1(v);
		siz[u] += siz[v]; if(siz[v] > siz[wson[u]]) wson[u] = v; 
	}
}

void dfs2(int u, int tp) {
	top[u] = tp; tops[u] = ++dfn;
	if(wson[u]) dfs2(wson[u], tp);
	for(register int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(v == wson[u]) continue;
		dfs2(v, v);
	}
}

void pushdown(int u) {
	if(p[u].tag) {
		p[u << 1].val = ele(-(p[u << 1].r - p[u << 1].l + 1), -1);
		p[u << 1 | 1].val = ele(-(p[u << 1 | 1].r - p[u << 1 | 1].l + 1), -1);
		p[u << 1].tag = p[u << 1 | 1].tag = 1;
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l; p[u].r = r;
	if(l == r) {
		p[u].val = ele(-1, -1);
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

void change(int u, int x, int y) {
	if(p[u].l == p[u].r) {
		p[u].val.sum += y;
		p[u].val.maxn += y;
		return;
	}
	pushdown(u); int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= x) change(u << 1, x, y);
	else change(u << 1 | 1, x, y);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
} // qwq

void _set(int u, int l, int r) {
	if(p[u].l >= l && p[u].r <= r) {
		p[u].tag = 1;
		p[u].val = ele(-(p[u].r - p[u].l + 1), -1);
		return;
	}
	pushdown(u); int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l) _set(u << 1, l, r);
	if(mid + 1 <= r) _set(u << 1 | 1, l, r);
	p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

ele query(int u, int l, int r) {
	if(p[u].l >= l && p[u].r <= r) return p[u].val;
	pushdown(u); int mid = (p[u].l + p[u].r) >> 1;
	if(mid >= l && mid + 1 <= r) return merge(query(u << 1, l, r), query(u << 1 | 1, l, r));
	else if(mid >= l) return query(u << 1, l, r); else return query(u << 1 | 1, l, r);
}

int main() {
	read(n); read(m);
	for(register int i = 2; i <= n; i++) {
		int t; read(t);
		adj[t].push_back(i);
	}
	dfs1(1); dfs2(1, 1); build(1, 1, n);
	for(register int i = 1; i <= m; i++) {
		int opt, x; read(opt); read(x);
		if(opt == 1) change(1, tops[x], 1);
		if(opt == 2) {
			ele ans; bool ok = 0; int tmp = x;
			_set(1, tops[x], tops[x] + siz[x] - 1);
			while(x) {
				ele now = query(1, tops[top[x]], tops[x]);
				if(!ok) ans = now, ok = 1; else ans = merge(now, ans);
				x = fa[top[x]];
			}
			change(1, tops[tmp], -ans.maxn - 1);
		}
		if(opt == 3) {
			ele ans; bool ok = 0;
			while(x) {
				ele now = query(1, tops[top[x]], tops[x]);
				if(!ok) ans = now, ok = 1; else ans = merge(now, ans);
				x = fa[top[x]];
			}
			if(ans.maxn >= 0) printf("black\n");
			else printf("white\n");
		}
	}
	return 0;
}