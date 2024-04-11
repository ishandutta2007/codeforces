// LUOGU_RID: 92724622
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;
#define fir first
#define sec second
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

const int maxn = 3e5 + 10;
int n, fa[maxn], siz[maxn], dep[maxn], son[maxn], tp[maxn], dfn[maxn], idx, len[maxn], res;
vi e[maxn];
void dfs(int u) {
	dep[u] = dep[fa[u]] + 1, siz[u] = 1;
	for (int v : e[u]) {
		dfs(v), siz[u] += siz[v];
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}

void dfs2(int u, int t) {
	tp[u] = t, dfn[u] = ++idx;
	if (son[u]) dfs2(son[u], t);
	for (int v : e[u]) if (v != son[u]) dfs2(v, v);
}

struct node {
	int a, s[2], x[2];
	node() { a = s[0] = s[1] = x[0] = x[1] = 0; }
	node(int p, int q) { a = s[0] = x[0] = p, s[1] = x[1] = q; }
	pii get(int input) { return pii(x[input == a], s[input == a]); }
	friend node operator + (node p, node q) {
		node o;
		o.a = q.a;
		pii f = p.get(q.x[0]);
		o.x[0] = f.fir, o.s[0] = f.sec + q.s[0];
		f = p.get(q.x[1]);
		o.x[1] = f.fir, o.s[1] = f.sec + q.s[1];
		return o;
	}
};
struct SegTree {
	node val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt] = val[ls] + val[rs]; }
	node query(int rt, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[rt];
		if (L > mid) return query(rs, mid + 1, r, L, R);
		if (R <= mid) return query(ls, l, mid, L, R);
		return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	void update(int rt, int l, int r, int p, node v) {
		if (l == r) return val[rt] = v, void();
		p <= mid ? update(ls, l, mid, p, v) : update(rs, mid + 1, r, p, v), push_up(rt);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

pii query_sum(int t) {
	if (!len[t]) return {-1, 0};
	node p = tr.query(1, 1, n, dfn[t], dfn[t] + len[t] - 1);
	return p.get(-1);
}

struct SegTree2 {
	int rt[maxn], ls[maxn << 6], rs[maxn << 6], cnt[maxn << 6], siz[maxn << 6], tot;
	#define mid ((l + r) >> 1)
	void push_up(int o) { siz[o] = siz[ls[o]] + siz[rs[o]]; }
	void update(int &o, int l, int r, int p, int v) {
		if (p < l || p > r) return;
		if (!o) o = ++tot;
		if (l == r) return cnt[o] += v, siz[o] = (cnt[o] > 0), void();
		p <= mid ? update(ls[o], l, mid, p, v) : update(rs[o], mid + 1, r, p, v), push_up(o);
	}
	int query(int o, int l, int r, int L, int R) {
		if (L > r || R < l || L > R || siz[o] == r - l + 1) return -1;
		if (L <= l && r <= R) {
			if (!o || l == r) return l;
			if (siz[ls[o]] < mid - l + 1) return query(ls[o], l, mid, L, R);
			return query(rs[o], mid + 1, r, L, R);
		}
		int res = query(ls[o], l, mid, L, R);
		if (res == -1) res = query(rs[o], mid + 1, r, L, R);
		return res;
	}
	void print(int o) {
		if (!o) return;
		printf("%d -> %d %d : %d\n", o, ls[o], rs[o], siz[o]);
		print(ls[o]), print(rs[o]);
	}
	#undef mid
} tr2;
node query_node(int u) {
	int x = tr2.query(tr2.rt[u], 0, n + 1, 0, n + 1);
	int y = tr2.query(tr2.rt[u], 0, n + 1, x + 1, n + 1);
	// printf("%d : %d %d\n", u, x, y);
	return node(x, y);
}

void add(int u) {
	// printf("add %d:\n", u);
	pii p = query_sum(tp[u]);
	res -= p.sec;
	len[tp[u]]++;
	tr.update(1, 1, n, dfn[u], node(0, 1));
	pii q = query_sum(tp[u]);
	res += q.sec;
	u = tp[u];
	while (fa[u]) {
		// printf("%d %d -> %d\n", fa[u], p.fir, q.fir);
		tr2.update(tr2.rt[fa[u]], 0, n + 1, p.fir, -1);
		p = query_sum(tp[fa[u]]);
		res -= p.sec;
		tr2.update(tr2.rt[fa[u]], 0, n + 1, q.fir, 1);
		tr.update(1, 1, n, dfn[fa[u]], query_node(fa[u]));
		q = query_sum(tp[fa[u]]);
		res += q.sec;
		// printf("%d %d - %d %d\n", p.fir, p.sec, q.fir, q.sec);
		u = tp[fa[u]];
	}
}

int main() {
	read(n), ++n;
	for (int i = 2; i <= n; ++i) read(fa[i]), e[fa[i]].push_back(i);
	dfs(1), dfs2(1, 1);
	add(1);
	for (int i = 2; i <= n; ++i) add(i), write(res, '\n');
	return 0;
}