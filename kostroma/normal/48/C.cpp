#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <string.h>
using namespace std;
typedef vector <int> vi;
typedef long long li;
typedef long double ld;
#define fin for (i=0; i<n; i++)
void prepare ()
{
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
#else 
#endif
}
int n;
int a[2000];
int main ()
{
	prepare ();
	cin>>n;
	int i;
	for (i=0; i<n; i++)
		cin>>a[i];
	if (n==2)
	{
		printf ("not unique");
		return 0;
	}
	int l=a[0]+a[n-1];
	int r=a[0]+a[n-1]+1;
	for (i=1; i<=n/2; i++)
	{
		int l1=a[i]+a[n-1-i];
		int r1=a[i]+a[n-1-i]+1;
		if (l1>l)
		{
			printf ("unique\n");
			printf ("%d", r);
			return 0;
		}
		if (r1<r)
		{
			printf ("unique\n");
			printf ("%d", l);
			return 0;
		}
	}
	printf ("not unique");
return 0;
}