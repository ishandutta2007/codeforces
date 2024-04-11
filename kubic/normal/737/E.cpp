#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 1000005
#define STT 1<<10
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
int n,m,c,tim,tp,ans=1e9,stt,a[N],s[STT],s1[N],s2[N],nw[N],dg[N],b[N][N];
int cntE,hd[N];struct Edge {int v,w,nxt;}e[M];
int S,T,dst[N],cur[N],q[N],st[M];
struct Node {int x,y,tim,w;}ans1[M];
void addE(int u,int v,int w)
{
	if(!w) return;e[cntE]=(Edge) {v,w,hd[u]};hd[u]=cntE++;dg[u]+=w;
	e[cntE]=(Edge) {u,0,hd[v]};hd[v]=cntE++;dg[v]+=w;
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
int slv1(int stt)
{
	int res=0;for(int i=1;i<=n;++i) res=max(res,s1[i]);
	for(int i=1;i<=m;++i) res=max(res,(stt>>i-1&1?(s2[i]+1)/2:s2[i]));return res;
}
void clear()
{
	st[0]=0;for(int i=1;i<cntE;i+=2) e[i].w=0;
	for(int i=hd[S];~i;i=e[i].nxt) e[i].w=1;
	for(int i=hd[T];~i;i=e[i].nxt) e[i^1].w=1;
}
int main()
{
	scanf("%d %d %d",&n,&m,&c);for(int i=1;i<=m;++i) scanf("%d",&a[i]);
	for(int i=1,x,v,w;i<=n;++i)
	{scanf("%d",&x);for(int j=1;j<=x;++j) scanf("%d %d",&v,&w),b[i][v]=w;}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) s1[i]+=b[i][j],s2[j]+=b[i][j];
	for(int i=0,t;i<1<<m;++i)
	{
		bool fl=s[i]<=c;
		for(int j=1;j<=m;++j) if(!(i>>j-1&1))
		{s[i|(1<<j-1)]=s[i]+a[j];if(s[i]+a[j]<=c) fl=0;}
		if(fl) {t=slv1(i);if(t<ans) ans=t,stt=i;}
	}printf("%d\n",ans);for(int i=1;i<=m;++i) putchar((stt>>i-1&1)+'0');
	puts("");cntE=0;set(hd,-1);S=n*2+m*4+1;T=S+1;
	for(int i=1,t1,t2;i<=n;++i) for(int j=1;j<=m;++j) if(stt>>j-1&1)
	{
		t1=nw[j];nw[j]+=b[i][j];t2=nw[j];
		if(t2<=s2[j]/2) addE(i,n+j,b[i][j]);
		else if(t1>=s2[j]/2) addE(i,n+m+j,b[i][j]);
		else addE(i,n+j,s2[j]/2-t1),addE(i,n+m+j,t2-s2[j]/2);
	}else addE(i,n+j,b[i][j]);
	for(int i=1;i<=n;++i) addE(i,n+m*2+i,ans-dg[i]);
	for(int i=1;i<=m*2;++i) addE(n*2+m*2+i,n+i,ans-dg[n+i]);
	for(int i=1;i<=n;++i) for(int j=1;j<=m*2;++j)
		addE(n*2+m*2+j,n+m*2+i,ans-max(dg[n*2+m*2+j],dg[n+m*2+i]));
	for(int i=1;i<=n;++i) addE(S,i,1),addE(n+m*2+i,T,1);
	for(int i=1;i<=m*2;++i) addE(n+i,T,1),addE(S,n*2+m*2+i,1);
	while(1)
	{
		int mn=1e9;clear();Dinic(S,T);
		for(int i=1;i<cntE;i+=2) if(e[i].w && e[i^1].v!=T && e[i].v!=S)
			st[++st[0]]=i,mn=min(mn,e[i^1].w);if(!st[0]) break;
		for(int i=1,u,v;i<=st[0];++i)
		{
			e[st[i]^1].w-=mn;u=e[st[i]].v;v=e[st[i]^1].v;
			if(u<=n && v<=n+m) ans1[++tp]=(Node) {u,v-n,tim,mn+1};
			else if(u<=n && v<=n+m*2) ans1[++tp]=(Node) {u,v-n-m,tim,mn+1};
		}tim+=mn+1;
	}printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d %d %d %d\n",ans1[i].x,ans1[i].y,ans1[i].tim,ans1[i].w);
	return 0;
}