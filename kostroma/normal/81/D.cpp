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
int n, m, a[200], ans[2000];
bool good ( int i )
{
	if ( ans[i]!=ans[(i+1)%n] && ans[i]!=ans[(i-1+n)%n] )
		return true;
	return false;
}
void solve ()
{
	cin>>n>>m;
	for ( int i=0; i<m; i++ )
		cin>>a[i];
	for ( int i=0; i<n; i++ )
	{
		int need=0;
		for ( int i=0; i<m; i++ )
			if ( a[i]>a[need] )
				need=i;
		if ( i>0 && need==ans[i-1] )
		{
		int nd=0;
		if ( need==0 )
			nd=1;
		for ( int i=0; i<m; i++ )
			if ( a[i]>a[nd] && i!=need)
				nd=i;
			need=nd;
		}
		if ( a[need]<=0 )
		{
			cout<<"-1";
			return;
		}
		a[need]--;
		ans[i]=need;
	}
	if ( ans[n-1]==ans[0] )
	{
		bool flag=false;
		int it=ans[0];
		for ( int i=0; i<m; i++ )
			if ( ans[n-2]!=i && i!=it && a[i]>0 )
			{
				flag=true;
				ans[n-1]=i;
				break;
			}
		if ( !flag )
		{
			bool f=false;
			for ( int i=n-1; i>0; i-=2 )
			{
				swap (ans[i], ans[i-1]);
				if ( ans[i-1]!=ans[(i-2+n)%n] )
				{
					f=true;
					break;
				}
			}
			if ( !f )
			{
				cout<<"-1";
				return;
			}
		}
	}
	for (int i=0; i<n; i++)
		cout<<ans[i]+1<<' ';
}