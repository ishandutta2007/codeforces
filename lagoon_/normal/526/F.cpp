#include<bits/stdc++.h>
#define re register
int p[300100];
struct pp
{
	int x,y;
	pp operator +(const pp&A){return x==A.x?(pp){x,y+A.y}:(x<A.x?*this:A);}
};
struct seg
{
	pp aa,mi,mx;
	seg operator +(const seg&A){return (seg){aa+A.aa,mi+A.mi,mx+A.mx};}
}f[1200100];
int ti[1200100],tx[1200100];
void sti(re int i,re int l,re int r,re int x)
{
	ti[i]=x;f[i].aa=(pp){f[i].mx.x-x,f[i].mx.y};
	f[i].mi=(pp){l-x,1};
}
void stx(re int i,re int l,re int r,re int x)
{
	tx[i]=x;f[i].aa=(pp){f[i].mi.x+x,f[i].mi.y};
	f[i].mx=(pp){x+l,1};
}
void pd(re int i,re int l,re int r)
{
	re int mid=(l+r)/2;
	if(ti[i])
	{
		sti(i*2,l,mid,ti[i]);sti(i*2+1,mid+1,r,ti[i]);
		ti[i]=0;
	}
	if(tx[i])
	{
		stx(i*2,l,mid,tx[i]);stx(i*2+1,mid+1,r,tx[i]);
		tx[i]=0;
	}
}
int l1,r1,x;
void mdfi(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){sti(i,l,r,x);return;}
	pd(i,l,r);
	re int mid=(l+r)/2;
	if(l1<=mid)mdfi(i*2,l,mid);
	if(r1>mid)mdfi(i*2+1,mid+1,r);
	f[i]=f[i*2]+f[i*2+1];
}
void mdfx(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){stx(i,l,r,x);return;}
	pd(i,l,r);
	re int mid=(l+r)/2;
	if(l1<=mid)mdfx(i*2,l,mid);
	if(r1>mid)mdfx(i*2+1,mid+1,r);
	f[i]=f[i*2]+f[i*2+1];
}
int q1[300100],q2[300100],ta1,ta2;
int main()
{
	re int n,xx,y;
	re long long ans=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d%d",&xx,&y),p[xx]=y;
	for(re int i=1;i<=4*n;i++)f[i].aa.x=f[i].mx.x=f[i].mi.x=1<<30;
	for(re int i=1;i<=n;i++)
	{
		r1=i;x=p[i];
		while(ta1&&p[q1[ta1]]>p[i])ta1--;
		l1=q1[ta1]+1;q1[++ta1]=i;mdfi(1,1,n);l1=i;
		while(ta2&&p[q2[ta2]]<p[i])ta2--;
		l1=q2[ta2]+1;q2[++ta2]=i;mdfx(1,1,n);
		ans+=f[1].aa.y;
	}
	printf("%lld\n",ans);
}