#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF)
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
int n,a[MAXN+10],b[MAXN+10],col[MAXN*2+10];
struct node{
	int v;
	node *next;
}*adj[MAXN*2+10],edge[MAXN*4+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n);
	int i;
	for(i=1;i<=n;i++){
		Read(a[i]),Read(b[i]);
		addedge(a[i],b[i]);
		addedge(b[i],a[i]);
		addedge(2*i-1,2*i);
		addedge(2*i,2*i-1);
	}
}
void dfs(int u){
	for(node *p=adj[u];p;p=p->next)
		if(!col[p->v]){
			col[p->v]=3-col[u];
			dfs(p->v);
		}
}
void solve(){
	int i;
	for(i=1;i<=2*n;i++)
		if(!col[i]){
			col[i]=1;
			dfs(i);
		}
}
void print(){
	int i;
	for(i=1;i<=n;i++)
		printf("%d %d\n",col[a[i]],col[b[i]]);
}
int main()
{
	read();
	solve();
	print();
}