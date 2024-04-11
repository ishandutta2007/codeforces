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
        int t;
		cin>>t;
        while (t--)
        solve ();
}
#define int li
int a, b;
void solve ()
{
	cin>>a>>b;
	int all=a*2*b;
	if ( a==0 )
	{
		if ( b!=0 )
			cout<<"0.5000000"<<endl;
		else 
			cout<<"1"<<endl;
		return;
	}
	if ( b==0 )
	{
		cout<<"1"<<endl;
		return;
	}
	ld good=0;
	good+=(ld)a*b;
	ld p;
	if ( a<4*b )
	{
		ld r=(ld)a/4;
		good+=(ld)r*a/2;
	}
	else 
		good+=(ld)a*b-b*2*b;
	p=(ld)good/all;
	printf ("%.10Lf\n", p);
}