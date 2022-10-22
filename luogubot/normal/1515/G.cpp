#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long 
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int head[N],to[N],nxt[N],val[N],cnt;
void add(int u,int v,int w){
	to[++cnt]=v,val[cnt]=w,nxt[cnt]=head[u],head[u]=cnt;
}int n,m,a[N];
int dfn[N],low[N],idx,in[N],stk[N],tp;
int scnt,num[N],deg[N];
void tarjan(int u){
	dfn[u]=low[u]=++idx;
	in[u]=1,stk[++tp]=u;
	go(u){
		int v=to[i];
		if(!dfn[v])tarjan(v),low[u]=min(low[u],low[v]);
		else if(in[v])low[u]=min(low[u],dfn[v]);
	}if(low[u]==dfn[u]){
		scnt++;int x;
		do x=stk[tp--],in[x]=0,num[x]=scnt;
		while(x!=u);
	}
}int g[N],dep[N],vis[N];
void dfs(int u){
	vis[u]=1;go(u){
		int v=to[i];
		if(num[v]!=num[u])continue;
		if(!vis[v])dep[v]=dep[u]+val[i],dfs(v);
		else g[num[u]]=__gcd(g[num[u]],dep[u]-dep[v]+val[i]);
	}
}
signed main(){
	n=read(),m=read();
	For(i,1,m){int u=read(),v=read(),w=read();add(u,v,w);}
	For(i,1,n)if(!dfn[i])tarjan(i);
	For(i,1,n)if(!vis[i])dfs(i);
	int q=read();while(q--){
		int u=read(),s=read(),t=read();
		puts(s%__gcd(t,g[num[u]])==0?"YES":"NO");
	}
	return 0;
}