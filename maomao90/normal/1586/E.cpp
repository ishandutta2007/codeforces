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

int n, m;
vi adj[MAXN];
int x[MAXN], y[MAXN];
bool used[MAXN];
int q;
int a[MAXN], b[MAXN];
int occ[MAXN];

int p[MAXN], rnk[MAXN];
void init() {
	REP (i, 0, n + 1) {
		p[i] = i;
		rnk[i] = 1;
	}
}
int findSet(int a) {
	if (p[a] == a) return a;
	return p[a] = findSet(p[a]);
}
bool unionSet(int a, int b) {
	int pa = findSet(a), pb = findSet(b);
	if (pa == pb) return 0;
	if (rnk[pa] < rnk[pb]) swap(pa, pb);
	if (rnk[pa] == rnk[pb]) rnk[pa]++;
	p[pb] = pa;
	return 1;
}

int tar;
vi ans;
bool dfs(int u, int p) {
	if (u == tar) {
		ans.pb(u);
		return 1;
	}
	for (int v : adj[u]) {
		if (v == p) continue;
		if (dfs(v, u)) {
			ans.pb(u);
			return 1;
		}
	}
	return 0;
}
void dfs1(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		used[v] = 1;
		dfs1(v, u);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	REP (i, 0, m) {
		int x, y; scanf("%d%d", &x, &y);
		if (unionSet(x, y)) {
			adj[x].pb(y);
			adj[y].pb(x);
		}
	}
	scanf("%d", &q);
	REP (i, 0, q) {
		scanf("%d%d", &a[i], &b[i]);
		occ[a[i]]++;
		occ[b[i]]++;
	}
	int odd = 0;
	REP (i, 1, n + 1) {
		odd += occ[i] % 2;
	}
	if (odd != 0) {
		printf("NO\n");
		printf("%d\n", odd / 2);
		return 0;
	}
	printf("YES\n");
	REP (i, 0, q) {
		tar = b[i];
		ans.clear();
		dfs(a[i], -1);
		reverse(ALL(ans));
		printf("%d\n", (int) ans.size());
		for (int v : ans) {
			printf("%d ", v);
		}
		printf("\n");
	}
	return 0;
}