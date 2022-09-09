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
        int t=1;
        while (t--)
        solve ();
}
//#define int li

void solve ()
{
	int n;
	cin>>n;
	if (n%2)
	{
		n/=2;
		cout<<"a";
		for ( int i=0; i<n; i++ )
		{
			if (i%2)
				cout<<"bb";
			else 
				cout<<"cc";
		}
		cout<<endl;
		cout<<"a";
		for ( int i=0; i<n; i++ )
		{
			if (i%2)
				cout<<"dd";
			else 
				cout<<"ee";
		}
		cout<<endl;
		for ( int i=0; i<n; i++ )
		{
			if (i%2)
				cout<<"ff";
			else 
				cout<<"gg";
		}
		cout<<"h";
		cout<<endl;
		for ( int i=0; i<n; i++ )
		{
			if (i%2)
				cout<<"ee";
			else 
				cout<<"jj";
		}
		cout<<"h";
		return;
	}
	n/=2;
	for ( int i=0; i<n; i++ )
	{
		if (i%2)
			cout<<"bb";
		else 
			cout<<"aa";
	}
	cout<<endl;
	cout<<"c";
	for ( int i=0; i<n-1; i++ )
	{
		if ( i%2 )
			cout<<"dd";
		else 
			cout<<"ee";
	}
	cout<<"f";
			cout<<endl;
	cout<<"c";
	for ( int i=0; i<n-1; i++ )
	{
		if ( i%2 )
			cout<<"gg";
		else 
			cout<<"hh";
	}
	cout<<"f";
	cout<<endl;
	for ( int i=0; i<n; i++ )
	{
		if (i%2)
			cout<<"ii";
		else 
			cout<<"jj";
	}
}