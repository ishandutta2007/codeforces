#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
#define per(i,a,b) for(register int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;
typedef pair<int,bool> pii;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int n,sz[N],f[N],g[N],ans;
vector<pii>e[N];

bool lucky(int x) {
	while(x) {
		if(x%10!=4&&x%10!=7) return 0;
		x/=10;
	}
	return 1;
}

void dfs1(int u,int fa) {
	sz[u]=1;
	for(auto to:e[u]) {
		int v=to.first, w=to.second;
		if(v==fa) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		f[u]+=(w?sz[v]:f[v]);
	}
}
void dfs2(int u,int fa) {
	for(auto to:e[u]) {
		int v=to.first, w=to.second;
		if(v==fa) continue;
		g[v]=(w?n-sz[v]:g[u]+f[u]-f[v]);
		dfs2(v,u); 
	}
	ans+=(f[u]+g[u])*(f[u]+g[u])-f[u]-g[u];
}

signed main() {
	n=read();
	rep(i,2,n) {
		int u=read(), v=read(), w=read(); bool l=lucky(w);
		e[u].push_back(make_pair(v,l)),
		e[v].push_back(make_pair(u,l));
	}
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}