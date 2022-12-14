#include <stdio.h>
#define MAXN 300

int n, p;
bool hash[MAXN];

int main()
{
	int x;
	scanf("%d%d", &p, &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &x);
		if(hash[x % p])
		{
			printf("%d\n", i);
			return 0;
		}
		hash[x % p] = true;
	}
	printf("-1\n");
	return 0;
}