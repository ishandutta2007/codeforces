#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define M 2000005
#define ll long long
const int INF=1e9;
int n1,n2,m,c,S,T,cntV,q[N],dst[N],cur[N],st[N],w[N];ll ans;
int cntE=1,hd[N];struct Edge {int v,w,id,nxt;}e[M];
void addE(int u,int v,int w,int id)
{
	e[++cntE]=(Edge) {v,w,id,hd[u]};hd[u]=cntE;
	e[++cntE]=(Edge) {u,0,id,hd[v]};hd[v]=cntE;
}
bool bfs(int S,int T)
{
	for(int i=1;i<=cntV;++i) dst[i]=-1,cur[i]=hd[i];
	q[0]=2;q[1]=1;dst[q[++q[1]]=S]=0;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=hd[u],v,w;i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;
			if(w && dst[v]==-1)
			{dst[v]=dst[u]+1;q[++q[1]]=v;if(v==T) return 1;}
		}
	}return 0;
}
int dfs(int u,int T,int nw)
{
	if(u==T) return nw;int flw=0;
	for(int i=cur[u],v,w,t;i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;cur[u]=i;
		if(w && dst[v]==dst[u]+1 && (t=dfs(v,T,min(nw,w))))
		{nw-=t;flw+=t;e[i].w-=t;e[i^1].w+=t;if(!nw) break;}
	}return flw;
}
int Dinic(int S,int T)
{int flw=0;while(bfs(S,T)) flw+=dfs(S,T,INF);return flw;}
int main()
{
	scanf("%d %d %d %d",&n1,&n2,&m,&c);S=n1+n2+1;T=S+1;cntV=T;
	for(int i=1,u,v;i<=m;++i) scanf("%d %d",&u,&v),addE(u,n1+v,INF,i);
	for(int i=1;i<=n1;++i) addE(S,i,1,0);
	for(int i=1;i<=n2;++i) addE(n1+i,T,1,0);Dinic(S,T);bfs(S,0);
	for(int i=1;i<=n1;++i) if(dst[i]==-1) st[++st[0]]=i;
	for(int i=1;i<=n2;++i) if(~dst[n1+i]) st[++st[0]]=n1+i;
	for(int i=1;i<=n1;++i) for(int j=hd[i];j;j=e[j].nxt)
		if(e[j].id && e[j^1].w) w[i]=w[e[j].v]=e[j].id;
	for(int i=1;i<=st[0];++i) ans+=w[st[i]];
	for(int i=1,op,t;i<=c;++i)
	{
		scanf("%d",&op);
		if(op==1)
		{
			t=st[st[0]--];ans-=w[t];t=t<=n1?t:n1-t;
			printf("1\n%d\n%lld\n",t,ans);
		}
		if(op==2)
		{
			printf("%d\n",st[0]);
			for(int j=1;j<=st[0];++j) printf("%d ",w[st[j]]);putchar('\n');
		}fflush(stdout);
	}return 0;
}