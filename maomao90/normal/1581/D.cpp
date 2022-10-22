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
#define MAXN 105

int n, m, k, p;
int MOD;
int memo[MAXN][MAXN][MAXN], c[MAXN][MAXN];
ll f[MAXN];

int dp(int i, int j, int l) {
	if (i < 0 || j < 0 || l < 0) return 0;
	if (memo[i][j][l] != -1) {
	   	return memo[i][j][l];
	}
	if (i == 0) {
		return memo[i][j][l] = l == 0;
	}
	if (j == 0) {
		return memo[i][j][l] = f[i] * (l == 0);
	}
	int res = 0;
	bool is1 = j == 1;
	REP (o, 0, i) {
		int tmp = 0;
		for (int p = max(0, l + o + 1 - i - 1); p <= min(l, o) + 1; p++) {
			tmp += (ll) dp(o, j - 1, p) *
				dp(i - o - 1, j - 1, l - p - is1) % MOD;
			if (tmp >= MOD) {
				tmp -= MOD;
			}
		}
		tmp = (ll) tmp * c[i - 1][o] % MOD;
		res += tmp;
		if (res >= MOD) {
			res -= MOD;
		}
	}
	return memo[i][j][l] = res;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &p);
	MOD = p;
	REP (i, 0, MAXN) {
		c[i][0] = c[i][i] = 1;
		REP (j, 1, i) {
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
			if (c[i][j] >= MOD) {
				c[i][j] -= MOD;
			}
		}
	}
	f[0] = 1;
	REP (i, 1, MAXN) {
		f[i] = f[i - 1] * i % MOD;
	}
	/*
	REP (j, 0, m + 1) {
		dp[0][j][0] = 1;
	}
	ll f = 1;
	REP (i, 1, n + 1) {
		f = f * i % MOD;
		dp[i][0][0] = f;
		REP (j, 1, m + 1) {
			bool is1 = j == 1;
			int mn = min(i, k);
			REP (l, 0, mn + 1) {
				REP (o, 0, i) {
					REP (p, 0, l + 1 - is1) {
						dp[i][j][l] += (ll) dp[o][j - 1][p] *
						   	dp[i - o - 1][j - 1][l - p - is1] % MOD * 
							c[i - 1][o] % MOD;
						if (dp[i][j][l] >= MOD) {
							dp[i][j][l] -= MOD;
						}
					}
				}
			}
		}
	}
	printf("%d\n", dp[n][m][k]);
	*/
	memset(memo, -1, sizeof memo);
	printf("%d\n", dp(n, m, k));
	return 0;
}