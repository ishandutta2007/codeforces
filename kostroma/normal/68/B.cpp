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
	solve ();
}
#define int li
int n;
ld k;
ld nak[10050];
ld curans=0;
void solve ()
{
	cin>>n>>k;
	for (int i=0; i<n; i++)
		cin>>nak[i];
	sort (nak, nak+n);
	reverse (nak, nak+n);
	ld l=0, r=1001;
	while (r-l>0.00000001)
	{
		ld m=(l+r)/2;
		ld bal=0;
		for (int i=0; i<n; i++)
		{
			if ( nak[i]>m )
				bal+=(nak[i]-m)*(100-k)/100;
			else 
				bal+=nak[i]-m;
		}
		//cout<<bal<<endl;
		if ( bal<=0 )
			r=m;
		else 
			l=m;
	}
	printf ("%.8Lf", l);
}