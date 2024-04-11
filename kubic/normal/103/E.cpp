#include <bits/stdc++.h>
using namespace std;
#define N 605
#define M 1000005
#define pb push_back
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
int n,s,a[N],mch[N];vector<int> vc[N];
int cntE,hd[N];struct Edge {int v,w,nxt;}e[M];
int S,T,dst[N],cur[N],q[N];
void addE(int u,int v,int w)
{e[cntE]=(Edge) {v,w,hd[u]};hd[u]=cntE++;e[cntE]=(Edge) {u,0,hd[v]};hd[v]=cntE++;}
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
int main()
{
	scanf("%d",&n);set(hd,-1);S=n*2+1;T=S+1;
	for(int i=1,m,x;i<=n;++i)
	{
		scanf("%d",&m);
		for(int j=1;j<=m;++j) scanf("%d",&x),vc[i].pb(x),addE(i,n+x,1);
	}for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) addE(S,i,1),addE(n+i,T,1);Dinic(S,T);
	for(int i=1;i<=n;++i) for(int j=hd[i];~j;j=e[j].nxt)
		if(e[j^1].w) mch[e[j].v-n]=i;cntE=0;set(hd,-1);S=n+1;T=S+1;
	for(int i=1;i<=n;++i) if(a[i]<0) addE(S,i,-a[i]),s+=a[i];else addE(i,T,a[i]);
	for(int i=1;i<=n;++i) for(auto j:vc[i]) addE(i,mch[j],1e9);
	printf("%d\n",s+Dinic(S,T));return 0;
}