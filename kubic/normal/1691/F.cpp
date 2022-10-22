#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define MOD 1000000007
#define pb push_back
int n,m,ans,w1,w2,inv[N],C[N],fa[N],sz[N];vector<int> e[N];
int add(int x,int y) {x+=y;return x<MOD?x:x-MOD;}
void W(int &x,int y) {x+=y;if(x>=MOD) x-=MOD;}
void dfs(int u,int f)
{
	sz[u]=1;for(auto v:e[u]) if(v!=f) dfs(v,u),sz[u]+=sz[v];w1=w2=0;
	for(auto v:e[u]) if(v!=f) W(w1,1ll*(n-sz[v])*sz[v]%MOD),W(w2,MOD-sz[v]);
	for(auto v:e[u]) if(v!=f)
	{
		W(ans,1ll*C[sz[v]]*(n-sz[v])%MOD);
		W(ans,1ll*C[sz[v]]*(sz[u]-sz[v])%MOD*(n-sz[u])%MOD);
		W(ans,1ll*C[sz[v]]*(w1+1ll*w2*sz[v]%MOD)%MOD);
		W(ans,MOD-1ll*C[sz[v]]*(n-sz[v]*2+MOD)%MOD*sz[v]%MOD);
		W(ans,1ll*C[n-sz[v]]*sz[v]%MOD);
		for(auto v1:e[v]) if(v1!=u)
			W(ans,1ll*C[n-sz[v]]*(sz[v]-sz[v1])%MOD*sz[v1]%MOD);
	}
}
int main()
{
	scanf("%d %d",&n,&m);C[m]=1;
	for(int i=1;i<=n;++i) inv[i]=i>1?1ll*inv[MOD%i]*(MOD-MOD/i)%MOD:1;
	for(int i=m+1;i<=n;++i) C[i]=1ll*C[i-1]*i%MOD*inv[i-m]%MOD;
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);dfs(1,0);
	printf("%d\n",add(1ll*C[n]*n%MOD*n%MOD,MOD-ans));return 0;
}