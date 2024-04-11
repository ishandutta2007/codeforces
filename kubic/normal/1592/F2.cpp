#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 1000005
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
int n,m,ans,w,w1,w2,w3,a[N][N];char a1[N];
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
	scanf("%d %d",&n,&m);set(hd,-1);S=n+m+1;T=S+1;
	for(int i=1;i<=n;++i)
	{scanf("%s",a1+1);for(int j=1;j<=m;++j) a[i][j]=a1[j]=='B';}
	for(int i=n;i;--i) for(int j=m;j;--j)
		a[i][j]=a[i][j]^a[i-1][j]^a[i][j-1]^a[i-1][j-1];
	for(int i=2;i<=n;++i) for(int j=2;j<=m;++j)
		if(a[i][j]) ++w,a[1][1]^=1,a[i][1]^=1,a[1][j]^=1;
	for(int i=2;i<=n;++i) if(a[i][1]) ++w1,a[1][1]^=1;
	for(int i=2;i<=m;++i) if(a[1][i]) ++w2,a[1][1]^=1;
	ans=w+w1+w2+a[1][1];
	for(int i=2;i<=n;++i) for(int j=2;j<=m;++j) if(a[i][j]) addE(i,n+j,1);
	for(int i=2;i<=n;++i) if(a[i][1]) addE(S,i,1);
	for(int i=2;i<=m;++i) if(a[1][i]) addE(n+i,T,1);
	w3=Dinic(S,T);if(a[1][1]) ans-=(w3+1)/2*2;else ans-=w3/2*2;
	printf("%d\n",ans);return 0;
}