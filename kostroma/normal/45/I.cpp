#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <string>
#include <math.h>
#include <memory.h>
#include <utility>
using namespace std;
int a[150];
int n;
int main()
{
	scanf ("%d", &n);
	memset (a, 0, sizeof(a));
	int i, t=0, q=0;
	for (i=0; i<n; i++)
	{
		scanf ("%d", &a[i]);
		if (a[i]<0)
			t++;
		if (a[i]==0)
			q++;
	}
	sort (a, a+n);
	if (n-t-q==0)
	{
		if (t==0) 
		{
			printf ("0");
			return 0;
		}
		if (t==1 && q==0)
		{
			printf ("%d", a[0]);
			return 0;
		}
		if (t==1 && q!=0)
		{
			printf ("0");
			return 0;
		}
	}
	for (i=n-1; i>=t+q; i--)
		printf ("%d ", a[i]);
	
		for (i=0; i<t-t%2; i++)
		{
			printf ("%d ", a[i]);
		}
	return 0;
}