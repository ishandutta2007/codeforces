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
#define MAXN 500005
#define MAXL 20

int n, q;
vii adj[MAXN];
int u[MAXN], v[MAXN], x[MAXN];
bool ans[MAXN];

namespace dsu {
	int p[MAXN], rnk[MAXN];
	inline void init() {
		REP (i, 0, n + 5) {
			p[i] = i;
		}
	}
	int find(int i) {
		if (p[i] == i) return i;
		return p[i] = find(p[i]);
	}
	inline bool same(int a, int b) {
		return find(a) == find(b);
	}
	inline bool join(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa == pb) return 0;
		if (rnk[pa] < rnk[pb]) swap(pa, pb);
		if (rnk[pa] == rnk[pb]) rnk[pa]++;
		p[pb] = pa;
		return 1;
	}
}

int pre[MAXN], pst[MAXN], ptr = 1;
int p[MAXL][MAXN];
bool visited[MAXN];
int d[MAXN], l[MAXN];
void dfs(int u, int cp) {
	pre[u] = ptr++;
	p[0][u] = cp;
	REP (k, 1, MAXL) {
		if (p[k - 1][u] == -1) {
			p[k][u] = -1;
		} else {
			p[k][u] = p[k - 1][p[k - 1][u]];
		}
	}
	for (auto [v, x] : adj[u]) {
		if (v == cp) continue;
		d[v] = d[u] + x;
		l[v] = l[u] + 1;
		visited[v] = 1;
		dfs(v, u);
	}
	pst[u] = ptr;
}

inline int getlca(int a, int b) {
	if (l[a] < l[b]) swap(a, b);
	RREP (k, MAXL - 1, 0) {
		if (p[k][a] == -1) continue;
		if (l[p[k][a]] >= l[b]) {
			a = p[k][a];
		}
	}
	if (a == b) {
	   	return a;
	}
	RREP (k, MAXL - 1, 0) {
		if (p[k][a] != p[k][b]) {
			a = p[k][a];
			b = p[k][b];
		}
	}
	return p[0][a];
}

int fw[MAXN];
inline void incre(int i, int x) {
	for (; i < MAXN; i += i & -i) fw[i] += x;
}
inline void incre(int s, int e, int x) {
	incre(s, x); incre(e + 1, -x);
}
inline int qsm(int i) {
	int res = 0;
	for (; i > 0; i -= i & -i) res += fw[i];
	return res;
}

void addBlock(int u, int v) {
	while (u != v) {
		if (l[u] < l[v]) swap(u, v);
		int cp = p[0][u];
		incre(pre[u], pst[u] - 1, 1);
		u = cp;
	}
}

int main() {
	scanf("%d%d", &n, &q);
	dsu::init();
	REP (i, 0, q) {
		scanf("%d%d%d", &u[i], &v[i], &x[i]);
		if (dsu::join(u[i], v[i])) {
			ans[i] = 1;
			adj[u[i]].pb(MP(v[i], x[i]));
			adj[v[i]].pb(MP(u[i], x[i]));
		} else {
			ans[i] = 0;
		}
	}
	REP (i, 1, n + 1) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i, -1);
		}
	}
	REP (i, 0, q) {
		if (ans[i]) continue;
		int lca = getlca(u[i], v[i]);
		int block = qsm(pre[u[i]]) + qsm(pre[v[i]]) - 2 * qsm(pre[lca]);
		debug("%d: %d\n", i, block);
		if (block != 0) continue;
		int dist = d[u[i]] + d[v[i]] - 2 * d[lca];
		debug(" %d\n", dist);
		if ((dist + x[i]) % 2 == 1) {
			ans[i] = 1;
			addBlock(u[i], v[i]);
		}
	}
	REP (i, 0, q) {
		if (ans[i]) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}