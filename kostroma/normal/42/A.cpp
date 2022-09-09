#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <algorithm>
using namespace std;
double a[1000];
double b[1000];
int n;
double v;
int main ()
{
	scanf ("%d%lf", &n, &v);
	int i;
	double s=0, q=0;
	for (i=0; i<n; i++)
	{
		scanf ("%d", &a[i]);
		q+=a[i];
	}
	double r=100000000;
	for (i=0; i<n; i++)
	{
		scanf ("%lf", &b[i]);
		s+=b[i];
		r=min (r, b[i]/a[i]*q);
	}
	printf ("%.6lf", min (v, r));
	return 0;
}