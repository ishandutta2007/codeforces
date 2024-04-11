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


int main ()
{
	prepare ();
	string s[3];
	int a[3];
	int i;
	for (i=0; i<3; i++)
	{
		cin>>s[i];
		char q=getchar ();
		if (s[i]=="rock")
			a[i]=0;
		else 
		if (s[i]=="paper")
			a[i]=1;
		else a[i]=2;
	}
	int b[3], j;
	b[0]=0; b[1]=0; b[2]=0;
	for (i=0; i<3; i++)
		for (j=0; j<3; j++)
		if (i!=j)
		{
			if (a[i]==0 && a[j]==2)
				b[i]++;
			if (a[i]==1 && a[j]==0)
				b[i]++;
			if (a[i]==2 && a[j]==1)
				b[i]++;
		}
	for (i=0; i<3; i++)
		if (b[i]==2)
		{
			if (i==0)
				printf ("F");
			if (i==1)
				printf ("M");
			if (i==2)
				printf ("S");
			return 0;
		}
	printf ("?");
return 0;
}