// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/D

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
#define MAXN 400005

int t;
int n, m;
vii adj[MAXN];
vii tree[MAXN];
int c[MAXN];
bool pos;
vector<iii> ans;

void dfs(int u) {
	for (auto [v, w] : adj[u]) {
		assert(w == 0 || w == 1);
		if (c[v] == -1) {
			c[v] = c[u] ^ w;
			dfs(v);
			if (!pos) {
				break;
			}
		} else {
			if (c[v] != c[u] ^ w) {
				pos = 0;
				break;
			}
		}
	}
}

void getAns(int u, int p) {
	for (auto [v, w] : tree[u]) {
		if (v == p) continue;
		if (w != -1) {
			ans.pb(MT(u, v, w));
		} else {
			ans.pb(MT(u, v, c[u] ^ c[v]));
		}
		getAns(v, u);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		pos = 1;
		REP (i, 0, n + 1) {
			adj[i].clear();
			tree[i].clear();
			c[i] = -1;
		}
		REP (i, 1, n) {
			int x, y, v; scanf("%d%d%d", &x, &y, &v);
			tree[x].pb(MP(y, v));
			tree[y].pb(MP(x, v));
			if (v != -1) {
				int pv = __builtin_popcount(v) % 2;
				adj[x].pb(MP(y, pv));
				adj[y].pb(MP(x, pv));
			}
		}
		REP (i, 0, m) {
			int a, b, p; scanf("%d%d%d", &a, &b, &p);
			adj[a].pb(MP(b, p));
			adj[b].pb(MP(a, p));
		}
		REP (i, 1, n + 1) {
			if (c[i] != -1) continue;
			c[i] = 0;
			dfs(i);
			if (!pos) {
				break;
			}
		}
		if (!pos) {
			printf("NO\n");
			continue;
		}
		ans.clear();
		getAns(1, -1);
		printf("YES\n");
		for (auto [a, b, c] : ans) {
			printf("%d %d %d\n", a, b, c);
		}
	}
	return 0;
}