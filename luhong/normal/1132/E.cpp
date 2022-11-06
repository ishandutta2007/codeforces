#include <cstdio>
#include <iostream>
#include <cstring>

typedef long long ll;

bool f[9][13441];
ll cnt[9], sum[13441];

ll get(ll x)
{
	x = std::min(x, 13440ll);
	for(int i = x; i >= 0; i--)
		if(f[8][i]) return i;
}

int main()
{
	ll w; scanf("%lld", &w);
	ll s = 0, ans = 0;
	for(int i = 1; i <= 8; i++)
	{
		int t = 840 / i;
		scanf("%lld", &cnt[i]);
		if(cnt[i] >= 2 * t)
		{
			s += cnt[i] / t - 1;
			cnt[i] = cnt[i] % t + t;
		}
	}
	
	f[0][0] = 1;
	
	for(int i = 1; i <= 8; i++)
	{
		memset(sum, 0, sizeof(sum)); 
		for(int j = 0; j <= 13440; j++)
		{
			sum[j] = (j >= i ? sum[j - i] : 0) + f[i - 1][j];
			int k = j - (cnt[i] + 1) * i;
			if(sum[j] - (k < 0 ? 0 : sum[k]) > 0) f[i][j] = 1;
		}
	}
	
	if(s * 840 <= w) ans = std::max(ans, get(w - s * 840) + s * 840);
	
	for(ll i = (w - 13440) / 840; i * 840 <= w && i <= s; i++)
		ans = std::max(ans, get(w - i * 840) + i * 840);
	
	printf("%lld\n", ans);
}

/*
1a+2b+3c+4d+5e+6f+7g+8h+k*840 = W
a<840,b<420,c<280,d<210,e<168,f<140,g<120,h<105
DP(W-(1a+2b+3c+4d+5e+6f+7g+8h))/840k 
*/