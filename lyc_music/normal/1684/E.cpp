// Lynkcat.
// Problem: E. MEX vs DIFF
// Contest: Codeforces - Codeforces Round #792 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1684/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
int n,m,a[N];
int tr[N],tr1[N];
int p[N];
void upd(int x,int y)
{
	while (x<=n)
	{
		tr[x]+=y;
		x+=x&-x;
	}
}
int query(int x)
{
	int res=0;
	while (x)
	{
		res+=tr[x];
		x-=x&-x;
	}
	return res;
}
void upd1(int x,int y)
{
	while (x<=n)
	{
		tr1[x]+=y;
		x+=x&-x;
	}
}
int query1(int x)
{
	int res=0;
	while (x)
	{
		res+=tr1[x];
		x-=x&-x;
	}
	return res;
}
void BellaKira()
{
	map<int,int>Mp;
	map<int,int>ind;
	cin>>n>>m;
	int lstm=m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		Mp[a[i]]++;
	}
	for (int i=1;i<=n;i++)
		p[i]=i;
	sort(p+1,p+n+1,[&](int x,int y)
	{
		return Mp[a[x]]<Mp[a[y]];
	});
	for (int i=1;i<=n;i++)
		ind[a[p[i]]]=i;
	int ans=Mp.size();
	int t=0;
	multiset<pa>G,G1;
	for (auto u:Mp)
		if (u.fi>=n) 
		{
			G.insert(mp(u.se,u.fi)),t+=u.se;
			// cout<<u.fi<<" "<<ind[u.fi]<<"?"<<endl;
			upd(ind[u.fi],1);
			upd1(ind[u.fi],u.se);
		}
	int o=0;
	for (int i=0;i<n;i++)
		if (!Mp[i]) o++;
	for (int i=n-1;i>=0;i--)
	{
		m-=max(0ll,o-t);
		int l=1,r=n;
		int now=0;
		while (l<=r)
		{
			int mid=l+(r-l)/2;
			if (query1(mid)<=m)
			{
				now=mid;
				l=mid+1;
			} else r=mid-1;
		}
		int nw=query(n)-query(now);
		m+=max(0ll,o-t);
		if (o<=m)
			ans=min(ans,nw);
		// cout<<"?"<<o<<" "<<i<<" "<<m<<" "<<t<<" "<<nw<<endl;
		// cout<<i<<" "<<nw<<" "<<o<<" "<<t<<" "<<m<<" "<<now<<" "<<query1(now)<<" "<<ind[i]<<" "<<Mp[i]<<endl;
		t+=Mp[i];
		o-=(!Mp[i]);
		if (Mp[i])
		{
			upd(ind[i],1);
			upd1(ind[i],Mp[i]);
		}
	}
	cout<<ans<<endl;
		
	for (int i=1;i<=n;i++) tr[i]=tr1[i]=0;
			
			
		
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