#include <cstdio>
#include <iostream>
#define MN 201000

int a[MN];
int d[31];

int main()
{
	int n; scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] ^= a[i - 1];
	
	if(a[n] == 0) return 0 * puts("-1");
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 30; j >= 0; j--)
		{
			if((a[i] >> j) & 1)
			{
				if(!d[j]) d[j] = a[i], ans++;
				a[i] ^= d[j];
			}
		}
	}
	
	printf("%d\n", ans);
}