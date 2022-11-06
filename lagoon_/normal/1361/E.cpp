#include<bits/stdc++.h>
#define re register
std::vector<int>to[100100];
int rad(){return rand()*32768+rand();}
bool vis[100100],in[100100],ok[100100],bl;
int vl[100100],dep[100100],vv[100100],tot;
void dfs(re int a)
{
	in[a]=1;vis[a]=1;
	for(auto x:to[a])if(!vis[x])dfs(x);
	else if(!in[x])bl=0;
	in[a]=0;
}
void dfs1(re int a)
{
	vis[a]=1;vv[a]=a;
	for(auto x:to[a])if(!vis[x])
	{
		dep[x]=dep[a]+1;
		dfs1(x);
		vl[a]+=vl[x];
		if(dep[vv[x]]<dep[vv[a]])vv[a]=vv[x];
	}
	else
	{
		if(dep[x]<dep[vv[a]])vv[a]=x;
		vl[a]++;vl[x]--;
	}
}
void dfs2(re int a)
{
	if(vl[a]==1)
	{
		ok[a]=ok[vv[a]];
	}else ok[a]=(vl[a]==0);
	vis[a]=1;
	//printf("****%d %d %d %d\n",a,vl[a],vv[a],ok[a]);
	for(auto x:to[a])if(!vis[x])
	{
		dfs2(x);
	}
}
int main()
{
	//srand(time(0));
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		re int n,m,x,y,bb=1;
		scanf("%d%d",&n,&m);
		for(re int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);to[x].push_back(y);
		}
		for(re int i=1;i<=100;i++)
		{
			x=rad()%n+1;bl=1;
			for(re int i=1;i<=n;i++)vis[i]=0;
			dfs(x);
			if(bl)
			{
				tot=0;
				for(re int i=1;i<=n;i++)vis[i]=0;
				dep[x]=1;dfs1(x);
				for(re int i=1;i<=n;i++)vis[i]=0;
				dfs2(x);
				re int xx=0;
				for(re int i=1;i<=n;i++)xx+=ok[i];
				if(xx*5<n)puts("-1");
				else
				{
					for(re int i=1;i<=n;i++)if(ok[i])printf("%d ",i);
					puts("");
				}
				bb=0;
				break;
			}
		}
		if(bb)puts("-1");
		for(re int i=1;i<=n;i++)to[i].clear(),ok[i]=vv[i]=vl[i]=dep[i]=0;
	}
}