// Lynkcat.
// Problem: C. Traffic Light
// Contest: Codeforces - Codeforces Round  #828 (Div. 3)
// URL: https://codeforces.com/contest/1744/problem/C
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
#define inf 1e9
#define mod 998244353
#define int ll
// #define N 
using namespace std;
void BellaKira()
{
	int n;
	cin>>n;
	char ch;
	cin>>ch;
	string st;
	cin>>st;
	poly x,y;
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		if (st[i-1]==ch) x.push_back(i);
		if (st[i-1]=='g') y.push_back(i);
	}
	for (auto u:x)
	{
		int o=lower_bound(y.begin(),y.end(),u)-y.begin();
		if (o!=y.size())
		{
			ans=max(ans,y[o]-u);
			// cout<<"?"<<u<<" "<<y[o]<<endl;
		}
		else
		{
			if (y[0]<=u) ans=max(ans,n-u+y[0]);
			// cout<<"?"<<u<<" "<<y[0]<<endl;
		}
	}
	cout<<ans<<'\n';
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