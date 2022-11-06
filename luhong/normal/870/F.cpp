#include <cstdio>
#include <iostream>
#define MN 10010000

int pri[MN], tot = 0;
bool ok[MN];
int phi[MN], Min[MN];
int n; 
int s[MN];

void init()
{
	for(int i = 2; i <= n; i++)
	{
		if(!ok[i]) pri[++tot] = i, phi[i] = i - 1, Min[i] = i;
		for(int j = 1; j <= tot && i * pri[j] <= n; j++)
		{
			ok[i * pri[j]] = 1; Min[i * pri[j]] = pri[j];
			if(i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			phi[i * pri[j]] = phi[i] * phi[pri[j]];
		}
	}
}

int main()
{
	scanf("%d", &n);
	init();
	for(int i = 2; i <= n; i++) s[Min[i]]++;
	for(int i = 2; i <= n; i++) s[i] += s[i - 1];
	long long Ans = 0;
	for(int i = 1; i <= tot; i++)
	{
		if(pri[i] > n / 2) break;
		int S = s[pri[i]] - s[pri[i] - 1];
		if(n / pri[i] >= pri[i])
		{
			Ans = Ans + (s[n / pri[i]] - s[pri[i]]) * 2ll * S; 
		}
		int w = std::max(pri[i], n / pri[i]);
		Ans = Ans + (s[n / 2] - s[w]) * 3ll * S;
		
		int o = 3;
		if(1ll * pri[i] * pri[i] <= n) o = 2;
		
		Ans = Ans + 1ll * (1 + S) * S / 2 * o;
	}
	for(int i = 2; i <= n; i++)
	{
		Ans -= (i - 1) - phi[i];
		if(1ll * Min[i] * Min[i] <= n) Ans -= 2;
		else if(Min[i] * 2 <= n) Ans -= 3;
	}
	printf("%lld\n", Ans);
}