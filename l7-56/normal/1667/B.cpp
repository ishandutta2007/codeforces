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
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const int maxn = 5e5 + 10, inf = 1e9;
int n,a[maxn],f[maxn],d;
ll s[maxn];
vector <ll> S;
struct SegTree {
	struct dat {
		int x, y, z;
		dat() : x(-inf), y(-inf), z(-inf) {}
		dat(int x, int y, int z) : x(x), y(y), z(z) {}
		friend dat operator + (dat p, dat q) { return dat(max(p.x, q.x), max(p.y, q.y), max(p.z, q.z)); }
	}t[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(int rt) { t[rt] = t[ls] + t[rs]; }
	void build(int rt, int l, int r) {
		if (l == r) return t[rt] = dat(), void();
		build(ls, l, mid), build(rs, mid + 1, r), push_up(rt);
	}
	void update(int rt, int l, int r, int j) {
		if (l == r) {
			t[rt].x = max(t[rt].x, f[j] - j);
			t[rt].y = max(t[rt].y, f[j]);
			t[rt].z = max(t[rt].z, f[j] + j);
			return;
		}
		s[j] <= mid ? update(ls, l, mid, j) : update(rs, mid + 1, r, j); push_up(rt);
	}
	dat query(int rt, int l, int r, int L, int R) {
		if (L > r || R < l) return dat();
		if (L <= l && r <= R) return t[rt];
		return query(ls, l, mid, L, R) + query(rs, mid + 1, r, L, R);
	}
	#undef ls
	#undef rs
	#undef mid
}tr;
void work() {
	read(n);
	S.clear(), S.push_back(s[0] = 0);
	for (int i = 1; i <= n; ++i) read(a[i]), s[i] = s[i - 1] + a[i], S.push_back(s[i]);
	sort(S.begin(), S.end()), S.erase(unique(S.begin(), S.end()), S.end()), d = S.size();
	for (int i = 0; i <= n; ++i) s[i] = lower_bound(S.begin(), S.end(), s[i]) - S.begin() + 1;
	tr.build(1, 1, d), tr.update(1, 1, d, 0);
	for (int i = 1; i <= n; ++i) {
		SegTree :: dat pl = tr.query(1, 1, d, 1, s[i] - 1), pm = tr.query(1, 1, d, s[i], s[i]), pr = tr.query(1, 1, d, s[i] + 1, d);
		f[i] = max(max(pl.x + i, pm.y), pr.z - i), tr.update(1, 1, d, i);
	}
	write(f[n], '\n');
}

int main() {
	int T; read(T);
	while (T--) work();
	return 0;
}