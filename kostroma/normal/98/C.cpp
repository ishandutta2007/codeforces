#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
//#define int li
ld a, b, l;
#define M_PI 3.14159265358979323846
ld fun ( ld w, ld x )
{
	//ld x=sin(alpha);
	return l*x-a*x/sqrt(1-x*x)+w/sqrt(1-x*x);
	//return l*sin(alpha)-a*tan(alpha)+w/cos(alpha);
		//x*l-a*x/y+w/y;
}
ld check ( ld w )
{
	ld ll=0, rr=1;
	for ( int i=0; i<100; i++ )
	{
		ld m1=(2*ll+rr)/3, m2=(ll+2*rr)/3;
		//printf ("fun(m1) = %.9Lf      %.9Lf\n", fun(w, m1), fun(w, ll));
		if ( fun(w, m1)<=fun(w, ll) )
		{
			rr=m1;
			continue;
		}
		if ( fun(w, m1)>=fun(w, m2) )
		{
			rr=m2;
			continue;
		}
		ll=m1;
	}
	ld ans=fun(w, ll);
	return ans<=b;
}
void solve ()
{
	cin>>a>>b>>l;
	if ( a<b )
		swap (a, b);
	ld ll=0, rr=b;
	if ( l<=b )
	{
		printf ("%.8Lf", l);
		return;
	}
	if ( l<=a )
	{
		printf ("%.8Lf", b);
		return;
	}
	for ( int i=0; i<200; i++ )
	{
		ld mm=ll+rr; mm/=2;
		if ( check(mm) )
			ll=mm;
		else 
			rr=mm;
	}
	if ( ll>1e-8 )
	printf ("%.8Lf", min(ll, l));
	else
	printf ("My poor head =(");
}