#include <cstdio>
#include <iostream>
#define mod 1000000007
#define MN 3010

int ch[MN * MN][2], tot = 0;
int id[MN][MN];
int f[MN][MN];
int a[MN], ans = 0;

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		f[i][i - 1] = 1;
		for(int j = 1; j <= i; j++)
		{
			int x = id[j][i - 1];
			if(!ch[x][a[i]]) ch[x][a[i]] = ++tot;
			id[j][i] = ch[x][a[i]];
			for(int k = std::max(1, i - 3); k <= i; k++)
			{
				if(k == i - 3 && (!a[i - 3] && !a[i - 2] && a[i - 1] && a[i] || !a[i - 3] && a[i - 2] && !a[i - 1] && a[i] || a[i - 3] && a[i - 2] && a[i - 1] && !a[i] || a[i - 3] && a[i - 2] && a[i - 1] && a[i])) continue;
				f[j][i] = (f[j][i] + f[j][k - 1]) % mod;
			}
			if(id[j][i] == tot)	ans = (ans + f[j][i]) % mod;
		}
		printf("%d\n", ans);
	}
}