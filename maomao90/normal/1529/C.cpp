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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int t;
int n;
int l[MAXN], r[MAXN];
vi adj[MAXN];

ll memo[MAXN][2];
ll dp(int u, bool pl, int p) {
	if (memo[u][pl] != -1) return memo[u][pl];
	int pw;
	if (p == -1) {
		pw = -1;
	} else {
 		pw = pl ? l[p] : r[p];
	}
	ll suml = 0, sumr = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		suml += dp(v, 1, u);
		sumr += dp(v, 0, u);
	}
	if (p != -1) {
		suml += abs(pw - l[u]);
		sumr += abs(pw - r[u]);
	}
	return memo[u][pl] = max(suml, sumr);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d%d", &l[i], &r[i]);
		}
		REP (i, 1, n + 1) {
			adj[i].clear();
		}
		REP (i, 1, n) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		REP (i, 1, n + 1) {
			memo[i][0] = -1;
			memo[i][1] = -1;
		}
		printf("%lld\n", dp(1, 0, -1));
	}
	return 0;
}