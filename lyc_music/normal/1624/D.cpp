// Lynkcat.
// Problem: D. Palindromes Coloring
// URL: https://codeforces.com/contest/1624/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
void BellaKira()
{
	map<int,int>Mp;
	int n,m;
	string st;
	cin>>n>>m;
	cin>>st;
	for (auto u:st)
		Mp[u]++;
	int tot=0,p=0;
	for (auto u:Mp)
	{
		tot+=(u.se/2);
		p+=u.se%2;
	}
	int now=tot/m;
	// cout<<tot<<" "<<m<<" "<<p<<endl;
	if (tot%m==0)
	{
		if (p>=m)
		{
			cout<<now*2+1<<endl;
		} else
		{
			cout<<now*2<<endl;
		}
	} else
	{
		int x=tot%m,y=m-tot%m;
		if (p+x>=y)
		{
			cout<<now*2+1<<endl;
		} else
		{
			cout<<now*2<<endl;
		}
	}
		
	
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}