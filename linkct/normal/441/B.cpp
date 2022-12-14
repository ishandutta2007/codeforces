#include <stdio.h>
#define MAXN 3005

int fruit[MAXN][2], n, v, maxd;

int init()
{
	int i, a, b;
	scanf("%d%d", &n, &v);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d%d", &a, &b);
		fruit[a][1] += b;
		fruit[a + 1][0] += b;
		if(a + 1 > maxd)
			maxd = a + 1;
	}
	return 0;
}
inline int min(int a, int b){return a > b ? b : a;}
int solve()
{
	int i, delta, temp, ans = 0;
	for(i = 1; i <= maxd; i ++)
	{
		delta = min(fruit[i][0], v);
		temp = v - delta;
		ans += delta;
		delta = min(fruit[i][1], temp);
		fruit[i][1] -= delta;
		fruit[i + 1][0] -= delta;
		ans += delta;
	}
	printf("%d\n", ans);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}