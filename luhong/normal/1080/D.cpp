#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <set> 
#define MN 501000

typedef long long ll;

int main()
{
	int t; scanf("%d", &t);
	while(t--)
	{
		int n; ll k; scanf("%d%lld", &n, &k);
		ll r = 1;
		ll s = 0;
		ll w = 1;
		ll ans = -1;
		ll p = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			ll o = 1;
			s += r; r = r * 2 + 1; 
			if(s > k) break;
			if(s + p >= k) {ans = i; break;}
			for(int j = i; j >= 1; j--, o *= 4)
			{
				if(s + p + (long double)o * w >= (long double)k - 0.5)
				{
					ans = i; break;
				}
				p += o * w;
			}
			if(ans != -1) break;
			w = w * 2 + 3;
		}
		if(ans != -1) printf("YES %lld\n", ans);
		else puts("NO");
	}
	return 0;
}