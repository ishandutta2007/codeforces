#include <iostream>
#include <cstdio>
#define MN 101000

int f[MN], g[MN], h[MN], l[MN], r[MN];
int L, n, p, t; 

void calc(int v, int w, int i)
{
	v += (r[i] - w) / p + 1;
	w += (r[i] - w) / p * p;
	if(v == f[i] && w < g[i] || v > f[i]) f[i] = v, g[i] = w;
}

int main()
{
	scanf("%d%d%d%d", &L, &n, &p, &t); t += p;
	int j = 0;
	for(int i = 1; i <= n; i++)
	{
		int L, R;
		scanf("%d%d", &L, &R);
		R -= p;
		if(L <= R) ++j, l[j] = L, r[j] = R;
	}
	n = j;
	int id = 1, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		h[i] = std::max(h[i], h[i - 1]);
		calc(h[i], l[i], i);
		ans = std::max(ans, f[i]);
		while(id <= n && g[i] + t > r[id]) id++;
		if(id == n + 1) continue;
		int x;
		if(g[i] + t >= l[id])
		{
			x = id + 1; 
			calc(f[i], g[i] + t, id);
		}
		else x = id;
		if(x <= n) h[x] = std::max(h[x], f[i]);
	}
	printf("%d\n", ans);
}