// Lynkcat.
// Problem: C. Greedy Shopping
// URL: https://codeforces.com/contest/1439/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int tr[N<<2],mn[N<<2],mx[N<<2],sam[N<<2],col[N<<2],tag[N<<2];
int ans,val;
int n,q,a[N];
void ptag(int k,int x,int l,int r)
{
	tr[k]=x*(r-l+1);
	mn[k]=x;
	mx[k]=x;
	tag[k]=x;
	col[k]=x;
	sam[k]=1;
}
void pushdown(int k,int l,int r)
{
	if (!tag[k]) return;
	int mid=l+(r-l)/2;
	ptag(k<<1,tag[k],l,mid);
	ptag(k<<1|1,tag[k],mid+1,r);
	tag[k]=0;
}
void pushup(int k)
{
	tr[k]=tr[k<<1]+tr[k<<1|1];
	mn[k]=mn[k<<1|1];
	mx[k]=mx[k<<1];
	if (sam[k<<1]&&sam[k<<1|1])
	{
		if (col[k<<1]!=col[k<<1|1]) sam[k]=0,col[k]=-1;
		else sam[k]=1,col[k]=col[k<<1];
	} else
	{
		col[k]=-1;
		sam[k]=0;
	}
}
void build(int k,int l,int r)
{
	tag[k]=0;
	if (l==r)
	{
		tr[k]=a[l];
		col[k]=a[l];
		sam[k]=1;
		mn[k]=mx[k]=a[l];
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void query(int k,int l,int r,int L,int R)
{
	int mid=l+(r-l)/2;
	if (L<=l&&r<=R)
	{
		if (val<mn[k]) return;
		if (val-tr[k]>=mn[k])
		{
			val-=tr[k];
			ans+=r-l+1;
			return;
		}
		if (sam[k])
		{
			ans+=val/mn[k];
			val%=mn[k];
			return;
		}
		pushdown(k,l,r);
		query(k<<1,l,mid,L,R);
		query(k<<1|1,mid+1,r,L,R);
		return;
	}
	pushdown(k,l,r);
	if (L<=mid) query(k<<1,l,mid,L,R);
	if (R>mid) query(k<<1|1,mid+1,r,L,R);
}
void update(int k,int l,int r,int L,int R,int x)
{
	int mid=l+(r-l)/2;
	if (L<=l&&r<=R)
	{
		if (mn[k]>=x) return;
		if (mx[k]<=x)
		{
			ptag(k,x,l,r);
			return;
		}
		pushdown(k,l,r);
		update(k<<1,l,mid,L,R,x);
		update(k<<1|1,mid+1,r,L,R,x);
		pushup(k);
		return;
	}
	pushdown(k,l,r);
	if (L<=mid) update(k<<1,l,mid,L,R,x);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,x);
	pushup(k);
}
void BellaKira()
{
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	build(1,1,n);
	for (int i=1;i<=q;i++)
	{
		int opt,x,y;
		cin>>opt>>x>>y;
		if (opt==1)
		{
			update(1,1,n,1,x,y);
		} else
		{
			ans=0;
			val=y;
			query(1,1,n,x,n);
			cout<<ans<<endl;
		}
	}
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}