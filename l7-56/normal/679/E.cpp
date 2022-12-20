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

const ll maxn = 1e5 + 10, inf = 1e18;
int n, q, a[maxn];
ll pw42[10];
ll ask(ll x) { return *lower_bound(pw42, pw42 + 10, x) - x; }

struct SegTree {
	struct node {
		ll add, cov, mn;
		node() {}
		node(ll add, ll cov, ll mn) : add(add), cov(cov), mn(mn) {}
		friend node operator + (node a, node b) {
			if (a.cov && b.cov && a.cov == b.cov) return a;
			return node(0, 0, min(a.mn, b.mn));
		}
	} tr[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { tr[rt] = tr[ls] + tr[rs]; }
	void tagcov(int rt, ll c) { tr[rt] = node(0, c, ask(c)); }
	void tagadd(int rt, ll v) {
		if (tr[rt].cov) tr[rt].mn = ask(tr[rt].cov += v);
		else tr[rt].add += v, tr[rt].mn -= v;
	}
	void build(int rt, int l, int r) {
		if (l == r) return tagcov(rt, a[l]);
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void push_down(int rt) {
		if (tr[rt].cov) tagcov(ls, tr[rt].cov), tagcov(rs, tr[rt].cov);
		else if (tr[rt].add) tagadd(ls, tr[rt].add), tagadd(rs, tr[rt].add), tr[rt].add = 0;
	}
	void COV(int rt, int l, int r, int L, int R, ll v) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tagcov(rt, v);
		push_down(rt), COV(ls, l, mid, L, R, v), COV(rs, mid + 1, r, L, R, v), push_up(rt);
	}
	ll update(int rt, int l, int r, int L, int R, ll v) {
		if (L > r || R < l) return inf;
		if (L <= l && r <= R && (tr[rt].cov || tr[rt].mn >= v)) return tagadd(rt, v), tr[rt].mn;
		push_down(rt);
		ll res = min(update(ls, l, mid, L, R, v), update(rs, mid + 1, r, L, R, v));
		return push_up(rt), res;
	}
	ll query(int rt, int l, int r, int pos) {
		if (l == r) return tr[rt].cov;
		return push_down(rt), pos <= mid ? query(ls, l, mid, pos) : query(rs, mid + 1, r, pos);
	}
	#undef ls
	#undef rs
	#undef mid
} T;

int main() {
	pw42[0] = 1;
	for (int i = 1; i < 10; ++i) pw42[i] = pw42[i - 1] * 42;
	read(n, q);
	for (int i = 1; i <= n; ++i) read(a[i]);
	T.build(1, 1, n);
	while (q--) {
		int opt, l, r, x; read(opt, l);
		if (opt == 1) write(T.query(1, 1, n, l), '\n');
		else {
			read(r, x);
			if (opt == 2) T.COV(1, 1, n, l, r, x);
			else
				while (!T.update(1, 1, n, l, r, x));
		}
	}
	return 0;
}