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
typedef pair <long long, long long> pi;
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
int st[100];
string s[]={ "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
void solve ()
{

	int n;
	cin>>n;
	st[0]=1;
	int u=0;
	while ( st[u]<=n )
		st[u+1]=st[u++]*2;
	for ( int i=0; i<u; i++ )
	{
		if ( n>5*st[i] )
			n-=5*st[i];
		else 
		{
			int ans=(n-1)/(st[i]);
			cout<<s[ans];
			return;
		}
	}
}