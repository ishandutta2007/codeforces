#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int qz[200005];
struct tree
{
	int l,r,maxn;
}a[800004];
void build(int l,int r,int k)
{
	a[k].l=l;
	a[k].r=r;
	if(l==r)
	{
		a[k].maxn=qz[l];
		return;
	}
	build(l,(l+r)>>1,k<<1);
	build(((l+r)>>1)+1,r,k<<1|1);
	a[k].maxn=max(a[k<<1].maxn,a[k<<1|1].maxn);
}
int querynex(int x,int k,int y)
{
	if(a[k].r<x)return -1;
	if(a[k].maxn<y)return -1;
	if(a[k].l==a[k].r)return a[k].l;
	int sth=-1;
	if(a[k<<1].maxn>=y)sth=querynex(x,k<<1,y);
	if(sth!=-1)return sth;
	return querynex(x,k<<1|1,y);
}
int querylas(int x,int k,int y)
{
	if(a[k].l>x)return -1;
	if(a[k].maxn<y)return -1;
	if(a[k].l==a[k].r)return a[k].l;
	int sth=-1;
	if(a[k<<1|1].maxn>=y)sth=querylas(x,k<<1|1,y);
	if(sth!=-1)return sth;
	return querylas(x,k<<1,y);
}
signed main()
{
	int n,m,q,xs,ys,xt,yt,k,x,y;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)qz[i]=read();
	build(1,m,1);
	q=read();
	for(int i=1;i<=q;i++)
	{
		xs=read();
		ys=read();
		xt=read();
		yt=read();
		k=read();
		if(abs(xs-xt)%k!=0||abs(ys-yt)%k!=0)
		{
			printf("NO\n");
			continue;
		}
		xs=n/k*k+xs%k;
		if(xs>n)xs-=k;
		x=querylas(ys-1,1,xs);
		if(x==-1)x=0;
		else x++;
		y=querynex(ys+1,1,xs);
		if(y==-1)y=m+1;
		else y--;
		//printf("%d %d\n",x,y);
		if(yt>=x&&yt<=y)
		{
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0;
}