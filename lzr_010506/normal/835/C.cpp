#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
int n, q, c;
int a[11][110][110];
int x[100010], y[100010], s[100010];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	q = read();
	c = read();
	rep(i, 1, n)
	{
		x[i] = read();
		y[i] = read();
		s[i] = read();
	}
	rep(i, 0, c)
	{
		rep(j, 1, n)
			a[i][x[j]][y[j]] += (s[j] + i) % (c + 1);
		rep(u, 1, 100)
			rep(v, 1, 100)
				a[i][u][v] += a[i][u - 1][v] + a[i][u][v - 1] - a[i][u - 1][v - 1];
	}
	
	while(q --)
	{
		int t, xx, yy, xx1, yy1;
		t = read();
		xx = read();
		yy = read();
		xx1 = read();
		yy1 = read();
		t = t % (c + 1);
		printf("%d\n", a[t][xx1][yy1] - a[t][xx1][yy - 1] - a[t][xx - 1][yy1] + a[t][xx - 1][yy - 1]);
	}
	
	return 0;
}