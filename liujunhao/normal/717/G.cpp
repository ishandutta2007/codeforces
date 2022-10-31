#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define MAXN 500
#define MAXM 100
#define INF 0x7f7f7f7f
queue<int>q;
char s[MAXN+10],t[MAXN+10];
int n,T,S,tot,dist[MAXN+10],m,x;
bool vis[MAXN+10];
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
struct node{
	int v,cap,wt;
	node *next,*back;
}*adj[MAXN+10],edge[MAXN*MAXM*2+10],*ecnt=edge,*pre[MAXN+10];
inline void addedge(int u,int v,int cap,int wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->cap=cap;
	p->next=adj[u];
	adj[u]=p;
	p=p->back=++ecnt;
	p->v=u;
	p->wt=-wt;
	p->cap=0;
	p->next=adj[v];
	adj[v]=p;
	p->back=ecnt-1;
}
void read(){
	Read(n);
	scanf("%s",s+1);
	int i,j,len,p;
	bool flag=0;
	Read(m);
	while(m--){
		scanf("%s",t+1);
		Read(p);
		len=strlen(t+1);
		for(i=1;i+len-1<=n;i++){
			flag=0;
			for(j=1;j<=len;j++)
				if(s[i+j-1]!=t[j]){
					flag=1;
					break;
				}
			if(!flag)
				addedge(i,i+len,1,-p);
		}
	}
	Read(x);
	for(i=1;i<n;i++)
		addedge(i,i+1,x,0);
	T=n+1,S=tot=T+1;
	addedge(S,1,x,0);
	addedge(n,T,x,0);
}
bool spfa(){
	int u;
	int i;
	for(i=1;i<=tot;i++)
		dist[i]=INF;
	dist[S]=0;
	q.push(S);
	while(!q.empty()){
		u=q.front();
		q.pop();
		vis[u]=0;
		for(node *p=adj[u];p;p=p->next){
			if(p->cap&&dist[p->v]>dist[u]+p->wt){
				pre[p->v]=p;
				dist[p->v]=dist[u]+p->wt;
				if(!vis[p->v])
					vis[p->v]=1,q.push(p->v);
			}
		}
	}
	return dist[T]!=INF;
}
int mcmf(){
	int cost=0,delta;
	node *p;
	while(spfa()){
		delta=INF;
		for(p=pre[T];p;p=pre[p->back->v])
			delta=min(delta,p->cap);
		for(p=pre[T];p;p=pre[p->back->v]){
			p->cap-=delta;
			p->back->cap+=delta;
		}
		cost+=dist[T]*delta;
	}
	return cost;
}
int main()
{
	read();
	printf("%d\n",-mcmf());
}