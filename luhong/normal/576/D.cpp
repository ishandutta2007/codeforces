#include <iostream>
#include <algorithm> 
#include <cstdio>
#include <bitset>
#define MN 152

int n, m; 

struct edge {
	int a, b, d;
}e[MN];

struct xxx {
	std::bitset<MN> r[MN];
	std::bitset<MN> c[MN];
}st[30], now;

bool cmp(edge a, edge b) {return a.d < b.d;}

xxx operator * (xxx a, xxx b)
{
	xxx c; 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			c.r[i][j] = c.c[j][i] = ((a.r[i] & b.c[j]).count() > 0);
	return c;
}

int main()
{
	scanf("%d%d", &n, &m); ++m;
	for(int i = 2; i <= m; i++) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].d);
	
	std::sort(e + 2, e + m + 1, cmp);
	e[1].a = n; e[1].b = n; e[1].d = 0;
	int ans = 0; now.r[1][1] = now.c[1][1] = 1;
	e[m + 1].d = (int)1e9 + 200;
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				st[0].r[j][k] = st[0].c[k][j] = 0;
		
		for(int j = 1; j <= i; j++)
			st[0].r[e[j].a][e[j].b] = st[0].c[e[j].b][e[j].a] = 1;
		
		for(int j = 1; j < 30; j++) st[j] = st[j - 1] * st[j - 1];
		
		for(int j = 29; j >= 0; j--)
		{
			if(ans + (1 << j) <= e[i + 1].d && !(now * st[j]).r[1][n])
				now = now * st[j], ans += (1 << j);
		}
	}
	
	if(ans >= (int)1e9 + 151) puts("Impossible");
	else printf("%d\n", ans + 1);
}