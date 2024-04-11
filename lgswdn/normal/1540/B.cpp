#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=209, mod=1e9+7;

inline long long read() {
    register long long x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,f[N][N],d[N],fa[N][19],ans;
vector<int>e[N];

int ksm(int x,int y,int ret=1) {
	while(y) {
		if(y%2) ret=ret*x%mod;
		x=x*x%mod, y=y>>1;
	}
	return ret;
}

void dfs(int u) {
	d[u]=d[fa[u][0]]+1;
	rep(h,1,10) fa[u][h]=fa[fa[u][h-1]][h-1];
	for(auto v:e[u]) if(v!=fa[u][0]) fa[v][0]=u, dfs(v);
}
int lca(int x,int y) {
	if(d[x]<d[y]) swap(x,y);
	per(h,10,0) if(d[fa[x][h]]>=d[y]) x=fa[x][h];
	per(h,10,0) if(fa[x][h]!=fa[y][h]) x=fa[x][h], y=fa[y][h];
	return x==y?x:fa[x][0];
}

signed main() {
	n=read();
	rep(i,2,n) {
		int u=read(), v=read();
		e[u].push_back(v), e[v].push_back(u);
	}
	rep(i,1,n) f[0][i]=1, f[i][0]=0;
	rep(i,1,n) rep(j,1,n) f[i][j]=(f[i-1][j]+f[i][j-1])*ksm(2,mod-2)%mod;
	rep(r,1,n) {
		rep(i,1,n) rep(h,0,10) fa[i][h]=0;
		dfs(r);
		int ret=0;
		rep(i,1,n) rep(j,i+1,n) {
			int l=lca(i,j);
			int di=d[i]-d[l], dj=d[j]-d[l];
			ret=(ret+mod+1-f[di][dj])%mod;
		}
		ans=(ans+ret*ksm(n,mod-2))%mod;
	}
	printf("%lld\n",ans);
	return 0;
}