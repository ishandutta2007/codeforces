#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
int main ()
{
	int m, j, i;
	scanf ("%d", &n);
	if (n==1)
	{
		printf ("0");
		return 0;
	}
	if (n==2)
	{
		printf ("1\n1 2");
		return 0;
	}
	if (n==3)
	{
		printf ("2\n1 2\n2 3");
		return 0;
	}
	m=n*n;
	m=m/4;
	printf ("%d\n", m);
	if (n%2==0)
	{
		for (i=1; i<=n/2; i++)
			for (j=n/2+1; j<=n; j++)
				printf ("%d %d\n", i, j);
		return 0;
	}
	else 
	{
		
		for (i=1; i<=n/2; i++)
			for (j=n/2+1; j<=n; j++)
				printf ("%d %d\n", i, j);
		return 0;
	}
return 0;
}