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
#define MAXN 200005

int n;
int MOD;

class modi {
	public:
		int x;
		modi(): x(0) {}
		modi(int x): x(x) {}
		inline int norm(ll x) const {
                        if (x >= MOD) x %= MOD;
                        return x;
		}
		explicit operator int () {
			return x;
		}
		modi operator+ (const modi& o) const {
			return modi((x + o.x) % MOD);
		}
		modi operator* (const modi &o) const {
			return modi((ll) x * o.x % MOD);
		}
};

modi dp[MAXN];

int main() {
	scanf("%d%d", &n, &MOD);
	dp[n] = 1;
	RREP (i, n, 1) {
		dp[i] = dp[i] + dp[i + 1];
		debug("%d: %d\n", i, (int) dp[i]);
		int j = 2;
		while (j <= i) {
			int cur = i / j;
			int hi = i / cur + 1;
			dp[cur] = dp[cur] + dp[i] * modi(hi - j);
			j = hi;
		}
		if (i != 1) {
			dp[i] = dp[i + 1] + dp[i];
		}
	}
	printf("%d\n", (int) dp[1]);
	return 0;
}