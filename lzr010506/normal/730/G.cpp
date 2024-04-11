#include <bits/stdc++.h>
#define FOR(i, x, y) for((i) = (x); (i) <= (y); (i) ++)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
struct Node
{
	int l,r,xh;
	bool friend operator <(const Node &a,const Node &b)
	{
		if(a.l == b.l)return a.r < b.r;
		return a.l < b.l;
	}
}a[210];
int i, j, n, cnt, x, b;
int main()
{
	n = read();
	FOR(i, 1, n)
	{
		x = read();
		b = read();
		FOR(j, 1, cnt)
			if(a[j].l <= x + b - 1 && a[j].r >= x) break;
		if(j <= cnt)
		{
			if(a[1].l > b) a[++ cnt] = (Node){1,b,i};
			else
			{
				FOR(j, 1, cnt) if(a[j + 1].l - a[j].r > b)break;
				if(j <= cnt) a[++ cnt] = (Node){a[j].r + 1, a[j].r + b,i};
				else a[++ cnt] = (Node){a[cnt - 1].r + 1, a[cnt - 1].r + b,i};
			}
		}
		else a[++ cnt] = (Node){x, x + b - 1, i};
		sort(a + 1, a + 1 + cnt);
	}
	FOR(i, 1, n)
		FOR(j, 1, n)
			if(a[j].xh == i)
			{
				printf("%d %d\n", a[j].l, a[j].r);
				break;
			}
	return 0;
}