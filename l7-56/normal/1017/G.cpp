#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
template <typename __Tp> void read(__Tp &x) {
	int f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
void read(char &ch) { for (ch = getchar(); isspace(ch); ch = getchar()); }
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (; *s; ++s) putchar(*s); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 1e5 + 10, inf = 1e9 + 10;
int n, q, fa[maxn], siz[maxn], hson[maxn], top[maxn], st[maxn], ed[maxn], idx;
vector <int> son[maxn];
void dfs1(int u) {
	siz[u] = 1, hson[u] = 0;
	for (int v : son[u]) {
		dfs1(v), siz[u] += siz[v];
		if (siz[hson[u]] < siz[v]) hson[u] = v;
	}
}

void dfs2(int u, int t) {
	st[u] = ++idx;
	top[u] = t;
	if (hson[u]) dfs2(hson[u], t);
	for (int v : son[u])
		if (v != hson[u]) dfs2(v, v);
	ed[u] = idx;
}

struct SegTree {
	int clr[maxn << 2];
	struct node {
		int rmx, sum;
		node() {}
		node(int rmx, int sum) : rmx(rmx), sum(sum) {}
		friend node operator + (node a, node b) {
			return node(max(a.rmx + b.sum, b.rmx), a.sum + b.sum);
		}
	} val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt] = val[ls] + val[rs]; }
	void tag(int rt, int l, int r) {
		val[rt] = node(-1, - (r - l + 1));
		clr[rt] = 1;
	}
	void push_down(int rt, int l, int r) {
		if (clr[rt]) tag(ls, l, mid), tag(rs, mid + 1, r), clr[rt] = 0;
	}
	void build(int rt, int l, int r) {
		if (l == r) return val[rt] = node(-1, -1), void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void update(int rt, int l, int r, int pos, int v) {
		if (l == r) return val[rt].sum += v, val[rt].rmx += v, void();
		push_down(rt, l, r), pos <= mid ? update(ls, l, mid, pos, v) : update(rs, mid + 1, r, pos, v); push_up(rt);
	}
	node query(int rt, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[rt];
		push_down(rt, l, r);
		if (L > mid) return query(rs, mid + 1, r, L, R);
		if (R <= mid) return query(ls, l, mid, L, R);
		return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	void clear(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, l, r);
		push_down(rt, l, r), clear(ls, l, mid, L, R), clear(rs, mid + 1, r, L, R), push_up(rt);
	}
	#undef ls
	#undef rs
	#undef mid
} T;

SegTree :: node query(int x) {
	SegTree :: node res(-inf, 0);
	while (x) {
		res = T.query(1, 1, idx, st[top[x]], st[x]) + res;
		x = fa[top[x]];
	}
	return res;
}

int main() {
	read(n, q);
	for (int i = 2; i <= n; ++i) read(fa[i]), son[fa[i]].push_back(i);
	dfs1(1), dfs2(1, 1);
	T.build(1, 1, idx);
	while (q--) {
		int opt, x; read(opt, x);
		if (opt == 1) T.update(1, 1, idx, st[x], 1);
		else if (opt == 2) {
			T.clear(1, 1, idx, st[x], ed[x]);
			T.update(1, 1, idx, st[x], - query(x).rmx - 1);
		}
		else {
			int w = query(x).rmx;
			if (w >= 0) write("black\n");
			else write("white\n");
		}
	}
	return 0;
}