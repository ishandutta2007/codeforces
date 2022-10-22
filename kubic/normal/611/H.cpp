#include <bits/stdc++.h>
using namespace std;
#define N 15
#define N1 105
#define N2 200005
#define M 10005
#define pb push_back
#define set(a,vl) memset(a,vl,sizeof(a))
#define cpy(x,y) memcpy(x,y,sizeof(x))
int n,m,tp,pf[N],lst[N],nw[N],rv[N1],w[N][N],w1[N][N];char a[N];vector<int> vc[N];
struct Node {int u,v;}ans[N2];priority_queue<int,vector<int>,greater<int> > q1;
int cntE,hd[N1];struct Edge {int v,w,nxt;}e[M];
int S,T,dst[N1],cur[N1],q[N1];
int min(int x,int y) {return x<y?x:y;}
void f(int u,int v) {ans[++tp]=(Node) {u,v};}
int f1(int u,int v) {if(u>v) swap(u,v);return (m*2-u+2)*(u-1)/2+v-u+1;}
void f2(int u,int v) {if(u>v) swap(u,v);--w1[u][v];f(vc[u][0],vc[v][0]);}
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
void slv()
{
	int tmp;tp=cntE=0;set(lst,0);set(nw,0);set(hd,-1);cpy(w1,w);
	for(int i=1;i<m-1;++i) lst[pf[i]]=i;for(int i=1;i<=m;++i) if(!lst[i]) q1.push(i);
	for(int i=1;i<m-1;++i)
	{f2(pf[i],q1.top());q1.pop();if(lst[pf[i]]==i) q1.push(pf[i]);}
	if(m>1) tmp=q1.top(),q1.pop(),f2(tmp,q1.top()),q1.pop();
	for(int i=1;i<=m;++i) if(vc[i].size()>1) addE(S,i,vc[i].size()-1);
	for(int i=1;i<=m;++i) for(int j=i;j<=m;++j)
	{if(w1[i][j]<0) return;if(w1[i][j]) addE(m+f1(i,j),T,w1[i][j]);}
	for(int i=1;i<=m;++i) for(int j=1;j<=m;++j) addE(i,m+f1(i,j),1e9);
	if(Dinic(S,T)<n-m) return;
	for(int i=1;i<=m;++i) for(int j=hd[i],v,w;~j;j=e[j].nxt)
	{
		v=e[j].v;if(v==S) continue;w=e[j^1].w;
		for(int k=1;k<=w;++k) f(vc[i][++nw[i]],vc[rv[v-m]-i][0]);
	}for(int i=1;i<n;++i) printf("%d %d\n",ans[i].u,ans[i].v);exit(0);
}
void dfs1(int u) {if(u>m-2) {slv();return;}for(int i=1;i<=m;++i) pf[u]=i,dfs1(u+1);}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%s",a);u=strlen(a);scanf("%s",a);v=strlen(a);
		if(u>v) swap(u,v);++w[u][v];
	}for(int i=1,t=0;i<=n;++i,t=0) {for(int j=i;j;j/=10) ++t;m=t;vc[t].pb(i);}
	for(int i=1;i<=m;++i) for(int j=i;j<=m;++j) rv[f1(i,j)]=i+j;
	S=m*(m+3)/2+1;T=S+1;dfs1(1);puts("-1");return 0;
}