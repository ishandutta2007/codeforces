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
int n, a[200000];
int b[200000];
int c[200000];
pair <int, int> d[200000];
int f[200000];
int main ()
{
	prepare ();
	cin>>n;
	int i;
	for (i=0; i<n; i++)
	{
		cin>>a[i];
		b[a[i]]++;
		d[i]=make_pair (a[i], i);
	}
	sort (d, d+n);
	for (i=1; i<=100000; i++)
	{	c[i]=b[i]-b[i+1];
	if (c[i]<0)
	{
		printf ("-1");
		return 0;
	}
	}
	for (i=100001; i>=0; i--)
		if (c[i]>0)
			break;
	int p=i, z=0;
	for (i=1; i<=p; i++)
		z+=c[i];
	int t=1;
	int k=1, u=0, s=1;
	printf ("%d\n", z);
	for (i=0; i<n; i++)
	{
		printf ("%d ", f[a[i]]+1);
		f[a[i]]++;
	}
return 0;
}