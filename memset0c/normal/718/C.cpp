// =================================
//   author: memset0
//   date: 2018.12.27 21:57:28
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)

namespace ringo {
typedef long long ll;
typedef unsigned long long ull;

template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 1e5 + 10, P = 1e9 + 7;
int n, m, a[N];

struct matrix { int a[2][2]; } one, base, pow[N];
inline matrix operator + (const matrix &a, const matrix &b) {
	return (matrix) {{{(a.a[0][0] + b.a[0][0]) % P, (a.a[0][1] + b.a[0][1]) % P},{0, 0}}};
}
inline matrix operator * (const matrix &a, const matrix &b) {
	return (matrix) {{{
		((ll)a.a[0][0] * b.a[0][0] + (ll)a.a[0][1] * b.a[1][0]) % P,
		((ll)a.a[0][0] * b.a[0][1] + (ll)a.a[0][1] * b.a[1][1]) % P}, {
		((ll)a.a[1][0] * b.a[0][0] + (ll)a.a[1][1] * b.a[1][0]) % P,
		((ll)a.a[1][0] * b.a[0][1] + (ll)a.a[1][1] * b.a[1][1]) % P
	}}};
}
inline matrix fpow(matrix a, ll b) {
    matrix s = {{{1, 0}, {0, 1}}};
    for (; b; b >>= 1, a = a * a) if (b & 1) s = s * a;
    return s;
}

struct node { int l, r, mid; matrix x, lazy; } p[N << 2];
inline bool check(const matrix &a) { return a.a[0][0] || a.a[0][1] || a.a[1][0] || a.a[1][1]; }
inline void pushup(int u, matrix x) { p[u].lazy = p[u].lazy * x, p[u].x = p[u].x * x; }
inline void pushdown(int u) { if (check(p[u].lazy) && p[u].l != p[u].r) pushup(u << 1, p[u].lazy), pushup(u << 1 | 1, p[u].lazy), p[u].lazy = one; }

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1, p[u].lazy = one;
	if (l == r) { p[u].x = (matrix){{{1, 0}, {0, 0}}} * fpow(base, a[l] - 1); return; }
	build(u << 1, l, p[u].mid), build(u << 1 | 1, p[u].mid + 1, p[u].r);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x;
}

void modify(int u, int l, int r, matrix x) {
	pushdown(u); if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else modify(u << 1, l, p[u].mid, x), modify(u << 1 | 1, p[u].mid + 1, r, x);
	p[u].x = p[u << 1].x + p[u << 1 | 1].x;
}

int query(int u, int l, int r) {
	pushdown(u); if (p[u].l == l && p[u].r == r) return p[u].x.a[0][0];
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return (query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r)) % P;
}

int calc(int x) {
	matrix temp;
	temp.a[0][0] = 1, temp.a[0][1] = temp.a[1][0] = temp.a[1][1] = 0;
	temp = temp * fpow(base, x);
	return temp.a[0][0];
}

void main() {
	read(n), read(m), base.a[0][0] = base.a[0][1] = base.a[1][0] = one.a[0][0] = one.a[1][1] = 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	build(1, 1, n);
	for (int i = 1, l, r, x, op; i <= m; i++) {
		read(op), read(l), read(r);
		if (op == 1) {
			read(x);
			if (x) modify(1, l, r, fpow(base, x));
		} else print(query(1, l, r), '\n');
	}
}

} signed main() { return ringo::main(), 0; }