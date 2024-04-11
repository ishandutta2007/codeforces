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
#define MOD 998244353
#define MAXN 200005

int t;
int n;
vi adj[MAXN];
int ans[MAXN];

ll fpow(ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			res = res * b % MOD;
		}
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}

int k;
int dfs(int u, int p) {
	int cur = 0;
	for (int v : adj[u]) {
		if (v == p) continue;
		int tmp = dfs(v, u);
		if (tmp == -1) {
			return -1;
		}
		cur += tmp;
	}
	cur %= k;
	if (cur % k == 0) {
		return 1;
	} else {
		if ((cur + 1) % k == 0) {
			return 0;
		} else {
			return -1;
		}
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			adj[i].clear();
		}
		REP (i, 1, n) {
			int u, v; scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		ans[1] = fpow(2, n - 1);
		REP (i, 2, n + 1) {
			if ((n - 1) % i != 0) {
				ans[i] = 0;
			} else {
				k = i;
				ans[i] = (dfs(1, -1) == 1);
			}
		}
		RREP (i, n, 1) {
			for (int j = i * 2; j <= n; j += i) {
				ans[i] -= ans[j];
				ans[i] %= MOD;
				ans[i] = (ans[i] + MOD) % MOD;
			}
		}
		REP (i, 1, n + 1) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}