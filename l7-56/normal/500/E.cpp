#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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
int n, q, x[maxn], h[maxn], to[maxn], f[20][maxn], g[20][maxn];
struct SegTree {
	int mx[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { mx[rt] = max(mx[ls], mx[rs]); }
	void update(int rt, int l, int r, int pos, int val) {
		if (l == r) return mx[rt] = val, void();
		pos <= mid ? update(ls, l, mid, pos, val) : update(rs, mid + 1, r, pos, val), push_up(rt);
	}
	int query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l || L > R) return 0;
		if (L <= l && r <= R) return mx[rt];
		return max(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int main() {
	read(n);
	for (int i = 1; i <= n; ++i) read(x[i], h[i]);
	x[n + 1] = 1000000001;
	for (int i = n; i >= 1; --i) {
		int pos = upper_bound(x + 1, x + n + 1, x[i] + h[i]) - x - 1;
		to[i] = max(tr.query(1, 1, n, i + 1, pos), x[i] + h[i]);
		tr.update(1, 1, n, i, to[i]);
		pos = upper_bound(x + 1, x + n + 1, to[i]) - x;
		f[0][i] = pos, g[0][i] = x[pos] - to[i];
	}
	for (int i = 0; i < 20; ++i) f[i][n + 1] = n + 1;
	for (int i = 1; i < 20; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = f[i - 1][f[i - 1][j]],
			g[i][j] = min(1000000000, g[i - 1][j] + g[i - 1][f[i - 1][j]]);
	read(q);
	while (q--) {
		int l, r; read(l, r);
		int ans = 0;
		for (int i = 19; i >= 0; --i)
			if (f[i][l] <= r) ans += g[i][l], l = f[i][l];
		write(ans, '\n');
	}
	return 0;
}