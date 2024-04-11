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

const int maxn = 50;

int n;
int a[maxn + 5];
int dp[maxn + 5][2];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int sum = 0;
	REP(i, 0, n) scanf("%d", a + i), sum += a[i];
	dp[n][0] = dp[n][1] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		dp[i][0] = max(dp[i + 1][0], dp[i + 1][1] + a[i]);
		dp[i][1] = min(dp[i + 1][0], dp[i + 1][1] + a[i]);
	}
	printf("%d %d\n", dp[0][1], sum - dp[0][1]);
	return 0;
}