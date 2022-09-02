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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int n;
int a[maxn + 5][2];

int dp[maxn + 5];

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		static char s[maxn + 5];
		scanf("%d", &n);
		memset(a, 0, sizeof(a[0]) * (n + 1));
		scanf("%s", s);
		REP(i, 0, n) a[i][s[i] - '0'] |= 1;
		scanf("%s", s);
		REP(i, 0, n) a[i][s[i] - '0'] |= 1;
		int lst0 = -1, lst1 = -1;
		memset(dp, 0, sizeof(dp[0]) * (n + 1));
		dp[0] = 0;
		REP(i, 1, n + 1)
		{
			if (a[i - 1][0]) lst0 = i - 1;
			if (a[i - 1][1]) lst1 = i - 1;
			chkmax(dp[i], dp[i - 1]);
			if (~lst0) chkmax(dp[i], dp[lst0] + 1);
			if (~min(lst0, lst1)) chkmax(dp[i], dp[min(lst0, lst1)] + 2);
		}
		printf("%d\n", dp[n]);
	}
	return 0;
}