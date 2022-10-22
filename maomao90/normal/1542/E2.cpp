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
#define MAXN 505
#define MAX 260005
#define BUF 130000

int n;
int mod;
ll dp[2][MAX], s[2][MAX], ans[MAXN];

int main() {
	scanf("%d %d", &n, &mod);
	dp[0][BUF] = 1;
	REP (j, BUF, MAX) {
		s[0][j] = 1;
	}
	REP (i, 1, n + 1) {
		int bnd = i * (i - 1) / 2;
		dp[i % 2][-bnd + BUF] = 1;
		s[i % 2][-bnd + BUF] = dp[i % 2][-bnd + BUF];
		debug("%d %d: %lld\n", i, -bnd, dp[i % 2][-bnd + BUF]);
		REP (j, -bnd + 1, bnd + 1) {
			s[i % 2][j + BUF] = s[i % 2][j - 1 + BUF];
			dp[i % 2][j + BUF] = dp[i % 2][j - 1 + BUF] - 
				(s[(i - 1) % 2][j - 1 + BUF] - s[(i - 1) % 2][j - 1 - i + BUF]) +
				(s[(i - 1) % 2][j  - 1 + i + BUF] - s[(i - 1) % 2][j - 1 + BUF]);
			dp[i % 2][j + BUF] %= mod;
			if (dp[i % 2][j + BUF] < 0) dp[i % 2][j + BUF] += mod;
			s[i % 2][j + BUF] += dp[i % 2][j + BUF];
			s[i % 2][j + BUF] %= mod;
			debug("%d %d: %lld\n", i, j, dp[i % 2][j + BUF]);
		}
		REP (j, bnd + 1, (i + 2) * (i + 1) / 2 + 1) {
			s[i % 2][j + BUF] = s[i % 2][j - 1 + BUF];
		}
		REP (j, 1, i) {
			ans[i] += (s[(i - 1) % 2][bnd + BUF] - s[(i - 1) % 2][BUF + j]) * (i - j) % mod;
			ans[i] %= mod;
			if (ans[i] < 0) ans[i] += mod;
		}
	}
	REP (i, 2, n + 1) {
		ans[i] += ans[i - 1] * i % mod;
		ans[i] %= mod;
	}
	printf("%lld\n", ans[n]);
	return 0;
}