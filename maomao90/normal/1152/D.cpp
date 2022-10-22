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
#define MAXN 2005

int n;
ll dp[MAXN][MAXN];
ll ans;

int main() {
	scanf("%d", &n);
	dp[0][1] = 1;
	REP (i, 1, 2 * n) {
		int mx = 2 * n - i;
		REP (j, 0, min(mx, n + 1)) {
			if (j > 0) dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}
	for (int i = 0; i < 2 * n; i += 2) {
		ll cnt = 0;
		REP (j, 0, n + 1) {
			cnt += dp[i][j];
			cnt %= MOD;
		}
		ans += cnt;
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}