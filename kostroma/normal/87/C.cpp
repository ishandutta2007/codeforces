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
#define N 100500
int n;
vector <pli> per[N];
int gr[N];
int prefgr[N];
int sum (int a, int b) { return b*(b+1)/2-a*(a-1)/2; }
int grandi ( int a, int b ) { return prefgr[a-1]^prefgr[b]; }
void solve ()
{
       cin>>n;
		for ( int a=1; a<=n; a++ )
			   for ( int b=a+1; b<=n; b++ )
			   {
				   if ( sum(a, b)>n )
					   break;
					per[sum (a, b)].pb( mp (a, b) );
				}
	   for ( int cur=1; cur<=n; cur++ )
	   {
		   //cout<<cur<<' '<<per[cur].size()<<endl;
		   int be[1000];
		   memset (be, 0, sizeof (be));
		   for ( int i=0; i<per[cur].size(); i++ )
		   {
			   int a=per[cur][i].first, b=per[cur][i].second;
			   int xor=grandi (a, b);
			   be[xor]=1;
		   }
		   int now;
		   for ( int i=0; i<1000; i++ )
				if (!be[i])
				{
					now=i;
					break;
				}
			gr[cur]=now;
			prefgr[cur]=prefgr[cur-1]^now;
	   }
	   int ans=gr[n];
	   if ( !ans )
		   cout<<"-1";
	   else 
	   {
			int  answer=1<<30;
			for ( int i=0; i<per[n].size(); i++ )
				if ( !grandi (per[n][i].first, per[n][i].second) )
					answer=min (answer, per[n][i].second-per[n][i].first+1);
			cout<<answer;
	   }
}