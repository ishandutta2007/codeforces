#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
#define fir first
#define sec second
typedef tuple <int, int, int> piii;
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

const int maxn = 2e5 + 10, B = 30;
int n,m;
struct LB {
	int r[40];
	void ins(int x) {
		for (int bit = B; bit >= 0; --bit)
			if ((x >> bit) & 1) {
				if (r[bit]) x ^= r[bit];
				else return r[bit] = x, void();
			}
	}
	int query(int x) {
		for (int bit = B; bit >= 0; --bit) x = min(x, x ^ r[bit]);
		return x;
	}
} R;

struct DSU {
	int fa[maxn], siz[maxn], val[maxn], tp;
	pii sta[maxn];
	void init() {
		tp = 0;
		for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1, val[i] = 0;
	}
	pii get(int x) {
		if (fa[x] == x) return make_pair(0, x);
		pii p = get(fa[x]); return make_pair(p.fir ^ val[x], p.sec);
	}
	void merge(int x, int y, int z) {
		pii px = get(x), py = get(y);
		z ^= px.fir ^ py.fir;
		x = px.sec, y = py.sec;
		if (x == y) return;
		if (siz[x] < siz[y]) swap(x, y);
		fa[y] = x, siz[x] += siz[y], val[y] = z, sta[++tp] = {x, y};
	}
	void undo(int tar) {
		while (tp > tar) {
			pii p = sta[tp--];
			fa[p.sec] = p.sec, siz[p.fir] -= siz[p.sec], val[p.sec] = 0;
		}
	}
} T;

map <pii, pii> lst;
vector <piii> val[maxn << 2];
pii q[maxn];
int ans[maxn];
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)
void update(int rt, int l, int r, int L, int R, pii e, int w) {
	if (L > r || R < l) return;
	if (L <= l && r <= R) return val[rt].push_back(make_tuple(e.fir, e.sec, w)), void();
	update(ls, l, mid, L, R, e, w), update(rs, mid + 1, r, L, R, e, w);
}

void solve(int rt, int l, int r) {
	int tmp = T.tp; LB tmR = R;
	for (piii p : val[rt]) {
		int u, v, w; tie(u, v, w) = p;
		pii pu = T.get(u), pv = T.get(v);
		if (pu.sec != pv.sec) T.merge(u, v, w);
		else R.ins(pu.fir ^ pv.fir ^ w);
	}
	if (l == r) {
		if (q[l].fir)
			ans[l] = R.query(T.get(q[l].fir).fir ^ T.get(q[l].sec).fir);
	}
	else solve(ls, l, mid), solve(rs, mid + 1, r);
	T.undo(tmp), R = tmR;
}

int main() {
	read(n, m);
	for (int i = 1; i <= m; ++i) {
		pii t; int w; read(t.fir, t.sec, w);
		if (t.fir > t.sec) swap(t.fir, t.sec);
		lst[t] = {w, 0};
	}
	T.init();
	read(m);
	for (int i = 1; i <= m; ++i) {
		int op, w; pii p;
		read(op, p.fir, p.sec);
		if (p.fir > p.sec) swap(p.fir, p.sec);
		if (op == 1)
			read(w), lst[p] = {w, i};
		else if (op == 2) {
			pii o = lst[p]; lst.erase(p);
			update(1, 0, m, o.sec, i - 1, p, o.fir);
		}
		else q[i] = p;
	}
	for (auto pp : lst) {
		pii p = pp.fir, o = pp.sec;
		update(1, 0, m, o.sec, m, p, o.fir);
	}
	solve(1, 0, m);
	for (int i = 1; i <= m; ++i)
		if (q[i].fir) printf("%d\n", ans[i]);
	return 0;
}