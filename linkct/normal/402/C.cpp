#include <stdio.h>
#include <string.h>
#define MAXN 25

int n, p, testcase;
bool g[MAXN][MAXN];

int init()
{
	scanf("%d%d", &n, &p);
	return 0;
}
int solve()
{
	int cnt = 0, i, j;
	for(i = 1; i <= n; i ++)
	{
		if(i < n - 1)
		{
			cnt ++;
			g[i][i + 2] = true;
			printf("%d %d\n", i, i + 2);
		}
		if(i < n)
		{
			cnt ++;
			g[i][i + 1] = true;
			printf("%d %d\n", i, i + 1);
		}
	}
	for(i = 1; i <= n && cnt != 2 * n + p; i ++)
		for(j = i + 3; j <= n && cnt != 2 * n + p; j ++)
			if(!g[i][j])
			{
				g[i][j] = true;
				printf("%d %d\n", i, j);
				cnt ++;
			}
	return 0;
}
int main()
{
	scanf("%d", &testcase);
	while(testcase --)
	{
		memset(g, false, sizeof(g));
		init();
		solve();
	}
	return 0;
}