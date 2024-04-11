#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define N1 100005
#define M 1000005
#define ll long long
const int INF=1e9;
int n,tp,res,ds[N1],st[N1],id[N1],a[N][N];ll ans;
int cntE,hd[N1];struct Edge {int v,w,nxt;}e[M];
int cntV,S,T,dst[N1],pr[N1],pr1[N1],q[N1];
int f(int x,int y) {return (x-1)*n+y;}
void addE(int u,int v,int w1,int w2)
{
	e[cntE]=(Edge) {v,w1,hd[u]};hd[u]=cntE++;
	e[cntE]=(Edge) {u,w2,hd[v]};hd[v]=cntE++;
}
bool bfs(int S,int T)
{
	for(int i=1;i<=cntV;++i) dst[i]=-1;
	dst[S]=0;q[0]=2;q[1]=1;q[++q[1]]=S;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];
		for(int i=hd[u],v,w;~i;i=e[i].nxt)
		{
			v=e[i].v;w=e[i].w;
			if(w && dst[v]==-1)
				pr[v]=u,pr1[v]=i,dst[v]=dst[u]+1,q[++q[1]]=v;
		}
	}return dst[T]!=-1;
}
int Dinic(int S,int T,int flw)
{
	int res=0,t;
	while(flw && bfs(S,T))
	{
		t=flw;for(int i=T;i!=S;i=pr[i]) t=min(t,e[pr1[i]].w);
		res+=t;flw-=t;
		for(int i=T;i!=S;i=pr[i]) e[pr1[i]].w-=t,e[pr1[i]^1].w+=t;
	}return res;
}
int main()
{
	scanf("%d",&n);S=n*n+1;T=cntV=S+1;
	for(int i=1;i<=cntV;++i) hd[i]=-1;
	for(int i=1,t;i<=n;++i) for(int j=1;j<=n;++j)
	{
		scanf("%d",&a[i][j]);t=f(i,j);
		if(i==1 || i==n || j==1 || j==n)
		{
			ds[++tp]=a[i][j];st[++st[0]]=t;
			id[st[0]]=cntE;addE(S,t,INF,0);
		}
	}sort(ds+1,ds+tp+1);tp=unique(ds+1,ds+tp+1)-ds-1;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(~a[i][j])
	{
		if(i>1 && ~a[i-1][j]) addE(f(i,j),f(i-1,j),1,1);
		if(j>1 && ~a[i][j-1]) addE(f(i,j),f(i,j-1),1,1);
	}
	for(int i=1,t;i<tp;++i)
	{
		for(int j=1;j<=st[0];++j)
		{
			if(a[(st[j]-1)/n+1][(st[j]-1)%n+1]!=ds[i]) continue;
			t=e[id[j]^1].w;e[id[j]].w=e[id[j]^1].w=0;
			res-=t;addE(st[j],T,INF,0);
		}res+=Dinic(S,T,INF);ans+=1ll*res*(ds[i+1]-ds[i]);
	}printf("%lld\n",ans);return 0;
}