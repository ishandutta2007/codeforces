#include <stdio.h>
char str[205];
int n;
int main()
{
	int i, cnt = 0;
	scanf("%d%s", &n, str);
	for(i = 0; i < n; i ++)
		if(str[i] == 'x')
			cnt ++;
	if(cnt < n / 2)
	{
		printf("%d\n", n / 2 - cnt);
		for(i = 0; i < n; i ++)
			if(str[i] == 'X' && cnt < n / 2)
			{
				putchar('x');
				cnt ++;
			}
			else putchar(str[i]);
	}
	else if(cnt > n / 2)
	{
		printf("%d\n", cnt - n / 2);
		for(i = 0; i < n; i ++)
			if(str[i] == 'x' && cnt > n / 2)
			{
				putchar('X');
				cnt --;
			}
			else putchar(str[i]);
	}
	else printf("%d\n%s\n", 0, str);
	return 0;
}