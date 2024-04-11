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
#define MOD 1000000007
#define MAXN 100005

int r, n;
int t[MAXN], x[MAXN], y[MAXN];
int dp[MAXN];
int ans;

int main() {
	scanf("%d%d", &r, &n);
	REP (i, 1, n + 1) {
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
	}
	t[0] = 0;
	x[0] = y[0] = 1;
	int mx = -INF;
	dp[0] = 0;
	REP (i, 1, n + 1) {
		dp[i] = mx + 1;
		RREP (j, i - 1, max(0, i - 2 * r)) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) + t[j] <= t[i]) {
				mxto(dp[i], dp[j] + 1);
			}
		}
		if (i - 2 * r >= 0) {
			mxto(mx, dp[i - 2 * r]);
		}
		mxto(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}