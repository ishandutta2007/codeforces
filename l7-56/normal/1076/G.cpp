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

const int maxn = 2e5 + 10, maxs = 32;
int n,m,q,a[maxn],S;
struct node {
	int to[maxs];
	friend node merge(node a, node b) {
		node c;
		for (int i = 0; i <= S; ++i)
			c.to[i] = a.to[b.to[i]];
		return c;
	}
}e[2];

struct SegTree {
	node val[maxn << 2][2];
	int rev[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt][0] = merge(val[ls][0], val[rs][0]), val[rt][1] = merge(val[ls][1], val[rs][1]); }
	void build(int rt, int l, int r) {
		rev[rt] = 0;
		if (l == r) {
			val[rt][0] = e[a[l] & 1];
			val[rt][1] = e[(a[l] & 1) ^ 1];
			return;
		}
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void tag(int rt) { swap(val[rt][0], val[rt][1]), rev[rt] ^= 1; }
	void push_down(int rt) { if (rev[rt]) tag(ls), tag(rs), rev[rt] = 0; }
	void update(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt);
		push_down(rt), update(ls, l, mid, L, R), update(rs, mid + 1, r, L, R), push_up(rt);
	}
	node query(int rt, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[rt][0];
		push_down(rt);
		if (L > mid) return query(rs, mid + 1, r, L, R);
		if (R <= mid) return query(ls, l, mid, L, R);
		return merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
}tr;

int main() {
	read(n, m, q); S = (1 << m) - 1;
	for (int i = 0; i <= S; ++i)
		e[0].to[i] = ((i << 1) & S) | 1,
		e[1].to[i] = ((i << 1) & S) | (i != S);
	for (int i = 1; i <= n; ++i) read(a[i]);
	tr.build(1, 1, n);
	while (q--) {
		int opt, l, r, d; read(opt, l, r);
		if (opt == 1) {
			read(d);
			if (d & 1) tr.update(1, 1, n, l, r);
		}
		else {
			node p = tr.query(1, 1, n, l, r);
			if (p.to[S] & 1) write("1\n");
			else write("2\n");
		}
	}
	return 0;
}