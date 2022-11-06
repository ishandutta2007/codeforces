
 #include<bits/stdc++.h>
using namespace std;
#define re register
long long f[400100],tg[400100],P,a[100100],ans[100100],nw;
void ad(re int i,re long long p){tg[i]=max(tg[i],p);f[i]=max(f[i],p);}
void pd(re int i)
{
	if(tg[i])
	{
		ad(i*2,tg[i]);
		ad(i*2+1,tg[i]);
		tg[i]=0;
	}
}
void pu(re int i)
{
	f[i]=min(f[i*2],f[i*2+1]);
}
void build(re int i,re int l,re int r)
{
	if(l==r){f[i]=a[l];return;}
	re int mid=(l+r)/2;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	pu(i);
}
void qus(re int i,re int l,re int r)
{
	if(l==r){ans[l]=max(f[i]+P,nw+P);nw=ans[l];f[i]=1ll<<60;return;}
	pd(i);
	re int mid=(l+r)/2;
	if(f[i*2]==f[i])ad(i*2+1,max(f[i]+P,nw+P)),qus(i*2,l,mid);
	else qus(i*2+1,mid+1,r);
	pu(i);
}
int main()
{
	re int n;
	scanf("%d%lld",&n,&P);
	for(re int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	for(re int i=1;i<=n;i++)qus(1,1,n);
	for(re int i=1;i<=n;i++)printf("%lld ",ans[i]);
}