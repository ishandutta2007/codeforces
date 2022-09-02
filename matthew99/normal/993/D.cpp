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
const LL OO = 0x3f3f3f3f3f3f3f3fLL;

const int maxn = 52, maxm = 5010;

int n;
pair<int, int> a[maxn + 5];
LL dp[maxn + 5][maxn + 5][maxm + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", &a[i].x);
	REP(i, 0, n) scanf("%d", &a[i].y);
	sort(a, a + n, greater<pair<int, int> >());
	memset(dp, oo, sizeof dp);
	dp[0][0][0] = 0;
	for (int i = 0; i < n; )
	{
		int j = i;
		while (j < n && a[j].x == a[i].x) ++j;
		REP(balance, 0, i + 1)
		{
			REP(sumb, 0, maxm + 1) if (dp[i][balance][sumb] < OO)
			{
				LL newa = 0;
				int newb = 0;
				REP(k, i, j + 1)
				{
					if (balance - (j - k) >= 0)
					{
						chkmin(dp[j][balance + (k - i) - (j - k)][sumb + newb], dp[i][balance][sumb] + newa);
					}
					if (k < j) newa += a[k].x, newb += a[k].y;
				}
			}
		}
		i = j;
	}
	LL ans = OO;
	REP(balance, 0, n + 1) REP(sumb, 0, maxm + 1)
		if (dp[n][balance][sumb] < OO) 
		{
			chkmin(ans, (dp[n][balance][sumb] * 1000 + sumb - 1) / sumb);
		}
	cout << ans << endl;
	return 0;
}