#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	solve ();
}
int may[2000];
void solve ()
{
	int n, m, i;
	cin>>n>>m;
	for (i=0; i<m; i++)
	{
		char s[20]; int q;
		scanf ("\nTo the %s of %d", &s, &q);
		if ( strlen (s)==5 )
		{
			for ( int j=1; j<=q; j++ )
				may[j]=1;
		}
		else
			for ( int j=q; j<=n; j++ )
			{may[j]=1;
		
		}
	}
	int z=0;
	for ( i=1; i<=n; i++ )
		if ( may[i]==0 )
			z++;
	if (z==0)
		printf ("-1");
	else 
		cout<<z;
}