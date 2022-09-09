#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory.h>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
#define mp make_pair
#define pb push_back
typedef pair <int, int> pi;
typedef vector <li, li> vli;
typedef pair <int, char> pic;
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
//#define int li
int n, m;
vector < int > str[5010], stolb[5010];
string matrix[5010];
vector <vector <pi> > strchange;
vector < vector <pi> > stolbchange;
void doing ( pi cur )
{
	pi one=strchange[cur.first][cur.second], two=stolbchange[cur.first][cur.second];
	if ( one.first!=-1 )
		strchange[cur.first][str[cur.first][one.first]].second=one.second;
	if ( one.second!=-1 )
		strchange[cur.first][str[cur.first][one.second]].first=one.first;
	if ( two.first!=-1 )
		stolbchange[stolb[cur.second][two.first]][cur.second].second=two.second;
	if ( two.second!=-1 )
		stolbchange[stolb[cur.second][two.second]][cur.second].first=two.first;
}
int dfs1 ( pi cur )
{
	char c=matrix[cur.first][cur.second];
	if ( c=='U' )
	{
		pi next=stolbchange[cur.first][cur.second];
		if ( next.first==-1 )
			return 0;
		doing (cur);
		return 1+dfs1 ( mp (  stolb[cur.second][next.first], cur.second ) );
	}
	if ( c=='D' )
	{
		pi next=stolbchange[cur.first][cur.second];
		if (next.second==-1)
			return 0;
		doing (cur);
		return 1+dfs1 ( mp (  stolb[cur.second][next.second], cur.second ) );
	}
	if ( c=='L' )
	{
		pi next=strchange[cur.first][cur.second];
		if (next.first==-1)
			return 0;
		doing (cur);
		return 1+dfs1 ( mp ( cur.first, str[cur.first][next.first] ) );
	}
	if ( c=='R' )
	{
		pi next=strchange[cur.first][cur.second];
		if (next.second==-1)
			return 0;
		doing (cur);
		return 1+dfs1 ( mp ( cur.first, str[cur.first][next.second] ) );
	}
}
void def ()
{
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<str[i].size(); j++ )
		{
			int cur=str[i][j];
			if ( j<(int)str[i].size()-1 )
				strchange[i][cur].second=j+1;
			else 
				strchange[i][cur].second=-1;
			if ( j>0 )
				strchange[i][cur].first=j-1;
			else 
				strchange[i][cur].first=-1;
		}
	for ( int i=0; i<m; i++ )
		for ( int j=0; j<stolb[i].size(); j++ )
		{
			int cur=stolb[i][j];
			if ( j<(int)stolb[i].size()-1 )
				stolbchange[cur][i].second=j+1;
			else 
				stolbchange[cur][i].second=-1;
			if ( j>0 )
				stolbchange[cur][i].first=j-1;
			else 
				stolbchange[cur][i].first=-1;
		}
}
void solve ()
{
	cin>>n>>m;
	strchange.resize(n+5);
	stolbchange.resize(n+5);
	for ( int i=0; i<n; i++ )
		strchange[i].resize(m+5);
	for ( int i=0; i<n; i++ )
		stolbchange[i].resize(m+5);
	for ( int i=0; i<n; i++ )
	{
		string q;
		cin>>q;
		matrix[i]=q;
		for ( int j=0; j<m; j++ )
		{
			char c=q[j];
			if ( c!='.' )
			{
				str[i].pb ( j );
				stolb[j].pb( i );
			}
		}
	}
	int ans=0;
	int num=0;
	for ( int i=0; i<n; i++ )
		for ( int j=0; j<m; j++ )
			if ( matrix[i][j]!='.' )
			{
				//cout<<i<<' '<<j<<endl;
				def();
				char c=matrix[i][j];
				pi cur=mp (i, j);
				int z=dfs1 ( mp (i, j) );
				if ( z==ans )
					num++;
				if ( z>ans )
				{
					num=1;
					ans=z;
				}

			}
	cout<<ans+1<<' '<<num<<endl;
}