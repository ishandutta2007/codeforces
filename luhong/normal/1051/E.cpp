#include <cstdio>
#include <cstring>
#include <iostream>
#define base 83
#define mod 998244353

char c[3][1010000];
long long p[3][1010000];
long long mi[1010000];
long long dp[1010000], sum[1010000];
int n, A, B, C;

long long get_hash(int x, int l, int r)
{
	return ( p[x][r] - mi[r - l + 1] * p[x][l - 1] % mod + mod ) % mod; 
}

void init()
{
	for(int j = 0; j < 3; j++)
		for(int i = 1; i <= n; i++)
			p[j][i] = ( p[j][i - 1] * base + c[j][i] - '0' ) % mod;
	mi[0] = 1; for(int i = 1; i <= n; i++) mi[i] = mi[i - 1] * base % mod;
}

int LCP(int x, int t)
{
	int l = 1, r = std::min(A - x + 1, (t == 1 ? B : C) ) + 1; 
	while(l < r)
	{
		int mid = l + r >> 1;
		if(get_hash(0, x, x + mid - 1) == get_hash(t, 1, mid)) l = mid + 1;
		else r = mid;
	}
	return r - 1;
}

int main()
{
	scanf("%s", c[0] + 1);
	scanf("%s", c[1] + 1);
	scanf("%s", c[2] + 1);
	A = strlen(c[0] + 1);
	B = strlen(c[1] + 1);
	C = strlen(c[2] + 1);
	n = std::max(std::max(A, B), C);
	init();
	dp[0] = 1;
	sum[0] = 1;
	for(int i = 1; i <= A; i++)
	{
		if(B == C)
		{
			if(i >= B)
			{
				if(c[1][1] == '0' && c[0][i] == '0') dp[i] = (dp[i] + dp[i - 1]) % mod;
				if(c[0][i - B + 1] != '0') 
				{
					int y = LCP(i - B + 1, 1);
					if(y < B)
					{
						if(c[0][i - B + y + 1] < c[1][y + 1]) continue;
					}
					y = LCP(i - C + 1, 2);
					if(y < C)
					{
						if(c[0][i - C + y + 1] > c[2][y + 1]) continue;
					}
					dp[i] = dp[i - B];
				}
				
			}
		}
		else
		{
			if(i >= B)
			{
				dp[i] = ( (i - B - 1 <= -1 ? 0 : sum[i - B - 1]) - ( i - C <= -1 ? 0 : sum[i - C] ) + mod ) % mod;
				if(c[1][1] == '0' && c[0][i] == '0') dp[i] = (dp[i] + dp[i - 1]) % mod;
				if(c[0][i - B + 1] != '0') 
				{
					int y = LCP(i - B + 1, 1); 
					if(y < B)
					{
						if(c[0][i - B + y + 1] >= c[1][y + 1]) dp[i] = (dp[i] + dp[i - B]) % mod;
					}
					else {dp[i] = (dp[i] + dp[i - B]) % mod;}	
				}
			}
			if(i >= C)
			{
				if(c[0][i - C + 1] != '0')
				{
					int y = LCP(i - C + 1, 2);
					if(y < C)
					{
						if(c[0][i - C + y + 1] <= c[2][y + 1]) dp[i] = (dp[i] + dp[i - C]) % mod;
					}
					else dp[i] = (dp[i] + dp[i - C]) % mod;		
				}
			}
		}
		if(c[0][i + 1] != '0') sum[i] = (sum[i - 1] + dp[i]) % mod;
		else sum[i] = sum[i - 1];
	}
	printf("%lld\n", dp[A]);
	return 0;
}