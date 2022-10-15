// Problem: A. Organizing SWERC
// URL: https://codeforces.com/contest/1662/problem/0
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// //

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
poly G[15];
int n,a[105],b[105];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		swap(a[i],b[i]);
		G[a[i]].push_back(b[i]);
	}
	int ans=1;
	int sm=0;
	for (int i=1;i<=10;i++)
	{
		if (G[i].empty()) 
		{
			// cout<<"!"<<i<<endl;
			ans=0;
			break;
		}
		sort(G[i].begin(),G[i].end());
		sm+=G[i].back();
	}
	if (ans)
	cout<<sm<<endl;
	else cout<<"MOREPROBLEMS"<<endl;
	for (int i=1;i<=10;i++) G[i].clear();
}
signed main()
{
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/