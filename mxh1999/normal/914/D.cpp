#include<bits/stdc++.h>
using namespace std;

const int maxn=500010;
int a[maxn];
int seg[maxn<<2];
int n,m;
void build(int t,int l,int r)
{
	if (l==r)	{seg[t]=a[l];return;}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	seg[t]=__gcd(seg[t<<1],seg[t<<1|1]);
}
bool ok(int t,int l,int r,int ql,int qr,int x)
{
	if (ql<=l && qr>=r)	return (seg[t]%x==0);
	int mid=(l+r)>>1;
	if (qr<=mid)	return ok(t<<1,l,mid,ql,qr,x);
	if (ql>mid)	return ok(t<<1|1,mid+1,r,ql,qr,x);
	return (ok(t<<1,l,mid,ql,mid,x)&&ok(t<<1|1,mid+1,r,mid+1,qr,x));
}
bool ask(int t,int l,int r,int ql,int qr,int x)
{
	if (ql==qr)	return true;
	int mid=(l+r)>>1;
	if (qr<=mid)	return ask(t<<1,l,mid,ql,qr,x);
	if (ql>mid)	return ask(t<<1|1,mid+1,r,ql,qr,x);
	if (ok(t<<1,l,mid,ql,qr,x))	return ask(t<<1|1,mid+1,r,mid+1,qr,x);
	else return (ok(t<<1|1,mid+1,r,mid+1,qr,x) && ask(t<<1,l,mid,ql,mid,x));
}
void change(int t,int l,int r,int num,int y)
{
	if (l==r)
	{
		seg[t]=y;
		return;
	}
	int mid=(l+r)>>1;
	if (num<=mid)	change(t<<1,l,mid,num,y);else change(t<<1|1,mid+1,r,num,y);
	seg[t]=__gcd(seg[t<<1],seg[t<<1|1]);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int op;
		scanf("%d",&op);
		if (op==1)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			bool qaq=ask(1,1,n,l,r,x);
			if (qaq)	printf("YES\n");else printf("NO\n");
		}	else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			change(1,1,n,x,y);
		}
	}
	return 0;
}