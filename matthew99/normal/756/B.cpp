#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n;
int a[maxn + 5];
int dp[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	dp[0] = 0;
	REP(i, 0, n)
	{
		dp[i + 1] = dp[i] + 20;
		chkmin(dp[i + 1], dp[upper_bound(a, a + n, a[i] - 90) - a] + 50);
		chkmin(dp[i + 1], dp[upper_bound(a, a + n, a[i] - 1440) - a] + 120);
		printf("%d\n", dp[i + 1] - dp[i]);
	}
	return 0;
}