#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 1000005
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
int n,m,c,h,mx,ans,dg[N],w[N],ans1[M];
int cntE,hd[N];struct Edge {int v,w,id,nxt;}e[M];
int S,T,dst[N],cur[N],q[N];
void addE(int u,int v,int w,int id)
{
	if(!w) return;e[cntE]=(Edge) {v,w,id,hd[u]};hd[u]=cntE++;dg[u]+=w;
	e[cntE]=(Edge) {u,0,id,hd[v]};hd[v]=cntE++;dg[v]+=w;
}
bool bfs(int S,int T)
{
	cpy(cur,hd);set(dst,-1);dst[S]=0;q[0]=2;q[1]=1;q[++q[1]]=S;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=hd[u],v;~i;i=e[i].nxt)
		{v=e[i].v;if(e[i].w>0 && dst[v]==-1) dst[v]=dst[u]+1,q[++q[1]]=v;}
	}return dst[T]!=-1;
}
int dfs(int u,int T,int nw)
{
	if(u==T) return nw;int flw=0;
	for(int i=cur[u],v,w,t;~i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;cur[u]=i;
		if(w>0 && dst[v]==dst[u]+1 && (t=dfs(v,T,min(nw,w))))
		{nw-=t;flw+=t;e[i].w-=t;e[i^1].w+=t;if(!nw) break;}
	}return flw;
}
int Dinic(int S,int T) {int res=0;while(bfs(S,T)) res+=dfs(S,T,1e9);return res;}
void clear()
{
	for(int i=1;i<cntE;i+=2) e[i].w=0;
	for(int i=hd[S];~i;i=e[i].nxt) e[i].w=w[e[i].v];
	for(int i=hd[T];~i;i=e[i].nxt) e[i^1].w=w[e[i].v];
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&c,&h);cntE=0;set(hd,-1);S=n*2+m*2+3;T=S+1;
	for(int i=1,u,v;i<=c;++i) scanf("%d %d",&u,&v),addE(u,n+v,1,i);
	for(int i=1;i<=n;++i) if(dg[i]%h) ++ans;
	for(int i=1;i<=m;++i) if(dg[n+i]%h) ++ans;
	for(int i=1;i<=n;++i) addE(i,n+m+i,(h-dg[i]%h)%h,0);
	for(int i=1;i<=m;++i) addE(n*2+m+i,n+i,(h-dg[n+i]%h)%h,0);
	for(int i=1;i<=n;++i) addE(n*2+m*2+1,n+m+i,(h-dg[n+m+i])%h,0);
	for(int i=1;i<=m;++i) addE(n*2+m+i,n*2+m*2+2,(h-dg[n*2+m+i])%h,0);
	addE(n*2+m*2+1,n*2+m*2+2,(h-dg[n*2+m*2+1]%h)%h,0);
	for(int i=1;i<=n*2+m*2+2;++i) w[i]=dg[i]/h;
	for(int i=1;i<=n;++i) addE(S,i,1,0),addE(n+m+i,T,1,0);
	for(int i=1;i<=m;++i) addE(n+i,T,1,0),addE(S,n*2+m+i,1,0);
	addE(S,n*2+m*2+1,1,0);addE(n*2+m*2+2,T,1,0);
	for(int i=1;i<=h;++i)
	{
		clear();Dinic(S,T);
		for(int j=1;j<cntE;j+=2) if(e[j].w) ans1[e[j].id]=i;
	}printf("%d\n",ans);for(int i=1;i<=c;++i) printf("%d ",ans1[i]);return 0;
}