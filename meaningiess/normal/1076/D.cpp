#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define ll long long
#define N 300010
using namespace std;
struct graph
{
	int nxt[N<<1],fst[N<<1],to[N<<1],val[N<<1],v2[N<<1],cnt;
	void add(int u,int v,int w,int r) {nxt[++cnt]=fst[u],fst[u]=cnt,to[cnt]=v,val[cnt]=w;v2[cnt]=r;}
}g1,g2;
struct node{int x;ll dis;};
bool operator < (node a,node b) {return a.dis>b.dis;}
ll dis[N];int pre[N],n,r[N],k,vis[N];
priority_queue <node> q;queue<int> q2;
inline void dij()
{
    int a,i;
    for (i=1;i<=n;i++) dis[i]=21474836470000000LL;
    dis[1]=0;q.push((node){1,0});
    while(!q.empty())
    {
        a=q.top().x;q.pop();if(vis[a]) continue;vis[a]=1;
        for (i=g1.fst[a];i;i=g1.nxt[i])if(dis[g1.to[i]]>dis[a]+g1.val[i]) 
			{dis[g1.to[i]]=dis[a]+g1.val[i];pre[g1.to[i]]=a;r[g1.to[i]]=g1.v2[i];if(!vis[g1.to[i]])q.push((node){g1.to[i],dis[g1.to[i]]});};
    }
}
void bfs()
{
	q2.push(1);memset(vis,0,sizeof(vis));
	while (!q2.empty() && k)
	{
		int a=q2.front();q2.pop();vis[a]=1;
		for (int i=g2.fst[a];i;i=g2.nxt[i]) if (!vis[g2.to[i]]) {if (k) q2.push(g2.to[i]),k--,printf("%d ",g2.val[i]);}
	}
}
int main()
{
	int m,i,u,v,x;scanf("%d%d%d",&n,&m,&k);
	for (i=1;i<=m;i++) scanf("%d%d%d",&u,&v,&x),g1.add(u,v,x,i),g1.add(v,u,x,i);
	dij();
	for (i=1;i<=n;i++) if (pre[i]) g2.add(i,pre[i],r[i],0),g2.add(pre[i],i,r[i],0);
	cout<<min(n-1,k)<<endl;bfs();
}