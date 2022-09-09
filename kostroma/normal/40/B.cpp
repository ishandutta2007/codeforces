#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <math.h>
#include <algorithm>
using namespace std;
int main ()
{
	int n, m, x, q, w;
	scanf ("%d%d%d", &n, &m, &x);
	if (m<=2*x-2 || n<=2*x-2)
	{
		printf ("0");
		return 0;
	}
	else
	{
		q=m-2*x+2;
		w=n-2*x+2;
		if (q==1)
		{
			printf ("%d", (w+1)/2);
			return 0;
		}
		if (w==1)
		{
			printf ("%d", (q+1)/2);
			return 0;
		}
		printf ("%d", q+w-2);
	}
return 0;
}