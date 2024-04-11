#include<bits/stdc++.h>
#define ll long long
#define N 300010
using namespace std;
struct segt
{
	int a[N<<2],b[N<<2];
	void bil(int x,int l,int r)
	{
		a[x]=1e9;b[x]=l;if (l==r) {return;}int mid=(l+r)>>1;bil(x<<1,l,mid);bil(x<<1|1,mid+1,r);
	}
	void upd(int x,int l,int r,int p,int c)
	{
		if (l==r) {a[x]=c;return;}int mid=(l+r)>>1;
		if (p<=mid) upd(x<<1,l,mid,p,c);else upd(x<<1|1,mid+1,r,p,c);
		if (a[x<<1]<a[x<<1|1]) a[x]=a[x<<1],b[x]=b[x<<1];else a[x]=a[x<<1|1],b[x]=b[x<<1|1];
	}
	pair<int,int> qry(int x,int l,int r,int p,int q)
	{
		if (p<=l && r<=q) return {a[x],b[x]};int mid=(l+r)>>1;pair<int,int> res={1e9,1e9};
		if (p<=mid) res=min(res,qry(x<<1,l,mid,p,q));
		if (q>mid) res=min(res,qry(x<<1|1,mid+1,r,p,q));
		return res;
	}
}sgt;
int a[N],b[N],f[N],to[N];
int main()
{
	int n,i;cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	sgt.bil(1,0,n);
	sgt.upd(1,0,n,0,0);pair<int,int> tp;
	for (i=1;i<=n;i++)
	{
		tp=sgt.qry(1,0,n,i+b[i]-a[i+b[i]],i-1);
		sgt.upd(1,0,n,i,tp.first+1);to[i]=tp.second;
	}
	if (tp.first>n+10) {puts("-1");return 0;}
	printf("%d\n",tp.first+1);
	int u=n;
	while (u)
	{
		u=to[u];printf("%d ",u);
	}
}