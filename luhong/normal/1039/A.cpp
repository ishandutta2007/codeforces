#include <cstdio>
#include <algorithm>

long long b[201000], a[201000], t; int x[201000];
int main()
{
	int n; scanf("%d%lld", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		if(x[i] < x[i - 1] || x[i] < i) return 0 * puts("No");
	}
	for(int i = 1; i <= n; i++) //ix[i]a[i]b[i-1]
	{
		for(int k = i; k <= x[i] - 1; k++) b[k] = std::max(b[k - 1] + 1, a[k + 1] + t);
		if(i == x[i]) b[x[i]] = std::max(b[x[i] - 1] + 1, a[x[i]] + t), i = x[i];
		else i = x[i] - 1;
	}
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		if(x[i] == n) break;
		if(j <= i)
		{
			while(j <= x[i])
			{
				j++;
				if(b[j - 1] < a[j] + t) break;
				if(j == x[i] + 1) return 0 * puts("No");
			}
		}
	}
	puts("Yes");
	for(int i = 1; i <= n; i++) printf("%lld ", b[i]);
	return 0;
}