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
int gcd ( int q, int w )
{
	if ( q<w )
		swap (q,w);
	while ( w>0 )
	{
		q%=w;
		swap (q, w);
	}
	return q;
}
vector < pair <int, int> > p;
void solve ()
{
	int a, b;
	cin>>a>>b;
	int n=a*b/gcd(a,b);
	p.pb ( mp(0, 0) );
	int q=1;
	if ( a<b )
		q=2;
	p.pb ( mp(n, q) );
	for ( int i=a; i<n; i+=a )
		p.pb ( mp (i, 1) );
	for ( int i=b; i<n; i+=b )
		p.pb ( mp (i, 2) );
	sort ( p.begin(), p.end() );
	int aa=0, bb=0;
	for ( int i=1; i<p.size(); i++ )
	{
		if ( p[i].second==1 )
			aa+=p[i].first-p[i-1].first;
		if ( p[i].second==2 )
			bb+=p[i].first-p[i-1].first;
	}
	if (aa==bb)
	{
		cout<<"Equal";
		return;
	}
	if ( aa>bb )
		cout<<"Dasha";
	else 
		cout<<"Masha";
}