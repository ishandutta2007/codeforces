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
#define int li
int n, k;
string s, cur;
int bliz[30][100500];
void solve ()
{
	cin>>n>>k;
	cin>>s;
	for ( char c='a'; c<='z'; c++ )
	{
		int z=0;
		int u=0;
		for (int i=0; i<100500; i++)
		{
			if ( i<k )
			{
				if ( s[i]==c )
				{
				z++;
				for ( int j=u; j<=i; j++ )
				{
					if (z>1)
					bliz[c-97][j]=min ( j-u, i-j );
					else 
					bliz[c-97][j]=i-j;
				}
				u=i;
				}
				else 
					bliz[c-97][i]=bliz[c-97][i-1]+1;
			}
			else bliz[c-97][i]=bliz[c-97][i-1]+1;
		}
		if (z==0)
			for (int i=0; i<100500; i++)
				bliz[c-97][i]=-1;
	}
	for ( int j=0; j<n; j++ )
	{
		cin>>cur;
		int ans=0;
		for ( int i=0; i<cur.length();  i++)
		{
			if ( bliz[cur[i]-97][i]!=-1 )
			ans+=bliz[cur[i]-97][i];
			else 
				ans+=cur.length();
			/*if (cur=="vkontrakte")
			cout<<cur[i]<<" "<<i<<" "<<bliz[cur[i]-97][i]<<endl;
			if (cur=="vkontrakte")
			cout<<ans<<endl;*/
		}
		cout<<ans<<endl;
	}
}