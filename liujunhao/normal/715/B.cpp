#include<cstdio>
#include<algorithm>
#include<queue>
#define INF 0x7fffffffffffffffll
using namespace std;
queue<int>q;
#define MAXN 1000
#define MAXM 10000
bool vis[MAXN+10];
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
int n,m,L,S,T,p,len,cp;
long long dist[MAXN+10];
struct node{
	int v,wt;
	node *next;
}*adj[MAXN+10],edge[MAXM*2+10],*ecnt=edge;
inline void addedge(int u,int v,int wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->next=adj[u];
	adj[u]=p;
}
struct Edge{
	int u,v,wt;
	inline Edge(){
	}
	inline Edge(int u,int v,int wt):u(u),v(v),wt(wt){
	}
}eset[MAXM+10];
void read(){
	Read(n),Read(m),Read(L),Read(S),Read(T);
	int i,u,v,wt;
	for(i=1;i<=m;i++){
		Read(u),Read(v),Read(wt);
		if(wt){
			addedge(u,v,wt);
			addedge(v,u,wt);
		}
		else
			cp++;
		eset[i]=Edge(u,v,wt);
	}
}
void spfa(int S){
	int u,i;
	for(i=0;i<n;i++)
		dist[i]=INF;
	dist[S]=0;
	q.push(S);
	while(!q.empty()){
		u=q.front();
		vis[u]=0;
		q.pop();
		for(node *p=adj[u];p;p=p->next){
			if(dist[p->v]>dist[u]+p->wt){
				dist[p->v]=dist[u]+p->wt;
				if(!vis[p->v])
					q.push(p->v),vis[p->v]=1;
			}
		}
	}
}
long long check(int p){
	int i,cnt=0,wt;
	for(i=0;i<n;i++)
		adj[i]=0;
	ecnt=edge;
	for(i=1;i<=m;i++){
		if(eset[i].wt){
			addedge(eset[i].u,eset[i].v,eset[i].wt);
			addedge(eset[i].v,eset[i].u,eset[i].wt);
		}
		else{
			if(++cnt<=p)
				wt=1;
			else
				wt=L+1;
			addedge(eset[i].u,eset[i].v,wt);
			addedge(eset[i].v,eset[i].u,wt);
		}
	}
	spfa(S);
	return dist[T];
}
int Divide_Conqure(int l,int r){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)<=L)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
long long check2(int len,int p){
	int i,cnt=0,wt;
	for(i=0;i<n;i++)
		adj[i]=0;
	ecnt=edge;
	for(i=1;i<=m;i++){
		if(eset[i].wt){
			addedge(eset[i].u,eset[i].v,eset[i].wt);
			addedge(eset[i].v,eset[i].u,eset[i].wt);
		}
		else{
			if(++cnt<p)
				wt=1;
			else if(cnt>p)
				wt=L+1;
			else
				wt=len;
			addedge(eset[i].u,eset[i].v,wt);
			addedge(eset[i].v,eset[i].u,wt);
		}
	}
	spfa(S);
	return dist[T];
}
int Divide_Conqure2(int l,int r,int p){
	int mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check2(mid,p)<=L)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}
void solve(){
	check(0);
	if(dist[T]<L){
		puts("NO");
		exit(0);
	}
	else if(dist[T]==L)
		return;
	else if(!cp&&dist[T]<L){
		puts("NO");
		exit(0);
	}
	p=Divide_Conqure(1,cp+1);
	if(p>cp){
		puts("NO");
		exit(0);
	}
	len=Divide_Conqure2(1,L,p);
}
void print(){
	int i,cnt=0;
	puts("YES");
	for(i=1;i<=m;i++){
		if(!eset[i].wt){
			if(++cnt==p)
				eset[i].wt=len;
			else if(cnt<p)
				eset[i].wt=1;
			else
				eset[i].wt=L+1;
		}
		printf("%d %d %d\n",eset[i].u,eset[i].v,eset[i].wt);
	}
}
int main()
{
	read();
	solve();
	print();
}