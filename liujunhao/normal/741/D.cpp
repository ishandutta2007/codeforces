#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAXN 500000
int size[MAXN+10],lgst[1<<22],n,s[MAXN+10],st[MAXN+10],dcnt,ed[MAXN+10],rdfn[MAXN+10],dep[MAXN+10],ans[MAXN+10],m;
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
struct node{
	int v;
	char wt;
	node *next;
}*adj[MAXN+10],edge[MAXN+10],*ecnt=edge;
inline void addedge(int u,int v,char wt){
	node *p=++ecnt;
	p->v=v;
	p->wt=wt;
	p->next=adj[u];
	adj[u]=p;
}
void read(){
	Read(n);
	int i,u;
	char wt[10];
	memset(lgst,0xff,sizeof lgst);
	for(i=2;i<=n;i++){
		Read(u),scanf("%s",wt);
		addedge(u,i,*wt);
	}
}
void dfs(int u){
	size[u]=1;
	st[u]=++dcnt;
	rdfn[dcnt]=u;
	for(node *p=adj[u];p;p=p->next){
		s[p->v]=s[u]^(1<<(p->wt-'a'));
		dep[p->v]=dep[u]+1;
		dfs(p->v);
		size[u]+=size[p->v];
	}
	ed[u]=dcnt;
}
void dfs2(int u,bool flag){
	int heavy(0),&ans=::ans[u];
	for(node *p=adj[u];p;p=p->next)
		if(size[p->v]>size[heavy])
			heavy=p->v;
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=heavy)
			dfs2(p->v,0);
	if(heavy)
		dfs2(heavy,1);
	int i,j;
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=heavy){
			for(i=st[p->v];i<=ed[p->v];i++){
				if(lgst[s[rdfn[i]]]!=-1)
					ans=max(ans,lgst[s[rdfn[i]]]+dep[rdfn[i]]-2*dep[u]);
				for(j=0;j<22;j++)
					if(lgst[s[rdfn[i]]^(1<<j)]!=-1)
						ans=max(ans,lgst[s[rdfn[i]]^(1<<j)]+dep[rdfn[i]]-2*dep[u]);
			}
			for(i=st[p->v];i<=ed[p->v];i++)
				lgst[s[rdfn[i]]]=max(lgst[s[rdfn[i]]],dep[rdfn[i]]);
		}
	if(lgst[s[u]]!=-1)
		ans=max(ans,lgst[s[u]]-dep[u]);
	for(j=0;j<22;j++)
		if(lgst[s[u]^(1<<j)]!=-1)
			ans=max(ans,lgst[s[u]^(1<<j)]-dep[u]);
	lgst[s[u]]=max(lgst[s[u]],dep[u]);
	if(!flag)
		for(i=st[u];i<=ed[u];i++)
			lgst[s[rdfn[i]]]=-1;
}
void print(){
	int i;
	for(i=n;i;i--)
		for(node *p=adj[i];p;p=p->next)
			ans[i]=max(ans[i],ans[p->v]);
	for(i=1;i<=n;i++)
		printf("%d ",ans[i]);
}
int main()
{
	read();
	dfs(1);
	dfs2(1,1);
	print();
}