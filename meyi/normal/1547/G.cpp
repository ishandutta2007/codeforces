#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=4e5+10;
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
bool cur[maxn];
int vis[maxn];
void dfs1(int p){
	cur[p]=true;
	vis[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to])dfs1(e[i].to);
		else if(vis[e[i].to]!=-1){
			if(cur[e[i].to])vis[e[i].to]=-1;
			else vis[e[i].to]=2;
		}
	cur[p]=false;
}
void dfs2(int p){
	vis[p]=2;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(vis[e[i].to]!=-1&&vis[e[i].to]!=2)
			dfs2(e[i].to);
}
void dfs3(int p){
	vis[p]=-1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(vis[e[i].to]!=-1)
			dfs3(e[i].to);
}
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		len=0;
		for(ri i=1;i<=n;++i)hd[i]=vis[i]=0;
		while(m--){
			ri x,y;
			scanf("%d%d",&x,&y);
			addedge(x,y);
		}
		dfs1(1);
		for(ri i=1;i<=n;++i)
			if(vis[i]==2)
				dfs2(i);
		for(ri i=1;i<=n;++i)
			if(vis[i]==-1)
				dfs3(i);
		for(ri i=1;i<=n;++i)printf("%d ",vis[i]);
		printf("\n");
	}
	return 0;
}