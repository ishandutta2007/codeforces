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
typedef pair <long long, long long> pi;
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
int n;
pi a[10000];
int ans[10000];

vector <pi> e[10000];
bool be[10000];

pi pred[10000];

int rest[10000];
int now[10000];

void dfs (int v)
{
	be[v]=true;
	for ( int i=0; i<e[v].size(); i++ )
	{
		int cur=e[v][i].first, w=e[v][i].second;
		if ( !be[cur] )
		{
			pred[cur]=mp ( v, w );
			dfs (cur);
		}
	}
}
void solve ()
{
	cin>>n;
	for ( int i=0; i<n; i++ )
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort ( a, a+n );
	for ( int i=0; i<n; i++ )
		now[i]=a[i].second;
	for ( int i=0; i<n-1; i++ )
	{
		int q, w, r; cin>>q>>w>>r;
		e[q-1].pb( mp (w-1, r) );
		e[w-1].pb ( mp (q-1, r) );
	}
	pred[0]=mp ( 0, 0 );
	dfs(0);
	int good=1;
	int timer=0;
	while ( good<n )
	{
		timer++;
		for ( int i=0; i<n; i++ )
			rest[i]=pred[i].second;
		for ( int i=0; i<n; i++ )
			if ( now[i]!=0 )
		{
			int pl=now[i];
			int need=pred[pl].first;
			if ( rest[pl]>0 )
			{
				now[i]=need;
				rest[pl]--;
				if ( need==0 )
				{
					ans[i]=timer;
					good++;
				}
			}
		}
	}
	int answer[10000];
	for ( int i=0; i<n; i++ )
		answer[a[i].second]=ans[i];
	answer[0]=0;
	for ( int i=0; i<n; i++ )
		cout<<answer[i]<<' ';
}