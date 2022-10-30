#include <stdio.h>

int N,M;

int main()
{
	int i;
	scanf("%d%d",&N,&M);
	for (i=1;;i=i%N+1) if (M >= i) M -= i; else break;
	printf("%d",M);
}