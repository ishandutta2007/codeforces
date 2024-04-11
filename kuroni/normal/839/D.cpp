#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;
int n, i, pw[1000005], t, j, maxa = 0;
long long a[1000005], ans = 0;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &t);
		maxa = max(maxa, t);
		for (j = 1; j <= sqrt(t); j++)
			if (t % j == 0)
			{
				++a[j];
				if (j * j != t)
					++a[t / j];
			}
	}
	pw[0] = 1;
	for (i = 1; i <= maxa; i++)
		pw[i] = pw[i - 1] * 2 % mod;
	for (i = maxa; i >= 2; i--)
	{
		a[i] *= pw[a[i] - 1]; a[i] %= mod;
		for (j = 2; j <= maxa / i; j++)
		{
			a[i] -= a[i * j];
			a[i] = (a[i] % mod + mod) % mod;
		}
		ans += a[i] * i; ans %= mod;
	}
	printf("%I64d", ans);
}