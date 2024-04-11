// Lynkcat.
// Problem: G. Just Add an Edge
// URL: https://codeforces.com/contest/1616/problem/G
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
#define N 300005
using namespace std;
int n,m;
poly G[N],G1[N];
int vis[N];
int nxt[N];
int pre[N][2],suf[N][2];
int cnt[5],cnt1[5];
void clr()
{
	for (int i=0;i<=n+1;i++) G[i].clear();
	for (int i=0;i<=n+1;i++)
		for (int j=0;j<=1;j++) pre[i][j]=suf[i][j]=0;
	for (int i=0;i<=3;i++) cnt[i]=cnt1[i]=0;
}
void BellaKira()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[y].push_back(x);
	}
	for (int i=1;i<=n;i++) G[i].push_back(0);
	for (int i=1;i<=n;i++) G[n+1].push_back(i);
	int sm=0;
	for (int i=2;i<=n;i++)
	{
		bool bl=0;
		for (auto u:G[i])
		{
			if (u==i-1) bl=1;
		}
		vis[i]=bl;
		sm+=bl;
	}
	nxt[n]=n;
	for (int i=n;i>=1;i--)
	{
		if (vis[i])
		{
			nxt[i-1]=nxt[i];
		} else 
			nxt[i-1]=i-1;
		// cout<<i<<" "<<nxt[i]<<endl;
	}
	// cout<<"?"<<sm<<endl;
	if (sm==n-1) return cout<<n*(n-1)/2<<endl,clr(),void();
	int nl=0,nr=0;
	for (int i=2;i<=n;i++)
		if (vis[i]==0) nr=i;
	for (int i=n;i>=2;i--)
		if (vis[i]==0) nl=i-1;
	// cout<<nl<<" "<<nr<<endl;
	pre[nl+1][0]=1;
	pre[nl+1][1]=2;
	for (int i=nl+2;i<=n+1;i++)
	{
		for (auto u:G[i])
			if (nxt[u+1]>=i-1&&u!=i-1)
			{
				for (int k=0;k<=1;k++)
				{
					pre[i][k]|=pre[u+1][k^1];
				}
			}
		// cout<<i<<" "<<pre[i][0]<<" "<<pre[i][1]<<endl;
	}
	suf[nl+1][0]=1;
	suf[nl+1][1]=2;
	for (int i=nl+1;i>=1;i--)
		for (auto u:G[i])
			if (nxt[u+1]>=i-1&&u!=i-1)
			{
				for (int k=0;k<=1;k++)
				{
					suf[u+1][k]|=suf[i][k^1];
				}
			}
	int ans=0;
	for (int i=1;i<=nl+1;i++)
		cnt[suf[i][0]]++;
	for (int i=nr;i<=n+1;i++)
		cnt1[pre[i][0]]++;
	// for (int i=0;i<=3;i++) cout<<cnt[i]<<" ";
	// cout<<endl;
	// for (int i=0;i<=3;i++) cout<<cnt1[i]<<" ";
	// cout<<endl;
	for (int i=0;i<=3;i++)
		for (int j=0;j<=3;j++)
			if (i&j)
				ans=(ans+cnt[i]*cnt1[j]);
	if (nl+1==nr) ans--;
	cout<<ans<<endl;	
	clr();
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