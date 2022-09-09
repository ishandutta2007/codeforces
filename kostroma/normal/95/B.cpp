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
string s, q;
void solve ()
{
	cin>>s;
	int n=s.length();
	if ( n%2 )
	{
		n++;
		for ( int i=0; i<n/2; i++ )
			putchar ('4');
		for ( int i=0; i<n/2; i++ )
			putchar ('7');
		return;
	}
	int z=0;
	for ( int i=0; i<n/2; i++ )
		if ( s[i]>'7' )
		{
			z=1;
			break;
		}
		else 
			if ( s[i]<'7' )
			{
				z=2;
				break;
			}
	if ( z==0 )
	for ( int i=n/2; i<n; i++ )
		if ( s[i]<'4' )
		{
			z=2;
			break;
		}
		else 
			if ( s[i]>'4' )
			{
				z=1;
				break;
			}
	if ( z==1 )
	{
		for ( int i=0; i<=n/2; i++ )
			putchar ('4');
		for ( int i=0; i<=n/2; i++ )
			putchar ('7');
		return;
	}
	if ( z==0 )
	{
		cout<<s;
		return;
	}
	for ( int i=n-1; i>0; i-- )
	{
		if ( s[i]-'0'==10 )
		{
			s[i-1]++;
			s[i]='0';
			continue;
		}
		if ( s[i]>'7' )
		{
			s[i]='4';
			s[i-1]++;
		}
	}
	bool big=false;
	for ( int i=0; i<n; i++ )
	{
		if ( s[i]<'4' )
		{
			s[i]='4';
			big=true;
			continue;
		}
		if ( s[i]>'4' && s[i]<'7' )
		{
			if (!big)
			{
				big=true;
				s[i]='7';
			}
			else 
				s[i]='4';
			continue;
		}
		if ( s[i]=='7' && big )
			s[i]='4';
	}
	int four=0, seven=0;
	for ( int i=0; i<n; i++ )
		if ( s[i]=='4' )
			four++;
		else 
			seven++;
	if ( four==seven )
	{
		cout<<s;
		return;
	}
	if ( four>seven )
	{
		int delta=four-seven;
		for ( int i=n-1; i>=0; i-- )
			if ( s[i]=='4' )
			{
				s[i]='7';
				delta-=2;
				if ( delta==0 )
				{
					cout<<s;
					return;
				}
			}
	}
	else 
	{
		int delta=seven-four;
		int need=delta/2+1;
		int u;
		int p=need, cnt4=0;
		for ( int i=n-1; i>=0; i-- )
			if ( s[i]=='7' )
			{
				p--;
				if ( p==0 )
				{
					u=i;
					break;
				}
			}
			else 
				cnt4++;
		for ( int i=u-1; i>=0; i-- )
			if ( s[i]=='4' )
			{
				s[i]='7';
				u=i+1;
				break;
			}
		for ( int i=u; i<u+need+cnt4; i++ )
			s[i]='4';
		for ( int i=u+need+cnt4; i<n; i++ )
			s[i]='7';
		cout<<s;
		return;
	}
}