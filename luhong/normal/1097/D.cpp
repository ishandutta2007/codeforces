#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <bitset>
#define mod 1000000007

long long n; int k;
long long inv[10100];
long long f[10100][61];

bool is[33100000];
int pri[10100000], tot = 0;

void init()
{
	for(int i = 2; i <= 33000000; i++)
	{
		if(!is[i]) pri[++tot] = i;
		for(int j = 1; j <= tot && i * pri[j] <= 33000000; j++)
		{
			is[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

void solve(int p)
{
	for(int i = 0; i <= k; i++)
		for(int j = 0; j <= p; j++)
			f[i][j] = 0;
	f[0][p] = 1;
	for(int i = 0; i <= k; i++)
	{
		if(i != 0)
		{
			for(int j = p - 1; j >= 0; j--) f[i][j] = (f[i][j] + f[i][j + 1]) % mod;
		}
		if(i != k)
		{
			for(int j = 0; j <= p; j++)
			{
				f[i + 1][j] = (f[i + 1][j] + f[i][j] * inv[j + 1]) % mod;
			}
		}
	}
}


int main()
{
	inv[0] = inv[1] = 1;
	for(int i = 2; i <= 10001; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod; 
	
	scanf("%lld%d", &n, &k);
	
	long long m = n, ans = 1;
	init();
	for(int I = 1; 1ll * pri[I] * pri[I] <= n; I++)
	{
		int i = pri[I];
		if(n % i == 0)
		{
			int p = 0;
			while(m % i == 0)
			{
				m /= i;
				p++;
			}
			solve(p);
			long long w = 1, s = 0;
			for(int j = 0; j <= p; j++)
			{
				s = (s + w * f[k][j]) % mod;
				w = w * i % mod;
			}
			ans = ans * s % mod;
		}
	}
	if(m != 1)
	{
		m %= mod;
		solve(1);
		long long s = (1 * f[k][0] + m * f[k][1]) % mod;
		ans = ans * s % mod;
	}
	printf("%lld\n", ans);
}