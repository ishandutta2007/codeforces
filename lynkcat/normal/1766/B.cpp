// Problem: B. Notepad#
// Contest: Codeforces - Educational Codeforces Round 139 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1766/problem/B
// Memory Limit: 256 MB
// Time Limit: 3000 ms

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
// #define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	char lst=' ';
	map<pair<char,char>,int>Mp;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		if (Mp.count(mp(lst,ch))&&Mp[mp(lst,ch)]<i-1) ans=1;
		else
		{
			if (!Mp.count(mp(lst,ch)))
				Mp[mp(lst,ch)]=i;
		}
		lst=ch;
	}
	if (ans) cout<<"YES\n";
	else cout<<"NO\n";
		
}
signed main()
{
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}