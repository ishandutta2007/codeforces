#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)
void chkmax(int &a,int b) {a = a < b ? b : a;}

const int N = 5e5 + 5;
int n,ans[N << 1],len,ans2[N << 1];
int fir[N],to[N << 1],eds,nxt[N << 1];
void addedge(int u,int v) {
	to[++eds] = v;
	nxt[eds] = fir[u];
	fir[u]  = eds;
}
int dp[N][2],dp2[N];
vector<int> buc[N];
void dfs1(int u,int fa) {
	foredge(i,u,v) if(v != fa) {
		dfs1(v,u);
		if(dp[v][0]+1 > dp[u][0]) dp[u][1] = dp[u][0],dp[u][0] = dp[v][0]+1;
		else if(dp[v][0]+1 > dp[u][1]) dp[u][1] = dp[v][0]+1;
		buc[u].push_back(dp[v][0] + 1);
	}
	chkmax(len,dp[u][0] + dp[u][1]);
}
void dfs2(int u,int fa) {
	foredge(i,u,v) if(v != fa) {
		if(dp[v][0]+1 == dp[u][0]) dp2[v] = max(dp2[u],dp[u][1]) + 1;
		else dp2[v] = max(dp2[u],dp[u][0]) + 1;
		dfs2(v,u);
	}
}
int KMP[N];
void dfs3(int u,int fa) {
	if(fa) buc[u].push_back(dp2[u]);
	chkmax(ans[1],buc[u].size() + 1);
	sort(buc[u].begin(),buc[u].end(),greater<int>());
	fo(j,0,buc[u].size()) chkmax(ans[buc[u][j]*2],j+1);
	int lst = 0;
	fo(j,1,buc[u].size()) if(buc[u][j] != buc[u][j-1]) {
		chkmax(ans[buc[u][j]*2+1],j+1);
		KMP[lst] = j-1;
		lst = j;
	}
	KMP[lst] = buc[u].size()-1;

	foredge(i,u,v) if(v != fa) {
		sort(buc[v].begin(),buc[v].end(),greater<int>());
		for(int l = 0,r = 0;l < buc[v].size() || r < buc[u].size();) {
			if(r == buc[u].size() || (l < buc[v].size() && buc[v][l] >= buc[u][r])) {
				if(l > 0 && r > 1) chkmax(ans2[buc[v][l]*2],l+r);
				++l;
			} else {
				r = KMP[r];
				if(l > 1 && r > 0) chkmax(ans2[buc[u][r]*2],l+r);
				++r;
			}
		}
	}
	foredge(i,u,v) if(v != fa) dfs3(v,u);
}
int main() {
	scanf("%d",&n);
	for(int i = 1,u,v;i < n;++i) {
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs1(1,0); dfs2(1,0);
	ans[len] = 2; ans[n] = 1;
	dfs3(1,0);
	rf(i,n,2) chkmax(ans[i],ans[i+1]);
	rf(i,n,2) if(~i & 1) chkmax(ans2[i],ans2[i+2]);
	fr(i,1,n) printf("%d ",max(ans[i],ans2[i]));
	return 0;
}