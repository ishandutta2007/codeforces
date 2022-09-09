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
//#define int li

void solve ()
{
	int n;
	cin>>n;
	int x=0, y=0, z=0;
	for (int i=0; i<n; i++)
	{
		int x1, y1, z1;
		cin>>x1>>y1>>z1;
		x+=x1; y+=y1; z+=z1;
	}
	if ( x==0 && y==0 && z==0 )
		printf ("YES");
	else 
		printf ("NO");
}