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
#define int li
int t, m;
int mem[200], z[200];
void solve ()
{
	cin>>t>>m;
	int id=1LL;
	while (t--)
	{
		string s;
		cin>>s;
		if ( s=="alloc" )
		{
			int n; cin>>n;
			bool flag=false;
			for ( int i=0; i<m && i+n<=m; i++ )
			{
				bool f=true;
				for (int j=i; j<i+n; j++)
					if (mem[j]!=0)
					{
						f=false;
						break;
					}
				if ( f )
				{
					//cout<<"i = "<<i<<endl;
					for (int j=i; j<i+n; j++)
						mem[j]=id;
					cout<<id<<endl;
					id++;
					flag=true;
					break;
				}
			}
			if ( !flag )
				cout<<"NULL\n";
		}
		if ( s=="erase" )
		{
			//cout<<s<<endl;
			int n; cin>>n;
			bool f=false;
			for (int i=0; i<m; i++)
				if (mem[i]==n && n!=0)
				{
					f=true;
					mem[i]=0;
				}
			if (!f)
				cout<<"ILLEGAL_ERASE_ARGUMENT\n";
		}
		if (s=="defragment")
		{
			//cout<<s<<endl;
			int u=0;
			memset (z, 0, sizeof z);
			for (int i=0; i<m; i++)
				if (mem[i]>0)
					z[u++]=mem[i];
			for (int i=0; i<m; i++)
				mem[i]=z[i];
		}
	}
}