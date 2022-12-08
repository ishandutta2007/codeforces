#include <stdio.h>

int N,C[1111],K;

int main()
{
	int i;

	scanf ("%d",&N);
	for (i=1;i<=N*N;i++){
		C[K] = 1; K = (K + i) % N;
	}

	for (i=0;i<N;i++) if (C[i] == 0){printf ("NO"); return 0;}
	printf ("YES");

	return 0;
}