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
#define MOD 998244353
#define MAXN 505

int n, x;
ll dp[MAXN][MAXN];
ll fact[MAXN], ifact[MAXN];
ll c[MAXN][MAXN];

int main() {
	scanf("%d%d", &n, &x);
	REP (i, 0, MAXN) {
		c[i][0] = c[i][i] = 1;
		REP (j, 1, i) {
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
			if (c[i][j] > MOD) {
				c[i][j] -= MOD;
			}
		}
	}
	REP (i, 0, x + 1) {
		dp[2][i] = i;
		dp[0][i] = 1;
	}
	REP (i, 3, n + 1) {
		REP (j, 1, x + 1) {
			ll pw = 1;
			RREP (k, i, 0) {
				ll p = k == 0 ? 1 : 0;
				if (j - i + 1 >= 0) {
					p = dp[k][j - i + 1];
				}
				if (p != 0 && c[i][i - k] != 0) {
					dp[i][j] += pw * c[i][i - k] % MOD * p % MOD;
					dp[i][j] %= MOD;
				}
				pw = pw * min(j, i - 1) % MOD;
			}
		}
	}
	printf("%lld\n", dp[n][x]);
	return 0;
}