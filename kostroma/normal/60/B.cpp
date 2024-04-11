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
int n, m, k, x, y;
string s[12][12];
int pol[12][12][12];
int want[12][12][12];
int time=1;
void solve ()
{
	cin>>k>>n>>m;
	int num=0;
	char c=getchar();
	//cout<<c;
	//c=getchar();
	//cout<<c;
	int i, j, w;
	for ( i=0; i<k; i++ )
	{
		getchar();
		for (j=0; j<n; j++)
		{
			cin>>s[i][j];
			for (w=0; w<s[i][j].length(); w++)
				if (s[i][j][w]=='.')
					num++;
			//cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
		}
	}
	cin>>x>>y;
	//cout<<x<<y;
	//cout<<num<<endl;
	pol[0][x-1][y-1]=1;
	int poln=1;
	for ( int h=0; h<1000; h++ )
	{
		for ( i=0; i<k; i++ )
			for (j=0; j<n; j++)
				for (w=0; w<m; w++)
					want[i][j][w]=0;
		for ( i=0; i<k; i++ )
			for (j=0; j<n; j++)
				for (w=0; w<m; w++)
					if ( pol[i][j][w]==1 )
					want[i][j][w]=1;
		for ( i=0; i<k; i++ )
			for (j=0; j<n; j++)
				for (w=0; w<m; w++)
				if ( want[i][j][w]==1 )
			{
				if ( i>0 && s[i-1][j][w]=='.' && pol[i-1][j][w]==0)
				{
					pol[i-1][j][w]=1;
					poln++;
					time++;
				}
				if ( i<k-1 && s[i+1][j][w]=='.' && pol[i+1][j][w]==0)
				{
					pol[i+1][j][w]=1;
					poln++;
					time++;
				}
				if ( j>0 && s[i][j-1][w]=='.' && pol[i][j-1][w]==0)
				{
					pol[i][j-1][w]=1;
					poln++;
					time++;
				}
				if ( j<n-1 && s[i][j+1][w]=='.'  && pol[i][j+1][w]==0)
				{
					pol[i][j+1][w]=1;
					poln++;
					time++;
				}
				if ( w>0 && s[i][j][w-1]=='.' && pol[i][j][w-1]==0)
				{
					pol[i][j][w-1]=1;
					poln++;
					time++;
				}
				if ( w<m-1 && s[i][j][w+1]=='.' && pol[i][j][w+1]==0)
				{
					pol[i][j][w+1]=1;
					poln++;
					time++;
				}
			}
	}
	cout<<time;
}