#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cctype>
#include <ctime>
#include <vector>
#define REP(i, a, b) for (register int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (register int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define SZ(x) (int((x).size()))
using namespace std;
typedef long long LL;
const int oo = 0x3f3f3f3f;
const int maxn = 100, maxk = 100;
int f[maxn + 5][maxn + 5];
vector<int> all[maxk + 5][maxn + 5];
int n, m;
int s[maxk + 5], t[maxk + 5];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b), --a, --b;
	memset(f, oo, sizeof f);
	REP(i, 0, n) f[i][i] = 0;
	REP(i, 0, m)
	{
		static int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		f[x][y] = 1;
	}
	REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	int k;
	scanf("%d", &k);
	REP(i, 0, k)
	{
		static int s, t;
		scanf("%d%d", &s, &t), --s, --t;
		::s[i] = s, ::t[i] = t;
		if (f[s][t] == oo) continue;
		REP(j, 0, n)
			if (f[s][t] == f[s][j] + f[j][t]) all[i][f[s][j]].pb(j);
	}
	static int dp[maxn + 5];
	memset(dp, oo, sizeof dp);
	dp[b] = 0;
	for (bool flag = 1; flag; )
	{
		flag = 0;
		REP(i, 0, k)
		{
			if (f[s[i]][t[i]] >= oo) continue;
			static int g[maxn + 5];
			for (int j = f[s[i]][t[i]]; j >= 0; --j)
			{
				REP(k, 0, SZ(all[i][j]))
				{
					const int &x = all[i][j][k];
					g[x] = -1;
					REP(l, 0, SZ(all[i][j + 1]))
					{
						const int &y = all[i][j + 1][l];
						if (f[x][y] == 1) g[x] = max(g[x], g[y]);
					}
					g[x] = min(g[x] == -1 ? oo : g[x], dp[x] + 1);
					if (SZ(all[i][j]) == 1 && dp[x] > g[x]) dp[x] = g[x], flag = 1;
				}
			}
		}
	}
	printf("%d\n", dp[a] >= oo ? -1 : dp[a]);
	return 0;
}