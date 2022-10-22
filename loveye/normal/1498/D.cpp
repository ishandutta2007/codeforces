#include<bits/stdc++.h>
using namespace std;

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

const int N = 205,M = 1e5 + 5,S = 1e5;
int n,m,dp[M],f[M],y;
int ans[M];
int fir[M],to[M],nxt[M],cnt,vis[M];
I addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
int stk[M],top;
void dfs(int u) {
	vis[u] = 1;
	stk[++top] = u;
	if(top > y+1) f[stk[top-y-1]] -= dp[u];
	f[u] = dp[u];
	foredge(i,u,v) {
		dfs(v);
		f[u] += f[v];
	}
	--top;
}
int main() {
	cin >> n >> m;
	dp[0] = 1;
	fr(i,1,m) ans[i] = -1;
	fr(i,1,n) {
		int t,d; double xx; LL x;
		cin >> t >> x >> y;
		d = (x + S-1) / S;
		cnt = 0;
		if(t == 1) fr(i,0,m-d) addedge(i+d,i);
		else fr(i,1,m) if((1ll * i * x + S-1) / S <= m) addedge((1ll * i * x + S-1) / S,i);
		rf(j,m,0) if(!vis[j]) dfs(j);
		fr(j,0,m) {
			if(!dp[j] && f[j]) dp[j] = 1,ans[j] = i;
			f[j] = vis[j] = fir[j] = 0;
		}
	}
	fr(i,1,m) cout << ans[i] << ' ';
	return 0;
}