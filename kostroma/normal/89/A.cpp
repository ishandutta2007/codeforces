#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <li, li> vli;
typedef pair <li, li> pli;
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
#define int li
int n, m, k;
int a[100500];
void solve ()
{
	cin>>n>>m>>k;
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	if ( n==1 )
	{
		cout<<min ( a[0], m*k );
		return;
	}
	if ( n%2==0 )
	{
		cout<<"0";
		return;
	}
	int z=n-1; z/=2;
	int mn=0;
	for ( int i=0; i<n; i++ )
		if ( i%2==0 && a[i]<a[mn])
			mn=i;
	if ( m<=z )
	{
		cout<<"0";
		return;
	}
	cout<<min (a[mn], (m/(z+1))*k);
}