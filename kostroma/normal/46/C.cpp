#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <deque>
using namespace std;
typedef long double ld;
typedef long long li;
typedef pair <li, li> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	solve ();
	return 0;
}
int n;
string s;
void solve ()
{
	cin>>n;
	cin>>s;
	string q=s+s;
	int h=0;
	for ( int i=0; i<n; i++ )
		if ( s[i]=='H' )
			h++;
	//cout<<h<<endl;
	int mint=0;
	for ( int i=0; i<h; i++ )
		if ( q[i]=='T' )
			mint++;
	int t=mint;
	for ( int i=1; i<n; i++ )
	{
		if ( q[i-1]=='T' )
			t--;
		if ( q[i+h-1]=='T' )
			t++;
		if ( mint>t )
			mint=t;
	}
	cout<<mint;
}