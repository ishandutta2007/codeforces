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

const int maxn = 500000, max0 = 100;

double dp[maxn + 5][max0 + 5];

int fa[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int qn;
	scanf("%d", &qn);
	REP(i, 1, max0) dp[0][i] = 1;
	fa[0] = -1;
	int N = 1;
	REP(i, 0, qn)
	{
		int ty, id;
		scanf("%d%d", &ty, &id), --id;
		if (ty == 1)
		{
			REP(i, 0, max0) dp[N][i] = 1;
			fa[N++] = id;
			int u = N - 1;
			int pos = 0;
			double now = 0.5, lst = 1;
			while (~u && pos < max0)
			{
				if (pos)
				{
					double tmp = dp[u][pos];
					dp[u][pos] *= now / lst;
					lst = 1 - (1 - tmp) / 2;
					now = 1 - (1 - dp[u][pos]) / 2;
				}
				++pos;
				u = fa[u];
			}
		}
		else
		{
			double ans = 0;
			REP(i, 1, max0) ans += 1 - dp[id][i];
			printf("%.15f\n", ans);
		}
	}
	return 0;
}