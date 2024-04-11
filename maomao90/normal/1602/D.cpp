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
#define MAXN 300005

int n;
int a[MAXN], b[MAXN];
vi ans;

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
ii v[MAXN * 4], lazy[MAXN * 4];
void propo(int u, int lo, int hi) {
	if (lazy[u] == MP(INF, -1) || lo == hi) return;
	MLR;
	mnto(v[lc], lazy[u]);
	mnto(v[rc], lazy[u]);
	mnto(lazy[lc], lazy[u]);
	mnto(lazy[rc], lazy[u]);
	lazy[u] = MP(INF, -1);
}
void upmn(int s, int e, ii x, int u = 1, int lo = 0, int hi = n) {
	if (lo >= s && hi <= e) {
		mnto(v[u], x);
		mnto(lazy[u], x);
		return;
	}
	propo(u, lo, hi);
	MLR;
	if (s <= mid) {
		upmn(s, e, x, lc, lo, mid);
	}
	if (e > mid) {
		upmn(s, e, x, rc, mid + 1, hi);
	}
	mnto(v[u], min(v[lc], v[rc]));
}
ii qmn(int s, int e, int u = 1, int lo = 0, int hi = n) {
	if (lo >= s && hi <= e) {
		return v[u];
	}
	propo(u, lo, hi);
	MLR;
	ii res = MP(INF, -1);
	if (s <= mid) {
		mnto(res, qmn(s, e, lc, lo, mid));
	}
	if (e > mid) {
		mnto(res, qmn(s, e, rc, mid + 1, hi));
	}
	return res;
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	REP (i, 1, n + 1) {
		scanf("%d", &b[i]);
	}
	REP (i, 0, MAXN * 4) {
		v[i] = lazy[i] = MP(INF, -1);
	}
	upmn(n, n, MP(0, -1));
	RREP (i, n, 1) {
		int u = i + b[i];
		upmn(max(u - a[u], 0), u, MP(qmn(i, i).FI + 1, i));
	}
	int res = qmn(0, 0).FI;
	if (res == INF) {
		printf("-1\n");
		return 0;
	} else {
		printf("%d\n", res);
	}
	int u = 0;
	while (u != -1) {
		ans.pb(u);
		u = qmn(u, u).SE;
	}
	ans.pop_back();
	reverse(ALL(ans));
	assert((int) ans.size() == res);
	for (int i : ans) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}