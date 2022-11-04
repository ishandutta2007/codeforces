#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9, mod=1e9+7;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,c[N],f[N][2];
void dfs(int u) {
    f[u][c[u]]=1;
	for(int i=hd[u],v;i;i=e[i].nxt) {
		dfs(v=e[i].to);
		f[u][1]=(f[u][1]*(f[v][0]+f[v][1])%mod+f[u][0]*f[v][1]%mod)%mod;
		(f[u][0]*=(f[v][0]+f[v][1]))%=mod;
	}
}

signed main() {
	scanf("%lld",&n);
	for(int i=2,fa;i<=n;i++)
		scanf("%lld",&fa), add(fa+1,i);
	for(int i=1;i<=n;i++) scanf("%lld",&c[i]);
	dfs(1);
	printf("%lld",f[1][1]);
	return 0;
}