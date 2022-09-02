#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int max0 = 60;

LL s, x;

LL dp[max0 + 5][2];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%I64d%I64d", &s, &x);
	memset(dp, 0, sizeof dp);
	dp[0][0] = 1;
	REP(i, 0, max0) REP(j, 0, 2)
		if (dp[i][j])
		{
			REP(a, 0, 2)
			{
				int b = (x >> i & 1) ^ a;
				if (((j + a + b) & 1) == (s >> i & 1)) dp[i + 1][(j + a + b) >> 1] += dp[i][j];
			}
		}
	LL ans = dp[max0][0];
	if (s == x) ans -= 2;
	printf("%I64d\n", ans);
	return 0;
}