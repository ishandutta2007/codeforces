#include <bits/stdc++.h>
using namespace std;
#define N 10005
#define M 100005
#define ll long long
#define pb push_back
const int B=1e9;const ll INF=1e18;
int n,m,l,r,ansL,ansR,ans;ll d[N];
struct Node {int u,v;ll x1,y1,x2,y2;}a[M];
int cntE,hd[N];struct Edge {int v,nxt;ll w;}e[M];
int cntV,S,T,cur[N],q[N],dst[N];
void addE(int u,int v,ll w)
{
	e[cntE]=(Edge) {v,hd[u],w};hd[u]=cntE++;
	e[cntE]=(Edge) {u,hd[v],0};hd[v]=cntE++;
}
bool bfs(int S,int T)
{
	for(int i=1;i<=cntV;++i) cur[i]=hd[i],dst[i]=-1;
	q[0]=2;q[1]=1;q[++q[1]]=S;dst[S]=0;
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
		ll w=e[i].w,t;cur[u]=i;v=e[i].v;
		if(w && dst[v]==dst[u]+1 && (t=dfs(v,T,min(nw,w))))
		{nw-=t;flw+=t;e[i].w-=t;e[i^1].w+=t;if(!nw) break;}
	}return flw;
}
ll Dinic(int S,int T)
{ll res=0;while(bfs(S,T)) res+=dfs(S,T,INF);return res;}
ll slv(ll w)
{
	ll res=0;cntE=0;for(int i=1;i<=cntV;++i) hd[i]=-1,d[i]=0;
	for(int i=1,u,v;i<=m;++i)
	{
		ll t1=w*a[i].x1+a[i].y1,t2=w*a[i].x2+a[i].y2;
		u=a[i].u;v=a[i].v;addE(u,v,t2-t1);d[u]-=t1;d[v]+=t1;
	}
	for(int i=1;i<=n;++i) if(d[i]<0) addE(i,T,-d[i]);
		else addE(S,i,d[i]),res+=d[i];return res-Dinic(S,T);
}
int main()
{
	scanf("%d %d",&n,&m);cntV=n+2;S=n+1;T=S+1;
	for(int i=1,u,v,x1,x2;i<=m;++i)
	{
		ll y1,y2;
		scanf("%d %d %d %lld %d %lld",&u,&v,&x1,&y1,&x2,&y2);
		a[i]=(Node) {u,v,x1,y1*B,x2,y2*B};
	}l=0;r=B;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(slv(mid)<=slv(mid+1)) r=mid;else l=mid+1;
	}ansL=l;l=0;r=B;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(slv(mid)<slv(mid+1)) r=mid;else l=mid+1;
	}ansR=l;ans=slv(ansL)?0:ansR-ansL;
	printf("%.9lf\n",1.0*ans/1e9);return 0;
}