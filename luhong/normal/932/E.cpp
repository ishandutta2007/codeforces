#include <cstdio>
#include <iostream>
#define MN 5010
#define mod 1000000007

int S[MN][MN];

int qpow(int x, int p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans = 1ll * ans * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return ans;
}

int main()
{
	S[0][0] = 1;
	for(int i = 1; i <= 5000; i++)
		for(int j = 1; j <= i; j++) S[i][j] = (S[i - 1][j - 1] + 1ll * j * S[i - 1][j]) % mod;
	int n, k; scanf("%d%d", &n, &k);
	int ans = 0;
	for(int j = 0; j <= std::min(n, k); j++)
	{
		int fac = 1;
		for(int l = n - j + 1; l <= n; l++) fac = 1ll * fac * l % mod;
		ans = (ans + 1ll * S[k][j] * fac % mod * qpow(2, n - j)) % mod; 
	}
	printf("%d\n", ans);
	
}

/*
sigma i=1~n C(n,i)*i^k
sigma i=1~n (C(n,i) * (sigma j=0~min(n,k) S(k,j) * j! * C(j,i)))
sigma j=0~min(n,k) (S(k,j) * (sigma i=j~n n! / (n-i)! / (i-j)!))
sigma j=0~min(n,k) (S(k,j) * n! / (n-j)! * (sigma i=j~n C(n-j, n-i)))
sigma j=0~min(n,k) S(k,j) * n! / (n-j)! * 2 ^ (n-j)
*/