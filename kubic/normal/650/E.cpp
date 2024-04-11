#include <bits/stdc++.h>
using namespace std;
#define N 500005
#define LIM 1000005 
#define pb push_back
//#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
#define gc getchar
char *P1,*P2,buf[LIM]; 
int n,tp,fa[N],fa1[N];vector<int> e1[N],e2[N];
struct Edge {int u,v;}w[N];struct Node {int u1,v1,u2,v2;}ans[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res; 
}
int findRt(int u) {return u==fa1[u]?u:fa1[u]=findRt(fa1[u]);}
void merge(int u,int v)
{u=findRt(u);v=findRt(v);if(u!=v) {fa1[u]=v;if(!w[v].u) w[v]=w[u];}}
void dfs1(int u,int f)
{
	int t,u1,v1;bool fl=0;for(auto v:e1[u]) if(v!=f) dfs1(v,u);
	for(auto v:e1[u]) if(v==fa[u]) {fl=1;break;}t=findRt(u);
	if(!fl) w[t].u=u,w[t].v=fa[u];if(!f) return;
	if(fa[u]==f || fa[f]==u) {merge(u,f);return;}u1=w[t].u;v1=w[t].v;
	ans[++tp]=(Node) {u,f,u1,v1};w[t].u=w[t].v=0;merge(u1,v1);
}
void dfs2(int u,int f) {fa[u]=f;for(auto v:e2[u]) if(v!=f) dfs2(v,u);}
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) fa1[i]=i;
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e1[u].pb(v),e1[v].pb(u);
	for(int i=1,u,v;i<n;++i) scanf("%d %d",&u,&v),e2[u].pb(v),e2[v].pb(u);
	dfs2(1,0);dfs1(1,0);printf("%d\n",tp);
	for(int i=1;i<=tp;++i)
		printf("%d %d %d %d\n",ans[i].u1,ans[i].v1,ans[i].u2,ans[i].v2);return 0;
}