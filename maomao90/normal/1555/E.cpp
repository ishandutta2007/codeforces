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
#define MAXM 1000005

struct range {
	int l, r, w;
	bool operator< (const range& o) const {
		return w < o.w;
	}
};

int n, m;
range rg[MAXN];
int ans;

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
int mn[MAXM * 4], lazy[MAXM * 4];
void propo(int u, int lo, int hi) {
	if (lo == hi || lazy[u] == 0) return;
	MLR;
	mn[lc] += lazy[u];
	lazy[lc] += lazy[u];
	mn[rc] += lazy[u];
	lazy[rc] += lazy[u];
	lazy[u] = 0;
}
void incre(int s, int e, int x, int u = 1, int lo = 1, int hi = m - 1) {
	if (lo >= s && hi <= e) {
		mn[u] += x;
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
	mn[u] = min(mn[lc], mn[rc]);
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		scanf("%d%d%d", &rg[i].l, &rg[i].r, &rg[i].w);
		rg[i].r--;
	}
	sort(rg, rg + n);
	int r = 0;
	ans = INF;
	REP (l, 0, n) {
		while (r < n && mn[1] == 0) {
			incre(rg[r].l, rg[r].r, 1);
			debug("%d %d: +1\n", rg[r].l, rg[r].r);
			r++;
		}
		if (mn[1] != 0) {
			debug(" %d %d: %d\n", l, r, rg[r - 1].w - rg[l].w);
			mnto(ans, rg[r - 1].w - rg[l].w);
		}
		incre(rg[l].l, rg[l].r, -1);
		debug("%d %d: -1\n", rg[l].l, rg[l].r);
	}
	printf("%d\n", ans);
	return 0;
}