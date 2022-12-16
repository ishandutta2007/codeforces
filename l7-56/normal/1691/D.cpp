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

const int maxn = 2e5 + 10, inf = 1e9 + 10;
int n, a[maxn];
struct SegTree {
	struct node {
		ll sum, lmx, rmx;
		friend node merge(node a, node b) {
			node c;
			c.sum = a.sum + b.sum;
			c.lmx = max(a.lmx, a.sum + b.lmx);
			c.rmx = max(b.rmx, b.sum + a.rmx);
			return c;
		}
	} t[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { t[rt] = merge(t[ls], t[rs]); }
	void build(int rt, int l, int r) {
		if (l == r) return t[rt].sum = a[l], t[rt].lmx = t[rt].rmx = max(a[l], 0), void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	node query(int rt, int l, int r, int L, int R) {
		if (L > R || L > r || R < l) return {0, 0, 0};
		if (L <= l && r <= R) return t[rt];
		return merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int sta[maxn], tp, L[maxn], R[maxn];

void work() {
	read(n);
	for (int i = 1; i <= n; ++i) read(a[i]);
	tr.build(1, 1, n);
	a[sta[tp = 1] = 0] = inf;
	for (int i = 1; i <= n; ++i) {
		while (tp && a[sta[tp]] < a[i]) R[sta[tp--]] = i;
		L[i] = sta[tp], sta[++tp] = i;
	}
	while (tp) R[sta[tp--]] = n + 1;
	for (int i = 1; i <= n; ++i)
		if (tr.query(1, 1, n, L[i] + 1, i - 1).rmx
		+ a[i] + tr.query(1, 1, n, i + 1, R[i] - 1).lmx > a[i]) return write("NO\n");
	write("YES\n");
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}