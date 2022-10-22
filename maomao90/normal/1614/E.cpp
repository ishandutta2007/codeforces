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
#define MOD 1000000001
#define MAXN 200005

int n;
int ans;

int ptr = 1;
int v[MAXN * 65], lz[MAXN * 65], lc[MAXN * 65], rc[MAXN * 65];
inline void makeChild(int u, int lo, int hi) {
	if (lo == hi || lc[u] != 0) return;
	lc[u] = ptr++;
	rc[u] = ptr++;
	int mid = lo + hi >> 1;
	v[lc[u]] = mid;
	v[rc[u]] = hi;
}
inline void propo(int u, int lo, int hi) {
	if (lo == hi || lz[u] == 0) return;
	v[lc[u]] += lz[u];
	v[rc[u]] += lz[u];
	lz[lc[u]] += lz[u];
	lz[rc[u]] += lz[u];
	lz[u] = 0;
}
void incre(int s, int e, int x, int u = 0, int lo = 0, int hi = INF) {
	mxto(s, 0);
	mnto(e, INF);
	if (s > e) return;
	if (lo >= s && hi <= e) {
		v[u] += x;
		lz[u] += x;
		return;
	}
	makeChild(u, lo, hi);
	propo(u, lo, hi);
	int mid = lo + hi >> 1;
	if (s <= mid) {
		incre(s, e, x, lc[u], lo, mid);
	}
	if (e > mid) {
		incre(s, e, x, rc[u], mid + 1, hi);
	}
	v[u] = max(v[lc[u]], v[rc[u]]);
}
int query(int p, int u = 0, int lo = 0, int hi = INF) {
	if (lo == hi) {
		return v[u];
	}
	makeChild(u, lo, hi);
	propo(u, lo, hi);
	int mid = lo + hi >> 1;
	if (p <= mid) {
		return query(p, lc[u], lo, mid);
	} else {
		return query(p, rc[u], mid + 1, hi);
	}
}
int lb(int x, int u = 0, int lo = 0, int hi = INF) {
	if (lo == hi) {
		return lo;
	}
	makeChild(u, lo, hi);
	propo(u, lo, hi);
	int mid = lo + hi >> 1;
	if (v[lc[u]] >= x) {
		return lb(x, lc[u], lo, mid);
	} else {
		if (v[rc[u]] < x) {
			return INF + 1;
		}
		return lb(x, rc[u], mid + 1, hi);
	}
}

int main() {
	scanf("%d", &n);
	v[0] = INF;
	while (n--) {
		int t; scanf("%d", &t);
		int k; scanf("%d", &k);
		int l = lb(t) - 1, r = lb(t + 1);
		incre(0, l, 1);
		incre(r, INF, -1);
		while (k--) {
			int x; scanf("%d", &x);
			x = (x + ans) % MOD;
			ans = query(x);
			printf("%d\n", ans);
		}
	}
	return 0;
}

/*
2
1000000000
1
1000000000
1000000000
1
1000000000

2
0
1
0
0
1
0
*/