#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back
int T,n,a[N];struct Edge {int id,v;};vector<Edge> e[N];
void dfs(int u,int f,bool fl)
{for(auto i:e[u]) if(i.v!=f) a[i.id]=fl?2:3,dfs(i.v,u,!fl);}
void slv()
{
	scanf("%d",&n);for(int i=1;i<=n;++i) e[i].clear();
	for(int i=1,u,v;i<n;++i) 
		scanf("%d %d",&u,&v),e[u].pb((Edge) {i,v}),e[v].pb((Edge) {i,u});
	for(int i=1;i<=n;++i) if(e[i].size()>2) {puts("-1");return;}
	for(int i=1;i<=n;++i) if(e[i].size()<2) {dfs(i,0,0);break;}
	for(int i=1;i<n;++i) printf("%d ",a[i]);puts("");
}
int main() {scanf("%d",&T);while(T--) slv();}