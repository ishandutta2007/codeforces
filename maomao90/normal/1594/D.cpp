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
#define MAXN 400005

int t;
int n, m;
vi adj[MAXN];
char c[MAXN];
int comp[MAXN];
int crew[MAXN], imp[MAXN];

int inv(int x) {
	return (x + n) % (2 * n);
}

void addEdge(int a, int b) {
	adj[a].pb(b);
	adj[b].pb(a);
	adj[inv(a)].pb(inv(b));
	adj[inv(b)].pb(inv(a));
}

void dfs(int u) {
	for (int v : adj[u]) {
		if (comp[v] != -1) continue;
		comp[v] = comp[u];
		dfs(v);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, 2 * n + 2) {
			adj[i].clear();
			comp[i] = -1;
			crew[i] = imp[i] = 0;
		}
		REP (i, 0, m) {
			int a, b; scanf("%d%d", &a, &b);
			scanf(" %s", c);
			a--; b--;
			if (c[0] == 'c') {
				addEdge(a, b);
			} else {
				addEdge(a, inv(b));
			}
		}
		REP (i, 0, 2 * n) {
			if (comp[i] == -1) {
				comp[i] = i;
				dfs(i);
			}
		}
		bool pos = 1;
		REP (i, 0, n) {
			if (comp[i] == comp[inv(i)]) {
				pos = 0;
			}
		}
		if (!pos) {
			printf("-1\n");
		} else {
			REP (i, 0, n) {
				crew[comp[i]]++;
			}
			REP (i, n, 2 * n) {
				imp[comp[i]]++;
			}
			int ans = 0;
			REP (i, 0, 2 * n) {
				ans += max(crew[i], imp[i]);
			}
			printf("%d\n", ans / 2);
		}
	}
	return 0;
}