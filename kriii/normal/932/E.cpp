#include <stdio.h>

const long long mod = 1000000007;
long long U[5050][5050];

long long fpow(long long a, long long p)
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
	int N,K;
	scanf ("%d %d",&N,&K);
	U[0][0] = 1;
	for (int i=1;i<=K;i++){
		for (int j=1;j<=i;j++){
			U[i][j] = (U[i][j] + U[i-1][j-1] * (N - (j-1))) % mod;
			U[i][j] = (U[i][j] + U[i-1][j] * j) % mod;
		}
	}

	long long ans = 0;
	for (int i=1;i<=K;i++) if (i <= N){
		ans = (ans + fpow(2,N-i) * U[K][i]) % mod;
	}

	printf ("%lld\n",ans);

	return 0;
}