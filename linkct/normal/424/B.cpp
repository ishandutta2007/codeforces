#include <stdio.h>
#include <math.h>
#include <algorithm>
using std :: sort;
struct point
{
	int x, y, w;
	bool operator < (const point& a) const
	{
		return sqrt(x * x + y * y) < sqrt(a.x * a.x + a.y * a.y);
	}
}p[1005];
int n, amo, cnt, i;
int main()
{
	scanf("%d%d", &n, &amo);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].w);
		cnt += p[i].w;
	}
	sort(p + 1, p + 1 + n);
	if(cnt + amo < 1000000)
	{
		printf("-1\n");
		return 0;
	}
	i = 1;
	while(amo < 1000000)
		amo += p[i ++].w;
	printf("%.10f\n", sqrt(p[i - 1].x * p[i - 1].x + p[i - 1].y * p[i - 1].y));
	return 0;
}