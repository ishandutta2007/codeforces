#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 200005

int n, q;
int a[MAXN];

ll calc(ll x) {
	return x * (x + 1) / 2;
}

struct thing {
	ll l, r, lr, m, lx, rx;
};

thing merge(thing a, thing b) {
	thing res = {0, 0, 0, 0, a.lx, b.rx};
	res.l = a.l;
	res.r = b.r;
	if (a.rx <= b.lx) {
		if (a.lr != 0) mxto(res.l, a.lr + max(b.l, b.lr));
		if (b.lr != 0) mxto(res.r, b.lr + max(a.r, a.lr));
		if (a.lr != 0 && b.lr != 0) {
			res.l = 0; res.r = 0;
			res.lr = a.lr + b.lr;
		}
		res.m = a.m + b.m;
		if (a.lr == 0 && b.lr == 0) {
			res.m += calc(a.r + b.l);
		}
	} else {
		mxto(res.l, a.lr);
		mxto(res.r, b.lr);
		res.lr = 0;
		res.m = a.m + b.m + calc(a.r) + calc(b.l);
	}
	return res;
}

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
thing v[MAXN * 4];
void upset(int i, int x, int u = 1, int lo = 1, int hi = n) {
	if (lo == hi) {
		v[u] = {0, 0, 1, 0, x, x};
		return;
	}
	MLR;
	if (i <= mid) {
		upset(i, x, lc, lo, mid);
	} else {
		upset(i, x, rc, mid + 1, hi);
	}
	v[u] = merge(v[lc], v[rc]);
	debug("%d %d: %lld %lld %lld %lld\n", lo, hi, v[u].l, v[u].r, v[u].lr, v[u].m);
}
thing query(int s, int e, int u = 1, int lo = 1, int hi = n) {
	if (lo >= s && hi <= e) {
		return v[u];
	}
	MLR;
	if (e <= mid) {
		return query(s, e, lc, lo, mid);
	} else if (s > mid) {
		return query(s, e, rc, mid + 1, hi);
	} else {
		return merge(query(s, e, lc, lo, mid), query(s, e, rc, mid + 1, hi));
	}
}

int main() {
	scanf("%d%d", &n, &q);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
		upset(i, a[i]);
	}
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int x, y; scanf("%d%d", &x, &y);
			upset(x, y);
		} else if (t == 2) {
			int l, r; scanf("%d%d", &l, &r);
			thing res = query(l, r);
			printf("%lld\n", calc(res.l) + calc(res.r) + calc(res.lr) + res.m);
		}
	}
	return 0;
}