#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#define MAXN 10000
using namespace std;
void Read(int &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int n,ans,son[MAXN+10],m;
bool vis[MAXN+10];
struct node{
	int v;
	node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void dfs(int u,int fa){
	vis[u]=1;
	for(node *p=adj[u];p;p=p->next){
		if(p->v!=fa&&!vis[p->v]){
			dfs(p->v,u);
			ans+=son[p->v];
			son[u]++;
		}
	}
	ans+=son[u]*(son[u]-1)/2;
}
void read(){
	Read(n),Read(m);
	if(m!=n-1){
		puts("no");
		exit(0);
	}
	int i,u,v;
	for(i=1;i<n;i++){
		Read(u),Read(v);
		addedge(u,v);
		addedge(v,u);
	}
}
int main()
{
	read();
	dfs(1,0);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			puts("no");
			return 0;
		}
	puts("yes");
}