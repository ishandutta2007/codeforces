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
#define MAXN 4000005

int n;
int MOD;
int dp[MAXN];
bool isp[MAXN];

//*
int main() {
	scanf("%d%d", &n, &MOD);
	REP (i, 2, n + 5) {
		isp[i] = 1;
	}
	for (int i = 2; i * i <= n; i++) {
		if (!isp[i]) continue;
		for (int j = i * i; j <= n; j += i) {
			isp[j] = 0;
		}
	}
	dp[1] = 1;
	int sm = 1, st = 0;
	REP (i, 2, n + 1) {
		int nst = (st + dp[i] + 1) % MOD;
		dp[i] = ((ll) dp[i] + sm + st + 1) % MOD;
		st = nst;
		debug("%d: %d\n", i, dp[i]);
		for (int j = i * 2; j <= n; j += i) {
			dp[j] = (dp[j] + dp[i]) % MOD;
			dp[j] = (dp[j] - dp[i - 1] + MOD) % MOD;
			debug(" %d: %d\n", j, dp[j]);
		}
		sm = (sm + dp[i]) % MOD;
	}
	printf("%d\n", dp[n]);
	return 0;
}
//*/