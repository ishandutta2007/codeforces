#include <stdio.h>

int ans[55];
int main()
{
	int n, v, i, j, cnt, t;
	bool sign;
	scanf("%d%d", &n, &v);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &cnt);
		sign = false;
		for(j = 1; j <= cnt; j ++)
		{
			scanf("%d", &t);
			if(t < v)
				sign = true;
		}
		if(sign)
			ans[++ ans[0]] = i;
	}
	printf("%d\n", ans[0]);
	for(i = 1; i <= ans[0]; i ++)
		printf("%d ", ans[i]);
	return 0;
}