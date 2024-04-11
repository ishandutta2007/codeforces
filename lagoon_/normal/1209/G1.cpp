#include<bits/stdc++.h>
using namespace std;
#define re register
int a[200100],mi[200100],bi[200100],nn[200100];
struct par
{
	int l,r,x;
}pp[200100];
inline bool cmp(const par&A,const par&B){return A.l<B.l;}
int main()
{
	re int n,m,t,ans=0,rr=0,nw=0;
	scanf("%d%*d",&n);
	for(re int i=1;i<=200000;i++)mi[i]=1e9;
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]),mi[a[i]]=min(mi[a[i]],i),bi[a[i]]=i,nn[a[i]]++;
	for(re int i=1;i<=200000;i++)pp[i]=(par){mi[i],bi[i],i};
	sort(pp+1,pp+200001,cmp);
	for(re int i=1;i<=200000;i++)
	{
		if(pp[i].l==1e9){continue;}
		if(pp[i].l>rr){ans+=nw;nw=nn[pp[i].x];rr=pp[i].r;}
		else rr=max(rr,pp[i].r),nw=max(nw,nn[pp[i].x]);
	}ans+=nw;
	printf("%d\n",n-ans);
}