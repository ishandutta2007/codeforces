#include<bits/stdc++.h>
long long t[100100],tl[100100],f[400100],qw[400100],nm[400100],tg[400100],st[400100];
#define re register
inline void pu(re int i)
{
	f[i]=std::min(f[i*2],f[i*2+1]);
	nm[i]=(nm[i*2]==nm[i*2+1]?nm[i*2]:(-1ll<<60));
	qw[i]=qw[i*2];
}
inline void add(re int i,re long long x)
{
	tg[i]+=x;f[i]-=x;nm[i]+=x;
	if(f[i]<0&&nm[i]>0)
	{
		for(qw[i]*=42;qw[i]<nm[i];qw[i]*=42);
		f[i]=qw[i]-nm[i];
	}
}
inline void pd(re int i)
{
	if(st[i])
	{
		st[i]=0;st[i*2]=st[i*2+1]=1;tg[i]=tg[i*2]=tg[i*2+1]=0;
		f[i*2]=f[i];nm[i*2]=nm[i];qw[i*2]=qw[i];
		f[i*2+1]=f[i];nm[i*2+1]=nm[i];qw[i*2+1]=qw[i];
	}
	else if(tg[i])
	{
		add(i*2,tg[i]);add(i*2+1,tg[i]);
		tg[i]=0;
	}
}
void build(re int i,re int l,re int r)
{
	if(l==r){nm[i]=t[l];f[i]=tl[l]-t[l];qw[i]=tl[l];return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	pu(i);
}
int l1,r1,x;
long long xx;
bool rbg;
void rdf(re int i)
{//printf("**%d %lld %lld %lld\n",i,f[i],nm[i],qw[i]);
	if(f[i]<0)pd(i),rdf(i*2),rdf(i*2+1),pu(i);
}
void mdf(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){add(i,x);rdf(i);rbg|=(f[i]==0);return;}
	pd(i);
	re int mid=(l+r)/2;
	if(l1<=mid)mdf(i*2,l,mid);
	if(r1>mid)mdf(i*2+1,mid+1,r);
	pu(i);
}
void rst(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){nm[i]=x;qw[i]=xx;f[i]=xx-x;st[i]=1;return;}
	pd(i);
	re int mid=(l+r)/2;
	if(l1<=mid)rst(i*2,l,mid);
	if(r1>mid)rst(i*2+1,mid+1,r);
	pu(i);
}
int qry(re int i,re int l,re int r)
{
	if(l==r){return i;}
	re int mid=(l+r)/2;
	pd(i);
	if(l1<=mid)return qry(i*2,l,mid);
	else return qry(i*2+1,mid+1,r);
}
int main()
{
	re int n,q;
	scanf("%d%d",&n,&q);
	for(re int i=1;i<=n;i++)
	{
		scanf("%lld",&t[i]);
		for(tl[i]=42;tl[i]<t[i];tl[i]*=42);
	}
	build(1,1,n);
	for(;q--;)
	{
		re int T;
		scanf("%d",&T);
		if(T==1)scanf("%d",&l1),printf("%lld\n",nm[qry(1,1,n)]);
		else if(T==2)
		{
			scanf("%d%d%d",&l1,&r1,&x);
			for(xx=42;xx<x;xx*=42);
			rst(1,1,n);
		}
		else
		{
			scanf("%d%d%d",&l1,&r1,&x);
			rbg=1;
			while(rbg)
			{
				rbg=0;//puts("********");
				mdf(1,1,n);
			}
		}
	}
	return 0;
}