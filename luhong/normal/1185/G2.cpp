#include <cstdio>
#include <iostream>
#define MN 53
#define mod 1000000007

int n, T;
int f[MN][MN][MN][4];
int g[MN][2510];
int h[MN][MN][2510];
int t[MN], o[MN];
int fac[MN];

int main()
{
	scanf("%d%d", &n, &T);
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &o[i]), fac[i] = 1ll * fac[i - 1] * i % mod;
		
	f[1][1][0][1] = f[1][0][1][2] = f[1][0][0][3] = f[1][1][0][0] = f[1][0][1][0] = f[1][0][0][0] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 0; j <= i; j++)
			for(int k = 0; j + k <= i; k++)
			{
				if(j) f[i][j][k][1] = (f[i - 1][j - 1][k][2] + f[i - 1][j - 1][k][3]) % mod;
				if(k) f[i][j][k][2] = (f[i - 1][j][k - 1][1] + f[i - 1][j][k - 1][3]) % mod;
				f[i][j][k][3] = (f[i - 1][j][k][1] + f[i - 1][j][k][2]) % mod;
				f[i][j][k][0] = ((f[i][j][k][1] + f[i][j][k][2]) % mod + f[i][j][k][3]) % mod;
			} 
			
	g[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(o[i] != 1) continue;
		for(int j = i; j >= 1; j--)
			for(int k = T; k >= t[i]; k--)
				g[j][k] = (g[j][k] + g[j - 1][k - t[i]]) % mod; 
	} 
	
	h[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(o[i] == 1) continue;
		for(int j = i; j >= 0; j--)
			for(int k = i; k >= 0; k--)
				for(int l = T; l >= t[i]; l--)
					if(o[i] == 2 && j) h[j][k][l] = (h[j][k][l] + h[j - 1][k][l - t[i]]) % mod; 
					else if(o[i] == 3 && k) h[j][k][l] = (h[j][k][l] + h[j][k - 1][l - t[i]]) % mod;
	}
	
	int Ans = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; i + j <= n; j++)
			for(int k = 0; i + j + k <= n; k++)
				for(int l = 0; l <= T; l++)
					Ans = (Ans + 1ll * fac[i] * fac[j] % mod * fac[k] % mod * f[i + j + k][i][j][0] % mod * g[i][l] % mod * h[j][k][T - l] % mod) % mod;
	printf("%d\n", Ans);
}

/*
ijk 
T
g[i][a1][a2][a3][t] ia1a2a3t  n^4 * Tkn^(k+1) * T
h[i][a1][t] i1a1t NTT
TTn^3 * T^2kn^k*T^2*kk=2T^2 *kT 
DPklmiMsigma mi = k   max mi = M
DP n^(M+1) * T + n^k * T^2 * l(1+2)n^3 * T

*/