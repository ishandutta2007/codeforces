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
#define MAXN 300005

int n, m, k;
int a[MAXN];
ll dp[MAXN][15];
ll ans;

main() {
	scanf("%d%d%d", &n, &m, &k);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	REP (i, 0, n + 1) {
		REP (j, 0, m) {
			dp[i][j] = -LINF;
		}
	}
	dp[0][0] = 0;
	REP (i, 1, n + 1) {
		dp[i][0] = 0;
		REP (j, 0, m) {
			if (dp[i - 1][(j - 1 + m) % m] == -LINF) continue;
			mxto(dp[i][j],
				   	dp[i - 1][(j - 1 + m) % m] + a[i] - (j == (1 % m) ? k : 0));
		}
		REP (j, 0, m) {
			mxto(ans, dp[i][j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}