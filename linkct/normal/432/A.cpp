#include <stdio.h>

int main()
{
	int n, i, k, t, ans = 0;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &t);
		if(5 - t >= k)
			ans ++;
	}
	printf("%d\n", ans / 3);
	return 0;
}