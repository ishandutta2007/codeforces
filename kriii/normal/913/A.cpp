#include <stdio.h>

int main()
{
	int N,M;

	scanf ("%d %d",&N,&M);
	if (N <= 30) printf ("%d\n",M%(1<<N));
	else printf ("%d\n",M);
	return 0;
}