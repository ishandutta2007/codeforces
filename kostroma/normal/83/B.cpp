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
#define int li
int n, a[100500], k;
map <int, int> m;
typedef map <int, int>::iterator it;
void solve ()
{
	cin>>n>>k;
	int sum=0;
	for ( int i=0; i<n; i++ )
	{
		cin>>a[i];
		m[a[i]]++;
		sum+=a[i];
	}
	if ( sum<k )
	{
		cout<<"-1";
		return;
	}
	if ( sum==k )
	{
		cout<<endl;
		return;
	}
	int go=0;
	int prev=0;
	int now=n, last=n;
	for ( it i=m.begin(); i!=m.end(); i++ )
	{
		go+=((i->first)-prev)*now;
		prev=i->first;
		last=now;
		now-=(i->second);
		//cout<<go<<' '<<prev<<' '<<now<<endl;
		if ( go>=k )
			break;
	}
	//cout<<prev<<endl;
	vector <int> b(0);
	int cnt=go-k;
	for ( int i=0; i<n; i++ )
		if ( a[i]>=prev )
			b.pb(i);
	int mn=cnt/last;
	cnt%=last;
	//for (int i=0; i<b.size(); i++ )
	//	a[b[i]]-=mn;
	for ( int i=b.size()-cnt; i<b.size(); i++ )
		cout<<b[i]+1<<' ';
	for ( int i=0; i<b.size()-cnt; i++ )
		if ( a[b[i]]>prev-mn )
		cout<<b[i]+1<<' ';
}