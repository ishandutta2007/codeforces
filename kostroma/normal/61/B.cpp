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
string s1[3];
string s[3];
string q;
void solve ()
{
	int i;
	for (i=0; i<3; i++)
	{
		cin>>s1[i];
		for (int j=0; j<s1[i].length(); j++)
		{
			if (s1[i][j]<='Z' && s1[i][j]>='A')
				s[i].pb(s1[i][j]-('A'-'a'));
			if (s1[i][j]<='z' && s1[i][j]>='a')
				s[i].pb(s1[i][j]);
		}
	}
	string a=s[0]+s[1]+s[2], b=s[1]+s[0]+s[2], c= s[0]+s[2]+s[1], d=s[1]+s[2]+s[0], e=s[2]+s[0]+s[1], f=s[2]+s[1]+s[0];
	int n; 
	cin>>n;
	for (i=0; i<n; i++)
	{
		cin>>q;
		string norm;
		for (int j=0; j<q.size(); j++)
		{
			if ( q[j]<='Z' && q[j]>='A' )
				norm.pb (q[j]-'A'+'a');
			if ( q[j]<='z' && q[j]>='a' )
				norm.pb (q[j]);
		}
		//cout<<norm<<endl;
		if ( norm==a || norm==b || norm==c || norm==d  || norm==e || norm==f)
			printf ("ACC\n");
		else 
			printf ("WA\n");
	}
}