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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 1000000;

int n;
int a[maxn + 5], x, y;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d", &n, &x, &y);
	REP(i, 0, n) scanf("%d", a + i);
	set<int> all;
	REP(t, 0, 2)
		REP(delta, -1, 2)
		{
			int u = a[(t == 0) ? 0 : n - 1] + delta;
			for (int i = 2; i * i <= u; ++i)
				if (!(u % i))
				{
					all.insert(i);
					while (!(u % i)) u /= i;
				}
			if (u > 1) all.insert(u);
		}
	LL ans = LLONG_MAX;
	for (auto fac : all)
	{
		static LL cost[maxn + 5];
		static LL dp[maxn + 5][3];
		REP(i, 0, n)
		{
			int tmp = a[i] % fac;
			if (!tmp) cost[i] = 0;
			else if (tmp == 1 || tmp == fac - 1) cost[i] = y;
			else cost[i] = OO;
		}
		memset(dp, oo, sizeof dp);
		dp[0][0] = 0;
		LL sum = 0;
		REP(i, 0, n)
		{
			sum += cost[i];
			chkmin(sum, OO);
			chkmin(ans, LL(n - i - 1) * x + sum);
			REP(j, 0, 3)
				if (dp[i][j] < OO)
				{
					if (j == 1)
					{
						chkmin(dp[i + 1][j], dp[i][j] + x);
						chkmin(dp[i + 1][2], dp[i][j] + cost[i]);
					}
					else
					{
						chkmin(dp[i + 1][j], dp[i][j] + cost[i]);
						if (!j) chkmin(dp[i + 1][1], dp[i][j] + x);
					}
				}
		}
		chkmin(ans, min(dp[n][0], dp[n][2]));
	}
	cout << ans << endl;
	return 0;
}