#include <iostream>
#include <cstdio>
#include <cstring>
#define LOG 8 

int f[9][310][310], g[310][310], h[310][310];

int main()
{
	memset(f, -0x3f, sizeof(f));
	memset(g, -0x3f, sizeof(g));
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int u, v, c1, c2; scanf("%d%d%d%d", &u, &v, &c1, &c2);
		f[0][u][v] = c1; f[0][v][u] = c2;
	}
	for(int i = 1; i <= n; i++) f[0][i][i] = 0, g[i][i] = 0;
	for(int i = 1; i <= LOG; i++)
		for(int j = 1; j <= n; j++)
			for(int l = 1; l <= n; l++)
				for(int k = 1; k <= n; k++)
				{
					f[i][j][k] = std::max(f[i][j][k], f[i - 1][j][l] + f[i - 1][l][k]); 
				}
	bool flag = 0; int ans = 0;
	for(int i = LOG; i >= 0; i--)
	{
		for(int j = 1; j <= n; j++)
			for(int l = 1; l <= n; l++) h[j][l] = g[j][l];
		for(int j = 1; j <= n; j++)
			for(int l = 1; l <= n; l++)
				for(int k = 1; k <= n; k++)
				{
					g[j][k] = std::max(g[j][k], h[j][l] + f[i][l][k]);
				}
		bool ok = 0;
		for(int j = 1; j <= n; j++) if(g[j][j] > 0) {ok = 1; break;}
		if(ok)
		{
			flag = 1;
			for(int j = 1; j <= n; j++)
				for(int l = 1; l <= n; l++) g[j][l] = h[j][l];
		}
		else ans += 1 << i;
	}
	if(!flag) puts("0");
	else printf("%d\n", ans + 1);
	return 0;
}