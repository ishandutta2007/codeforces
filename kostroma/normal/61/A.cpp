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
string s, q;
string ans;
void solve ()
{
	cin>>s>>q;
	for (int i=0; i<s.length(); i++)
	{
		if ( s[i]!=q[i] )
			ans.pb('1');
		else 
			ans.pb('0');
	}
	cout<<ans;
}