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
#define MAXN 200005

int q;
char s[MAXN], t[MAXN];
int n, m;
int dp[5];

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf(" %s", s);
		scanf(" %s", t);
		n = strlen(s), m = strlen(t);
		dp[0] = dp[1] = m;
		RREP (i, n - 1, 0) {
			int j = i & 1;
			if (dp[j ^ 1] != m && dp[j ^ 1] - 1 >= 0 && s[i] == t[dp[j ^ 1] - 1]) {
				mnto(dp[j], dp[j ^ 1] - 1);
			}
			if ((i & 1) != (n & 1) && s[i] == t[m - 1]) {
				mnto(dp[j], m - 1);
			}
			debug("%d: %d %d\n", i, dp[0], dp[1]);
		}
		if (min(dp[0], dp[1]) == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}