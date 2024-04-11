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
const int N=5e5+10,p=998244353;
int head[N],to[N],nxt[N],cnt;
void add(int u,int v){
	to[++cnt]=v,nxt[cnt]=head[u],head[u]=cnt;
}int n,a[N],f[N][2],g[N][2],l[N],r[N],idx;
void dfs(int u,int fa){
	int son=0;g[u][0]=g[u][1]=1;
	l[u]=idx+1;
	go(u){
		int v=to[i];if(v==fa)continue;
		son++,dfs(v,u);
	}if(!son)return f[u][0]=a[u],f[u][1]=0,l[u]=r[u]=++idx,void();
	int mn=1e9,tot=0;
	go(u){
		int v=to[i];if(v==fa)continue;
		f[u][1]+=f[v][0];
		if(mn>f[v][1]-f[v][0])mn=f[v][1]-f[v][0],tot=1;
		else if(mn==f[v][1]-f[v][0])tot++;
	}f[u][0]=f[u][1],f[u][1]+=mn;
	if(mn+a[u]<0)f[u][0]+=mn+a[u];
	r[u]=idx;
}int ok[N];
struct node{
	int u,v,w,id;
	bool operator < (const node &x) const {
		return w<x.w;
	}
}e[N];int fa[N];
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void merge(int x,int y){fa[get(x)]=get(y);}
signed main(){
	For(i,1,n=read())a[i]=read();
	For(i,2,n){
		int u=read(),v=read();
		add(u,v),add(v,u);
	}dfs(1,0),cout<<f[1][0]<<" ";
	For(i,1,n)e[i]=(node){l[i],r[i]+1,a[i],i};sort(e+1,e+1+n);
	For(i,1,idx+1)fa[i]=i;
	for(int i=1,j=1;i<=n;i=j){
		while(j<=n&&e[j].w==e[i].w)j++;
		For(k,i,j-1)if(get(e[k].u)!=get(e[k].v))ok[e[k].id]=1;
		For(k,i,j-1)merge(e[k].u,e[k].v);
	}int res=0;For(i,1,n)if(ok[i])res++;cout<<res<<endl;
	For(i,1,n)if(ok[i])printf("%d ",i);
	return 0;
}