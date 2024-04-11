// Lynkcat.
// Problem: E. New School
// URL: https://codeforces.com/contest/1621/problem/E
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
int tr[N<<2],tag[N<<2];
int n,a[N],m;
int tot;
int b[N],fl[N],sm[N],sz[N];
void ptag(int k,int x)
{
	tr[k]+=x;
	tag[k]+=x;
}
void pushup(int k)
{
	tr[k]=min(tr[k<<1],tr[k<<1|1]);
}
void pushdown(int k)
{
	if (!tag[k])
	{
		return;
	}
	ptag(k<<1,tag[k]);
	ptag(k<<1|1,tag[k]);
	tag[k]=0;
}
void update(int k,int l,int r,int L,int R,int x)
{
	if (L<=l&&r<=R)
	{
		ptag(k,x);
		return;
	}
	int mid=l+(r-l)/2;
	pushdown(k);
	if (L<=mid)
		update(k<<1,l,mid,L,R,x);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,x);
	pushup(k);
}
void BellaKira()
{
	tot=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) update(1,1,100001,1,a[i],1);
	for (int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		poly g;
		sm[i]=0;
		for (int j=1;j<=x;j++)
		{
			tot++;
			cin>>b[tot];
			fl[tot]=i,sm[i]+=b[tot];
		}
		sz[i]=x;
		int nw=sm[i]/sz[i]+(sm[i]%sz[i]!=0);
		// cout<<"?"<<nw<<endl;
		nw=min(nw,100001ll);
		update(1,1,100001,1,nw,-1);
		// cout<<"!"<<tr[1]<<endl;
	}
	for (int i=1;i<=tot;i++)
	{
		int nw=sm[fl[i]]/sz[fl[i]]+(sm[fl[i]]%sz[fl[i]]!=0);
		nw=min(nw,100001ll);
		update(1,1,100001,1,nw,1);
		int x=(sm[fl[i]]-b[i])/(sz[fl[i]]-1)+((sm[fl[i]]-b[i])%(sz[fl[i]]-1)!=0);
		// cout<<nw<<" "<<fl[i]<<" "<<sz[fl[i]]-1<<" "<<x<<endl;
		x=min(x,100001ll);
		update(1,1,100001,1,x,-1);
		if (tr[1]>=0) cout<<1;
		else cout<<0;
		update(1,1,100001,1,x,1);
		update(1,1,100001,1,nw,-1);
	}
	for (int i=1;i<=m;i++)
	{
		int nw=sm[i]/sz[i]+(sm[i]%sz[i]!=0);
		nw=min(nw,100001ll);
		update(1,1,100001,1,nw,1);
	}
	for (int i=1;i<=n;i++) update(1,1,100001,1,a[i],-1);
	cout<<endl;
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