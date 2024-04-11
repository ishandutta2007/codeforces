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
typedef pair <li, li> pi;
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
//#define int li

void solve ()
{
	int n, x1, y1, x2, y2;
	cin>>n>>x1>>y1>>x2>>y2;
	int z1, z2;
	if ( x1==0 )
		z1=(n-y1)%(4*n);
	if (x1==n)
		z1=(y1+2*n)%(4*n);
	if (y1==0)
		z1=(n+x1)%(4*n);
	if (y1==n)
		z1=(4*n-x1)%(4*n);

	if ( x2==0 )
		z2=(n-y2)%(4*n);
	if (x2==n)
		z2=(y2+2*n)%(4*n);
	if (y2==0)
		z2=(n+x2)%(4*n);
	if (y2==n)
		z2=(4*n-x2)%(4*n);

	int ans=min ( (z1-z2+4*n)%(4*n), (z2-z1+4*n)%(4*n) );
	cout<<ans;
}