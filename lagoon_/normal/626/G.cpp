#include<bits/stdc++.h>
#define re register
int p[200100],l[200100],l1[200100],N,f[800100],g[800100],q[200100];
inline long double vl(re int i,re int q)
{
	if(q<0)return -1e100;
	if(q>l[i])q=l[i];
	return (long double)q/(l[i]+q)*p[i];
}
inline void upd(re int a)
{
	re int x1=f[a*2],x2=f[a*2+1];
	if(!x2)x2=x1;
	f[a]=(vl(x1,l1[x1]+1)-vl(x1,l1[x1])>=vl(x2,l1[x2]+1)-vl(x2,l1[x2]))?x1:x2;
	//printf("**%d %d %d %d\n",a,x1,x2,f[a]);
	x1=g[a*2],x2=g[a*2+1];
	if(!x2)x2=x1;
	g[a]=(vl(x1,l1[x1])-vl(x1,l1[x1]-1)<=vl(x2,l1[x2])-vl(x2,l1[x2]-1))?x1:x2;
}
void mdf(re int a)
{
	for(a=(a+N)/2;a;a/=2)upd(a);
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);
	re int n,t,q1,ta;
	re long double ans=0;
	scanf("%d%d%d",&n,&t,&q1);
	for(N=1;N<n;N*=2);N--;
	for(re int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(re int i=1;i<=n;i++)scanf("%d",&l[i]);
	for(re int i=1;i<=n;i++)f[i+N]=g[i+N]=i;
	for(re int i=(N+n)/2;i;i--)upd(i);
	for(;t;t--)
	{//printf("**%d %d %Lf\n",t,f[1],vl(f[1],l1[f[1]]+1)-vl(f[1],l1[f[1]]));
		ans+=vl(f[1],l1[f[1]]+1)-vl(f[1],l1[f[1]]);
		l1[f[1]]++;
		mdf(f[1]);
	}
	for(;q1--;)
	{
		re int tk,rk;
		scanf("%d%d",&tk,&rk);
		tk=(tk==1?1:-1);
		ans-=vl(rk,l1[rk]);
		l[rk]+=tk;
		ans+=vl(rk,l1[rk]);
		mdf(rk);
		while(vl(f[1],l1[f[1]]+1)-vl(f[1],l1[f[1]])>vl(g[1],l1[g[1]])-vl(g[1],l1[g[1]]-1))
		{
			ans+=vl(f[1],l1[f[1]]+1)-vl(f[1],l1[f[1]])-(vl(g[1],l1[g[1]])-vl(g[1],l1[g[1]]-1));
			l1[f[1]]++;l1[g[1]]--;
			re int gg=g[1];
			mdf(f[1]);mdf(gg);
		}
		std::cout<<std::setprecision(20)<<ans<<'\n';
	}
}