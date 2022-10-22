#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define db double
int n,G,ans1,a[N],sz[N];db s1,s2,ans2=1e100,dr[N];bool vs[N];
struct Edge {int v,w;};vector<Edge> e[N];
void getG(int u,int f,int all)
{
	int mx=0;sz[u]=1;
	for(int i=0,v;i<e[u].size();++i)
	{
		v=e[u][i].v;
		if(!vs[v] && v!=f)
			getG(v,u,all),sz[u]+=sz[v],mx=max(mx,sz[v]);
	}mx=max(mx,all-sz[u]);if(mx<=all/2) G=u;
}
void dfs(int u,int f,int rt,int dst)
{
	dr[rt]+=pow(dst,0.5)*1.5*a[u];s2+=pow(dst,1.5)*a[u];
	for(int i=0,v,w;i<e[u].size();++i)
	{v=e[u][i].v;w=e[u][i].w;if(v!=f) dfs(v,u,rt,dst+w);}
} 
void slv(int u,int all)
{
	getG(u,0,all);u=G;getG(u,0,all);if(vs[u]) return;vs[u]=1;s1=s2=0;
	for(int i=0,v;i<e[u].size();++i)
		v=e[u][i].v,dr[v]=0,dfs(v,u,v,e[u][i].w),s1+=dr[v];
	if(s2<ans2) ans1=u,ans2=s2;
	for(int i=0,v;i<e[u].size();++i)
	{v=e[u][i].v;if(s1-dr[v]*2<0) {slv(v,sz[v]);break;}}
}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%d %d %d",&u,&v,&w);
		e[u].push_back((Edge) {v,w});e[v].push_back((Edge) {u,w});
	}slv(1,n);printf("%d %.10lf\n",ans1,ans2);return 0; 
}