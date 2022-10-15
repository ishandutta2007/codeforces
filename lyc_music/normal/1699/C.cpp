// Lynkcat.
// Problem: C. The Third Problem
// Contest: Codeforces - Codeforces Round #804 (Div. 2)
// URL: https://codeforces.com/contest/1699/problem/C
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
#define mod 1000000007
#define int ll
#define N 100005
using namespace std;
int n,a[N],p[N],fac[N];

void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]=i;
	int l=p[0],r=p[0];
	int ans=1;
	int tt=0;
	for (int i=1;i<n;i++)
	{
		if (p[i]<l||p[i]>r)
		{
		}
		else
		{
			ans=ans*tt%mod;
			tt--;
		}
		// cout<<"?"<<l<<" "<<r<<endl;
		if (p[i]<l) 
		{
			tt+=l-p[i]-1;
		}
		if (p[i]>r) 
		{
			tt+=p[i]-r-1;
		}
		l=min(l,p[i]);
		r=max(r,p[i]);
		// cout<<i<<" "<<l<<" "<<r<<" "<<tt<<" "<<ans<<endl;
		
	}
	cout<<ans<<endl;
			
		
}
signed main()
{
	fac[0]=1;
	for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}