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
#endif
	solve ();
}
int prove ( int a, int b)
{
	if ( a>b+1 )
		return 0;
	if ( b>2*a+2 )
		return 0;
	return 1;
}
void solve ()
{
int a, b, c, d;
cin>>a>>b>>c>>d;
if (  prove (a, d) || prove (b, c))
cout<<"YES";
else 
cout<<"NO";
}