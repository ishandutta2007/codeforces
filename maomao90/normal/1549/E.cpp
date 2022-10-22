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
#define MAXN 3000005

int n, q;
ll fact[MAXN], ifact[MAXN];
ll dp[MAXN][5];
ll inv3;

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
ll inv(ll b) {
	return fpow(b, MOD - 2);
}
ll cse(ll n, ll r) {
	if (n < r) return 0;
	return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
}

int main() {
	scanf("%d%d", &n, &q);
	fact[0] = 1;
	REP (i, 1, 3 * n + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	ifact[3 * n] = inv(fact[3 * n]);
	RREP (i, 3 * n - 1, 0) {
		ifact[i] = ifact[i + 1] * (i + 1) % MOD;
	}
	inv3 = inv(3);
	dp[0][0] = dp[0][1] = dp[0][2] = n;
	REP (i, 1, n * 3 + 1) {
		ll tot = cse(3 * n, i + 1);
		// tot = dp[i][0] + 2 * (dp[i][0] + dp[i - 1][0]) + dp[i - 1][1]
		// dp[i][0] = (tot - 2 * dp[i - 1][0] - dp[i - 1][1]) / 3
		dp[i][0] = ((tot - 2 * dp[i - 1][0] - dp[i - 1][1]) % MOD + MOD) % MOD;
		dp[i][0] *= inv3;
		dp[i][0] %= MOD;
		dp[i][1] = (dp[i][0] + dp[i - 1][0]) % MOD;
		dp[i][2] = (dp[i][1] + dp[i - 1][1]) % MOD;
	}
	while (q--) {
		int x; scanf("%d", &x);
		ll ans = (dp[x][0] + cse(3 * n, x)) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}