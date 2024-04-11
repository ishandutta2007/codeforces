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
//#define int li
int n, k, b[1050];
int a[1050];
bool used[1050];
int more[1050];
void solve ()
{
	cin>>n>>k;
	for ( int i=0; i<n; i++ )
		cin>>b[i];
	for ( int pos=0; pos<n; pos++ )
	{
		for ( int i=0; i<n; i++ )
			if ( !used[i] && b[i]==more[i])
			{
				a[pos]=i;
				for ( int j=0; j<n; j++ )
					if ( j+k<=i )
						more[j]++;
				used[i]=true;
				break;
			}
	}
	for ( int i=0; i<n; i++ )
		cout<<a[i]+1<<' ';
}