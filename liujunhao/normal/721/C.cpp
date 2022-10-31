#include<cstdio>
#include<algorithm>
#include<queue>
#define MAXN 5000
#define MAXM 5000
using namespace std;
#include<cstring>
queue<int>q;
int n,m,T,f[MAXN+10][MAXN+10],in[MAXN+10],pre[MAXN+10][MAXN+10];
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
	int v,wt;
	node *next;
}*adj[MAXN+10],edge[MAXM+10],*ecnt=edge;
inline void addedge(int u,int v,int wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n),Read(m),Read(T);
	int i,u,v,wt;
	for(i=1;i<=m;i++){
		Read(u),Read(v),Read(wt);
		addedge(u,v,wt);
		in[v]++;
	}
	memset(f,0x3f,sizeof f);
}
void solve(){
	f[1][1]=0;
	int i,u;
	for(i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(node *p=adj[u];p;p=p->next){
			for(i=1;i<=n;i++){
				if(f[u][i]+p->wt<f[p->v][i+1])
					pre[p->v][i+1]=u,f[p->v][i+1]=f[u][i]+p->wt;
			}
			if(!--in[p->v])
				q.push(p->v);
		}
	}
}
void structure(int u,int i){
	if(u==1){
		printf("%d",u);
		return;
	}
	structure(pre[u][i],i-1);
	printf(" %d",u);
}
void print(){
	int i;
	for(i=n;i;i--)
		if(f[n][i]<=T)
			break;
	printf("%d\n",i);
	structure(n,i);
}
int main()
{
	read();
	solve();
	print();
}