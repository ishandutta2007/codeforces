// Lynkcat.
// Problem: H2. Maximum Crossings (Hard Version)
// URL: https://codeforces.com/contest/1676/problem/H2
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// -----------------------------------------------

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
#define N 200005
using namespace std;
int n,a[N];
int tr[N];
void upd(int x,int y)
{
	int res=0;
	while (x<=n) tr[x]+=y,x+=x&-x;
}
int query(int x)
{
	int res=0;
	while (x) res+=tr[x],x-=x&-x;
return res;}
void BellaKira()
{
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
	{
		upd(a[i],1);
		ans+=query(n)-query(a[i]-1)-1;
		// cout<<i<<","<<ans<<endl;
	}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) tr[i]=0;
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