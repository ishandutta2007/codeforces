#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10,LG=17;
int fa[N],n,m,U[N],V[N],ban[N],Fa[N][LG];
vector<int> g[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool merge(int x,int y){
	x=get(x),y=get(y);if(x==y)return 0;
	fa[x]=y;return 1;
}int dep[N],dfn[N],idx,sz[N],bk[N];
void dfs(int u,int f){
	Fa[u][0]=f,dep[u]=dep[f]+1,dfn[u]=++idx,sz[u]=1,bk[idx]=u;
	For(i,1,LG-1)Fa[u][i]=Fa[Fa[u][i-1]][i-1];
	for(int v:g[u])if(v!=f)dfs(v,u),sz[u]+=sz[v];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	Rof(i,LG-1,0)if(dep[Fa[x][i]]>=dep[y])x=Fa[x][i];
	if(x==y)return x;
	Rof(i,LG-1,0)if(Fa[x][i]!=Fa[y][i])x=Fa[x][i],y=Fa[y][i];
	return Fa[x][0];
}int tg[N],ok[N];
int kf(int x,int y){
	Rof(i,LG-1,0)if(dep[Fa[x][i]]>dep[y])x=Fa[x][i];return x;
}
signed main(){
	n=read(),m=read();For(i,1,n)fa[i]=i;
	For(i,1,m){
		int u=read(),v=read();
		if(merge(u,v))g[u].push_back(v),g[v].push_back(u);
		else ban[i]=1;
		U[i]=u,V[i]=v;
	}dfs(1,0);int all=0;For(i,1,m)if(ban[i]){
		int u=U[i],v=V[i],l=lca(u,v);
		all++;
		if(u!=l&&v!=l){
			tg[dfn[u]]++,tg[dfn[u]+sz[u]]--,tg[dfn[v]]++,tg[dfn[v]+sz[v]]--;
		}else{
			if(v==l)swap(u,v);
			tg[dfn[v]]++,tg[dfn[v]+sz[v]]--;
			int vv=kf(v,u);
			tg[1]++,tg[dfn[vv]]--,tg[dfn[vv]+sz[vv]]++;
		}
	}For(i,1,n)tg[i]+=tg[i-1],ok[bk[i]]=tg[i];
	For(i,1,n)putchar(ok[i]==all?'1':'0');
	return 0;
}