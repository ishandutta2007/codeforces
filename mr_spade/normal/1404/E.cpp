#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using std::min;
using std::queue;
const int inf=0x3f3f3f3f;
namespace dinic
{
	const int N=1e5+5,M=1e6+5;
	int n,s,t,tot;
	int v[M],w[M],first[N],next[M];
	int lv[N],iter[N];
	inline void add_edge(int x,int y,int z)
	{
		tot+=2;v[tot+1]=x;v[tot]=y;
		w[tot]=z;w[tot+1]=0;
		next[tot]=first[x];first[x]=tot;
		next[tot+1]=first[y];first[y]=tot+1;
		return;
	}
	int dfs(int x,int f)
	{
		if(x==t)
			return f;
		int tot=0,d;
		for(int &i=iter[x];i;i=next[i])
			if(w[i]&&lv[v[i]]==lv[x]+1&&(d=dfs(v[i],min(w[i],f-tot))))
			{
				w[i]-=d;w[i^1]+=d;
				if((tot+=d)==f)
					break;
			}
		return tot;
	}
	queue<int> Q;
	inline bool bfs()
	{
		int x;
		register int i;
		memset(lv+1,inf,sizeof(int)*n);
		lv[s]=0;Q.push(s);
		while(!Q.empty())
		{
			x=Q.front();Q.pop();
			for(i=first[x];i;i=next[i])
				if(w[i]&&lv[v[i]]==inf)
					lv[v[i]]=lv[x]+1,Q.push(v[i]);
		}
		return lv[t]<inf;
	}
	inline int run()
	{
		int res=0;
		while(bfs())
			memcpy(iter+1,first+1,sizeof(int)*n),res+=dfs(s,inf);
		return res;
	}
}
const int N=205;
int n,m,sum,idx;
char mp[N][N];
int id[N][N][2];
signed main()
{
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(mp[i][j]=='#')
				sum++;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(mp[i][j]=='#'&&mp[i][j+1]=='#')
				id[i][j][0]=++idx;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(mp[i][j]=='#'&&mp[i+1][j]=='#')
				id[i][j][1]=++idx;
	dinic::n=idx+2;dinic::s=idx+1;dinic::t=idx+2;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(id[i][j][0])
			{
				dinic::add_edge(dinic::s,id[i][j][0],1);
				if(id[i-1][j][1])
					dinic::add_edge(id[i][j][0],id[i-1][j][1],1);
				if(id[i][j][1])
					dinic::add_edge(id[i][j][0],id[i][j][1],1);
				if(id[i-1][j+1][1])
					dinic::add_edge(id[i][j][0],id[i-1][j+1][1],1);
				if(id[i][j+1][1])
					dinic::add_edge(id[i][j][0],id[i][j+1][1],1);
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(id[i][j][1])
				dinic::add_edge(id[i][j][1],dinic::t,1);
	printf("%d\n",sum-(idx-dinic::run()));
	return 0;
}