#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring> 

long long x[101000];

int Abs(int x) {return x > 0 ? x : -x;}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 2; i <= n; i += 2) scanf("%lld", &x[i]);
	long long lst = 0;
	for(int i = 2; i <= n; i += 2)
	{
		long long now = 0;
		for(int j = 1; j * j <= x[i]; j++)
		{
			if(x[i] % j == 0)
			{
				int u = x[i] / j, v = j;
				if((u + v) % 2 == 1) continue;
				int a = u + v >> 1;
				int b = u - v >> 1;
				b = Abs(b);
				if(b > lst)
				{
					now = a;
					x[i - 1] = 1ll * b * b - 1ll * lst * lst;
				}
			}
		}
		if(!now) return 0 * puts("No");
		lst = now;
	}
	puts("Yes");
	for(int i = 1; i <= n; i++) printf("%lld ", x[i]);
}