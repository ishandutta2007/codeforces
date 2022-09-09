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
int n;
int a[200];
vector <int> ans;
void solve ()
{
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	int cur=1;
	for (int i=0; i<n; i++)
		if (a[i]==cur)
		{
			ans.pb (i+2001);
			cur++;
		}
	cout<<ans.size()<<endl;
	for (int i=0; i<ans.size(); i++)
		cout<<ans[i]<<' ';
}