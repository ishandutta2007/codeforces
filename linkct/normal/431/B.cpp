#include <stdio.h>

int arrange[6], weight[6][6], ans;
bool vis[6];
inline int max(int a, int b){return a > b ? a : b;}
inline int calc()
{
	int i = 1, j, retval = 0;
	for(i = 1; i <= 5; i ++)
		for(j = i; j < 5; j += 2)
			retval += weight[arrange[j]][arrange[j + 1]] + weight[arrange[j + 1]][arrange[j]];
	return retval;
}
void dfs(int x)
{
	if(x == 6)
	{
		ans = max(ans, calc());
		return;
	}
	for(int i = 1; i <= 5; i ++)
		if(!vis[i])
		{
			vis[i] = true;
			arrange[x] = i;
			dfs(x + 1);
			vis[i] = false;
		}
}
int main()
{
	for(int i = 1; i <= 5; i ++)
		for(int j = 1; j <= 5; j ++)
			scanf("%d", &weight[i][j]);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}