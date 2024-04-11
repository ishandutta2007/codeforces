#include <stdio.h>

int main()
{
	int a,b;
	scanf ("%d %d",&a,&b);
	int c = a < b ? a : b;
	int f = 1;
	for (int i=2;i<=c;i++) f *= i;
	printf ("%d\n",f);
	return 0;
}