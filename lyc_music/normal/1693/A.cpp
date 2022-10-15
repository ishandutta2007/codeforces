// Lynkcat.
// Problem: A. Directional Increase
// Contest: Codeforces - Codeforces Round #800 (Div. 1)
// URL: https://codeforces.com/contest/1693/problem/0
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
#define int ll
#define N 200005 
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	int sm=0,mx=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],sm+=a[i],mx=max(mx,a[i]);
	if (sm||a[1]<0)return cout<<"No"<<endl,void();
	if (mx==0) return cout<<"Yes"<<endl,void();
	a[1]-=1;
	for (int i=n;i>=1;i--)
	{
		if (!a[i]) continue;
		if (a[i]>0) return cout<<"No"<<endl,void();
		a[i]++;
		break;
	}
	for (int i=n;i>=1;i--) 
	{
		sm+=a[i];
		if (sm>0) return cout<<"No"<<endl,void();
	}
	cout<<"Yes"<<endl;
		
		
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