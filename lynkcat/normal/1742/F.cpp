// Lynkcat.
// Problem: F. Smaller
// Contest: Codeforces - Codeforces Round #827 (Div. 4)
// URL: https://codeforces.com/contest/1742/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int q;
	cin>>q;
	map<int,int>Mp[2];
	for (int i=1;i<=q;i++)
	{
		int x;
		cin>>x;
		x--;
		int k;
		cin>>k;
		string st;
		cin>>st;
		for (auto u:st)
			Mp[x][u-'a']+=k;
		int bl=1;
		for (int i=0;i<26;i++)
			for (int j=1;j<26;j++)
				if (Mp[0][i]&&Mp[1][j]) bl=0;
			int bl1=0;
		int sm=0;
		int sm1=0;
		for (int i=0;i<26;i++) sm+=Mp[0][i],sm1+=Mp[1][i];
		// cout<<sm<<" "<<sm1<<endl;
		for (int i=0;i<26;i++)
			if (Mp[0][i]==sm&&((Mp[0][i]==Mp[1][i]&&Mp[1][i]!=sm1)||Mp[0][i]<Mp[1][i])) bl1=1;
		if (bl&&!bl1)
			cout<<"NO\n";
		else cout<<"YES\n";
	}
				
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}