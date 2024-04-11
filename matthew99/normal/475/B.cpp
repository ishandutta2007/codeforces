#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)

using namespace std;

const int maxn = 20, maxm = 20;

int n, m;

int col[maxm], row[maxn];

bool f[maxn][maxm][maxn][maxm] = {{{{0}}}};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	scanf("\n");
	REP(i, 0, n)
	{
		char c;
		scanf("%c", &c);
		row[i] = (c == '>' ? 1 : -1);
	}
	scanf("\n");
	REP(i, 0, m)
	{
		char c;
		scanf("%c", &c);
		col[i] = (c == 'v' ? 1 : -1);
	}
	REP(i, 0, n)
		REP(j, 0, m)
		{
			int x = i + col[j], y = j;
			if (x < n && x >= 0) f[i][j][x][y] = 1;
			x = i, y = j + row[i];
			if (y < m && y >= 0) f[i][j][x][y] = 1;
		}
	REP(i0, 0, n)
		REP(j0, 0, m)
			REP(i1, 0, n)
				REP(j1, 0, m)
					REP(i2, 0, n)
						REP(j2, 0, m)
							f[i1][j1][i2][j2] |= f[i1][j1][i0][j0] & f[i0][j0][i2][j2];
	REP(i0, 0, n)
		REP(j0, 0, m)
			REP(i1, 0, n)
				REP(j1, 0, m)
					if (!f[i0][j0][i1][j1]) EXIT("NO\n");
	printf("YES\n");
	return 0;
}