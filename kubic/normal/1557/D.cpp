#include <bits/stdc++.h>
using namespace std;
#define N 600005
#define mid ((l+r)/2)
#define pb push_back 
int n,m,ps,a[N],dp[N],pr[N],ds[N];bool vs[N];
struct Node {int l,r;}b[N];vector<Node> vc[N];
struct Seg {int vl,tg;}sg[N*4];
void pu(int p)
{
	int tL=sg[p*2].vl,tR=sg[p*2+1].vl;
	sg[p].vl=dp[tL]>dp[tR]?tL:tR;
}
void mdf(int p,int vl)
{
	if(dp[vl]>dp[sg[p].vl]) sg[p].vl=vl;
	if(dp[vl]>dp[sg[p].tg]) sg[p].tg=vl;
}
void pd(int p)
{
	if(sg[p].tg)
		mdf(p*2,sg[p].tg),mdf(p*2+1,sg[p].tg),sg[p].tg=0;
}
void upd(int p,int l,int r,int qL,int qR,int vl)
{
	if(l>=qL && r<=qR) {mdf(p,vl);return;}pd(p);
	if(qL<=mid) upd(p*2,l,mid,qL,qR,vl);
	if(qR>mid) upd(p*2+1,mid+1,r,qL,qR,vl);pu(p);
}
int qMx(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p].vl;pd(p);int tL,tR;
	if(qL<=mid) tL=qMx(p*2,l,mid,qL,qR);
	if(qR>mid) tR=qMx(p*2+1,mid+1,r,qL,qR);
	if(qL<=mid && qR>mid) return dp[tL]>dp[tR]?tL:tR;
	if(qL<=mid) return tL;return tR; 
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d %d %d",&a[i],&b[i].l,&b[i].r);
		ds[++ds[0]]=b[i].l;ds[++ds[0]]=b[i].r;
	}sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=m;++i)
	{
		b[i].l=lower_bound(ds+1,ds+ds[0]+1,b[i].l)-ds;
		b[i].r=lower_bound(ds+1,ds+ds[0]+1,b[i].r)-ds;
		vc[a[i]].pb(b[i]);
	}
	for(int i=1,t;i<=n;++i)
	{
		dp[i]=1;
		for(auto j:vc[i])
		{
			t=qMx(1,1,ds[0],j.l,j.r);
			if(dp[t]+1>dp[i]) dp[i]=dp[t]+1,pr[i]=t;
		}for(auto j:vc[i]) upd(1,1,ds[0],j.l,j.r,i);
		if(dp[i]>dp[ps]) ps=i;
	}for(int i=ps;i;i=pr[i]) vs[i]=1;
	printf("%d\n",n-dp[ps]);
	for(int i=1;i<=n;++i) if(!vs[i]) printf("%d ",i);return 0;
}