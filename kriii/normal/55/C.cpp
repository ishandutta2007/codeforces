#include <stdio.h>

int N,M,K,F;

int main()
{
	int i,x,y;

	scanf ("%d %d %d",&N,&M,&K);
	for (i=0;i<K;i++){
		scanf ("%d %d",&x,&y);
		if (x <= 5){F = 1; break;}
		if (y <= 5){F = 1; break;}
		if (x >= N-4){F = 1; break;}
		if (y >= M-4){F = 1; break;}
	}

	printf ("%s",(F)?"YES":"NO");

	return 0;
}