#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=3009,mod=1e9+7;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,d,f[N][N],g[N][N],inv[N];
vector<int>e[N];

void dfs(int u,int fa) {
	rep(i,1,n+1) f[u][i]=1;
	for(auto v:e[u]) {
		if(v==fa) continue;
		dfs(v,u);
		rep(i,1,n+1) f[u][i]=(f[u][i]*g[v][i])%mod;
	}
	rep(i,1,n+1) g[u][i]=(g[u][i-1]+f[u][i])%mod;
}
int lagrange(int ret=0) {
	inv[0]=inv[1]=1;
	rep(i,2,n+1) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
	rep(i,1,n+1) {
		int res=g[1][i];
		rep(j,1,n+1) if(i!=j) res=res*(d-j)%mod*(i<j?-inv[j-i]:inv[i-j])%mod;
		ret+=res;
		if(ret>=mod) ret-=mod; if(ret<0) ret+=mod;
	}
	return ret;
}

signed main() {
	n=read(), d=read();
	rep(i,2,n) e[read()].push_back(i);
	dfs(1,0);
	printf("%lld\n",d<=n+1?g[1][d]:lagrange());
	return 0;
}