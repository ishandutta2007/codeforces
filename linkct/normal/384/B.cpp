#include <stdio.h>
int arr[1005][105], n, m, k;
int main()
{
	int i, j;
	scanf("%d%d%d", &n, &m, &k);
	printf("%d\n", m * (m - 1) / 2);
	if(k)
		for(i = m; i > 1; i --)
			for(j = m; j > m - i + 1; j --)
				printf("%d %d\n", j, j - 1);
	else
		for(i = m - 1; i; i --)
			for(j = 1; j <= i; j ++)
				printf("%d %d\n", j, j + 1);
	return 0;
}