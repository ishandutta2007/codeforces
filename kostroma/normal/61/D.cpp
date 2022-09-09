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
int n;
vi e[100500];
vi len[100500];
int be[100500];
int rec (int v)
{
	be[v]=1;
	int z=0;
	int i;
	for ( i=0; i<e[v].size(); i++ )
		if (be[e[v][i]]==0)
			z=1;
	if (z==0)
		return 0;
	int big=0;
	for ( i=0; i<e[v].size(); i++ )
		if (be[e[v][i]]==0)
		{
			int p=rec(e[v][i])+len[v][i];
			big=max (big, p);
			//cout<<p<<endl;
		}
	return big;
}
void solve ()
{
cin>>n;
int i;
int s=0;
for (i=0; i<n-1; i++)
{
	int q, w, r;
	cin>>q>>w>>r;
	e[q-1].pb(w-1);
	len[q-1].pb(r);
	e[w-1].pb(q-1);
	len[w-1].pb(r);
	s+=r;
}
cout<<2*s-rec(0);
}