// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/E

// Glory to God in the highest heaven, and on earth peace to those
// on whom his favor rests
// Luke 2:14
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

int n, k;
vi adj[MAXN];
bool used[MAXN];
ll ans;

int p[MAXN], pre[MAXN], pst[MAXN], mp[MAXN], ptr;
void dfs(int u, int cp) {
	p[u] = cp;
	pre[u] = ptr++;
	mp[pre[u]] = u;
	for (int v : adj[u]) {
		if (v == cp) continue;
		dfs(v, u);
	}
	pst[u] = ptr;
}

ii mx[MAXN * 4];
int lz[MAXN * 4];
#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
void init(int u = 1, int lo = 0, int hi = n - 1) {
	if (lo == hi) {
		mx[u].SE = lo;
	} else {
		MLR;
		init(lc, lo, mid);
		init(rc, mid + 1, hi);
	}
}
void propo(int u, int lo, int hi) {
	if (lz[u] == 0 || lo == hi) return;
	MLR;
	mx[lc].FI += lz[u];
	mx[rc].FI += lz[u];
	lz[lc] += lz[u];
	lz[rc] += lz[u];
	lz[u] = 0;
}
void incre(int s, int e, int x, int u = 1, int lo = 0, int hi = n - 1) {
	if (lo >= s && hi <= e) {
		lz[u] += x;
		mx[u].FI += x;
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
	mx[u] = max(mx[lc], mx[rc]);
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 1, n) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1);
	init();
	REP (i, 1, n + 1) {
		incre(pre[i], pst[i] - 1, 1);
	}
	ll b = n;
	REP (i, 1, k + 1) {
		int u = mp[mx[1].SE];
		debug("%d\n", u);
		while (u != -1 && !used[u]) {
			used[u] = 1;
			incre(pre[u], pst[u] - 1, -1);
			b--;
			u = p[u];
		}
		debug("%d %d\n", i, b);
		mxto(ans, (n - b - i) * (i - b));
	}
	if (b == 0) {
		printf("%lld\n", ans);
		return 0;
	}
	ans = LINF;
	REP (i, 1, b + 1) {
		mnto(ans, (ll) (n - i - k) * (k - i));
	}
	printf("%lld\n", ans);
	return 0;
}