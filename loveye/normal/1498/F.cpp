#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 1e5 + 5,K = 45;
int n,k,a[N];
int fir[N],to[N << 1],nxt[N << 1],cnt;
I addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
int dp[N][K],dp2[N][K];
void dfs(int u,int fa) {
	fo(i,k,2*k) dp[u][i] = a[u];
	foredge(id,u,v) if(v != fa) {
		dfs(v,u);
		fo(i,0,2*k) dp[u][i] ^= dp[v][(i+1) % (2*k)];
	}
}
void dfs2(int u,int fa) {
	if(u != 1) fo(i,0,2*k) {
		int kk = (i+1) % (2*k);
		dp2[u][i] = dp2[fa][kk] ^ dp[fa][kk] ^ dp[u][(kk+1) % (2*k)];
	}
	foredge(id,u,v) if(v != fa) dfs2(v,u);
}
int main() {
	cin >> n >> k;
	for(int i = 1,u,v;i < n;++i)
		cin >> u >> v,addedge(u,v),addedge(v,u);
	fr(i,1,n) cin >> a[i];
	dfs(1,0);
	dfs2(1,0);
	fr(i,1,n) cout << (dp[i][0] ^ dp2[i][0] ? 1 : 0) << ' ';
	return 0;
}