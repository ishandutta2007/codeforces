#include <cstdio>
#include <iostream>

int a[301000], m, n;

bool solve(int x)
{
	int lst = 0;
	for(int i = 1; i <= n; i++)
	{
		if((lst - a[i] + m) % m > x)
		{
			if(lst < a[i]) lst = a[i];
			else return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]); 
	int L = 0, R = m;
	while(L < R)
	{
		int mid = L + R >> 1;
		if(solve(mid)) R = mid;
		else L = mid + 1;
	}
	printf("%d\n", R); return 0;
}