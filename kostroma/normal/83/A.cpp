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
        //freopen ("out.txt", "w", stdout);
#endif
        int t=1;
        while (t--)
        solve ();
}
#define int li
int n, a[100500];
void solve ()
{
	cin>>n;
	for ( int i=0; i<n; i++ )
		cin>>a[i];
	int u=0, ans=0;
	for ( int i=0; i<n; i++ )
	{
		while ( i<n && a[i]==a[u] )
			i++;
		ans+=(i-u)*(i-u+1)/2;
		u=i;
		if ( i==n-1 )
			ans++;
	}
	cout<<ans;
}