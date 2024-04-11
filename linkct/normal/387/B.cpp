#include <stdio.h>
#define MAXLEN 3005

int a[MAXLEN], b[MAXLEN], n, m;

int init()
{
	int i;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i ++)
		scanf("%d", &a[i]);
	for(i = 1; i <= m; i ++)
		scanf("%d", &b[i]);
	return 0;
}
int solve()
{
	int i = n, j = m, ans = 0;//i for a and j for b
	while(i > 0 && j > 0)
	{
		if(b[j] >= a[i])
		{
			i --;
			j --;
		}
		else
		{
			ans ++;
			i --;
		}
	}
	printf("%d", i + ans);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}