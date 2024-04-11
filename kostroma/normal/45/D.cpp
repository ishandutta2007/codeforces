#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <memory.h>
#include <algorithm>
using namespace std;
#define file "chimera"
#define fin for (i=0; i<n; i++)
typedef long long lint;
pair < pair < int, int > , int > a[100];
pair < pair < int, int > , int > q;
int w[150];
int n;
int c[10000500];
int main ()
{
scanf ("%d", &n);
int i;
for (i=0; i<n; i++)
{
scanf ("%d%d", &q.first.first, &q.first.second);
q.second=i;
a[i]=q;
}
sort (a, a+n);
int j;
for (i=n-1; i>=0; i--)
{
	j=a[i].first.second;
	while (c[j]==1)
	{
		j--;
	}
	if (j>=0)
	{
		c[j]=1;
		w[a[i].second]=j;
	}
}
for (i=0; i<n; i++)
printf ("%d ", w[i]);
return 0;
}