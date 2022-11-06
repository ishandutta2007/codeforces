#include <cstdio>
#include <iostream>
#define mod 998244353

int a[201000];

int main()
{
	int ans = 1;
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i += 2)
	{
		int k1 = 1, k2 = 0;
		if(a[i] == -1)
		{
			int I = i - 2; i += 2;
			while(i <= n && a[i] == -1)
			{
				if(I < 1)
				{
					k1 = 1ll * k1 * (k - 1) % mod;
				}
				else
				{
					int t1 = (k2 + 1ll * k1 * (k - 2) % mod) % mod;
					int t2 = 1ll * k1 * (k - 1) % mod;
					k1 = t1; k2 = t2;
				}
				i += 2;
			}
			
			if(I >= 1 && i <= n && a[i] == a[I]) ans = 1ll * ans * (k - 1) % mod * k1 % mod;
			else
			{
				int b = 0; 
				if(I < 1) b++; if(i > n) b++;
				ans = 1ll * ans * (1ll * (k - 2 + b) * k1 % mod + k2) % mod;
			}
		}
		else if(i - 2 > 0 && a[i] == a[i - 2]) ans = 0;
	}
	
	for(int i = 2; i <= n; i += 2)
	{
		int k1 = 1, k2 = 0;
		if(a[i] == -1)
		{
			int I = i - 2; i += 2;
			while(i <= n && a[i] == -1)
			{
				if(I < 1)
				{
					k1 = 1ll * k1 * (k - 1) % mod;
				}
				else
				{
					int t1 = (k2 + 1ll * k1 * (k - 2) % mod) % mod;
					int t2 = 1ll * k1 * (k - 1) % mod;
					k1 = t1; k2 = t2;
				}
				i += 2;
			}
			
			if(I >= 1 && i <= n && a[i] == a[I]) ans = 1ll * ans * (k - 1) % mod * k1 % mod;
			else
			{
				int b = 0; 
				if(I < 1) b++; if(i > n) b++;
				ans = 1ll * ans * (1ll * (k - 2 + b) * k1 % mod + k2) % mod;
			}
		}
		else if(i - 2 > 0 && a[i] == a[i - 2]) ans = 0;
	}
	printf("%d\n", ans);
}