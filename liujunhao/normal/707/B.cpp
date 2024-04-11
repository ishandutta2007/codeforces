#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 100000
#define MAXM 100000
int n,m,k,a[MAXN+10];
bool vis[MAXN+10];
template<class T>
bool Read(T &x){
	char c;
	bool f=0;
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
			return 1;
		}
	}
	return 0;
}
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
void read(){
	int i,u,v,wt;
	Read(n),Read(m),Read(k);
	for(i=1;i<=m;i++){
		Read(u),Read(v),Read(wt);
		addedge(u,v,wt);
		addedge(v,u,wt);
	}
	for(i=1;i<=k;i++){
		Read(a[i]);
		vis[a[i]]=1;
	}
}
int ans=0x7fffffff;
void solve(){
	int i;
	for(i=1;i<=n;i++)
		if(vis[i]){
			for(node *p=adj[i];p;p=p->next)
				if(!vis[p->v])
					ans=min(ans,p->wt);
		}
}
int main()
{
	read();
	solve();
	if(ans==0x7fffffff)
		puts("-1");
	else
		printf("%d\n",ans);
}