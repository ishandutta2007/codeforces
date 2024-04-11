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
#define MAXN 1005

int n;
vi adj[MAXN];
int des;

vii eg;
void dfs(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		eg.pb(MP(u, v));
		dfs(v, u);
	}
}

int solve(int s, int e) {
	if (s == e) return s;
	int m = s + e >> 1;
	set<int> st;
	REP (i, s, m + 1) {
		st.insert(eg[i].FI);
		st.insert(eg[i].SE);
	}
	printf("? %d", (int) st.size());
	for (int i : st) {
		printf(" %d", i);
	}
	printf("\n");
	fflush(stdout);
	int x; scanf("%d", &x);
	if (x == des) {
		return solve(s, m);
	} else {
		return solve(m + 1, e);
	}
}

int main() {
	scanf("%d", &n);
	REP (i, 1, n) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, -1);
	printf("? %d", n);
	REP (i, 1, n + 1) {
		printf(" %d", i);
	}
	printf("\n");
	fflush(stdout);
	scanf("%d", &des);
	int ans = solve(0, eg.size() - 1);
	printf("! %d %d\n", eg[ans].FI, eg[ans].SE);
	return 0;
}