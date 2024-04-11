#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

#define int long long
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 3005;
const ll INF = 1e18;
int n,t,m,a[N];
int to[N << 1],eds,nxt[N << 1],fir[N];
void addedge(int u,int v) {
	to[++eds] = v;
	nxt[eds] = fir[u];
	fir[u] = eds;
}
int siz[N];
struct Data {
	int cnt,val;
	bool operator < (const Data &o) const {
		if(cnt ^ o.cnt) return cnt < o.cnt;
		return val < o.val;
	}
};
Data dp[N][N][2],tmp[N][2],emp;
void dfs(int u,int fa) {
	siz[u] = 1;
	if(a[u] > 0) dp[u][1][0] = emp,dp[u][1][1] = (Data){1,a[u]};
	else dp[u][1][0] = (Data){0,a[u]},dp[u][1][1] = emp;
	foredge(id,u,v) if(v != fa) {
		dfs(v,u);
		fr(i,1,siz[u]) fr(j,1,siz[v]) fr(b1,0,1) fr(b2,0,1) {
			tmp[i+j][b1] = max(tmp[i+j][b1],(Data){dp[u][i][b1].cnt + dp[v][j][b2].cnt,dp[u][i][b1].val});
			int dt = (dp[u][i][b1].val + dp[v][j][b2].val > 0);
			tmp[i+j-1][dt] = max(tmp[i+j-1][dt],(Data){dp[u][i][b1].cnt + dp[v][j][b2].cnt - b1 - b2 + dt,
					dp[u][i][b1].val + dp[v][j][b2].val});
		}
		siz[u] += siz[v];
		fr(i,1,siz[u]) {
			dp[u][i][0] = tmp[i][0];
			dp[u][i][1] = tmp[i][1];
			tmp[i][0] = tmp[i][1] = emp;
		}
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	emp = (Data){-INF,-INF};
	while(t--) {
		static int x;
		cin >> n >> m;
		fr(i,1,n) cin >> a[i];
		fr(i,1,n) cin >> x,a[i] = x - a[i];
		eds = 0; fr(i,1,n) fir[i] = 0,tmp[i][0] = tmp[i][1] = emp;
		for(int i = 1,u,v;i < n;++i) {
			cin >> u >> v;
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1,0);
		cout << max(dp[1][m][0].cnt,dp[1][m][1].cnt) << endl;
	}
	return 0;
}