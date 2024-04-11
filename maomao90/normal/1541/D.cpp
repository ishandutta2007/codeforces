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
#define MAXN 205

int n;
int d[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll ans;

ll pw(ll b, ll p) {
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

int main() {
	scanf("%d", &n);
	REP (i, 1, n + 1) {
		REP (j, 1, n + 1) {
			d[i][j] = INF;
		}
	}
	REP (i, 1, n) {
		int x, y; scanf("%d%d", &x, &y);
		d[x][y] = d[y][x] = 1;
	}
	REP (k, 1, n + 1) {
		REP (i, 1, n + 1) {
			REP (j, 1, n + 1) {
				mnto(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	REP (j, 1, n + 1) {
		dp[0][j] = 1;
	}
	REP (i, 1, n + 1) {
		REP (j, 1, n + 1) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] % 2 == 1) dp[i][j] += MOD;
			dp[i][j] /= 2;
			dp[i][j] %= MOD;
		}
	}
	REP (k, 1, n + 1) {
		REP (i, 1, n + 1) {
			REP (j, 1, i) {
				int l = d[i][k], r = d[j][k];
				int extra = (l + r - d[i][j]) / 2;
				l -= extra;
				r -= extra;
				ans += dp[l][r];
				ans %= MOD;
			}
		}
	}
	ans = ans * pw(n, MOD - 2) % MOD;
	printf("%lld\n", ans);
	return 0;
}