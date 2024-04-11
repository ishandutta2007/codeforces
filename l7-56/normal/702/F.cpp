#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10, inf = 3e18;
ll n,m,val[maxn],cnt[maxn];
struct Splay {
	struct node {
		ll son[2], fa, add1, add2;
	}tr[maxn];
	ll rt;
	#define son(x, y) tr[x].son[y]
	#define fa(x) tr[x].fa
	#define val(x) val[x]
	#define cnt(x) cnt[x]
	#define add1(x) tr[x].add1
	#define add2(x) tr[x].add2
	ll get(ll x) { return x == son(fa(x), 1); }
	void rotate(ll x) {
		ll y = fa(x), z = fa(y), f1 = get(x), f2 = get(y);
		son(y, f1) = son(x, !f1), son(x, !f1) = y;
		if (son(y, f1)) fa(son(y, f1)) = y;
		fa(y) = x, fa(x) = z;
		if (z) son(z, f2) = x;
	}
	void splay(ll x, ll tar = 0) {
		for (ll f = fa(x); f != tar; rotate(x), f = fa(x))
			if (fa(f) != tar) rotate(get(x) == get(f) ? f : x);
		if (tar == 0) rt = x;
	}
	void tag(ll o, ll val1, ll val2) {
		if (!o) return;
		val(o) += val1, cnt(o) += val2;
		add1(o) += val1, add2(o) += val2;
	}
	void push_down(ll o) {
		tag(son(o, 0), add1(o), add2(o));
		tag(son(o, 1), add1(o), add2(o));
		add1(o) = add2(o) = 0;
	}
	ll getpre(ll x) {
		ll res = 0;
		for (ll o = rt; o;) {
			push_down(o);
			if (val(o) < x) res = o, o = son(o, 1);
			else o = son(o, 0);
		}
		if (res) splay(res);
		return res;
	}
	ll getnxt(ll x) {
		ll res = 0;
		for (ll o = rt; o;) {
			push_down(o);
			if (val(o) > x) res = o, o = son(o, 0);
			else o = son(o, 1);
		}
		if (res) splay(res);
		return res;
	}
	void ins(ll &o, ll f, ll i) {
		if (!o) {
			o = i, fa(o) = f;
			son(o, 0) = son(o, 1) = 0;
			splay(o); return;
		}
		push_down(o);
		if (val(o) > val(i)) ins(son(o, 0), o, i);
		else ins(son(o, 1), o, i);
	}
	void build() {
		for (ll i = 1; i <= m; ++i) ins(rt, 0, i);
		val[m + 1] = -inf, ins(rt, 0, m + 1);
		val[m + 2] = inf, ins(rt, 0, m + 2);
	}
	void rei(ll o) {
		if (!o) return;
		push_down(o), rei(son(o, 0)), rei(son(o, 1)), ins(rt, 0, o);
	}
	void print(ll o) {
		if (!o) return;
		push_down(o);
		printf("%lld : %lld %lld -> %lld -> %lld | %lld\n", o, val(o), cnt(o), son(o, 0), son(o, 1), fa(o));
		print(son(o, 0)), print(son(o, 1));
	}
	void work(ll c) {
		ll x = getpre(c), y = getnxt(2 * c - 1);
		splay(x), splay(y, x), tag(y, -c, 1), push_down(y);
		ll z = son(y, 0); son(y, 0) = 0, rei(z);
	}
	void dfs(int o) {
		if (!o) return;
		push_down(o), dfs(son(o, 0)), dfs(son(o, 1));
	}
	#undef son
	#undef fa
	#undef val
	#undef cnt
	#undef add1
	#undef add2
}T;

struct obj {
	ll c, q;
	friend bool operator < (obj x, obj y) { return x.q == y.q ? x.c < y.c : x.q > y.q; }
}a[maxn];

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld%lld", &a[i].c, &a[i].q);
	sort(a + 1, a + n + 1);
	scanf("%lld", &m);
	for (ll i = 1; i <= m; ++i) scanf("%lld", &val[i]);
	T.build();
	for (ll i = 1; i <= n; ++i) T.work(a[i].c);
	T.dfs(T.rt);
	for (ll i = 1; i <= m; ++i) printf("%lld%c", cnt[i], " \n"[i == m]);
	return 0;
}