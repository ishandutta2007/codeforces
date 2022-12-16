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

const int maxn = 1e5 + 10;
const ll inf = 1e18;
struct mat {
	ll a[2][2];
	mat() { a[0][0] = a[1][1] = 0, a[1][0] = a[0][1] = inf; }
	friend mat operator * (mat p, mat q) {
		mat res;
		res.a[0][0] = min(p.a[0][0] + q.a[0][0], p.a[0][1] + q.a[1][0]);
		res.a[1][0] = min(p.a[1][0] + q.a[0][0], p.a[1][1] + q.a[1][0]);
		res.a[0][1] = min(p.a[0][0] + q.a[0][1], p.a[0][1] + q.a[1][1]);
		res.a[1][1] = min(p.a[1][0] + q.a[0][1], p.a[1][1] + q.a[1][1]);
		return res;
	}
} A[maxn];
struct SegTree {
	mat val[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void build(int rt, int l, int r) {
		if (l >= r) return val[rt] = A[l], void();
		build(ls, l, mid), build(rs, mid + 1, r), val[rt] = val[ls] * val[rs];
	}
	mat query(int rt, int l, int r, int L, int R) {
		if (L > R || L > r || R < l) return mat();
		if (L <= l && r <= R) return val[rt];
		return query(ls, l, mid, L, R) * query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
	#undef mid
} tr;

int n, q, dx[maxn][2], dy[maxn][2];
int dist(int sx, int sy, int ex, int ey) { return abs(sx - ex) + abs(sy - ey); }

int main() {
	read(n);
	for (int i = 1; i < n; ++i) read(dx[i][0], dy[i][0], dx[i][1], dy[i][1]);
	for (int i = 1; i < n - 1; ++i)
		for (int p = 0; p < 2; ++p)
			for (int q = 0; q < 2; ++q)
				A[i].a[p][q] = dist(dx[i][p] + (p == 0), dy[i][p] + (p == 1), dx[i + 1][q], dy[i + 1][q]) + 1;
	tr.build(1, 1, n - 2);
	read(q);
	while (q--) {
		int sx, sy, ex, ey, i, j;
		read(sx, sy, ex, ey);
		i = max(sx, sy), j = max(ex, ey);
		if (i == j) {
			write(dist(sx, sy, ex, ey), '\n');
			continue;
		}
		if (i > j) swap(sx, ex), swap(sy, ey), swap(i, j);
		mat st;
		st.a[0][0] = dist(sx, sy, dx[i][0], dy[i][0]);
		st.a[1][1] = dist(sx, sy, dx[i][1], dy[i][1]);
		st = st * tr.query(1, 1, n - 2, i, j - 2);
		ll res = inf;
		for (int p = 0; p < 2; ++p)
			res = min(res, min(st.a[0][p], st.a[1][p]) + dist(dx[j - 1][p] + (p == 0), dy[j - 1][p] + (p == 1), ex, ey) + 1);
		write(res, '\n');
	}
	return 0;
}