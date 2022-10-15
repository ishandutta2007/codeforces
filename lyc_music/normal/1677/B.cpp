// Lynkcat.
// Problem: B. Tokitsukaze and Meeting
// Contest: Codeforces - Codeforces Round #789 (Div. 1)
// URL: https://codeforces.com/contest/1677/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#pragma GCC optimize(2,3,"Ofast")
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
#define N  2000005
using namespace std;
int n,m;
string st;
int ans[N],s[N],tot[N];
void BellaKira()
{
	cin>>n>>m;
	cin>>st;
	for (int i=0;i<m;i++)
	{
		int x=0;
		for (int j=0;j*m+i<n*m;j++)
		{
			x+=(st[j*m+i]=='1');
			if (x) 
			{
				// cout<<i<<" "<<j<<" "<<j*m+i<<endl;
				ans[j*m+i]++;
				ans[j*m+i+m]--;
			}
		}
	}
	for (int i=1;i<n*m;i++)
		s[i]=s[i-1]+(st[i]=='1');
	int now=0;
	for (int i=0;i<m-1;i++)
	{
		now+=(st[i]=='1');
		if (now) tot[i]++;
	}
	for (int i=0;i+m-1<n*m;i++)
	{
		int r=i+m-1;
		if (s[r]-s[i]+(st[i]=='1')>0)
		{
			tot[r]++;
			// cout<<i<<" "<<r<<endl;
		}
	}
	for (int i=0;i<n*m;i++)
	{
		if (i>0)
			ans[i]+=ans[i-1];
		if (i>=m)
			tot[i]+=tot[i-m];
		cout<<ans[i]+tot[i]<<" ";
	}
	cout<<endl;
	for (int i=0;i<=n*m+m;i++)
	ans[i]=tot[i]=0;
	// memset(ans,0,sizeof(ans));
	// memset(tot,0,sizeof(tot));
	
		
		
		
		
}
signed main()
{
	int T=1;
	IOS;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}