#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int in (double q)
{
	int i;
	for (i=0; (double)i<=q; i++)
	{
		i=i;
	}
	return (i-1);
}
int main ()
{
	int x, y, z=0;
	scanf ("%d%d", &x, &y);
	if (x*y<=0)
		z=1;
	int s=x*x+y*y;
	double r=sqrt((double)s);
	s=in(r);
	if ((double)s==r)
	{
		printf ("black");
		return 0;
	}
	if ((s%2==1 && z==0) || (s%2==0 && z==1))
		printf ("white");
	else printf ("black");
return 0;
}