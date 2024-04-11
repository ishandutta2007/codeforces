#include <cstdio>
#include <iostream>
#define MN 201000

int f[MN][2], g[MN][2];
int a[MN], ans[MN];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	f[0][0] = 1e9, f[0][1] = -1e9;
	for(int i = 1; i <= n; i++)
	{
		f[i][0] = -1e9, f[i][1] = 1e9;
		if(i == 1 || a[i] > a[i - 1])
		{
			f[i][0] = f[i - 1][0];
			g[i][0] = 0;
		}
		if(a[i] > f[i - 1][1] && a[i - 1] > f[i][0])
		{
			f[i][0] = a[i - 1];
			g[i][0] = 1;
		}
		if(i == 1 || a[i] < a[i - 1])
		{
			f[i][1] = f[i - 1][1];
			g[i][1] = 1;
		}
		if(a[i] < f[i - 1][0] && a[i - 1] < f[i][1])
		{
			f[i][1] = a[i - 1];
			g[i][1] = 0;
		}
		if(f[i][0] == (int)-1e9 && f[i][1] == (int)1e9) return 0 * puts("NO");
	}
	puts("YES");
	int lst = 0;
	if(f[n][1] != (int)1e9) lst = 1;
	for(int i = n; i >= 1; i--) ans[i] = lst, lst = g[i][lst];
	for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

//f[i][0/1]i///