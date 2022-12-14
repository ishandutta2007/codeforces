#include <stdio.h>
#include <algorithm>
#define MAXN 205
using std :: max;
using std :: sort;

int seq[MAXN], n, k, map[MAXN];
bool cmp(const int& a, const int& b){return seq[a] > seq[b];}

int getAns(int s, int t)
{
	int cnt = 0, swaps = 0, i, retval = 0;
	for(i = 1; i <= n; i ++)
	{
		if(map[i] >= s && map[i] <= t)
		{
			retval += seq[map[i]];
			cnt ++;
		}
		else if(swaps < k)
		{
			retval += seq[map[i]];
			cnt ++;
			swaps ++;
		}
		if(cnt == t - s + 1)
			return retval;
	}
	return -1;
}
int main()
{
	int i, j, ans = -2000;
	scanf("%d%d", &n, &k);
	for(i = 1; i <= n; i ++)
	{
		map[i] = i;
		scanf("%d", &seq[i]);
	}
	sort(map + 1, map + 1 + n, cmp);
	for(i = 1; i <= n; i ++)
		for(j = i; j <= n; j ++)
			ans = max(ans, getAns(i, j));
	printf("%d\n", ans);
	return 0;
}