// Problem: A. Ela Sorting Books
// Contest: Codeforces - Dytechlab Cup 2022
// URL: https://codeforces.com/contest/1737/problem/0
// Memory Limit: 256 MB
// Time Limit: 1000 ms

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
	int n,m;
	cin>>n>>m;
	map<int,int>Mp;
	for (int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		Mp[ch-'a'+1]++;
		// cout<<"?"<<ch-'a'+1<<endl;
	}
	for (int i=1;i<=m;i++)
	{
		int x=n/m+1;
		x=min(x,26);
		// cout<<"??"<<x<<" "<<Mp[4]<<endl;
		for (int j=1;j<=n/m;j++)
		{
			if (Mp[j]==0)
			{
				x=j;
				break;
			}
		}
		for (int j=1;j<x;j++) Mp[j]--;
		cout<<char('a'+x-1);
	}
	cout<<'\n';
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