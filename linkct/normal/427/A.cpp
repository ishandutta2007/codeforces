#include <stdio.h>
int main()
{
	int n, i, t, cnt = 0, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &t);
		cnt += t;
		if(cnt < 0)
		{
			cnt = 0;
			ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}