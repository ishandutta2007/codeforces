#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double ld;
template <typename __Tp> void read(__Tp &x) {
	signed f = x = 0; char ch = getchar();
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

const ll maxn = 2e4 + 10;
ll n,k,a[maxn],st[maxn],tp,f[maxn],g[maxn];
struct line {
	ll k, b;
}t[maxn];
ll calc(ll i, ll x) { return t[i].k * x + t[i].b; }
struct SegTree {
	ll rt[maxn], ls[maxn << 5], rs[maxn << 5], c[maxn << 5], tot;
	#define mid ((l + r) >> 1)
	ll NEW(ll o) { return ls[++tot] = ls[o], rs[tot] = rs[o], c[tot] = c[o], tot; }
	void clr() { tot = 0, t[0].b = 1e9; }
	void insert(ll &o, ll l, ll r, ll id) {
		o = NEW(o);
		if (l == r) return calc(id, l) < calc(c[o], l) ? c[o] = id : 0, void();
		if (calc(id, mid) < calc(c[o], mid)) swap(id, c[o]);
		calc(id, l) < calc(c[o], l) ? insert(ls[o], l, mid, id) : insert(rs[o], mid + 1, r, id);
	}
	ll query(ll o, ll l, ll r, ll x) {
		if (l == r || !o) return calc(c[o], x);
		return min(calc(c[o], x), x <= mid ? query(ls[o], l, mid, x) : query(rs[o], mid + 1, r, x));
	}
	#undef mid
}tr;

struct convex {
	deque <ll> v;
	#define slope(i, j) ((ld) (g[j] - g[i]) / ((j) - (i)))
	void merge(convex &p) {
		if (p.v.size() > v.size()) {
			v.swap(p.v);
			ll t = v.size() - 1;
			for (ll x : p.v) {
				while (t > 0 && slope(v[t - 1], v[t]) >= slope(v[t], x)) v.pop_back(), --t;
				++t, v.push_back(x);
			}
		}
		else {
			reverse(p.v.begin(), p.v.end());
			for (ll x : p.v) {
				while (v.size() > 1 && slope(x, v[0]) >= slope(v[0], v[1])) v.pop_front();
				v.push_front(x);
			}
		}
		p.v.clear();
	}
	ll query(ll k) {
		ll l = 1, r = v.size() - 1, mid;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (slope(v[mid - 1], v[mid]) >= k) r = mid - 1;
			else l = mid + 1;
		}
		return g[v[l - 1]] - k * v[l - 1] + k;
	}
	#undef X
	#undef Y
	#undef chk
}h[maxn];

void solve(ll k) {
	tr.clr(); tp = 0;
	for (ll i = k; i <= n; ++i) {
		h[i].v = deque <ll> (1, i);
		while (tp && a[st[tp]] < a[i]) h[i].merge(h[st[tp--]]);
		t[i].k = a[i], t[i].b = h[i].query(a[i]);
		tr.rt[i] = tr.rt[st[tp]];
		tr.insert(tr.rt[i], 1, n, i);
		f[i + 1] = tr.query(tr.rt[i], 1, n, i);
		st[++tp] = i;
	}
}

signed main() {
	read(n, k);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	for (ll i = 1, mx = 0; i <= n; ++i) mx = max(mx, a[i]), f[i + 1] = i * mx;
	for (ll i = 2; i <= k; ++i) swap(f, g), solve(i);
	write(f[n + 1], '\n');
	return 0;
}