#include <stdio.h>

int main()
{
	int a,b,c; scanf ("%d %d %d",&a,&b,&c);

	int mx = 0;
	for (int i=1;i<=100;i++) if (i <= a && i+1 <= b && i+2 <= c) mx = i*3+3;
	printf ("%d\n",mx);

	return 0;
}