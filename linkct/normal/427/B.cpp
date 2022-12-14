#include <stdio.h>
int main()
{
	int n, t, c, i, temp, lastpos = 0, ans = 0;
	scanf("%d%d%d", &n, &t, &c);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &temp);
		if(temp > t)
		{
			if(lastpos && i - lastpos >= c)
				ans += i - lastpos - c + 1;
			lastpos = 0;
		}
		else
			if(!lastpos)
				lastpos = i;
	}
	if(lastpos && n - lastpos + 1 >= c)
		ans += n - lastpos + 2 - c;
	printf("%d\n", ans);
	return 0;
}