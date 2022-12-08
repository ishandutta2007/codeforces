#include <stdio.h>

__int64 N,MOD=1000000007,I[101010];

int main( )
{
	scanf ("%I64d",&N);

	__int64 i;
	for (i=1;i<N;i++){
		__int64 a,b,c,d,e,f,q,r,t;

		a = 1; b = 0; c = i;
		d = 0; e = 1; f = MOD;
		while (1){
			q = c / f; r = c % f;
			if (r == 0) break;
			c = f; f = r;
			t = a; a = d; d = t - q * d;
			t = b; b = e; e = t - q * e;
		}
		I[i] = (d + MOD) % MOD;
	}

	__int64 RES = 1;
	for (i=N+1;i<=2*N-1;i++) RES = (RES * i) % MOD;
	for (i=1;i<=N-1;i++) RES = (RES * I[i]) % MOD;
	printf ("%I64d\n",(RES*2-N+MOD)%MOD);

	return 0;
}