#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset> 
#define MN 26
#define MA 50100 

std::bitset<1250001> f[MN * 2][MN];
int sum = 0, ans = 1e9, id;
int a[MN * 2], used[MN * 2];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
	std::sort(a + 1, a + 2 * n + 1);
	f[2][0][0] = 1;
	for(int i = 3; i <= 2 * n; i++) 
	{
		sum += a[i];
		for(int j = 0; j <= n - 1; j++)
		{
			f[i][j] = f[i - 1][j];
			if(j) f[i][j] = f[i][j] | (f[i - 1][j - 1] << a[i]);
		}
	}
	for(int i = 0; i <= 1250000; i++)
	{
		if(f[2 * n][n - 1][i] && std::max(i, sum - i) <= ans)
		{
			ans = std::max(i, sum - i);
			id = i; 
		}
	}
	int k = n - 1;
	for(int i = 2 * n; i >= 3; i--)
	{
		if(f[i - 1][k][id]) used[i] = 0;
		else used[i] = 1, id -= a[i], k--;
	}
	
	printf("%d ", a[1]); for(int i = 3; i <= 2 * n; i++) if(used[i]) printf("%d ", a[i]); puts("");
	for(int i = 2 * n; i >= 3; i--) if(!used[i]) printf("%d ", a[i]); printf("%d ", a[2]);
}