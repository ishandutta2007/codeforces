#include <cstdio>
#include <iostream>
#include <cstring>
#define MN 300010

int f[MN][19];
bool ok[MN][19];
int nxt[19];

int main()
{
	memset(f, 0x3f, sizeof(f));
	int n, q; scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		for(int j = 0; j <= 18; j++) 
			if((x >> j) & 1) ok[i][j] = 1, f[i][j] = i;
	}
	for(int i = n; i >= 1; i--)
	{
		for(int j = 0; j <= 18; j++)
		{
			if(!ok[i][j]) continue;
			if(nxt[j]) 
				for(int k = 0; k <= 18; k++)
					f[i][k] = std::min(f[nxt[j]][k], f[i][k]);
			nxt[j] = i;
		}
	}
	for(int i = 1; i <= q; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
		bool okk = 0;
		for(int j = 0; j <= 18; j++)
			if(ok[b][j] && f[a][j] <= b) {okk = 1; break;}
		if(okk) puts("Shi");
		else puts("Fou");
	}
	return 0;
}