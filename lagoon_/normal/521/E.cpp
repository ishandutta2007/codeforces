#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[400100],*la[200100],*cnt=e;
void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int f[200100],fa[200100],dfn[200100],ed[200100],a1[200100],a2[201000],a3[200100],n1,n2,n3,tot;
void clac(re int a)
{
	puts("YES");
	re int xx=fa[a],qq=-1,xx1,qq1=-1;
	a1[n1=1]=a2[n2=1]=a3[n3=1]=a;
	for(;qq==-1;xx=fa[xx])
	{
		a1[++n1]=xx;
		for(eg*i=la[xx];i;i=i->nx)if(dfn[i->to]>=dfn[a]&&dfn[i->to]<=ed[a]){qq=i->to;i->to=0;break;}
		if(qq!=-1)break;
	}
	xx1=xx;
	for(;qq1==-1;xx1=fa[xx1])
	{
		for(eg*i=la[xx1];i;i=i->nx)if(dfn[i->to]>=dfn[a]&&dfn[i->to]<=ed[a]){qq1=i->to;break;}
		if(qq1!=-1)break;
	}
	//printf("**%d %d %d %d %d\n",a,xx,xx1,qq,qq1);
	for(re int i=xx;;i=fa[i])
	{
		a3[++n3]=i;
		if(i==xx1)break;
	}
	a2[++n2]=xx;
	for(re int i=qq;i!=a;i=fa[i])a2[++n2]=i;
	for(re int i=qq1;i!=a;i=fa[i])a3[++n3]=i;
	std::reverse(a2+2,a2+n2+1);
	std::reverse(a3+2,a3+n3+1);
	printf("%d ",n1);for(re int i=1;i<=n1;i++)printf("%d ",a1[i]);puts("");
	printf("%d ",n2);for(re int i=1;i<=n2;i++)printf("%d ",a2[i]);puts("");
	printf("%d ",n3);for(re int i=1;i<=n3;i++)printf("%d ",a3[i]);puts("");
	exit(0);
}
void dfs(re int a)
{
	dfn[a]=++tot;
	for(eg*i=la[a];i;i=i->nx)if(!dfn[i->to])
	{
		re int vv=i->to;i->to=0;
		fa[vv]=a;
		dfs(vv);
		f[a]+=f[vv];
	}else if(dfn[i->to]<dfn[a]&&i->to!=fa[a])
	{
		f[a]++;f[i->to]--;
	}ed[a]=tot;
	if(f[a]>1)
	{
		clac(a);
	}
}
int main()
{
	re int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)scanf("%d%d",&a,&b),addE(a,b);
	for(re int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	puts("NO");
}