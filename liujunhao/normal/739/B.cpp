#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
void Read(LL &x){
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
#define MAXN 200000
LL n,a[MAXN+10],c[MAXN+10],dep[MAXN+10],r[MAXN+10],rcnt,ans[MAXN+10];
struct node{
	int v,wt;
	node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
inline void addedge(int u,int v,int wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->next=adj[u];
	adj[u]=p;
}
void dfs(int u){
	r[++rcnt]=dep[u];
	for(node *p=adj[u];p;p=p->next){
		dep[p->v]=dep[u]+p->wt;
		dfs(p->v);
	}
}
inline int lowbit(int x){
	return x&-x;
}
inline void update(int x,int d){
	while(x<=rcnt){
		c[x]+=d;
		x+=lowbit(x);
	}
}
int get_sum(int x){
	int ret(0);
	while(x){
		ret+=c[x];
		x^=lowbit(x);
	}
	return ret;
}
void dfs2(int u){
	int t=lower_bound(r+1,r+rcnt+1,dep[u])-r;
	ans[u]-=get_sum(t);
	for(node *p=adj[u];p;p=p->next)
		dfs2(p->v);
	ans[u]+=get_sum(t);
	t=lower_bound(r+1,r+rcnt+1,dep[u]-a[u])-r;
	update(t,1);
}
void read(){
	LL i,u,wt;
	Read(n);
	for(i=1;i<=n;i++)
		Read(a[i]);
	for(i=2;i<=n;i++){
		Read(u),Read(wt);
		addedge(u,i,wt);
	}
}
void solve(){
	dfs(1);
	sort(r+1,r+rcnt+1);
	rcnt=unique(r+1,r+rcnt+1)-r-1;
	dfs2(1);
}
void print(){
	int i;
	for(i=1;i<=n;i++)
		printf("%I64d ",ans[i]);
}
int main()
{
	read();
	solve();
	print();
}