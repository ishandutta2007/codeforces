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
struct player 
{
	int l,  r,  t,  c;
};
pair <int, int> win[200];
void solve ()
{
	for (int i=0; i<200; i++)
		win[i]=mp (1<<30, 1<<30);
	int n, m;
	cin>>n>>m;
	player a[200];
	for (int i=0; i<m; i++)
	{
		cin>>a[i].l>>a[i].r>>a[i].t>>a[i].c;
		for ( int j=a[i].l; j<=a[i].r; j++ )
		{
			if ( mp (a[i].t, i)<win[j] )
				win[j]=mp(a[i].t, i);
		}
	}
	int pr=0;
	for (int i=1; i<=n; i++)
	{
		pi cur=win[i];
		if (cur.first==1<<30)
			continue;
		pr+=a[cur.second].c;
		//cout<<i<<" "<<pr<<endl;
	}
	cout<<pr;
}