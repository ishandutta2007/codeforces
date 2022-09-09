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
typedef pair <li, li> pi;
typedef vector <li, li> vli;
typedef pair <li, li> pli;
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
#define int li
int p[4];
int sum () { return p[0]+p[1]+p[2]+p[3]; }
vector <pair <char, int> > ans;
void solve ()
{
	cin>>p[0]>>p[1]>>p[2]>>p[3];
	while ( sum()>6 )
	{
		int u=0;
		for ( int i=0; i<4; i++ )
			if ( p[i]>p[u] )
				u=i;
		if ( p[u]%2==0 )
		{
			if ( p[(u+1)%4]%2==0 )
			{
				ans.pb ( mp ( '/', u ) );
				p[u]/=2;
				p[(u+1)%4]/=2;
			}
			else 
			{
				if ( p[(u-1+4)%4]%2==0 )
				{
				ans.pb ( mp ( '/', (u-1+4)%4 ) );
				p[u]/=2;
				p[(u-1+4)%4]/=2;
				}
				else 
				{
					ans.pb ( mp ('+', (u+1)%4) );
					ans.pb ( mp ('/', u) );
					p[(u+1)%4]++;
					p[(u+2)%4]++;
					p[(u+1)%4]/=2;
					p[u]/=2;
				}
			}
		}
		else 
		{
			ans.pb ( mp ('+', u) );
			p[u]++;
			p[(u+1)%4]++;
		}
	}
	int be[100];
	memset (be, 0, sizeof (be));
	//cout<<p[0]<<' '<<p[1]<<' '<<p[2]<<' '<<p[3]<<endl; return;
	for ( int i=0; i<4; i++ )
		be[p[i]]=1;
	if ( be[3] )
	{
		for ( int i=0; i<4; i++ )
			if ( p[i]==3 )
			{
				ans.pb ( mp ('+', i) );
				ans.pb ( mp ('/', i) );
				p[i]=2; p[(i+1)%4]=1;
			}
	}
	memset (be, 0, sizeof (be));
	for ( int i=0; i<4; i++ )
		be[p[i]]=1;
	if (!be[2])
	{
		for ( int i=0; i<ans.size(); i++ )
			cout<<ans[i].first<<ans[i].second+1<<endl;
		return;
	}
	for ( int i=0; i<4; i++ )
		if ( p[i]==2 )
		{
			if ( p[(i+1)%4]==2 )
			{
				for ( int j=0; j<ans.size(); j++ )
					cout<<ans[j].first<<ans[j].second+1<<endl;
				cout<<"/"<<i+1;
				return;
			}
		}
	for ( int i=0; i<3; i++ )
		if ( p[i]==2 )
			if ( p[(i+2)%4]==2 )
			{
				ans.pb ( mp ( '+', (i+2)%4 ) );
				ans.pb ( mp ( '+', (i+1)%4 ) );
				ans.pb ( mp ( '/', (i-1+4)%4 ) );
				ans.pb ( mp ( '/', (i+1)%4 ) );
				p[i]=1;
			}
	memset (be, 0, sizeof (be));
	for ( int i=0; i<4; i++ )
		be[p[i]]=1;
	for ( int i=0; i<4; i++ )
		if ( p[i]==2 )
		{
			for ( int j=0; j<ans.size(); j++ )
					cout<<ans[j].first<<ans[j].second+1<<endl;
			cout<<"+"<<(i-1+4)%4+1<<endl;
			cout<<"+"<<(i)%4+1<<endl;
			cout<<"/"<<(i-1+4)%4+1<<endl;
			cout<<"/"<<(i)%4+1<<endl;
			return;
		}
}