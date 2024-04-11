#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MAXN 405

int n, MOD;
ll c[MAXN][MAXN];
ll dp[MAXN][MAXN];
ll pw[MAXN];
ll ans;

int main() {
	scanf("%d%d", &n, &MOD);
	REP (i, 0, n + 5) {
		c[i][0] = c[i][i] = 1;
		REP (j, 1, i) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
	pw[0] = 1;
	REP (i, 1, n + 5) {
		pw[i] = pw[i - 1] * 2 % MOD;
	}
	dp[0][0] = 1;
	REP (i, 1, n + 2) {
		REP (j, 0, i + 1) {
			//dp[i][j] = dp[i - 1][j - 1] * 2 % MOD;
			REP (k, 0, i) {
				int l = i - k - 1;
				if (j - l >= 0) {
				   	dp[i][j] += dp[k][j - l] * pw[l - 1] % MOD * c[j][l] % MOD;
					dp[i][j] %= MOD;
				}
			}
		}
	}
	REP (i, 1, n + 1) {
		ans = (ans + dp[n + 1][i]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}