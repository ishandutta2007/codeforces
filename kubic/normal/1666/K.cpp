#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1000005
#define ll long long
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
const ll INF=1e18;
int n,m,c1,c2;bool vs[N];
int cntE,S,T,hd[N],cur[N],q[N],dst[N];
struct Edge {int v,nxt;ll w;}e[M];
void addE(int u,int v,ll w1,ll w2)
{
	e[cntE]=(Edge) {v,hd[u],w1};hd[u]=cntE++;
	e[cntE]=(Edge) {u,hd[v],w2};hd[v]=cntE++;
}
bool bfs(int S,int T)
{
	cpy(cur,hd);set(dst,-1);q[0]=2;q[1]=1;q[++q[1]]=S;dst[S]=0;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=hd[u],v;~i;i=e[i].nxt)
		{
			ll w=e[i].w;v=e[i].v;
			if(w && dst[v]==-1) dst[v]=dst[u]+1,q[++q[1]]=v;
		}
	}return dst[T]!=-1;
}
ll dfs(int u,int T,ll nw)
{
	if(u==T) return nw;ll flw=0;
	for(int i=cur[u],v;~i;i=e[i].nxt)
	{
		ll w=e[i].w,t;v=e[i].v;cur[u]=i;
		if(w && dst[v]==dst[u]+1 && (t=dfs(v,T,min(nw,w))))
		{nw-=t;flw+=t;e[i].w-=t;e[i^1].w+=t;if(!nw) break;}
	}return flw;
}
ll Dinic(int S,int T)
{ll res=0;while(bfs(S,T)) res+=dfs(S,T,INF);return res;}
void dfs1(int u)
{
	if(vs[u]) return;vs[u]=1;
	for(int i=hd[u];~i;i=e[i].nxt) if(e[i].w) dfs1(e[i].v);
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&c1,&c2);set(hd,-1);
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		addE(u,n+v,w,w);addE(v,n+u,w,w);
	}S=n*2+1;T=S+1;addE(S,c1,INF,0);addE(n+c1,T,INF,0);
	addE(S,n+c2,INF,0);addE(c2,T,INF,0);
	printf("%lld\n",Dinic(S,T));dfs1(S);
	for(int i=1;i<=n;++i)
		if(vs[i] && !vs[n+i]) putchar('A');
		else if(!vs[i] && vs[n+i]) putchar('B');
		else putchar('C');return 0;
}