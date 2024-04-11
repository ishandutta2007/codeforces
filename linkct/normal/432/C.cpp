#include <stdio.h>
#define MAXN 100005

bool com[MAXN];
int n, a[MAXN], cnt, ans[MAXN * 5][2], pos[MAXN];

int getPrime()
{
	int i, j;
	for(i = 2; i < MAXN; i ++)
		if(!com[i])
			for(j = 2; i * j < MAXN; j ++)
				com[i * j] = true;
	return 0;
}
int init()
{
	getPrime();
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", &a[i]);
		pos[a[i]] = i;
	}
	return 0;
}
void swap(int i, int j)
{
	int x = a[i], y = a[j];
	a[j] = x;
	pos[x] = j;
	a[i] = y;
	pos[y] = i;
	cnt ++;
	ans[cnt][0] = i;
	ans[cnt][1] = j;
}
int solve()
{
	int i, j;
	cnt = 0;
	for(i = 1; i <= n; i ++)
		if(a[i] != i)
		{
			for(j = pos[i] - i + 1; j >= 1; j --)
				if(!com[j])
					break;
			swap(pos[i] - j + 1, pos[i]);
			i --;
		}
	printf("%d\n", cnt);
	for(i = 1; i <= cnt; i ++)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}