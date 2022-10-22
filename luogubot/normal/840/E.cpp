// LUOGU_RID: 90392193
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define pi pair<int,int>
#define fi first
#define se second
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=5e4+10,M=1.5e5+10,L=8,S=1<<L;
vector<pi> Q[N];
int n,q,a[N],dep[N],ans[M];vector<int> g[N];
struct Trie{
	int c[S*8+10][2],mx[S*8+10],idx;
	void init(){memset(c,0,sizeof c),memset(mx,0,sizeof mx),idx=0;}
	void ins(int x){
		int r=0;
		Rof(i,15,L){
			int u=x>>i&1;
			if(!c[r][u])c[r][u]=++idx;
			r=c[r][u];
		}
		mx[r]=max(mx[r],x&((1<<L)-1));
	}
	int qry(int x){
		int r=0,ret=0;
		Rof(i,15,L){
			int u=x>>i&1;
			if(c[r][u^1])r=c[r][u^1],ret+=(1<<i);
			else r=c[r][u];
			assert(r);
		}return ret+mx[r];
	}
}T;
void pre(int u,int f){dep[u]=dep[f]+1;for(int v:g[u])if(v!=f)pre(v,u);}
int stk[N],tp,val[N][S];
void dfs(int u,int f){
	stk[++tp]=u,T.init();Rof(i,tp,max(1,tp-S+1)){
		T.ins(a[stk[i]]^(tp-i));
	}
	For(i,0,n/S)val[u][i]=T.qry(i*S);
	for(auto o:Q[u]){
		int l=o.fi,id=o.se,i=tp,c=0,res=0;
		for(;i-S>=l;i-=S,c++)res=max(res,val[stk[i]][c]);
		for(;i>=l;i--)res=max(res,a[stk[i]]^(tp-i));
		ans[id]=res;
	}
	for(int v:g[u])if(v!=f)dfs(v,u);tp--;
}
bool ED;
signed main(){
	n=read(),q=read();For(i,1,n)a[i]=read();
	For(i,2,n){
		int u=read(),v=read();
		g[u].push_back(v),g[v].push_back(u);
	}pre(1,0);For(i,1,q){
		int u=read(),v=read();
		Q[v].push_back(pi(dep[u],i));
	}dfs(1,0);For(i,1,q)printf("%d\n",ans[i]);
	return 0;
}