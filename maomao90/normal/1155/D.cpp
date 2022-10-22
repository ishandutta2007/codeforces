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
#define MAXN 300005
 
int n, x;
int a[MAXN];
ll dp[MAXN][3];
ll ans;
 
int main() {
    scanf("%d%d", &n, &x);
    REP (i, 0, n) scanf("%d", &a[i]);
	dp[0][0] = a[0];
	dp[0][1] = (ll) a[0] * x;
	ans = max(ans, max(dp[0][0], dp[0][1]));
	REP (i, 1, n) {
        dp[i][0] = max(dp[i - 1][0], 0ll) + a[i];
        dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], 0ll)) + (ll) a[i] * x;
        dp[i][2] = max(dp[i - 1][1], max(dp[i - 1][2], 0ll)) + a[i];
        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }
    printf("%lld\n", ans);
    return 0;
}