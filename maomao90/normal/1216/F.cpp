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
#define MAXN 200005

int n, k;
char s[MAXN];
ll dp[MAXN][2];
deque<pll> dq, dq2;

int main() {
	scanf("%d%d", &n, &k);
	scanf(" %s", &s);
	dq2.push_back(MP(0, -1));
	REP (i, 0, n) {
		while (!dq.empty() && dq.front().SE < i - k) {
			dq.pop_front();
		}
		dp[i][0] = LINF;
		if (!dq.empty()) dp[i][0] = dq.front().FI;
		mnto(dp[i][0], i + 1 + (i == 0 ? 0 : dp[i - 1][0]));
		while (!dq2.empty() && dq2.front().SE < i - k - 1) {
			dq2.pop_front();
		}
		if (s[i] == '0') {
			dp[i][1] = LINF;
		} else {
			dp[i][1] = i + 1 + dq2.front().FI;
		}
		while (!dq.empty() && dq.back().FI >= dp[i][1]) {
			dq.pop_back();
		}
		dq.push_back(MP(dp[i][1], i));
		REP (j, 0, 2) {
			while (!dq2.empty() && dq2.back().FI >= dp[i][j]) {
				dq2.pop_back();
			}
			dq2.push_back(MP(dp[i][j], i));
		}
	}
	printf("%lld\n", min(dp[n - 1][0], dp[n - 1][1]));
	return 0;
}