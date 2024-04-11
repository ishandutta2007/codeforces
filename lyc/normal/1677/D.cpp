// Lynkcat.
// Problem: D. Tokitsukaze and Permutations
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define N 2000005
using namespace std;
int a[N];
int n,m;
int fac[N],inv[N];
int s[N];
int b[N];
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void BellaKira()
{
	int ans=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	ans=1;
	for (int i=n-m+1;i<=n;i++)
		if (a[i]!=0&&a[i]!=-1) ans=0;
	if (!ans)
	{
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=m;i++) 
		ans=ans*i%mod;
	for(int i=1;i<=n-m;i++)
	{
		if (a[i]==-1) 
			ans=ans*(i+m)%mod;
		else 
			if (a[i]==0) 
				ans=ans*(m+1)%mod;
	}
	cout<<ans<<endl;
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