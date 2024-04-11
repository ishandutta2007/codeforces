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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 300005

struct query {
	int x, y, i;
	bool operator< (const query& o) const {
		return x < o.x;
	}
};

int n, q;
int a[MAXN];
query qs[MAXN];
int ans[MAXN];

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
ii v[MAXN * 4];
int lazy[MAXN * 4];
void propo(int u, int lo, int hi) {
	if (lo == hi || lazy[u] == 0) return;
	MLR;
	lazy[lc] += lazy[u];
	lazy[rc] += lazy[u];
	v[lc].FI += lazy[u];
	v[rc].FI += lazy[u];
	lazy[u] = 0;
}
void upset(int i, int x, int u = 1, int lo = 1, int hi = n) {
	if (lo == hi) {
		v[u].FI = x;
		v[u].SE = lo;
		return;
	}
	propo(u, lo, hi);
	MLR;
	if (i <= mid) {
		upset(i, x, lc, lo, mid);
	} else {
		upset(i, x, rc, mid + 1, hi);
	}
	v[u] = min(v[lc], v[rc]);
}
void incre(int s, int e, int x, int u = 1, int lo = 1, int hi = n) {
	if (s > e) return;
	if (lo >= s && hi <= e) {
		v[u].FI += x;
		lazy[u] += x;
		return;
	}
	propo(u, lo, hi);
	MLR;
	if (s <= mid) {
		incre(s, e, x, lc, lo, mid);
	}
	if (e > mid) {
		incre(s, e, x, rc, mid + 1, hi);
	}
	v[u] = min(v[lc], v[rc]);
}

namespace fw {
	int fw[MAXN];
	void incre(int i, int x) {
		for (; i <= n; i += i & -i) fw[i] += x;
	}
	int qsm(int i) {
		int res = 0;
		for (; i > 0; i -= i & -i) res += fw[i];
		return res;
	}
	int qsm(int s, int e) {
		return qsm(e) - qsm(s - 1);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	REP (i, 0, MAXN * 4) {
		v[i] = MP(INF, -1);
	}
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
		a[i] = i - a[i];
		if (a[i] < 0) a[i] = INF;
	}
	REP (i, 0, q) {
		int x, y; scanf("%d%d", &x, &y);
		x++; y = n - y;
		qs[i] = {x, y, i};
	}
	sort(qs, qs + q);
	int j = n;
	RREP (i, q - 1, 0) {
		while (j >= qs[i].x) {
			upset(j, a[j]);
			j--;
		}
		while (v[1].FI <= 0) {
			int id = v[1].SE;
			upset(id, INF);
			fw::incre(id, 1);
			incre(id + 1, n, -1);
		}
		ans[qs[i].i] = fw::qsm(qs[i].x, qs[i].y);
	}
	REP (i, 0, q) {
		printf("%d\n", ans[i]);
	}
	return 0;
}