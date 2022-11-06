#include <cstdio>
#define mod 998244353

long long c[5110][5110];

long long C(int a, int b) {return c[a][b];} 

long long f(int i, int S) // iS 
{
	if(i == 0 && S == 0) return 1;
	if(i == 0) return 0;
	return C(i + S - 1, i - 1);
}

long long qpow(long long x, int p)
{
	long long ans = 1;
	while(p)
	{
		if(p & 1) ans = ans * x % mod;
		x = x * x % mod; p >>= 1;
	}
	return ans;
}

int main()
{
	for(int i = 0; i <= 5100; i++) c[i][0] = c[i][i] = 1;
	for(int i = 1; i <= 5100; i++)
		for(int j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	int p, s, r; scanf("%d%d%d", &p, &s, &r);
	long long Ans = 0, tot = 0;
	for(int i = r; i <= s; i++) // 
	{
		for(int j = 0; j < p; j++) // 
		{
			//i
			long long ans = 0;
			for(int k = 0; k < p - j; k++) // >= i 
			{
				int lst = s - (k + j + 1) * i;
				if(lst < 0) break;
				if(k & 1) ans = ans - C(p - j - 1, k) * f(p - j - 1, lst);
				else ans = ans + C(p - j - 1, k) * f(p - j - 1, lst);
				ans = (ans % mod + mod) % mod; 
			}
			ans = ans * C(p - 1, j) % mod;
			Ans = (Ans + ans * qpow(j + 1, mod - 2) % mod) % mod;
		}
		tot = (tot + f(p - 1, s - i)) % mod;
	}
	printf("%lld\n", Ans * qpow(tot, mod - 2) % mod);
	return 0;
}