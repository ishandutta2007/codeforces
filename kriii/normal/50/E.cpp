#include <stdio.h>
#include <math.h>
#define min(a,b) ((a<b)?(a):(b))
#define max(a,b) ((a>b)?(a):(b))

int C[10101010],MIN;
__int64 N,M,D;

int main()
{
	__int64 i,j,s,e;

	scanf ("%I64d %I64d",&N,&M);
	for (i=1;i<=N;i++){
		e = i - 1;
		if (i * i <= M) s = 0, D += i * (i - 1) * 2;
		else s = (int)sqrt(double(i * i - M - 1)) + 1, D += (M - (e - s + 1)) * 2;
		for (j=max(i+s,MIN);j<=i+e;j++) if (C[j] == 0){D++; C[j] = 1;}
		for (j=max(i-e,MIN);j<=i-s;j++) if (C[j] == 0){D++; C[j] = 1;}
		for (;;MIN++) if (!C[MIN+1]) break;
	}

	printf ("%I64d\n",D);

	return 0;
}