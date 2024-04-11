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
        int t=1;
        while (t--)
        solve ();
}
//#define int li

void solve ()
{
	int x, y;
	scanf ("%d:%d", &x, &y);
	if ( x<12 )
		x+=12;
	x-=12;
	int mn=y*6;
	ld ch=(ld)x+y/60.0;
	ch*=30;
	printf ("%.8Lf %d", ch, mn);
}