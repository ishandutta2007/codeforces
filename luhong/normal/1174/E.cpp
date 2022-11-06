#include <cstdio>
#include <iostream>
#define mod 1000000007
#define MN 1010000

int fac[MN], inv[MN];
int cnt2[MN], cnt3[MN], only2[MN];

int C(int a, int b) {return 1ll * fac[a] * inv[b] % mod * inv[a - b] % mod;}

int main()
{
	int n; scanf("%d", &n);
	
	fac[0] = inv[0] = inv[1] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
	for(int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for(int i = 1; i <= n; i++) inv[i] = 1ll * inv[i - 1] * inv[i] % mod;
	 
	int x = 1, p = 0;
	while(2 * x <= n) x *= 2, p++;
	
	for(int i = 1; i <= n; i++)
	{
		int j = i, C = 0;
		while(j % 2 == 0) j /= 2, C++;
		if(j % 3 == 0) cnt3[C]++;
		else only2[C]++;
		cnt2[C]++;
	}
	
	for(int i = p; i >= 0; i--) only2[i] += only2[i + 1];
	
	int s1 = 1, lst = n;
	for(int i = p; i >= 0; i--) s1 = 1ll * s1 * C(lst - 1, cnt2[i] - 1) % mod * fac[cnt2[i]] % mod, lst -= cnt2[i];
	
	if(x / 2 * 3 <= n)
	{
		int s2 = 0, s3 = 1;
		int lst2 = n - 1, lst3 = n;
		for(int i = p - 1; i >= 0; i--)
		{
			s3 = 1ll * s3 * C(lst3 - 1, cnt3[i] - 1) % mod * fac[cnt3[i]] % mod; lst3 -= cnt3[i]; 
			s2 = 1ll * s2 * C(lst2 - 1, cnt2[i] - 1) % mod * fac[cnt2[i]] % mod; lst2 -= cnt2[i];
			s2 = (s2 + 1ll * s3 * C(lst3 - 1, only2[i] - 1) % mod * fac[only2[i]]) % mod;
		}
		s1 = (s1 + s2) % mod;
	}
	
	printf("%d\n", s1);
}