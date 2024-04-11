#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MN 110
 
int f[3 * MN], sum[3 * MN];
int g[MN][3 * MN], h[MN];
int b[3 * MN], tot = 0;
struct xxx{
	int l, m, r;
}p[MN];
 
bool cmp(xxx a, xxx b) {return a.m < b.m;}
 
int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p[i].l = x - y; p[i].m = x; p[i].r = x + y; 
		b[++tot] = p[i].l;
		b[++tot] = p[i].m;
		b[++tot] = p[i].r;
	}
	std::sort(b + 1, b + tot + 1); tot = std::unique(b + 1, b + tot + 1) - b - 1;
	std::sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n; i++)
	{
		p[i].l = std::lower_bound(b + 1, b + tot + 1, p[i].l) - b;
		p[i].m = std::lower_bound(b + 1, b + tot + 1, p[i].m) - b;
		p[i].r = std::lower_bound(b + 1, b + tot + 1, p[i].r) - b;
	}
	
	for(int i = n; i >= 1; i--)
	{
		if(i == n) h[i] = b[p[i].r] - b[p[i].m];
		else h[i] = h[i + 1] + b[std::min(p[i].r, p[i + 1].m)] - b[p[i].m];
	}
	
	for(int j = 1; j <= tot; j++) g[n + 1][j] = j;
	for(int i = n; i >= 1; i--)
	{
		for(int j = 1; j <= tot; j++)
		{
			if(p[i].m > j) g[i][j] = j;
			else g[i][j] = g[i + 1][std::max(j, p[i].r)];
		}
	}
	
	int x = 0, ans = 0;
	for(int i = 1; i <= tot; i++)
	{
		if(i == p[x + 1].m) x++;
		int Max = 0;
		memset(sum, 0, sizeof(sum));
		for(int j = x + 1; j <= n; j++)
		{
			if(p[j].l > Max) {for(int k = Max + 1; k <= p[j].l; k++) sum[k] = sum[k - 1]; Max = p[j].l;}
			int nxt = g[j + 1][std::max(Max, p[j].m)];
			if(p[j].l < i) f[nxt] = std::max(f[nxt], f[i] + b[nxt] - b[i]);
			else f[nxt] = std::max(f[nxt], f[i] + sum[p[j].l] + b[nxt] - b[p[j].l]);
			if(p[j].m > Max)
			{
				for(int k = Max + 1; k <= p[j].m; k++) sum[k] = sum[k - 1];
				for(int k = p[j].m + 1; k <= p[j].r; k++) sum[k] = sum[k - 1] + b[k] - b[k - 1];
				Max = p[j].r;
			}
			else if(p[j].r > Max)
			{
				for(int k = Max + 1; k <= p[j].r; k++) sum[k] = sum[k - 1] + b[k] - b[k - 1];
				Max = p[j].r;
			}
		}
		ans = std::max(ans, f[i] + h[x + 1]);
	}
	
	printf("%d\n", ans);
}

//ilst[i](lst[i],i)i(g)
//i 
//g[i][j]i(j)
//f[i]i1i