#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1000006;
int n,m;
ll sum[N*4],a[N],ma[N*4];
inline int read()
{
	char C=getchar();
	int F=1,ANS=0;
	while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
	while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
	return F*ANS;
}
inline void push_up(int u)
{
	sum[u]=sum[u*2]+sum[u*2+1];
	ma[u]=max(ma[u*2],ma[u*2+1]);
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		sum[u]=a[l],ma[u]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid);
	build(u*2+1,mid+1,r);
	push_up(u);
}
void modify(int u,int l,int r,int x,ll p)
{
	if (l==r)
	{
		sum[u]=p,ma[u]=p;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) modify(u*2,l,mid,x,p);
	else modify(u*2+1,mid+1,r,x,p);
	push_up(u);
}
void change(int u,int l,int r,int L,int R,ll p)
{
	if (ma[u]<p) return;
	if (l==r)
	{
		sum[u]=sum[u]%p;
		ma[u]=sum[u];
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid) change(u*2,l,mid,L,R,p);
	if (mid<R) change(u*2+1,mid+1,r,L,R,p);
	push_up(u);
}
ll ask(int u,int l,int r,int L,int R)
{
	if (L<=l&&r<=R) return sum[u];
	ll res=0;
	int mid=(l+r)>>1;
	if (L<=mid) res+=ask(u*2,l,mid,L,R);
	if (mid<R) res+=ask(u*2+1,mid+1,r,L,R);
	return res;
}
int main()
{
	// freopen("tiao.in","r",stdin);
	// freopen("tiao.out","w",stdout);
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int tp=read();
		if (tp==1) 
		{
			int l=read(),r=read();
			ll ans=ask(1,1,n,l,r);
			printf("%lld\n",ans);
		}
		else if (tp==2)
		{
			ll l=read(),r=read(),p=read();
			change(1,1,n,l,r,p);
		}
		else
		{
			ll x=read(),p=read();
			modify(1,1,n,x,p);
		}
	}
	return 0;
}