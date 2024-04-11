#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
                solve ();
        return 0;
}
//caution: is int really int?
#define int li
int n, m;
int dsu[100500];
int find_set (int v)
{
	if (dsu[v]==v)
		return v;
	return dsu[v]=find_set(dsu[v]);
}
void merge (int v1, int v2)
{
	int a1=find_set(v1), a2=find_set(v2);
	if ( rand() & 1 )
		dsu[a1]=a2;
	else
		dsu[a2]=a1;
}
void solve ()
{
	cin>>n>>m;
	for (int i=1; i<=n; i++)
		dsu[i]=i;
	int ans=1, MOD=1000000009;
	for ( int i=0; i<m; i++ )
	{
		int q, w;
		cin>>q>>w;
		if ( find_set(q)==find_set(w) )
			{
				ans+=ans; ans%=MOD;
			}
		merge (q, w);
		cout<<(ans-1+MOD)%MOD<<endl;
	}
}