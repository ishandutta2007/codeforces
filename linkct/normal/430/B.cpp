#include <stdio.h>
#define N 105
#define num 0
#define col 1

int arr[N], n, x, k, reduce[N][2], pos;

int try_insert(int x)
{
	int retval = reduce[x][num], i = x - 1, j = x + 1;
	while(i >= 1 && j <= pos && reduce[i][col] == reduce[j][col] && reduce[i][num] + reduce[j][num] >= 3)
	{
		retval += reduce[i][num] + reduce[j][num];
		i --;
		j ++;
	}
	return retval;
}
inline int max(int a, int b){return a > b ? a : b;}
int main()
{
	int i, cnt, ans = 0;
	scanf("%d%d%d", &n, &k, &x);
	for(i = 1; i <= n; i ++)
		scanf("%d", &arr[i]);
	cnt = 1;
	pos = 0;
	for(i = 2; i <= n + 1; i ++)
		if(arr[i] != arr[i - 1])
		{
			reduce[++ pos][0] = cnt;
			reduce[pos][1] = arr[i - 1];
			cnt = 1;
		}
		else
			cnt ++;
	for(i = 1; i <= pos; i ++)
		if(reduce[i][col] == x && reduce[i][num] > 1)
			ans = max(ans, try_insert(i));
	printf("%d\n", ans);
	return 0;
}