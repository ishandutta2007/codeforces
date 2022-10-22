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
typedef vector<iii> viii;

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

int n, m;
vii lr[MAXN];
vector<tuple<int, int, int, int>> cords;
int p[MAXN];
int visited[MAXN];
vi vans;
int ptr;

#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
ii mn[MAXN * 8], lazy[MAXN * 8];
int lc[MAXN * 8], rc[MAXN * 8];
void propo(int u, int lo, int hi) {
	if (lo == hi) return;
	MLR;
	mnto(mn[lc], lazy[u]);
	mnto(mn[rc], lazy[u]);
	mnto(lazy[lc], lazy[u]);
	mnto(lazy[rc], lazy[u]);
}
void upset(int s, int e, int v, int id, int u, int lo, int hi) {
	if (lo >= s && hi <= e) {
		mnto(mn[u], MP(v, id));
		mnto(lazy[u], MP(v, id));
		return;
	}
	MLR;
	propo(u, lo, hi);
	if (s <= mid) upset(s, e, v, id, lc, lo, mid);
	if (e > mid) upset(s, e, v, id, rc, mid + 1, hi);
	mn[u] = min(mn[lc], mn[rc]);
}
void upset(int s, int e, int v, int id) {
	upset(s, e, v, id, 1, 1, ptr);
}
ii query(int s, int e, int u, int lo, int hi) {
	if (s < 0) s = 0;
	if (lo >= s && hi <= e) return mn[u];
	MLR;
	propo(u, lo, hi);
	if (e <= mid) return query(s, e, lc, lo, mid);
	else if (s > mid) return query(s, e, rc, mid + 1, hi);
	else return min(query(s, e, lc, lo, mid), query(s, e, rc, mid + 1, hi));
}
ii query(int s, int e) {
	return query(s, e, 1, 1, ptr);
}

int main() {
	REP (i, 0, MAXN * 8) {
		mn[i] = MP(0, -1);
		lazy[i] = MP(0, -1);
	}
	scanf("%d%d", &n, &m);
	REP (i, 0, m) {
		int id, l, r; scanf("%d%d%d", &id, &l, &r);
		lr[id].pb(MP(l, r));
		cords.pb(MT(l, id, lr[id].size() - 1, 0));
		cords.pb(MT(r, id, lr[id].size() - 1, 1));
	}
	sort(ALL(cords));
	int prv = -1;
	REP (i, 0, cords.size()) {
		auto [x, id, j, isr] = cords[i];
		if (prv != x) {
			ptr++;
			prv = x;
		}
		if (isr) {
			lr[id][j].SE = ptr;
		} else {
			lr[id][j].FI = ptr;
		}
	}
	int ans = INF;
	int v = -1;
	REP (i, 1, n + 1) {
		ii mn = MP(0, -1);
		for (auto [l, r] : lr[i]) {
			ii q = query(l, r);
			mnto(mn, q);
			debug(" %d %d ? %d %d\n", l, r, q.FI, q.SE);
		}
		int dp = mn.FI + i - 1;
		p[i] = mn.SE;
		debug("%d: %d %d %d\n", i, mn, dp, p[i]);
		for (auto [l, r] : lr[i]) {
			upset(l, r, dp - i, i);
			debug(" %d %d -> %d\n", l, r, dp - i);
		}
		if (mnto(ans, dp + n - i)) {
			v = i;
		}
	}
	do {
		visited[v] = 1;
		v = p[v];
	} while (v != -1);
	REP (i, 1, n + 1) {
		if (!visited[i]) vans.pb(i);
	}
	printf("%d\n", ans);
	assert(vans.size() == ans);
	for (int i : vans) {
		printf("%d ", i);
	}
	printf("\n");
	return 0;
}