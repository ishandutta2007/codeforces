#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>

int n;
long long f[101000];

long long S(int x)
{
	int g = n / x;
	return 1ll * (n - x) * g / 2 + g;
}
int main()
{
	scanf("%d", &n);
	int tot = 0;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			f[++tot] = S(i);
			f[++tot] = S(n / i);
		}
	}
	std::sort(f + 1, f + tot + 1);
	tot = std::unique(f + 1, f + tot + 1) - f - 1; 
	for(int i = 1; i <= tot; i++) printf("%lld ", f[i]);
}