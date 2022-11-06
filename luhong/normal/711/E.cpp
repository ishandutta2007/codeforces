#include <iostream>
#include <cstring>
#include <cstdio>
#define mod 1000003
#define inv 500002

typedef long long ll;
ll n, k;

ll qpow(ll x, ll p)
{
	ll ans = 1;
	while(p)
	{
		if(p & 1) ans = ans * x % mod;
		x = x * x % mod; p >>= 1;
	}
	return ans;
}

int main()
{	
	scanf("%lld%lld", &n, &k); 
	if(n <= 62 && k > (1ll << n)) return 0 * puts("1 1");
	k--;
	if(k <= 2 * mod)
	{
		ll v = qpow(2, n), ans = 1;
		for(int i = 1; i <= k; i++)
		{
			int j;
			ll V = v;
			for(j = 0; j <= 30; j++)
				if((i >> j) & 1) break;
				else V = V * inv % mod;
			ans = ans * (V - i / (i & -i) % mod + mod) % mod;
		}
		
		int y = 0;
		for(int i = 60; i >= 0; i--)
			if((k >> i) & 1) y++;
		ll w = k - y;
		ll Mod = mod - 1;
		ll t = qpow(2, ((n % Mod * k % Mod - w) % Mod + Mod) % Mod);
		
		printf("%lld %lld\n", (t - ans + mod) % mod, t);
	}
	else
	{
		int y = 0;
		for(int i = 60; i >= 0; i--)
			if((k >> i) & 1) y++;
		ll w = k - y;
		ll Mod = mod - 1;
		ll t = qpow(2, ((n % Mod * (k % Mod) - w) % Mod + Mod) % Mod);
		
		printf("%lld %lld\n", t, t);
	}
}