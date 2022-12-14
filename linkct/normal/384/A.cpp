#include <stdio.h>
int main()
{
	int n, i, j;
	scanf("%d", &n);
	printf("%d\n", n % 2 ? n * n / 2 + 1 : n / 2 * n);
	for(i = 1; i <= n; i ++)
	{
		for(j = 1; j <= n; j ++)
			printf("%c", (i & 1) ^ (j & 1) ^ 1 ? 'C' : '.');
		printf("\n");
	}
	return 0;
}