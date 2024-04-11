#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int main ()
{
int n, a, b, c;
scanf ("%d%d%d%d", &n, &a, &b, &c);
int i, q, w, k, j;
long long s=0;
if (a/2+b+c*2<n)
{
	printf ("0");
	return 0;
}
for (i=0; i<=a && i<=2*n; i=i+2)
{
	k=n-i/2;
	for (j=0; j<=b && j<=k; j++)
	{
		if ((k-j)%2==0 && (k-j)<=2*c)
			s++;
	}
}
printf ("%I64d", s);
return 0;
}