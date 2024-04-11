#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <math.h>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long int li;
typedef vector<int> vi;
void prepare ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#else
#endif
}



int n, a[100500];
int b[100500];
int prove (int k)
{
	if (k==-1)
	{
		if (n==2)
		{
			if (a[0]==0)
				if (a[1]==0)
					return 1;
				else return 0;
				if (a[0]!=0)
						return 1;
		}
		for (int i=0; i<n; i++)
		b[i]=a[i];
		for (int i=1; i<n-1; i++)
	{
		if (b[i]*b[i]!=b[i-1]*b[i+1] || ( b[i]==0 &&  b[i+1]!=0   ) || ( b[i]!=0 && b[i-1]==0) )
			return 0;
	}
		return 1;
	}
	int t=0;
	for (int i=0; i<n; i++)
	{
		if (i==k)
			continue;
		b[t]=a[i];
		t++;
	}
	if (n==3)
		{
			if (b[0]==0)
				if (b[1]==0)
					return 1;
				else return 0;
				if (b[0]!=0)
					if (b[1]!=0)
						return 1;
					else return 0;
		}
	if (n==2)
		return 1;
	for (int i=1; i<n-2; i++)
	{
		if (b[i]*b[i]!=b[i-1]*b[i+1] || ( b[i]==0 &&  b[i+1]!=0  )  || ( b[i]!=0 && b[i-1]==0 ) )
			return 0;
	}
	return 1;
}
int main()
{
	prepare ();
	int i;
	cin>>n;
	for (i=0; i<n; i++)
		cin>>a[i];
	if ( prove (-1) == 1 )
	{
		printf ("0");
		return 0;
	}
	//if (a[0]==0)
	//{
	//	int z=1;
	//	for (i=1; i<n; i++)
	//		if (a[i]==0)
	//		z++;
	//	if (z==n)
	//	{
	//		printf ("0");
	//		return 0;
	//	}
	//	if (z==n-1)
	//	{	
	//		printf ("1");
	//		return 0;
	//	}
	//	if (z>1)
	//	{
	//		printf ("2");
	//		return 0;
	//	}
	//	if ( prove (0) ==1 )
	//	{
	//		printf ("1");
	//		return 0;
	//	}
	//	printf ("2");
	//	return 0;
	//}
	if ( prove (0) ==1 || prove (n-1) ==1)
	{
		printf ("1");
		return 0;
	}
	for (i=1; i<n-1; i++)
	{
		if (a[i-1]*a[i+1]!=a[i]*a[i])
			break;
	}
	if ( prove (i+1) ==1 || prove (i)==1 || prove (i-1)==1 )
	{
		printf ("1");
		return 0;
	}
	printf ("2");
return 0;
}