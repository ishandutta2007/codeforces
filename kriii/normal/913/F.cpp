#include <stdio.h>

const long long mod = 998244353;
long long comb[2020][2020];
long long inv[200200]={0,1};
long long D[2020] = {0,0,1}, P[2020] = {0,1,0}, V[2020][2020];

long long pow(long long a, long long p)
{
	long long r = 1;
	while (p){
		if (p & 1) r = r * a % mod;
		a = a * a % mod;
		p /= 2;
	}
	return r;
}

int main()
{
	for (int i=0;i<2020;i++){
		comb[i][0] = comb[i][i] = 1;
		for (int j=1;j<i;j++) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
	}
	for (int i=2;i<200200;i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;

	int N,A,B; long long p;
	scanf ("%d %d %d",&N,&A,&B); p = A * inv[B] % mod;

	for (int j=0;j<=N;j++) V[0][j] = 1;
	long long u = 1;
	for (int i=1;i<=N;i++){
		u = u * p % mod;
		long long v = 1;
		for (int j=0;j<=N;j++){
			V[i][j] = V[i-1][j] * v % mod;
			v = v * (mod + 1 - p) % mod;
		}
		long long S = 0;
		for (int j=0;j<=N;j++){
			S = (S * u) % mod;
			S = (S + V[i][j]) % mod;
			V[i][j] = S;
		}
	}

	long long a[2020] = {0,1};
	for (int i=2;i<=N;i++){
		P[i] = 1;
		D[i] = i * (i - 1) / 2;
		for (int r=1;r<i;r++) if (P[r]){
			long long v = V[i-r][r] * P[r] % mod;
			P[i] = (P[i] + mod - v) % mod;
			D[i] = (D[i] + (D[r] + D[i-r] - (i - r) * (i - r - 1) / 2) * v) % mod;
		}
		D[i] = D[i] * pow(1+mod-P[i],mod-2) % mod;
	}
	printf ("%lld\n",D[N]);

	return 0;
}