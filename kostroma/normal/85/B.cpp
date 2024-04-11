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
int k[3], t[3];
int n, c[100500];
vector <int> last, nextgo;
void solve ()
{
	for (int i=0; i<3; i++)
		cin>>k[i];
	for (int i=0; i<3; i++)
		cin>>t[i];
	cin>>n;
	for ( int i=0; i<n; i++ )
	{
		int q;
		cin>>q; last.pb (q);
		c[i]=q;
	}
	for ( int i=0; i<3; i++ )
	{
		int have=k[i];
		int z=0;
		for ( int j=0; j<last.size(); j++ )
		{
			int cur=last[j];
			if ( have>0 )
			{
				have--;
				nextgo.pb ( cur+t[i] );
			}
			else 
				nextgo.pb ( t[i]+max (nextgo[z++], cur) );
		}
		last=nextgo;
		nextgo.resize(0);
	}
	int mx=0;
	for ( int i=0; i<last.size(); i++ )
		if ( last[i]-c[i]>mx )
			mx=last[i]-c[i];
	cout<<mx;
}