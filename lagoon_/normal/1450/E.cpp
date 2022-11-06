#include<bits/stdc++.h>
#define re register
struct eg{int to,c;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b,re int c)
{
	*++cnt=(eg){b,c,la[a]};la[a]=cnt;
}
int x[10010],y[10010],b[10010],vis[10010],dis[10010],q[4000010],dd[10010],da[10010],ta;
void dfs(re int a)
{
	for(re eg*i=la[a];i;i=i->nx)if(!vis[i->to])
	{
		vis[i->to]=vis[a]^1;
		dfs(i->to);
	}else if(vis[i->to]==vis[a])puts("NO"),exit(0);
}
int main()
{
	re int n,m;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&b[i]);
		addE(x[i],y[i],0);
		addE(y[i],x[i],0);
	}
	vis[1]=2;
	dfs(1);
	cnt=e;
	for(re int i=1;i<=n;i++)la[i]=0;
	for(re int i=1;i<=m;i++)
	{
		addE(x[i],y[i],1);
		if(!b[i])
		{
			addE(y[i],x[i],1);
		}
		else addE(y[i],x[i],-1);
	}
	re int ans=-1;
	for(re int i=1;i<=n;i++)
	{
		q[ta=1]=i;
		for(re int j=1;j<=n;j++)dis[j]=1<<30,dd[j]=0,vis[j]=0;
		dis[i]=0;
		vis[i]=1;
		for(re int j=1;j<=ta;j++)
		{
			re int x=q[j];
			for(re eg*i1=la[x];i1;i1=i1->nx)if(dis[i1->to]>dis[x]+i1->c)
			{
				dis[i1->to]=dis[x]+i1->c;
				if(!vis[i1->to])
				{
					q[++ta]=i1->to,vis[i1->to]=1;dd[i1->to]++;
					if(dd[i1->to]>n)puts("NO"),exit(0);
				}
			}
			vis[x]=0;
		}
		re int num=0;
		for(re int j=1;j<=n;j++)num=std::max(num,dis[j]);
		if(num>ans)
		{
			ans=num;
			for(re int j=1;j<=n;j++)da[j]=dis[j];
		}
	}
	puts("YES");
	printf("%d\n",ans);
	for(re int j=1;j<=n;j++)printf("%d ",da[j]);puts("");
}