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
const int N=3e5+10;
#define max(a,b) (a>b?a:b)
inline void gmax(int &a,int b){(a<b)&&(a=b);}
int n,head[N],to[N<<1],nxt[N<<1],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int deg[N],fa[N];vector<int> g[N];int stk[N],tp;
void pre(int u,int f){fa[u]=f;go(u)if(to[i]!=f)g[u].push_back(to[i]),deg[u]++,pre(to[i],u);stk[++tp]=u;g[u].resize(deg[u]);}
int k,S,F[N],G[N];long long ans;
bool cmp1(int x,int y){return F[x]>F[y];}
void dfs1(){//fdadasdasd
	For(u,1,n)G[u]=1;
	For(i,1,tp){
		int u=stk[i];F[u]=1;
		if(deg[u]>=k){
			nth_element(g[u].begin(),g[u].begin()+k-1,g[u].end(),cmp1);
			F[u]=F[g[u][k-1]]+1,gmax(G[u],F[u]);
		}
		ans+=G[u],gmax(G[fa[u]],G[u]);
	}
}
void dfs2(int u){
	for(int v:g[u])dfs2(v),deg[u]=max(deg[u],deg[v]);
	if(deg[u]>S)ans+=deg[u]-S;
}
signed main(){
	For(i,2,n=read()){int u=read(),v=read();add(u,v),add(v,u);}
//	For(i,2,n=300000){int u=i,v=max(1,i/3);add(u,v),add(v,u);}
	pre(1,0),S=min(n,(int)sqrt(n)+2);for(k=1;k<=S;k++)dfs1();dfs2(1),ans+=1ll*(n-S)*n;
	return cout<<ans<<endl,0;
}