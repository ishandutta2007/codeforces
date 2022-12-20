#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <pii> vp;
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

const int maxn = 2e5 + 10;
int n, m, P, a[maxn];
vp merge(vp a, vp b) {
	int mn;
	vp c;
	for (pii p : a) {
		for (pii &q : b)
			if (p.fir == q.fir) { q.sec += p.sec; goto done; }
		b.push_back(p);
		if ((int) b.size() <= 100 / P) goto done;
		mn = n, c.clear();
		for (pii q : b) mn = min(mn, q.sec);
		for (pii q : b) {
			if (q.sec == mn) continue;
			c.push_back({q.fir, q.sec - mn});
		}
		b.swap(c);
		done : ;
	}
	return b;
}
struct SegTree {
	vp val[maxn << 2]; int cov[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt] = merge(val[ls], val[rs]); }
	void tag(int rt, int l, int r, int c) {
		cov[rt] = c, val[rt].clear(), val[rt].push_back({c, r - l + 1});
	}
	void build(int rt, int l, int r) {
		if (l == r) return tag(rt, l, r, a[l]);
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void push_down(int rt, int l, int r) {
		if (cov[rt]) tag(ls, l, mid, cov[rt]), tag(rs, mid + 1, r, cov[rt]), cov[rt] = 0;
	}
	void COV(int rt, int l, int r, int L, int R, int c) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, l, r, c);
		push_down(rt, l, r), COV(ls, l, mid, L, R, c), COV(rs, mid + 1, r, L, R, c), push_up(rt);
	}
	vp query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return vp();
		if (L <= l && r <= R) return val[rt];
		return push_down(rt, l, r), merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
} T;

int main() {
	read(n, m, P);
	for (int i = 1; i <= n; ++i) read(a[i]);
	T.build(1, 1, n);
	while (m--) {
		int opt, l, r, x;
		read(opt, l, r);
		if (opt == 1) read(x), T.COV(1, 1, n, l, r, x);
		else {
			vp v = T.query(1, 1, n, l, r);
			write(v.size());
			for (pii p : v) write(' ', p.fir);
			write('\n');
		}
	}
	return 0;
}