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

const int maxn = 7010;

int n;
int dp[maxn + 5][2];
int res[maxn + 5][2];

int an[2];
int a[2][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	scanf("%d", an);
	REP(i, 0, an[0]) scanf("%d", a[0] + i);
	scanf("%d", an + 1);
	REP(i, 0, an[1]) scanf("%d", a[1] + i);
	REP(j, 0, 2) REP(i, 1, n) res[i][j] = an[j];
	queue<pair<int, int> > q;
	memset(dp, -1, sizeof dp);
	dp[0][0] = 1;
	dp[0][1] = 0;
	q.push(mp(0, 0));
	q.push(mp(0, 1));
	while (!q.empty())
	{
		auto x = q.front(); q.pop();
		if (dp[x.x][x.y] != x.y)
		{
			REP(i, 0, an[!x.y])
			{
				int nxt = (x.x + n - a[!x.y][i]) % n;
				if (!~dp[nxt][!x.y]) 
				{
					dp[nxt][!x.y] = dp[x.x][x.y]; 
					q.push(mp(nxt, !x.y));
				}
			}
		}
		else
		{
			REP(i, 0, an[!x.y])
			{
				int nxt = (x.x + n - a[!x.y][i]) % n;
				if (!--res[nxt][!x.y]) 
				{
					dp[nxt][!x.y] = dp[x.x][x.y]; 
					q.push(mp(nxt, !x.y));
				}
			}
		}
	}
	REP(j, 0, 2)
	{
		REP(i, 1, n)
		{
			if (dp[i][j] == -1) printf("Loop ");
			else if (dp[i][j] == j) printf("Win ");
			else printf("Lose ");
		}
		printf("\n");
	}
	return 0;
}