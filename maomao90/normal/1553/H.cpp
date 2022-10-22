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
#define MAXN 2000005

int k;
int n;
int a[MAXN];
int ans[MAXN];

int c[2][MAXN];
int mx[MAXN], mn[MAXN], dist[MAXN], len[MAXN];
inline void recalc(int u) {
	mx[u] = max(mx[c[0][u]], mx[c[1][u]] + len[c[0][u]]);
	mn[u] = min(mn[c[0][u]], mn[c[1][u]] + len[c[0][u]]);
	dist[u] = min(min(dist[c[0][u]], dist[c[1][u]]),
		   	mn[c[1][u]] + len[c[0][u]] - mx[c[0][u]]);
}
void init(int u = 1, int l = k - 1) {
	if (l == -1) {
		c[0][u] = c[1][u] = 0;
		len[u] = 1;
		recalc(u);
		return;
	}
	c[0][u] = u << 1, c[1][u] = u << 1 ^ 1;
	init(c[0][u], l - 1); init(c[1][u], l - 1);
	recalc(u);
	len[u] = len[c[0][u]] + len[c[1][u]];
}
void ins(int x, int u = 1, int l = k - 1) {
	if (l == -1) {
		debug("%d %d\n", x, u);
		mn[u] = mx[u] = 0;
		return;
	}
	bool dir = (x >> l) & 1;
	ins(x, c[dir][u], l - 1);
	recalc(u);
}

void swap_segs(int u, int upl, int l = k - 1) {
	if (l == upl) {
		swap(c[0][u], c[1][u]);
		recalc(u);
		return;
	}
	swap_segs(c[0][u], upl, l - 1); swap_segs(c[1][u], upl, l - 1);
	recalc(u);
}

int u;
void rec(int l) {
	ans[u] = dist[1];
	if (l == k) return;
	rec(l + 1);
	u ^= (1 << l);
	swap_segs(1, l);
	rec(l + 1);
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
	}
	mx[0] = -INF; mn[0] = INF; dist[0] = INF;
	init();
	REP (i, 0, n) {
		ins(a[i]);
	}
	rec(0);
	REP (i, 0, 1 << k) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}