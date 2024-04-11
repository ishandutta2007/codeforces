#include <stdio.h>

int a[105][105], n, m, ans;

bool check(int start_pos, int len)
{
	for(int i = 1; i <= m; i ++)
		for(int j = 0; j < len; j ++)
			if(a[start_pos + j][i] != a[start_pos + 2 * len - 1 - j][i])
				return false;
	return true;
}
void recur(int len)
{
	int i;
	for(i = 1; i <= n; i += 2 * len)
		if(!check(i, len))
			return;
	ans = len;
	if(len % 2)
		return;
	recur(len >> 1);
}
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	ans = n;
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			scanf("%d", &a[i][j]);
	if(!(n % 2))
		recur(n >> 1);
	printf("%d\n", ans);
	return 0;
}