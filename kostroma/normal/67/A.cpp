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
int n;
string s;
int gett[100500];
vector <int> shod;
int add[100500];
void solve ()
{
	cin>>n;
	cin>>s;
	gett[0]=1;
	for ( int i=0; i<n-1; i++ )
	{
		int cur=gett[i];
		if ( s[i]=='R' )
			gett[i+1]=cur+1;
		if (s[i]=='=')
			gett[i+1]=cur;
		if (s[i]=='L')
		{
			shod.pb(i);
			gett[i+1]=1;
		}
	}
	/*for (int i=0; i<shod.size(); i++)
		cout<<shod[i]<<" ";
	cout<<endl;*/
	for (int j=shod.size()-1; j>=0; j--)
	{
		int cur=shod[j];
		if ( gett[cur]<=gett[cur+1] )
		{
			int addon=-gett[cur]+gett[cur+1]+1;
			int beg;
			if (j==0)
				beg=-1;
			else 
				beg=shod[j-1];
			gett[cur]+=addon;
			for (int i=cur-1; i>beg; i--)
			{
				if ( s[i]!='=' )
					break;
				else 
					gett[i]+=addon;
			}
		}
	}
	for (int i=0; i<n; i++)
		cout<<gett[i]<<" ";
}