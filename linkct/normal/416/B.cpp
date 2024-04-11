#include <stdio.h>
int time[50005][6], n, m, fin[50005];
inline int max(int a, int b){return a > b ? a : b;}
int main()
{
	int i, j;
	scanf("%d%d", &m, &n);
	for(i = 1; i <= m; i ++)
		for(j = 1; j <= n; j ++)
			scanf("%d", &time[i][j]);
	for(i = 1; i <= n; i ++)
	{
		int nowt = 0;
		for(j = 1; j <= m; j ++)
		{
			int beg = max(nowt, fin[j]);
			nowt = fin[j] = beg + time[j][i];
		}
	}
	for(i = 1; i <= m; i ++)
		printf("%d ", fin[i]);
	return 0;
}