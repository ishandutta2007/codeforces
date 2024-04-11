#include<bits/stdc++.h>
#define re register
struct eg
{
	int to;eg*nx;
}e[200100],*la[1010],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
int x[2010],y[2010];
int vis[2010],ud[2010],q[2010],ta;
void rdfs(re int a,re int fa)
{
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa&&!ud[i->to])
	{
		vis[a]++;vis[i->to]++;
		rdfs(i->to,a);
	}
}
int main()
{
	re int n,m;
	scanf("%d",&n);
	if(n==2)
	{
			printf("? 1 2\n");
			fflush(stdout);
			re int xx;
			scanf("%d",&xx);
			printf("! %d\n",xx);
			return 0;
	}
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		addE(x[i],y[i]);
		vis[x[i]]++;vis[y[i]]++;
	}
	for(re int i=1;i<=n/2;i++)
	{
		re bool bo=1;
		for(re int j=1;j<n;j++)
		if(vis[x[j]]>1&&vis[y[j]]>1){
			bo=0;
			printf("? %d %d\n",x[j],y[j]);
			fflush(stdout);
			re int xx;
			scanf("%d",&xx);
			if(xx==x[j])
			{
				ud[y[j]]=1;
	for(re int i=1;i<=n;i++)vis[i]=0;
				rdfs(x[j],0);
			}else
			{
				ud[x[j]]=1;
	for(re int i=1;i<=n;i++)vis[i]=0;
				rdfs(y[j],0);
			}
			break;
		}
		if(bo)
		{
				re int xx,yy;
			for(re int i=1;i<=n;i++)if(vis[i]==1)q[++ta]=i;
			else if(vis[i]>1)yy=i;
			q[ta+1]=yy;
			for(re int i=1;i<=ta;i+=2)
			{
				
			printf("? %d %d\n",q[i],q[i+1]);
			fflush(stdout);
			re int xx;
			scanf("%d",&xx);
			if(xx!=yy){printf("! %d\n",xx);return 0;}
			}
			printf("! %d\n",yy);return 0;
		}
	}
}