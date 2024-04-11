#include<cstdio>
#include<algorithm>
#include<queue>
#define MAXN 10000
#define INF 0x7fffffff
using namespace std;
queue<int>q;
int fa[MAXN+10],dfn[MAXN+10],n,m,tot,dcnt,S,T,cnt=1;
bool vis[MAXN*4+10];
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
namespace MAXFLOW{
int dist[MAXN*3+10],vd[MAXN*3+10];
bool vis[MAXN*3+10];
struct node{
	int v,cap;
	node *next,*back;
}*adj[MAXN*3+10],edge[MAXN*20+10],*ecnt=edge;
inline void addedge(int u,int v,int cap){
	node *p=++ecnt;
	p->v=v;
	p->cap=cap;
	p->next=adj[u];
	adj[u]=p;
	p=p->back=++ecnt;
	p->v=u;
	p->cap=0;
	p->next=adj[v];
	adj[v]=p;
	p->back=ecnt-1;
}
void spfa(int S){
	int i,u;
	for(i=1;i<=tot;i++)
		dist[i]=INF;
	dist[S]=0;
	q.push(S);
	while(!q.empty()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(node *p=adj[u];p;p=p->next){
			if(p->back->cap&&dist[p->v]>dist[u]+1){
				dist[p->v]=dist[u]+1;
				if(!vis[p->v])
					q.push(p->v),vis[p->v]=1;
			}
		}
	}
}
int dfs(int u,int augu){
	if(u==T)
		return augu;
	int mind=tot-1,delta,augv=0;
	for(node *p=adj[u];p;p=p->next){
		if(p->cap){
			if(dist[u]==dist[p->v]+1){
				delta=min(p->cap,augu-augv);
				delta=dfs(p->v,delta);
				p->cap-=delta;
				p->back->cap+=delta;
				augv+=delta;
				if(augv==augu||dist[S]>=tot)
					return augv;
			}
			mind=min(dist[p->v],mind);	
		}
	}
	if(!augv){
		if(!--vd[dist[u]])
			dist[S]=tot;
		vd[dist[u]=mind+1]++;
	}
	return augv;
}
int sap(){
	int flow=0,i;
	spfa(T);
	for(i=1;i<=tot;i++)
		vd[i]=0;
	for(i=1;i<=tot;i++)
		if(dist[i]!=INF)
			vd[dist[i]]++;
	while(dist[S]<tot)
		flow+=dfs(S,INF);
	return flow;
}
}
struct node{
	int v,c;
	node *next;
}*adj[MAXN+10],edge[MAXN*4+10],*ecnt=edge,*pre[MAXN*2+10];
inline void addedge(int u,int v,int c){
	node *p=++ecnt;
	p->v=v;
	p->c=c;
	p->next=adj[u];
	adj[u]=p;
}
void dfs(int u){
	dfn[u]=++dcnt;
	for(node *p=adj[u];p;p=p->next){
		if(p->v!=fa[u]){
			if(!dfn[p->v]){
				pre[p->v]=p;
				fa[p->v]=u;
				dfs(p->v);
				if(!vis[p-edge])
					MAXFLOW::addedge(p->c,m+3,1);
			}
			else if(dfn[p->v]<dfn[u]){
				int x=u,num=0;
				cnt++;
				MAXFLOW::addedge(p->c,cnt+m+2,1);
				while(x!=p->v){
					MAXFLOW::addedge(pre[x]->c,cnt+m+2,1);
					vis[pre[x]-edge]=1;
					x=fa[x];
					num++;
				}
				MAXFLOW::addedge(cnt+m+2,T,num);
			}
		}
	}
}
void read(){
	Read(n),Read(m);
	int i,u,v,c;
	for(i=1;i<=m;i++){
		Read(u),Read(v),Read(c);
		addedge(u,v,c);
		addedge(v,u,c);
	}
	S=m+1,T=S+1;
}
void solve(){
	dfs(1);
	MAXFLOW::addedge(m+3,T,INF);
	tot=cnt+m+2;
	for(int i=1;i<=m;i++)
		MAXFLOW::addedge(S,i,1);
}
int main()
{
	read();
	solve();
	printf("%d\n",MAXFLOW::sap());
}