#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map> 
#define MN 1010000

int n, k, a[MN], cnt[MN];
typedef long long ll;
ll b[MN]; int tot = 0;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= 100000; i++)
	{
		ll w = 1;
		for(int j = 1; j <= k; j++)
		{
			w *= i;
			if(w > 1e10) break;
		}
		if(w > 1e10) break;
		b[++tot] = w;
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if(k >= 3)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= tot; j++)
				if(b[j] % a[i] == 0 && b[j] / a[i] <= 100000) ans += cnt[b[j] / a[i]];
			cnt[a[i]]++;
		}
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			int w = a[i]; 
			for(int j = 2; j * j <= w; j++)
			{
				while(w % (j * j) == 0) w /= j * j;
			}
			ans += cnt[w];
			cnt[w]++;
		}
	}
	printf("%lld\n", ans);
}