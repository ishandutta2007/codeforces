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
int n, k;
int a[MAXN];
vi adj[MAXN];
int x, sp, psp;

int dfs(int u, int p) {
	int res = a[u];
	for (int v : adj[u]) {
		if (v == p || v == psp) continue;
		res ^= dfs(v, u);
		if (sp != -1) {
			return 0;
		}
	}
	if (res == x) {
		sp = u;
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		x = 0;
		REP (i, 1, n + 1) {
			adj[i].clear();
			scanf("%d", &a[i]);
			x ^= a[i];
		}
		REP (i, 1, n) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int rt = -1;
		REP (i, 1, n + 1) {
			if (adj[i].size() == 1) {
				rt = i;
			}
		}
		assert(rt != -1);
		if (x == 0) {
			printf("YES\n");
			continue;
		} else if (k == 2) {
			printf("NO\n");
			continue;
		}
		sp = psp = -1;
		dfs(rt, -1);
		assert(sp != -1);
		if (sp == rt) {
			printf("NO\n");
			continue;
		}
		psp = sp;
		sp = -1;
		dfs(rt, -1);
		assert(sp != rt);
		if (sp == -1) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}