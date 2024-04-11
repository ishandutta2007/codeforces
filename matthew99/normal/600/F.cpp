#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <set>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

const double eps = 1e-6;

const int maxn = 1000, maxm = 100000;

int linkx[maxn + 5][maxn + 5], linky[maxn + 5][maxn + 5];
int id[maxn + 5][maxn + 5];

int ans[maxm + 5];

int n0, n1, m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(linkx, -1, sizeof linkx);
	memset(linky, -1, sizeof linky);
	scanf("%d%d%d", &n0, &n1, &m);
	REP(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y), --x, --y;
		id[x][y] = i;
		int u = 0, v = 0;
		while (linkx[u][x] != -1) ++u;
		while (linky[v][y] != -1) ++v;
		if (u == v) linkx[u][x] = y, linky[u][y] = x;
		else
		{
			int lst = x;
			int now = y;
			linkx[u][x] = y;
			while (1)
			{
				int tmp = linky[u][now];
				linky[u][now] = lst;
				linky[v][now] = tmp;
				if (tmp == -1) break;
				int tmp0 = linkx[v][tmp];
				linkx[v][tmp] = now;
				linkx[u][tmp] = tmp0;
				if (tmp0 == -1) break;
				lst = tmp, now = tmp0;
			}
		}
	}
	REP(i, 0, max(n0, n1)) REP(j, 0, n0) if (linkx[i][j] != -1) ans[id[j][linkx[i][j]]] = i + 1;
	printf("%d\n", *max_element(ans, ans + m));
	REP(i, 0, m) printf("%d ", ans[i]);
	return 0;
}