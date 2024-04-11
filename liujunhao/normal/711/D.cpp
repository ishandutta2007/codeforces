#include<cstdio>
#include<algorithm>
#define MAXN 200000
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
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
	bool vis;
	node *next,*back;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
	p->vis=0;
	p=p->back=++ecnt;
	p->v=u;
	p->next=adj[v];
	adj[v]=p;
	p->vis=0;
	p->back=ecnt-1;
}
int n;
bool vis[MAXN+10];
#define MOD 1000000007
inline int quick_pow(int a,int b){
	int ret(1);
	while(b){
		if(b&1)
			ret=1ll*ret*a%MOD;
		a=1ll*a*a%MOD;
		b>>=1;
	}
	return ret;
}
int fa[MAXN+10],dep[MAXN+10],cnt,ans=1;
void dfs(int u){
	vis[u]=1;
	for(node *p=adj[u];p;p=p->next){
		if(!p->vis){
			p->vis=p->back->vis=1;
			if(vis[p->v]){
				ans=((1ll*ans*(quick_pow(2,dep[u]-dep[p->v]+1)-2)%MOD)+MOD)%MOD;
				cnt+=dep[u]-dep[p->v]+1;
			}
			else{
				dep[p->v]=dep[u]+1;
				dfs(p->v);
			}
		}
	}
}
int main()
{
	int i,u;
	Read(n);
	for(i=1;i<=n;i++){
		Read(u);
		addedge(i,u);
	}
	for(i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	ans=1ll*ans*quick_pow(2,n-cnt)%MOD;
	printf("%d\n",ans);
}