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
string s, q;
void solve ()
{
	cin>>s>>q;
	int u=q.length();
	for (int i=0; i<q.length(); i++)
		if ( s[i]!=q[i] )
		{
			u=i;
			break;
		}
	int p=q.length();
	for ( int i=(int)q.length()-1; i>=0; i--)
		if (q[i]!=s[i+1])
		{
			p=q.length()-1-i;
			break;
		}
	//cout<<u<<' '<<p<<endl;
	vector <int> ans;
	for ( int i=0; i<s.length(); i++ )
		if ( i<=u && (s.length()-1-i)<=p)
			ans.pb (i+1);
	cout<<ans.size()<<endl;
	for (int i=0; i<ans.size(); i++)
		cout<<ans[i]<<' ';
}