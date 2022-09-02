#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 1000, maxm = 1000;

int n, m;
char c[maxn + 5][maxm + 5];

int ans = oo;

void init()
{
	scanf("%d%d", &n, &m);
	memset(c, 0, sizeof c);
	REP(i, 0, n)
	{
		scanf("\n");
		REP(j, 0, m)
			scanf("%c", &c[i][j]);
	}
}

void output()
{
	printf("%d\n", ans == oo ? -1 : ans);
}

bool vis[maxn + 5][maxm + 5];

void print(const int &x0, const int &y0, const int &x1, const int &y1)
{
	for (int i = x1; i >= x0; --i)
	{
		if (vis[i][y1]) break;
		for (int j = y1; j >= y0; --j)
		{
			if (vis[i][j]) break;
			vis[i][j] = 1;
		}
	}
}

void work()
{
	int xx = -1, yy = -1;
	REP(i, 0, n)
		REP(j, 0, m)
			if (c[i][j] == 'X')
			{
				xx = i, yy = j;
				goto label;
			}
label:;
	if (xx == -1)
	{
		ans = 0;
		return;
	}
	int ydc = m;
	REP(j, yy, m)
		if (c[xx][j] == '.')
		{
			ydc = j;
			break;
		}
	int vfk = ydc;
	ydc -= yy;
	int lyc = -1;
	int hza = n;
	REP(j, xx, n)
	{
		if (c[j][vfk] == 'X')
		{
			vfk = m;
			lyc = j;
		}
		if (c[j][yy] == '.')
		{
			hza = j;
			break;
		}
	}
	if (lyc == -1) lyc = 1;
	else lyc = hza - lyc;
	memset(vis, 0, sizeof vis);
logic:;	
	print(xx, yy, xx + lyc - 1, yy + ydc - 1);
	if (c[xx][yy + ydc] == 'X') 
	{
		++yy;
		goto logic;
	}
	if (c[xx + lyc][yy] == 'X')
	{
		++xx;
		goto logic;
	}
	REP(i, 0, n)
		REP(j, 0, m)
			if (vis[i][j] ^ (c[i][j] == 'X')) return;
	ans = min(ans, lyc * ydc);
}

char g[maxn + 5][maxm + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	work();
	memset(g, 0, sizeof g);
	REP(i, 0, n)
		REP(j, 0, m)
			g[j][i] = c[i][j];
	memcpy(c, g, sizeof c);
	swap(n, m);
	work();
	output();
	return 0;
}