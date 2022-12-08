#include <stdio.h>

__int64 A,B,C;

int main()
{
	scanf ("%I64d %I64d %I64d",&A,&B,&C);

	printf ("%I64d",((A+C-1)/C)*((B+C-1)/C));

	return 0;
}