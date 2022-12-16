#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 3e5 + 10, inf = 1e9 + 10;
struct Splay {
	struct node {
		ll son[2], fa, val, add;
	}tr[maxn];
	ll rt, tot;
	#define son(x, y) tr[x].son[y]
	#define fa(x) tr[x].fa
	#define val(x) tr[x].val
	#define add(x) tr[x].add
	ll NEW(ll v) {
		ll o = ++tot;
		son(o, 0) = son(o, 1) = fa(o) = add(o) = 0;
		val(o) = v;
		return tot;
	}
	void init() { rt = NEW(-inf), son(rt, 1) = NEW(inf), fa(2) = 1; }
	void tag(ll o, ll v) {
		if (!o) return;
		val(o) += v, add(o) += v;
	}
	void push_down(ll o) {
		if (add(o)) tag(son(o, 0), add(o)), tag(son(o, 1), add(o)), add(o) = 0;
	}
	ll get(ll x) { return x == son(fa(x), 1); }
	void rotate(ll x) {
		ll y = fa(x), z = fa(y), f1 = get(x), f2 = get(y);
		son(y, f1) = son(x, !f1);
		if (son(y, f1)) fa(son(y, f1)) = y;
		fa(y) = x, son(x, !f1) = y, fa(x) = z;
		if (z) son(z, f2) = x;
	}
	void splay(ll x, ll target = 0) {
		for (ll f = fa(x); f != target; rotate(x), f = fa(x))
			if (fa(f) != target) get(x) == get(f) ? rotate(f) : rotate(x);
		if (target == 0) rt = x;
	}
	void ins(ll &o, ll f, ll v) {
		if (!o) {
			o = NEW(v);
			fa(o) = f;
			splay(o);
			return;
		}
		push_down(o);
		if (v < val(o)) return ins(son(o, 0), o, v);
		else return ins(son(o, 1), o, v);
	}
	ll getpre(ll p) {
		ll res = 0;
		for (ll o = rt; o;) {
			push_down(o);
			if (val(o) < p) res = o, o = son(o, 1);
			else o = son(o, 0);
		}
		if (res) splay(res);
		return res;
	} // < p
	ll getnxt(ll p) {
		ll res = 0;
		for (ll o = rt; o;) {
			push_down(o);
			if (val(o) > p) res = o, o = son(o, 0);
			else o = son(o, 1);
		}
		if (res) splay(res);
		return res;
	} // > p
	void ADD(ll l, ll r) {
		ll x = getpre(l - 1), y = getpre(r);
		if (x == y) return;
		splay(x), splay(y, x);
		val(y)++;
		tag(son(y, 0), 1);
	}

	void del(ll x) {
		splay(x);
		ll y = son(x, 0), z = son(x, 1);
		if (!y || !z) return rt = y + z, fa(y + z) = 0, void();
		y = getpre(val(x));
		splay(x), splay(y, x);
		rt = y, fa(y) = 0, son(y, 1) = z, fa(z) = y;
	}
	void print(ll o) {
		if (!o) return;
		printf("%lld : %lld -> %lld -> %lld\n", o, val(o), son(o, 0), son(o, 1));
		push_down(o);
		print(son(o, 0)), print(son(o, 1));
	}
	#undef son
	#undef fa
	#undef val
	#undef add
}T;

ll n,ans;

int main() {
	T.init();
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) {
		// T.print(T.rt);
		ll l,r;
		scanf("%lld%lld", &l, &r);
		ll x = T.getnxt(r - 1);
		if (abs(T.tr[x].val) != inf) T.del(x), ans--;
		T.ADD(l, r);
		T.ins(T.rt, 0, l); ans++;
	}
	printf("%lld\n", ans);
	return 0;
}