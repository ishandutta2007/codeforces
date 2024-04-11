#include <stdio.h>
int main()
{
	int n, s, i, t, cnt = 0, maxv = 0;
	scanf("%d%d", &n, &s);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &t);
		cnt += t;
		if(t > maxv)
			maxv = t;
	}
	if(cnt - maxv <= s)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}