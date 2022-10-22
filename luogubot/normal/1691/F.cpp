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
const int N=2e5+10,p=1e9+7;
int fac[N],ifac[N];
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
void init(int n=N-10){
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
}int C(int n,int m){return (n<m||m<0)?0:fac[n]*ifac[m]%p*ifac[n-m]%p;}
int n,k;vector<int> g[N];
int sz[N],ans,res,f[N];
void dfs1(int u,int fa){
	sz[u]=1;for(int v:g[u])if(v!=fa)dfs1(v,u),sz[u]+=sz[v];
	f[u]=C(sz[u],k);for(int v:g[u])if(v!=fa)(f[u]+=p-C(sz[v],k))%=p;
	(res+=f[u]*sz[u])%=p;
}
void dfs2(int u,int fa){
	int now=0;(res+=p-f[u]*sz[u]%p)%=p;
	for(int v:g[u])if(v==fa)(now+=p-C(n-sz[u],k))%=p;else (now+=p-C(sz[v],k))%=p;
	(ans+=res+n*(now+C(n,k)))%=p;for(int v:g[u])if(v!=fa){
		int Now=now,Res=res;
		(now+=C(n-sz[v],k)+C(sz[v],k))%=p,(res+=now*(n-sz[v]))%=p;
		dfs2(v,u),res=Res,now=Now;
	}(res+=f[u]*sz[u])%=p;
}
signed main(){
	init(),n=read(),k=read();For(i,2,n){
		int u=read(),v=read();g[u].push_back(v),g[v].push_back(u);
	}dfs1(1,0),dfs2(1,0);
	cout<<ans<<endl;
	return 0;
}