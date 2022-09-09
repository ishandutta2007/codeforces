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
typedef pair <long long, long long> pi;
typedef vector <int> vi;
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
        //freopen ("out.txt", "w", stdout);
#endif
        int t=1;
        while (t--)
        solve ();
}
//#define int li

void solve ()
{
	int n, m;
	cin>>n>>m;
	for ( int i=n+1; i<m; i++ )
	{
		bool flag=false;
		for ( int j=2; j*j<=i; j++ )
			if ( i%j==0 )
			{
				flag=true;
				break;
			}
		if ( !flag )
		{
			printf ("NO");
			return;
		}
	}
	bool flag=true;
	for ( int j=2; j*j<=m; j++ )
		if ( m%j==0 )
		{
			flag=false;
			break;
		}
	if ( flag )
		printf ("YES");
	else 
		printf ("NO");
}