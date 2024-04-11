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
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int t;
int n;
char s[2][MAXN];
int v[MAXN];
int dp[MAXN][4];

int mex(int x) {
	REP (i, 0, 3) {
		if (!(x & (1 << i))) {
			return i;
		}
	}
	assert(0);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, 2) {
			scanf(" %s", s[i]);
		}
		REP (i, 0, n) {
			v[i] = (1 << (s[0][i] - '0')) | (1 << (s[1][i] - '0'));
			debug("%d: %d\n", i, v[i]);
		}
		REP (i, 0, n) {
			REP (j, 0, 4) {
				dp[i][j] = -INF;
			}
		}
		dp[0][v[0]] = 0;
		REP (i, 1, n) {
			REP (j, 0, 4) {
				mxto(dp[i][j | v[i]], dp[i - 1][j]);
				mxto(dp[i][v[i]], dp[i - 1][j] + mex(j));
			}
			debug("%d\n", i);
			REP (j, 0, 4) {
				debug(" %d: %d\n", j, dp[i][j]);
			}
		}
		int ans = 0;
		REP (j, 0, 4) {
			mxto(ans, dp[n - 1][j] + mex(j));
		}
		printf("%d\n", ans);
	}
	return 0;
}