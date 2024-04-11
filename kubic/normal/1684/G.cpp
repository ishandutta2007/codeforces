#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 1000005
int n,m,cnt,a[N];
int cntE,hd[N];struct Edge {int v,w,nxt;}e[M];
int cntV,S,T,dst[N],cur[N],q[N];
void addE(int u,int v,int w)
{
	e[cntE]=(Edge) {v,w,hd[u]};hd[u]=cntE++;
	e[cntE]=(Edge) {u,0,hd[v]};hd[v]=cntE++;
}
bool bfs(int S,int T)
{
	for(int i=1;i<=cntV;++i) cur[i]=hd[i],dst[i]=-1;
	dst[S]=0;q[0]=2;q[1]=1;q[++q[1]]=S;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=hd[u],v,w;~i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;
			if(w && dst[v]==-1) dst[v]=dst[u]+1,q[++q[1]]=v;
		}
	}return dst[T]!=-1;
}
int dfs(int u,int T,int nw)
{
	if(u==T) return nw;int flw=0;
	for(int i=cur[u],v,w,t;~i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;cur[u]=i;
		if(w && dst[v]==dst[u]+1 && (t=dfs(v,T,min(nw,w))))
		{nw-=t;flw+=t;e[i].w-=t;e[i^1].w+=t;if(!nw) break;}
	}return flw;
}
int Dinic(int S,int T)
{int res=0;while(bfs(S,T)) res+=dfs(S,T,1e9);return res;}
int main()
{
	scanf("%d %d",&n,&m);cntV=n+2;S=n+1;T=n+2;\
	for(int i=1;i<=cntV;++i) hd[i]=-1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i) if(a[i]>m/3)
	{
		++cnt;addE(S,i,1);
		for(int j=1;j<=n;++j)
			if(a[i]*2<=m-a[j] && !(a[i]%a[j])) addE(i,j,1);
	}else addE(i,T,1);
	if(Dinic(S,T)<cnt) {printf("-1\n");return 0;}
	printf("%d\n",n-cnt);
	for(int i=1;i<=n;++i) if(a[i]>m/3)
		for(int j=hd[i],v,w;~j;j=e[j].nxt)
		{
			v=e[j].v;w=e[j].w;
			if(!w) printf("%d %d\n",a[i]*2+a[v],a[i]+a[v]);
		}
	for(int i=hd[T],v,w;~i;i=e[i].nxt)
	{
		v=e[i].v;w=e[i].w;
		if(!w) printf("%d %d\n",a[v]*3,a[v]*2);
	}return 0;
}