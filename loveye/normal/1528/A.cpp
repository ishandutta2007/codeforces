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

const int N = 2e5 + 5;
int n,l[N],r[N];
int to[N << 1],nxt[N << 1],cnt,fir[N];
I addedge(int u,int v) {
	to[++cnt] = v;
	nxt[cnt] = fir[u];
	fir[u] = cnt;
}
LL dp[N][2];
void dfs(int u,int fa) {
	dp[u][0] = dp[u][1] = 0;
	foredge(i,u,v) if(v != fa) {
		dfs(v,u);
		dp[u][0] += max(dp[v][0] + abs(l[u]-l[v]),dp[v][1] + abs(l[u]-r[v]));
		dp[u][1] += max(dp[v][0] + abs(r[u]-l[v]),dp[v][1] + abs(r[u]-r[v]));
	}
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		cin >> n;
		fr(i,1,n) cin >> l[i] >> r[i];
		fr(i,1,n) fir[i] = 0;
		cnt = 0;
		for(int i = 1,u,v;i < n;++i)
			cin >> u >> v,addedge(u,v),addedge(v,u);
		dfs(1,0);
		cout << max(dp[1][0],dp[1][1]) << endl;
	}
	return 0;
}