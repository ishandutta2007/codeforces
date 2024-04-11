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
#define MAXN 5005

int n;
int dp[MAXN][MAXN];
vi a, b;
int ans;

int main() {
	scanf("%d", &n);
	a.pb(0); b.pb(0);
	REP (i, 0, n) {
		int tmp; scanf("%d", &tmp);
		if (tmp == 1) {
			a.pb(i);
		} else {
			b.pb(i);
		}
	}
	int x = a.size(), y = b.size();
	REP (i, 0, x) {
		REP (j, 0, y) {
			dp[i][j] = INF;
			if (i == 0) dp[i][j] = 0;
		}
	}
	REP (i, 1, x) {
		REP (j, i, y) {
			dp[i][j] = min(dp[i - 1][j - 1] + abs(a[i] - b[j]), dp[i][j - 1]);
		}
	}
	printf("%d\n", dp[x - 1][y - 1]);
	return 0;
}