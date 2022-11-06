#include <iostream>
#include <cstdio>

typedef long long ll;

ll f[65];
int mu[65], pri[65], tot = 0;
bool ok[65];

ll qpow(ll x, int p)
{
	ll ans = 1;
	while(p)
	{
		if(p & 1)
		{
			if((long double)ans * x >= 2e18) return (ll)2e18;
			ans = ans * x;
		}
		if(p / 2 > 0 && (long double)x * x >= 2e18) return (ll)2e18;
		x = x * x; p >>= 1;
	}
	return ans;
}

ll solve(ll x, int p)
{
	ll l = 1, r = (ll)1e9 + 1;
	while(l < r)
	{
		ll mid = l + r >> 1;
		if(qpow(mid, p) <= x) l = mid + 1;
		else r = mid;
	}
	return r - 1;
}

void init()
{
	mu[1] = 1;
	for(int i = 2; i <= 60; i++)
	{
		if(!ok[i]) pri[++tot] = i, mu[i] = -1;
		for(int j = 1; j <= tot && i * pri[j] <= 60; j++)
		{
			ok[i * pri[j]] = 1;
			if(i % pri[j] == 0) {mu[i * pri[j]] = 0; break;}
			mu[i * pri[j]] = -mu[i];
		}
	}
}

int main()
{
	init();
	int T; scanf("%d", &T);
	while(T--)
	{
		ll n; scanf("%lld", &n);
		ll x = 2;
		for(int i = 60; i >= 10; i--)
		{
			while(qpow(x, i) <= n) x++;
			f[i] = x - 2;
		}
		for(int i = 9; i >= 2; i--)
		{
			f[i] = solve(n, i) - 1;
		}
		ll ans = n - 1;
		for(int i = 2; i <= 60; i++) ans += mu[i] * f[i];
		printf("%lld\n", ans);
	}
}