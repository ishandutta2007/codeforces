#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
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

const int maxn = 3e5 + 10, inf = 1e9;
int n, a[maxn];
pii merge(pii a, pii b) {
	if (a.fir != b.fir) return min(a, b);
	return {a.fir, a.sec + b.sec};
}
struct SegTree {
	pii val[maxn << 2]; int add[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { val[rt] = merge(val[ls], val[rs]); }
	void build(int rt, int l, int r) {
		if (l == r) return val[rt] = {0, 1}, void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void tag(int rt, int v) { val[rt].fir += v, add[rt] += v; }
	void push_down(int rt) { if (add[rt]) tag(ls, add[rt]), tag(rs, add[rt]), add[rt] = 0; }
	void update(int rt, int l, int r, int L, int R, int v) {
		if (L > R || L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, v);
		push_down(rt), update(ls, l, mid, L, R, v), update(rs, mid + 1, r, L, R, v), push_up(rt);
	}
	pii query(int rt, int l, int r, int L, int R) {
		if (L > R || L > r || R < l) return {inf, 0};
		if (L <= l && r <= R) return val[rt];
		return push_down(rt), merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int mns[maxn], tmn, mxs[maxn], tmx;

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) {
		int x, y; read(x, y);
		a[x] = y;
	}
	tr.build(1, 1, n);
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		tr.update(1, 1, n, 1, i, -1);
		while (tmn && a[mns[tmn]] > a[i])
			tr.update(1, 1, n, mns[tmn - 1] + 1, mns[tmn], a[mns[tmn]] - a[i]), --tmn;
		mns[++tmn] = i;
		while (tmx && a[mxs[tmx]] < a[i])
			tr.update(1, 1, n, mxs[tmx - 1] + 1, mxs[tmx], a[i] - a[mxs[tmx]]), --tmx;
		mxs[++tmx] = i;
		pii p = tr.query(1, 1, n, 1, i);
		if (p.fir == -1) ans += p.sec;
	}
	write(ans, '\n');
	return 0;
}