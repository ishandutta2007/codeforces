#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define db long double
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e5+10;
int head[N],to[N<<1],val[N<<1],nxt[N<<1],cnt;
void add(int u,int v,int w){
	to[++cnt]=v,val[cnt]=w,nxt[cnt]=head[u],head[u]=cnt;
}int n,m,vis[N],stk[N],tp,vet[N],f[N],g[N];//a[u]=f[u]*x+g[u]
db ans[N];int fl;
void dfs(int u){
	stk[++tp]=f[u]<0?g[u]:-g[u],vet[tp]=u;
	vis[u]=1;go(u){
		int v=to[i],w=val[i];
		int F=-f[u],G=w-g[u];
		if(!vis[v])f[v]=F,g[v]=G,dfs(v);
		else if(f[v]!=F||g[v]!=G){
			if(!fl){
				if(f[u]+f[v])ans[vet[1]]=1.0*(w-g[u]-g[v])/(f[u]+f[v]),fl=1;
				else if(g[u]+g[v]!=w)puts("NO"),exit(0);
			}
			else if(fabs(f[u]*ans[vet[1]]+g[u]+f[v]*ans[vet[1]]+g[v]-w)>1e-9)puts("NO"),exit(0);
		}
	}
}
signed main(){
	n=read(),m=read();For(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w),add(v,u,w);
	}For(u,1,n)if(!vis[u]){
		fl=0;tp=0,f[u]=1,dfs(u);if(!fl){
			sort(stk+1,stk+1+tp);int x=stk[tp/2+1];
			For(i,1,tp)ans[vet[i]]=f[vet[i]]*x+g[vet[i]];
		}else For(i,2,tp)ans[vet[i]]=f[vet[i]]*ans[vet[1]]+g[vet[i]];
	}puts("YES");For(i,1,n)printf("%.10Lf ",ans[i]);puts("");
	return 0;
}