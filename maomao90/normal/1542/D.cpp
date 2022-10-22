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
#define MAXN 505
#define inv2 499122177

struct thing {
	char c; int x;
};

int n;
thing a[MAXN];
vii items;
int b[MAXN];
ll dp[MAXN][MAXN];
ll ans;

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		char c; scanf(" %c", &c);
		if (c == '-') {
			a[i] = {c, 0};
			b[i] = -1;
		} else {
			int x; scanf("%d", &x);
			a[i] = {c, x};
			items.pb(MP(x, i));
		}
	}
	sort(ALL(items));
	for (auto [x, id] : items) {
		REP (i, 0, n) {
			REP (j, 0, n + 1) {
				dp[i][j] = 0;
			}
		}
		if (b[0] == 1) {
			dp[0][0] = dp[0][1] = inv2;
		} else {
			dp[0][0] = 1;
		}
		debug("%d %d\n", x, id);
		REP (i, 1, id + 1) {
			REP (j, 0, n + 1) {
				if (b[i] == 0) {
					dp[i][j] = dp[i - 1][j];
					debug(" %d %d: %lld\n", i, j, dp[i][j]);
					continue;
				}
				dp[i][j] = dp[i - 1][j] * inv2 % MOD;
				if (j - b[i] >= 0) {
					dp[i][j] += dp[i - 1][j - b[i]] * inv2 % MOD;
					dp[i][j] %= MOD;
				}
				if (j == 0 && b[i] == -1) {
					dp[i][j] += dp[i - 1][j] * inv2 % MOD;
					dp[i][j] %= MOD;
				}
				debug(" %d %d: %lld\n", i, j, dp[i][j]);
			}
		}
		REP (i, id + 1, n) {
			REP (j, 0, n + 1) {
				if (b[i] == 0) {
					dp[i][j] = dp[i - 1][j];
					debug(" %d %d: %lld\n", i, j, dp[i][j]);
					continue;
				}
				dp[i][j] = dp[i - 1][j] * inv2 % MOD;
				if (j - b[i] >= 0) {
					dp[i][j] += dp[i - 1][j - b[i]] * inv2 % MOD;
					dp[i][j] %= MOD;
				}
				debug(" %d %d: %lld\n", i, j, dp[i][j]);
			}
		}
		REP (j, 0, n + 1) {
			ans += dp[n - 1][j] * x % MOD * inv2 % MOD;
			ans %= MOD;
		}
		b[id] = 1;
	}
	REP (i, 0, n) {
		ans = ans * 2 % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}