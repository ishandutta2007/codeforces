#include<bits/stdc++.h>
#define re register
struct eg{int to;long long c;eg*nx;}e[200100],*la[100100],*cnt=e;
void addE(re int a,re int b,re long long c)
{
	*++cnt=(eg){b,c,la[a]};la[a]=cnt;
	*++cnt=(eg){a,c,la[b]};la[b]=cnt;
}
int d1[100100],s1[100100],n,q;
long long ans[100100],dis[100100],dis1[100100];
void dfs(re int a,re int fa)
{
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dis[i->to]=dis[a]+i->c;
		dfs(i->to,a);
	}
}
void dfs1(re int a,re int fa)
{
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		dis1[i->to]=dis1[a]+i->c;
		dfs1(i->to,a);
	}
}
int fa[20][100100],q1[100100],bl[100100],ta,no[100100];
long long dep[100100],vv[100100],vl[100100];
inline bool cmp(re int a,re int b){return vl[a]>vl[b];}
void dp(re int a)
{
	bl[a]=a;dep[a]=0;
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[0][a])
	{
		fa[0][i->to]=a;
		dp(i->to);
		if(dep[i->to]+i->c>dep[a])dep[a]=dep[i->to]+i->c,bl[a]=bl[i->to];
	}
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa[0][a])
	{
		if(bl[i->to]!=bl[a])q1[++ta]=bl[i->to],vl[bl[i->to]]=dep[i->to]+i->c;
	}
}
void sol(re int x,re int y)
{
	fa[0][x]=0;ta=0;dp(x);
	q1[++ta]=bl[x];vl[bl[x]]=dep[x];
	std::sort(q1+1,q1+ta+1,cmp);
	for(re int i=1;i<=ta;i++)no[q1[i]]=i,vv[i]=vv[i-1]+vl[q1[i]];
	for(re int i=1;i<20;i++)
	{
		for(re int j=1;j<=n;j++)fa[i][j]=fa[i-1][fa[i-1][j]];
	}
	for(re int i=1;i<=q;i++)
	{
		d1[i]=(d1[i]+ans[i-1]-1+n)%n+1;
		s1[i]=(s1[i]+ans[i-1]-1+n)%n+1;
		s1[i]=2*s1[i]-1;
		if(s1[i]>=ta){ans[i]=vv[ta];continue;}
		if(no[bl[d1[i]]]<=s1[i]){ans[i]=std::max(ans[i],vv[s1[i]]);continue;}
		re long long vc=vv[s1[i]];
		re int xx=bl[d1[i]];
		for(re int i1=19;i1>=0;i1--)if(no[bl[fa[i1][xx]]]>s1[i])xx=fa[i1][xx];
		xx=fa[0][xx];
		ans[i]=std::max(ans[i],std::max(vc-dis[bl[xx]]+dis[bl[d1[i]]],vc-vl[q1[s1[i]]]+dis[bl[d1[i]]]-dis[xx]));
		ans[i]=std::max(ans[i],vc-dis1[x]+dis1[bl[d1[i]]]);
	}
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	re int x,y;re long long v;
	scanf("%d%d",&n,&q);
	for(re int i=1;i<n;i++)scanf("%d%d%lld",&x,&y,&v),addE(x,y,v);
	for(re int i=1;i<=q;i++)scanf("%d%d",&d1[i],&s1[i]);
	dfs(1,0);
	re int hv=1,hv1=1;
	for(re int i=1;i<=n;i++)if(dis[i]>dis[hv])hv=i;
	dis[hv]=0;dfs(hv,0);
	for(re int i=1;i<=n;i++)if(dis[i]>dis[hv1])hv1=i;
	dis1[hv1]=0;dfs1(hv1,0);
	sol(hv,hv1);
	for(re int i=1;i<=q;i++)printf("%lld\n",ans[i]);
}