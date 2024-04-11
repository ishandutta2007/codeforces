// time-limit: 3000
// problem-url: https://codeforces.com/contest/1591/problem/F

// Be kind and compassionate to one another, forgiving each other,
// just as in Christ God forgave you. Ephesians 4:32
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
#define MAXN 200005

int n;
int a[MAXN];
ll dp[MAXN][2], pdp[MAXN][2], res[2];

inline ll qsm(int s, int e, int j) {
	if (s == 0) {
		return pdp[e][j];
	}
	return (pdp[e][j] - pdp[s - 1][j] + MOD) % MOD;
}

int main() {
	int _t = 1;
   	// scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
		}
		stack<int> stk;
		stk.push(0);
		dp[0][0] = pdp[0][0] = 1;
		res[0] = 0;
		res[1] = 0;
		REP (i, 1, n + 1) {
			while (a[stk.top()] >= a[i]) {
				int u = stk.top(); stk.pop();
				int v = stk.top();
				debug("%d %d\n", u, v);
				REP (j, 0, 2) {
					res[j ^ 1] -= qsm(v, u - 1, j) * a[u] % MOD + MOD;
					res[j ^ 1] %= MOD;
				}
			}
			REP (j, 0, 2) {
				int v = stk.top();
				res[j ^ 1] += qsm(v, i - 1, j) * a[i] % MOD;
				res[j ^ 1] %= MOD;
			}
			REP (j, 0, 2) {
				dp[i][j] = res[j];
				pdp[i][j] = (pdp[i - 1][j] + dp[i][j]) % MOD;
				debug("%d %d: %lld\n", i, j, dp[i][j]);
			}
			stk.push(i);
		}
		ll ans = (dp[n][n & 1] - dp[n][n & 1 ^ 1] + MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}