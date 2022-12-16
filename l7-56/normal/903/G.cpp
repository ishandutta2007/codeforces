#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pii;
template <typename __Tp> void read(__Tp &x) {
	ll f = x = 0; char ch = getchar();
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

const ll maxn = 2e5 + 10;
ll n,m,q,val[maxn],wa[maxn],wb[maxn];
vector <pii> to[maxn];
struct SegTree {
	ll mn[maxn << 2], add[maxn << 2];
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) >> 1)
	void push_up(ll rt) { mn[rt] = min(mn[ls], mn[rs]); }
	void build(ll rt, ll l, ll r, ll *a) {
		add[rt] = 0;
		if (l == r) return mn[rt] = a[l], void();
		build(ls, l, mid, a), build(rs, mid + 1, r, a), push_up(rt);
	}
	void tag(ll rt, ll v) { add[rt] += v, mn[rt] += v; }
	void push_down(ll rt) { if (add[rt]) tag(ls, add[rt]), tag(rs, add[rt]), add[rt] = 0; }
	void ADD(ll rt, ll l, ll r, ll L, ll R, ll v) {
		if (L > r || R < l) return;
		if (L <= l && r <= R) return tag(rt, v);
		push_down(rt); ADD(ls, l, mid, L, R, v), ADD(rs, mid + 1, r, L, R, v); push_up(rt);
	}
	#undef ls
	#undef rs
	#undef mid
}T;

int main() {
	read(n, m, q);
	for (ll i = 1; i < n; ++i) read(wa[i], wb[i + 1]);
	for (ll i = 1; i <= m; ++i) {
		ll x, y, w; read(x, y, w);
		to[x].push_back({y, w});
	}
	T.build(1, 1, n, wb);
	for (ll i = 1; i <= n; ++i) {
		for (pii e : to[i]) T.ADD(1, 1, n, 1, e.first, e.second);
		val[i] = T.mn[1] + wa[i];
	}
	T.build(1, 1, n, val);
	write(T.mn[1], '\n');
	while (q--) {
		ll i, w; read(i, w);
		T.ADD(1, 1, n, i, i, w - wa[i]);
		write(T.mn[1], '\n'), wa[i] = w;
	}
	return 0;
}