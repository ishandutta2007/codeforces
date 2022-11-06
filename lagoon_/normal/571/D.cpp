#include<bits/stdc++.h>
#define re register
#define pi std::pair<int,int>
char ss[10];
int tp[500100],x[500100],xx[500100],y[500100],sz[1000100],fa[1001000],tg[1001000],pp[310];
long long ans[501000],num[1001000];
pi as[1001000];
int find(re int a)
{
	if(a==fa[a])return a;
	else
	{
		re int x=find(fa[a]);tg[a]=std::max(tg[fa[a]],tg[a]);
		return fa[a]=x;
	}
}
int find1(re int a)
{
	if(fa[fa[a]]==fa[a])return fa[a];
	re int x=find1(fa[a]);
	num[a]+=num[fa[a]];
	return fa[a]=x;
}
int main()
{
	pp['U']=1;pp['M']=2;pp['A']=3;pp['Z']=4;pp['Q']=5;
	re int n,m,n1,q1=0,j1=1;
	scanf("%d%d",&n,&m);n1=n;
	for(re int i=1;i<=2*n;i++)fa[i]=i;
	for(re int i=1;i<=m;i++)
	{
		scanf("%s%d",ss,&x[i]);
		tp[i]=pp[ss[0]];
		if(tp[i]<=2)scanf("%d",&y[i]);
		if(tp[i]==2)fa[find(x[i])]=fa[find(y[i])]=++n1;
		else if(tp[i]==4)tg[find(x[i])]=i;
		else if(tp[i]==5)
		{
			find(x[i]);
			as[++q1].first=tg[x[i]];as[q1].second=-(q1+1)/2;
			as[++q1].first=i;as[q1].second=q1/2;
			xx[q1/2]=x[i];
		}
	}
	std::sort(as+1,as+q1+1);n1=n;
	for(re int i=1;i<=2*n;i++)fa[i]=i,sz[i]=i<=n,num[i]=0;
	while(j1<=q1&&as[j1].first==0)j1++;
	for(re int i=1;i<=m;i++)
	{
		if(tp[i]==1)
		{
			re int x1=find1(x[i]),y1=find1(y[i]);
			if(x1!=y1){fa[x1]=fa[y1]=++n1;sz[n1]=sz[y1]+sz[x1];}
		}else if(tp[i]==3)
		{
			num[find1(x[i])]+=sz[find1(x[i])];
		}
		while(j1<=q1&&as[j1].first==i)
		{
			re int x1=xx[abs(as[j1].second)];
			find1(x1);
			re long long y1=((fa[x1]==x1)?num[x1]:(num[x1]+num[fa[x1]]));
			ans[abs(as[j1].second)]+=(as[j1].second>0?y1:-y1);
			j1++;
		}
	}
	for(re int i=1;i<=q1/2;i++)printf("%lld\n",ans[i]);
}