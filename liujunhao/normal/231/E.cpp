#include<cstdio>
#include<algorithm>
#define MOD 1000000007
#define MAXN 100000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int Q,fa[MAXN+10][20],dep[MAXN+10],size[MAXN+10],facir[MAXN+10],n,m,Log,pow2[MAXN+10],bl[MAXN+10],sum[MAXN+10];
bool vis[MAXN+10];
struct node{
	int v;
	node *next;
}*adj[MAXN+10],edge[MAXN*4+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
struct Edge{
	int u,v;
	inline Edge(){
	}
	inline Edge(int u,int v):u(u),v(v){
	}
}esets[MAXN*2+10];
void read(){
	Read(n),Read(m);
	int i,u,v;
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		addedge(u,v);
		addedge(v,u);
		esets[i]=Edge(u,v);
	}
}
void dfs(int u){
	bl[u]=u;
	dep[u]=dep[*fa[u]]+1;
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=*fa[u]&&!dep[p->v]){
			*fa[p->v]=u;
			dfs(p->v);
		}
		else if(dep[p->v]>dep[u]){
			int i=p->v;
			sum[u]=1;
			while(i!=u){
				bl[i]=u;
				i=*fa[i];
			}
		}
}
void dfs2(int u){
	dep[u]=dep[*fa[u]]+1;
	sum[u]+=sum[*fa[u]];
	for(int i=1;i<=Log;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=*fa[u]&&!dep[p->v]){
			*fa[p->v]=u;
			dfs2(p->v);
		}
}
inline int LCA(int x,int y){
	if(dep[x]<dep[y])
		swap(x,y);
	int i;
	for(i=Log;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	if(x==y)
		return x;
	for(i=Log;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return *fa[x];
}
void solve(){
	dfs(1);
	int i,x,y,lca;
	*pow2=1;
	for(i=1;i<=n;i++){
		adj[i]=0;
		dep[i]=0;
		pow2[i]=pow2[i-1]*2%MOD;
	}
	for(Log=1;(1<<Log)<n;Log++);
	Log--;
	ecnt=edge;
	for(i=1;i<=m;i++){
		addedge(bl[esets[i].u],bl[esets[i].v]);
		addedge(bl[esets[i].v],bl[esets[i].u]);
	}
	dfs2(1);
	Read(Q);
	while(Q--){
		Read(x),Read(y);
		x=bl[x],y=bl[y];
		lca=LCA(x,y);
		printf("%d\n",pow2[sum[x]+sum[y]-2*sum[lca]+sum[lca]-sum[*fa[lca]]]);
	}
}
int main()
{
	read();
	solve();
}