#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int n, b;
int a[2000];
int main ()
{
	int i;
	scanf ("%d%d", &n, &b);
	for (i=0; i<n; i++)
		scanf ("%d", &a[i]);
	int z=0;
	for (i=0; i<n-1; i++)
	if (a[i]<a[i+1])
	{
		z=1;
		break;
	}
	if (z==0)
	{
		printf ("%d", b);
		return 0;
	}
	int j, k;
	int c=b;
	for (j=0; j<n; j++)
		for (k=j+1; k<n; k++)
			if (b/a[j]*a[k]+b%a[j]>c)
			{
				c=b/a[j]*a[k]+b%a[j];
			}
	printf ("%d", c);
return 0;
}