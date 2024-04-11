#include <stdio.h>
#define MAXN 100005

int home[MAXN], n;
struct data
{
	int home, out;
}team[MAXN];

int main()
{
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d%d", &team[i].home, &team[i].out);
		home[team[i].home] ++;
	}
	for(i = 1; i <= n; i ++)
		printf("%d %d\n", n + home[team[i].out] - 1, n - home[team[i].out] - 1);
	return 0;
}