#include<bits/stdc++.h>
using namespace std;
#define re register
int L;
struct seg
{
	int n,a[5],b[5];
	seg operator + (const seg&A)
	{
		seg B=A;
		for(re int i=0;i<n;i++)
		{
			re bool bl=1;
			for(re int j=0;j<B.n;j++)if(a[i]==B.a[j]){B.b[j]+=b[i];bl=0;break;}
			if(bl)
			{
				if(B.n<L)B.a[B.n]=a[i],B.b[B.n++]=b[i];
				else
				{
					re int x=0;
					for(re int j=1;j<B.n;j++)if(B.b[j]<B.b[x])x=j;
					if(B.b[x]<b[i])
					{
						for(re int j=0;j<B.n;j++)if(j!=x)B.b[j]-=B.b[x];
						B.a[x]=a[i];B.b[x]=b[i]-B.b[x];
					}else for(re int j=0;j<B.n;j++)B.b[j]-=b[i];
				}
			}
		}
		return B;
	}
}f[600100],ans;
int a[150010],tg[600100];
void ad(re int i,re int a,re int l){f[i].n=1;f[i].a[0]=a;f[i].b[0]=l;tg[i]=a;}
void pu(re int i){f[i]=f[i*2]+f[i*2+1];}
void pd(re int i,re int l,re int r)
{
	if(tg[i])
	{
		re int mid=(l+r)/2;
		ad(i*2,tg[i],mid-l+1);
		ad(i*2+1,tg[i],r-mid+1);
		tg[i]=0;
	}
}
void build(re int i,re int l,re int r)
{
	if(l==r){ad(i,a[l],1);return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	pu(i);
}
int l1,r1,a1;
void mdf(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){ad(i,a1,r-l+1);return;}
	pd(i,l,r);
	re int mid=(l+r)/2;
	if(l1<=mid)mdf(i*2,l,mid);
	if(r1>mid)mdf(i*2+1,mid+1,r);
	pu(i);
}
void qus(re int i,re int l,re int r)
{
	if(l>=l1&&r<=r1){ans=ans+f[i];return;}
	pd(i,l,r);
	re int mid=(l+r)/2;
	if(l1<=mid)qus(i*2,l,mid);
	if(r1>mid)qus(i*2+1,mid+1,r);
}
int main()
{
	re int n,m,p,tp;
	scanf("%d%d%d",&n,&m,&p);L=100/p;
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d",&tp);
		if(tp==1)
		{
			scanf("%d%d%d",&l1,&r1,&a1);
			mdf(1,1,n);
		}else
		{
			scanf("%d%d",&l1,&r1);
			ans.n=0;
			qus(1,1,n);
			printf("%d ",ans.n);
			for(re int j=0;j<ans.n;j++)printf("%d ",ans.a[j]);puts("");
		}
	}
}