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

void solve ()
{
	int n, m, x, y;
	cin>>n>>x>>m>>y;
	if ( x>y )
	{
		swap (n, m);
		swap (x, y);
	}
	y-=x;
	x=0;
	int ans=1+m;
	for ( int i=1; i<=n; i++ )
	{
		if ( i<=y-m || i>=y+m)
		{
			ans++;
			continue;
		}
		int d=y-i;
		if ( d<0 )
		{
			d=i-y;
			int more=m-d;
			if ( -i<y-m )
			{
			ans+=2*more+1;
			}
			else 
			{
				ans+=4*y-1;
			}
		}
		else
		{
			int more=m-d;
			if ( -i<y-m )
			{
				ans+=2*more;
			}
			else 
			{
				ans+=4*i-2;
			}
		}
	}
	cout<<ans;
}