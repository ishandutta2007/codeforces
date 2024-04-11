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
vi adj[MAXN];
int ans;

int dfs(int u, int p) {
	int res = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		res += dfs(v, u);
	}
	if (res == 0) return 1;
	ans += res - 1;
	return 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n + 1) {
			adj[i].clear();
		}
		REP (i, 0, n - 1) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		ans = 0;
		dfs(1, -1);
		printf("%d\n", ans + 1);
	}
	return 0;
}