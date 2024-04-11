#include <bits/stdc++.h>
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) y = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s - 1; i >= e; i--)
typedef long long ll;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
#define MT make_tuple
typedef tuple<int, int, int> iii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 5005

inline ll add(ll a, ll b) {
	a = (a + MOD) % MOD; b = (b + MOD) % MOD;
	return (a + b + MOD) % MOD;
}
inline ll sub(ll a, ll b) {
	return add(a, -b);
}
inline ll mult(ll a, ll b) {
	a = (a + MOD) % MOD; b = (b + MOD) % MOD;
	return a * b % MOD;
}

int n, k, q;
int a[MAXN];
ll dp[MAXN][MAXN];
ll cnt[MAXN];
ll ans;

int main() {
	scanf("%d%d%d", &n, &k, &q);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	REP (i, 1, n + 1) {
		dp[i][0] = 1;
	}
	REP (j, 1, k + 1) {
		REP (i, 1, n + 1) {
			dp[i][j] = add(dp[i + 1][j - 1], dp[i - 1][j - 1]);
		}
	}
	REP (i, 1, n + 1) {
		REP (j, 0, k + 1) {
			cnt[i] = add(cnt[i], mult(dp[i][j], dp[i][k - j]));
		}
	}
	REP (i, 1, n + 1) {
		ans = add(ans, mult(cnt[i], a[i]));
	}
	while (q--) {
		int i, x; scanf("%d%d", &i, &x);
		ans = sub(ans, mult(cnt[i], a[i]));
		a[i] = x;
		ans = add(ans, mult(cnt[i], a[i]));
		printf("%lld\n", ans);
	}
	return 0;
}