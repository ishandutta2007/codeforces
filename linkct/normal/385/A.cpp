#include <stdio.h>
#define MAXLEN 105

int n, c, num[MAXLEN];

int init()
{
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= n; i ++)
		scanf("%d", &num[i]);
	return 0;
}
int solve()
{
	int i, max = 0;
	for(i = 1; i < n; i ++)
		if(max < (num[i] - num[i + 1]))
			max = num[i] - num[i + 1];
	if(max <= c)
		printf("0");
	else
		printf("%d", max - c);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}