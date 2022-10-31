#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAXN 200
template<class T>
void Read(T &x){
	char c;
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
struct node{
	int v;
	bool f;
	node *next,*back;
}*adj[MAXN+10],edge[MAXN*MAXN+10],*ecnt=edge,*pth[MAXN*MAXN+10];
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->f=0;
	p->next=adj[u];
	adj[u]=p;
	p=p->back=++ecnt;
	p->v=u;
	p->f=0;
	p->next=adj[v];
	adj[v]=p;
	p->back=ecnt-1;
}
struct Edge{
	int u,v;
	inline Edge(){
	}
	inline Edge(int u,int v):u(u),v(v){
	}
}eset[MAXN*MAXN+10];
int T,n,m,d[MAXN+10],a[MAXN+10],cnt,pcnt,st,ans;
bool mat[MAXN+10][MAXN+10];
void read(){
	pcnt=cnt=ans=0;
	memset(d,0,sizeof d);
	memset(mat,0,sizeof mat);
	memset(adj,0,sizeof adj);
	memset(pth,0,sizeof pth);
	ecnt=edge;
	Read(n),Read(m);
	int i,u,v;
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		d[u]++,d[v]++;
		addedge(u,v);
		eset[i]=Edge(u,v);
	}
	for(i=1;i<=n;i++)
		if(!(d[i]&1))
			ans++;
		else
			a[++cnt]=i;
	printf("%d\n",ans);
	for(i=1;i<=cnt;i+=2)
		addedge(a[i],a[i+1]);
}
void Get_euler(int u){
	node *p;
	while(adj[u]){
		p=adj[u];
		adj[u]=p->next;
		if(p->f)
			continue;
		p->back->f=1;
		Get_euler(p->v);
		pth[++pcnt]=p;
	}
}
void print(){
	int i,la;
//	printf("%d",st);
	la=st;
	for(i=pcnt;i;i--){
		mat[la][pth[i]->v]=1;
//		printf(" %d",pth[i]->v);
		la=pth[i]->v;
	}
}
void solve(){
	for(st=1;st<=n;st++){
		pcnt=0;
		Get_euler(st);
		print();
	}
	for(int i=1;i<=m;i++)
		if(mat[eset[i].u][eset[i].v])
			printf("%d %d\n",eset[i].u,eset[i].v);
		else
			printf("%d %d\n",eset[i].v,eset[i].u);
}
int main()
{
	Read(T);
	while(T--){
		read();
		solve();
	}
}