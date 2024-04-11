// Lynkcat.
// Problem: D. Max GEQ Sum
// URL: https://codeforces.com/contest/1691/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
int tr[N<<2];
int tr1[N<<2];
int s[N];
int L[N],R[N];
void pushup(int k)
{
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
	tr1[k]=max(tr1[k<<1],tr1[k<<1|1]);
}
void build(int k,int l,int r)
{
	if (l==r) return tr[k]=s[l],tr1[k]=s[l],void();
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
int query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		return tr[k];
	}
	int mid=l+(r-l)/2,res=inf;
	if (L<=mid) res=min(res,query(k<<1,l,mid,L,R));
	if (R>mid) res=min(res,query(k<<1|1,mid+1,r,L,R));
	return res;
}
int query1(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		return tr1[k];
	}
	int mid=l+(r-l)/2,res=-inf;
	if (L<=mid) res=max(res,query1(k<<1,l,mid,L,R));
	if (R>mid) res=max(res,query1(k<<1|1,mid+1,r,L,R));
	return res;
}
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	a[0]=inf;
	poly g;
	g.push_back(0);
	for (int i=1;i<=n;i++)
	{
		while (!g.empty()&&a[g.back()]<=a[i]) g.pop_back();
		L[i]=g.back()+1;
		g.push_back(i);
	}
	g.clear();
	a[n+1]=inf;
	g.push_back(n+1);
	for (int i=n;i>=1;i--)
	{
		while (!g.empty()&&a[g.back()]<a[i]) g.pop_back();
		R[i]=g.back()-1;
		g.push_back(i);
	}
	for (int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	build(1,0,n);
	// cout<<"?"<<query(1,0,n,0,0)<<endl;
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		int mn=query1(1,0,n,i,R[i]);
		int mx=query(1,0,n,L[i]-1,i-1);
		// cout<<i<<","<<L[i]<<" "<<R[i]<<" "<<mn<<" "<<mx<<endl;
		if (mn-a[i]>mx) ans=0;
	}
	if (ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
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