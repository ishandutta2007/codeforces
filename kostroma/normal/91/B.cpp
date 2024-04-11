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
void solve ();
int main()
{
		#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
		#endif
	int t;
	#ifndef ONLINE_JUDGE
		cin>>t;
	#else 
		t=1;
	#endif
	while (t--)
	solve ();
	return 0;
}                
int n, m;
int a[100500];
int b[100500];
int ans[100500];
int answer[100500];
int bs ( int val )
{
int l=0, r=m;
while (l+1<r)
{
int med=l+r; med=med>>1;
if ( b[med]<val )
r=med;
else 
l=med;
}
return l;
}
void solve ()
{
	cin>>n;
	memset (ans, -1, sizeof (ans));
	memset (answer, 0, sizeof (answer));
	int curborder=0;
	for ( int i=0; i<n; i++ )
	{
	cin>>a[i];
	b[i]=a[i];
	}
	sort (b, b+n);
	reverse (b, b+n);
	m= ( unique (b, b+n)-b );
	for ( int i=n-1; i>=0; i-- )
	{
		int cur=bs (a[i]);
		if ( cur>=curborder )
		answer[i]=-1;
		for ( int j=curborder; j<cur; j++ )
			ans[j]=i;
		curborder=max(cur, curborder);
	}
	for ( int i=0; i<n; i++ )
	{ if (answer[i]==-1)
		{
		cout<<"-1 ";
		continue;
		}
	  int pos=bs (a[i]);
	  int z=ans[pos];
	  if (z>i)
	  cout<<z-i-1<<' ';
	  else 
	  cout<<"-1 ";
	}
	cout<<endl;
}