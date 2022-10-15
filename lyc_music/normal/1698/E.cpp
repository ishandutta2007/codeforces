// Lynkcat.
// Problem: E. PermutationForces II
// Contest: Codeforces - Codeforces Round #803 (Div. 2)
// URL: https://codeforces.com/contest/1698/problem/E
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
int n,m,p[N],pp[N],a[N],b[N],tp[N];
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++) p[i]=0,pp[i]=0,b[i]=-1,tp[i]=0;
	for (int i=1;i<=n;i++)
	{
		cin>>pp[i];
		a[pp[i]]=i;
	}
	for (int i=1;i<=n;i++) 
	{
		cin>>p[i];
		if (p[i]!=-1)
			b[p[i]]=i;
	}
	// for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	// cout<<endl;
	// for (int i=1;i<=n;i++) cout<<b[i]<<" ";
	// cout<<endl;
	int ans=1;
	for (int i=1;i<=n;i++)
		if (p[i]!=-1)
		{
			if (p[i]>pp[i]) 
			{
				tp[i]=2;
				continue;
			}
			if (pp[i]-p[i]>m) ans=0;
			tp[i]=1;
		}
	// cout<<"?"<<ans<<endl;
	if (ans==0) return cout<<0<<endl,void();
	int x=0;
	for (int i=1;i<=m;i++)
	{
		if (tp[a[i]]==0) x++;
	}
	for (int i=1;i<=n;i++)
	{
		if (i+m<=n)
		{
			if (tp[a[i+m]]==0) x++;
		}
		// cout<<"?"<<i<<" "<<x<<endl;
		if (b[i]==-1)
		{
			ans=ans*x%mod;
			x--;
		}
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