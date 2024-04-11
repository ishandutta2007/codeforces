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

bool ok[1010];

int dp[1010];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(ok, 0, sizeof ok);
	REP(i, 2, 1001) REP(j, 2, 1001) if (i * j <= 1000) ok[i * j] = 1;
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	REP(i, 0, 1001) if (~dp[i]) REP(j, 0, 1001) if (i + j <= 1000 && ok[j])
		chkmax(dp[i + j], dp[i] + 1);
	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int x;
		scanf("%d", &x);
		if (x <= 1000)
		{
			printf("%d\n", dp[x]);
		}
		else
		{
			if (x & 1) 
			{
				printf("%d\n", ((x - 9) >> 2) + 1);
			}
			else printf("%d\n", x >> 2);
		}
	}
	return 0;
}