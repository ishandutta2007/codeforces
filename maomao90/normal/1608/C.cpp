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

int t;
int n;
ii a[MAXN], b[MAXN];
vi adj[MAXN], radj[MAXN];
char ans[MAXN];

int visited[MAXN];
vi stk;
void dfs(int u, vi *adj) {
	for (int v : adj[u]) {
		if (visited[v] != -1) continue;
		visited[v] = visited[u];
		dfs(v, adj);
	}
	stk.pb(u);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, 2 * n) {
			adj[i].clear();
			radj[i].clear();
		}
		REP (i, 0, n) {
			scanf("%d", &a[i].FI);
			a[i].SE = i;
		}
		REP (i, 0, n) {
			scanf("%d", &b[i].FI);
			b[i].SE = i;
		}
		sort(a, a + n);
		sort(b, b + n);
		REP (i, 1, n) {
			adj[a[i].SE].pb(a[i - 1].SE);
			radj[a[i - 1].SE].pb(a[i].SE);
		}
		REP (i, 1, n) {
			adj[b[i].SE + n].pb(b[i - 1].SE + n);
			radj[b[i - 1].SE + n].pb(b[i].SE + n);
		}
		REP (i, 0, n) {
			adj[i].pb(i + n);
			adj[i + n].pb(i);
			radj[i].pb(i + n);
			radj[i + n].pb(i);
		}
		REP (i, 0, 2 * n) {
			visited[i] = -1;
		}
		stk.clear();
		REP (i, 0, 2 * n) {
			if (visited[i] != -1) continue;
			visited[i] = i;
			dfs(i, adj);
		}
		vi topo = stk;
		reverse(ALL(topo));
		REP (i, 0, 2 * n) {
			visited[i] = -1;
		}
		int rt = -1;
		for (int u : topo) {
			if (visited[u] != -1) continue;
			if (rt == -1) {
				rt = u;
			}
			visited[u] = u;
			dfs(u, radj);
		}
		REP (i, 0, n) {
			if (visited[i] == rt) {
				ans[i] = '1';
			} else {
				ans[i] = '0';
			}
		}
		ans[n] = 0;
		printf("%s\n", ans);
	}
	return 0;
}

/*
1
4
1 2 3 4
1 2 3 4
*/