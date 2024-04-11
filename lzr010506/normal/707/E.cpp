/*
n*m
pleasure value

 1switch i i
2ask x1 y1 ~ x2 y2

N,M,KNMK
Klen
leni,j,w[i][j]w.

KQ
switch  ask
*/

#include <bits/stdc++.h>
#define F first
#define S second
#define M 2010
#define ll long long
using namespace std;
const int N = 1 << 11;
vector<pair<int, ll> > h[N][N];
int g[M][M], vis[M], val[M][M];

inline ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void ins(int i, int j, int X1, int Y1, int X2, int Y2, int y, int x, int k, ll w)
{
	if (y < X1 || y > Y1 || x < X2 || x > Y2) return;
	if (X1 == Y1)
	{
		g[y][x] = k;
		val[y][x] = w;
		return;
	}
	if ((int) h[i][j].size() > 0 && h[i][j].back().F == k) h[i][j].back().S += w;
	else h[i][j].push_back({k, w});
	if (X1 < Y1)
	{
		int ym = (X1 + Y1) >> 1;
		int xm = (X2 + Y2) >> 1;
		ins(i << 1, j << 1, X1, ym, X2, xm, y, x, k, w);
		ins(i << 1 | 1, j << 1, ym + 1, Y1, X2, xm, y, x, k, w);
		ins(i << 1, j << 1 | 1, X1, ym, xm + 1, Y2, y, x, k, w);
		ins(i << 1 | 1, j << 1 | 1, ym + 1, Y1, xm + 1, Y2, y, x, k, w);
	}
}

ll que(int i, int j, int X1, int Y1, int X2, int Y2, int y1, int y2, int x1, int x2)
{
	if (y2 < X1 || y1 > Y1 || x2 < X2 || x1 > Y2) return 0;
	if (y1 <= X1 && Y1 <= y2 && x1 <= X2 && Y2 <= x2)
	{
		if (X1 == Y1)
		{
			if (vis[g[X1][X2]]) return val[X1][X2];
			else return 0;
		}
		ll ret = 0;
		for (auto t: h[i][j])
			if (vis[t.F]) ret += t.S;
		
		return ret;
	}
	else
	{
		int ym = (X1 + Y1) / 2;
		int xm = (X2 + Y2) / 2;
		ll r = 0;
		r += que(i << 1, j << 1, X1, ym, X2, xm, y1, y2, x1, x2);
		r += que(i << 1 | 1, j << 1, ym + 1, Y1, X2, xm, y1, y2, x1, x2);
		r += que(i << 1, j << 1 | 1, X1, ym, xm + 1, Y2, y1, y2, x1, x2);
		r += que(i << 1 | 1, j << 1 | 1, ym + 1, Y1, xm + 1, Y2, y1, y2, x1, x2);
		return r;
	}
}
char sr[22];
int main()
{
	int n,m,k;
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= k; i ++)
	{
		int len;
		len = read();
		for (int j = 0; j < len; j ++)
		{
			int y,x,w;
			y = read();
			x = read();
			w = read();
			ins(1, 1, 0, N - 1, 0, N - 1, y, x, i, w);
		}
		vis[i] = 1;
		if (i % 1000 == 0 || i == k)
			for(int j = 0; j < N; j ++)
				for(int k = 0; k < N; k ++)
					h[j][k].shrink_to_fit();
	}
	int q;
	q = read();
	for (int i = 0; i < q; i ++)
	{
		scanf("%s", sr);
		if (sr[0]=='S')
		{
			int j;
			j = read();
			vis[j] ^= 1;
		}
		else
		{
			int x1,y1,x2,y2;
			x1 = read();
			y1 = read();
			x2 = read();
			y2 = read();
			printf("%I64d\n", que(1, 1, 0, N-1, 0, N-1, x1, x2, y1, y2));
		}
	}
	return 0;
}
/*
1(i, j)1
2(i, j)0
3i10,01
4k
*/

/*
n*m
pleasure value

 1switch i i
2ask x1 y1 ~ x2 y2

N,M,KNMK
Klen
leni,j,w[i][j]w.

KQ
switch  ask
*/