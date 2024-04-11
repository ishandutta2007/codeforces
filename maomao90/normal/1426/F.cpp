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
#define MAXN 200005

#ifdef DEBUG
#define debug(args...) _debug(__LINE__, args)
void _debug(int line, const char* format, ...) {
	printf("Line %d: ", line);
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

string key = "-abc";

int n;
char tmp[MAXN];
string s;
vi w;
ll ones;
ll pow3[MAXN];
ll dp[MAXN][5][5];

int main() {
	scanf("%d", &n);
	pow3[0] = 1;
	REP (i, 1, n + 1) {
		pow3[i] = pow3[i - 1] * 3 % MOD;
	}
	scanf(" %s", tmp);
	s = tmp;
	s = "-" + s;
	REP (i, 1, n + 1) {
		if (s[i] == '?') ones++;
	}
	dp[0][0][0] = 1;
	REP (i, 1, n + 1) {
		REP (j, 0, 4) {
			REP (k, 0, 4) {
				dp[i][j][k] += dp[i - 1][j][k];
				int prv = k;
				if (s[i] == '?') prv--;
				if (prv >= 0 && j > 0 && (s[i] == key[j] || s[i] == '?')) {
					dp[i][j][k] += dp[i - 1][j - 1][prv];
					dp[i][j][k] %= MOD;
				}
			}
		}
	}
	ll ans = 0;
	REP (i, 0, 4) {
		if (ones - i >= 0) {
			debug("%d: %lld %lld\n", i, dp[n][3][i], pow3[ones - i]);
			ans += dp[n][3][i] * pow3[ones - i] % MOD;
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}