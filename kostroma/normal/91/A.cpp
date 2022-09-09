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
string s, q;
vector <int> is[300];
void solve ()
{
	cin>>s>>q;
	for ( int i=0; i<s.length(); i++ )
		is[s[i]].pb (i);
	int ans=1;
	int curpos=-1;
	for ( int i=0; i<q.length(); i++ )
	{	char now=q[i];
		if ( is[now].size()==0 )
		{
		cout<<"-1";
		return;
		}
		int cur;
		vector <int>::iterator next=ub ( is[now].begin(), is[now].end(), curpos );
		if ( next==is[now].end() )
		cur=0;
		else 
		cur=next-is[now].begin();
		cur=is[now][cur];
		if ( cur<=curpos )
			ans++;
		curpos=cur;
	}
	cout<<ans;
}