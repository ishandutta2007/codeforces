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

int n, m;
char s[MAXN];
int dp[5][5][MAXN];

int main() {
	scanf("%d%d", &n, &m);
	scanf(" %s", s);
	REP (i, 0, 3) {
		REP (j, 0, 3) {
			if (i == j) continue;
			int a[] = {i, j, 3 - i - j};
			REP (k, 0, n) {
				if (s[k] != a[k % 3] + 'a') {
					dp[i][j][k]++;
				}
				if (k != 0) {
					dp[i][j][k] += dp[i][j][k - 1];
				}
			}
		}
	}
	REP (i, 0, m) {
		int l, r; scanf("%d%d", &l, &r);
		l--; r--;
		int ans = INF;
		REP (i, 0, 3) {
			REP (j, 0, 3) {
				if (i == j) continue;
				mnto(ans, dp[i][j][r] - (l == 0 ? 0 : dp[i][j][l - 1]));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}