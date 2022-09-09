#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
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
string s[10];
void solve ()
{
	int kl=0;
    for (int i=0; i<8; i++)
	{
		cin>>s[i];
		for (int j=0; j<8; j++)
			if ( s[i][j]=='B' )
				kl++;
	}
	if (kl==64)
	{
		cout<<'8';
		return;
	}
	int ans=0;
	for ( int i=0; i<8; i++ )
	{
		bool f=true;
		for (int j=0; j<8; j++)
			if (s[i][j]=='W')
			{
				f=false;
				break;
			}
		if (f)
			ans++;
	}
	for ( int i=0; i<8; i++ )
	{
		bool f=true;
		for (int j=0; j<8; j++)
			if (s[j][i]=='W')
			{
				f=false;
				break;
			}
		if (f)
			ans++;
	}
	cout<<ans;
}