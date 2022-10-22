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
#define MAXN 105

int t;
int n, k;
vi adj[MAXN];

vector<vi> frm[MAXN];
void getd(int u, int p) {
	frm[u].resize(1);
	frm[u][0].resize(1, 1);
	for (int v : adj[u]) {
		if (v == p) continue;
		getd(v, u);
		REP (i, 0, frm[v].size()) {
			int sm = 0;
			REP (j, 0, frm[v][i].size()) {
				sm += frm[v][i][j];
			}
			if (frm[u].size() <= i + 2) {
				frm[u].resize(i + 2);
			}
			frm[u][i + 1].pb(sm);
		}
	}
}

ll dp[MAXN];
ll calc(vi v) {
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i : v) {
		RREP (j, k, 1) {
			dp[j] += dp[j - 1] * i % MOD;
			dp[j] %= MOD;
		}
	}
	return dp[k];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		REP (i, 1, n + 1) {
			adj[i].clear();
		}
		REP (i, 1, n) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		if (k == 2) {
			ll ans = (ll) n * (n - 1) / 2;
			ans %= MOD;
			printf("%lld\n", ans);
			continue;
		}
		getd(1, -1);
		ll ans = 0;
		REP (u, 1, n + 1) {
			REP (j, 1, n + 1) {
				frm[u].clear();
			}
			getd(u, -1);
			REP (i, 1, frm[u].size()) {
				ans += calc(frm[u][i]);
				ans %= MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}