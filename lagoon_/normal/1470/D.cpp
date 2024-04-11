#include<bits/stdc++.h>
#define re register
struct eg{int to;eg*nx;}e[600100],*la[300100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int vis[300100],ans[300100],qq[1000100],ta;
int main()
{
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		re int n,m,u,v;
		scanf("%d%d",&n,&m);
		cnt=e;
		for(re int i=1;i<=n;i++)la[i]=0,vis[i]=ans[i]=0;
		for(re int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			addE(u,v);
		}
		qq[ta=1]=1;
		for(re int i=1;i<=ta;i++)
		{
			re int x=qq[i];
			if(vis[x])continue;
			vis[x]=ans[x]=1;
			for(re eg*i=la[x];i;i=i->nx)
			if(!vis[i->to]){
				for(re eg*j=la[i->to];j;j=j->nx)if(!vis[j->to])qq[++ta]=j->to;
				vis[i->to]=1;
			}
		}
		re bool bl=0;
		for(re int i=1;i<=n;i++)if(!vis[i]){bl=1;break;}
		if(bl)puts("NO");
		else
		{
			puts("YES");
			re int nn=0;
			for(re int i=1;i<=n;i++)nn+=ans[i];
			printf("%d\n",nn);
			for(re int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
			puts("");
		}
	}
}