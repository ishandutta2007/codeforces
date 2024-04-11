#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
using namespace std;
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <li> vli;
typedef vector <int> vi;
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fs first
#define sc second
#define len length()
void solve ();
int main()
{   int t;
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		cin>>t;
	#else
		t=1;
	#endif

	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
//#define int li
int n, t=0;
pi pt[10050];
pi ans[200500];
void doing ( int l, int r )
{
	if ( l==r )
		return;
	if ( r-l==1 )
	{
		ans[t++]=mp ( pt[l].fs, pt[r].sc );
		return;
	}
	int m=(l+r)/2;
	doing (l, m);
	doing (m+1, r);
	int y=pt[m].fs;
	for ( int i=l; i<=r; i++ )
	{
		int cur=pt[i].sc;
		ans[t++]=mp ( y, cur );
	}
}
void solve () 
{
	cin>>n;
	for ( int i=0; i<n; i++ )
	cin>>pt[i].fs>>pt[i].sc;
	sort (pt, pt+n);
	for ( int i=0; i<n; i++ )
		ans[t++]=pt[i];
	doing (0, n-1);
	sort (ans, ans+t);
	t=(unique (ans,ans+t)-ans);
	cout<<t<<endl;
	for ( int i=0; i<t; i++ )
		cout<<ans[i].fs<<' '<<ans[i].sc<<endl;
}