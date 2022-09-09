#pragma hdrstop
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
//#define int li
int n, m, k;
int d[200];
int val[200];
int koch[200];
void solve ()
{
	cin>>n>>m>>k;
	for (int i=0; i<m; i++)
		cin>>d[i];
	for (int i=0; i<k; i++)
	{
		cin>>koch[i];
		for (int j=0; j<m; j++)
			if (koch[i]%d[j]==0)
				val[j]++;
	}
	int mn=1<<30;
	for ( int i=0; i<m; i++ )
		mn=min (mn, val[i]);
	vector <int> ans;
	for (int i=0; i<m; i++)
		if (val[i]==mn)
			ans.pb (i+1);
	cout<<ans.size()<<endl;
	for (int i=0; i<ans.size(); i++)
		cout<<ans[i]<<' ';
}