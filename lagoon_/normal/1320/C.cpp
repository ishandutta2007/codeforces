#include<bits/stdc++.h>
#define re register
struct pi{int x,y,w,tp;}pp[1000100];
inline bool cmp(const pi&A,const pi&B){return A.x==B.x?A.tp>B.tp:A.x<B.x;}
long long f[4001000],tg[4001000],ww[4001000];
void pu(re int i)
{
	f[i]=std::max(f[i*2],f[i*2+1]);
}
void adv(re int i,re int v)
{
	f[i]+=v;tg[i]+=v;
}
void pd(re int i)
{
	if(tg[i])
	{
		adv(i*2,tg[i]);
		adv(i*2+1,tg[i]);
		tg[i]=0;
	}
}
void build(re int i,re int l,re int r)
{
	if(l==r){f[i]=ww[l];return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	pu(i);
}
int l1,r1,x1;
void add(re int i,re int l,re int r)
{
	if(l1>r1)return;
	if(l>=l1&&r<=r1){adv(i,x1);return;}
	pd(i);
	re int mid=(l+r)/2;
	if(l1<=mid)add(i*2,l,mid);
	if(r1>mid)add(i*2+1,mid+1,r);
	pu(i);
}
int main()
{
	re int n,m,p,x,y,k;
	scanf("%d%d%d",&n,&m,&p);
	for(re int i=1;i<=1e6;i++)ww[i]=-1ll<<60;
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&pp[i].x,&pp[i].w);
		pp[i].tp=2;
	}
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		ww[x]=std::max(ww[x],-1ll*y);
	}
	for(re int i=1;i<=p;i++)
	{
		scanf("%d%d%d",&pp[i+n].x,&pp[i+n].y,&pp[i+n].w);
		pp[i+n].tp=1;
	}
	r1=1e6;
	build(1,1,1e6);
	std::sort(pp+1,pp+n+p+1,cmp);
	re long long ans=-1ll<<60;
	for(re int i=1;i<=n+p;i++)
	{
		if(pp[i].tp==1)
		{
			l1=pp[i].y+1;x1=pp[i].w;
			add(1,1,1e6);
		}
		else
		{
			ans=std::max(ans,f[1]-pp[i].w);
		}
	}
	printf("%lld\n",ans);
}