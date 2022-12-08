#include <stdio.h>

int main()
{
	long long N,A=0;
	scanf ("%lld",&N);
	if (N == 0) A = 1;
	else{
		for (long long i=N,j=0;i>=0;i--){
			long long nj = j;
			while (i * i + j * j <= N * N) j++; j--;
			if (nj < j) A += j - nj;
			else A++;
		}
		A = (A-1) * 4;

	}

	printf ("%d\n",A);

	return 0;
}