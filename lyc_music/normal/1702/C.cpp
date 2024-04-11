// Lynkcat.
// Problem: C. Train and Queries
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/C
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
#define int ll
#define N  200005
using namespace std;
int a[N],n,m;
void BellaKira()
{
	map<int,int>mx,mn;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (!mx.count(a[i]))
		{
			mx[a[i]]=i;
			mn[a[i]]=i;
		} else
		{
			mn[a[i]]=min(mn[a[i]],i);
			mx[a[i]]=max(mx[a[i]],i);
		}
	}
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if (mn.count(x)&&mn.count(y))
		{
			if (mn[x]<mx[y]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		} else cout<<"NO"<<endl;
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