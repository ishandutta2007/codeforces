// Lynkcat.
// Problem: C. Jury Meeting
// URL: https://codeforces.com/contest/1569/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int fac[N],inv[N];
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
	cin>>n;
	map<int,int>Mp;
	int sm=0,mx=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],Mp[a[i]]++,mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	if ((*Mp.rbegin()).se>1)
	{
		cout<<fac[n]<<endl;
	} else
	{
		int ans=0;
		if (a[n]>a[n-1]+1) return cout<<0<<endl,void();
		for (int i=1;i<=n;i++)
			if (a[i]==a[n]-1) sm++;
		for (int i=1;i<=n;i++)
		{
			ans=(ans+C(n-i,sm)*fac[sm]%mod*fac[n-1-sm]%mod)%mod;
		}
		cout<<(fac[n]-ans+mod)%mod<<endl;
	}
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
	inv[200000]=quickPower(fac[200000],mod-2);
	for (int i=200000;i>=1;i--)
		inv[i-1]=inv[i]*i%mod;
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}