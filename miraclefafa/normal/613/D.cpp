#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
const int inf=0x20202020;
#define LOGN 18
int l[N],r[N],dep[N],p[N][20],dp[N][3];
map<int,int> vis,cv;
VI vc,e[N];
int u,v,n,tot,k,Q;
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

void dfs(int u,int f) {
	l[u]=++tot; dep[u]=dep[f]+1; p[u][0]=f;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
	r[u]=tot;
}

bool cmp(int u,int v) { return l[u]<l[v]; }
int solve(VI v) {
	if (SZ(v)==1) return 0;
	int m=SZ(v);
	vis.clear();
	sort(all(v),cmp);
	rep(i,0,m) vis[v[i]]=1;
	rep(i,0,m-1) v.pb(lca(v[i],v[i+1]));
	sort(all(v),cmp);
	v.erase(unique(all(v)),v.end());
	cv.clear();
/*	puts("Vec: ");
	rep(i,0,SZ(v)) printf("%d ",v[i]);
	puts("");*/
	per(i,0,SZ(v)) {
		int u=v[i];
		dp[i][0]=dp[i][1]=dp[i][2]=0;
		while (1) {
			auto it=cv.lower_bound(l[u]);
			if (it==cv.end()||it->fi>r[u]) break;
			int w=it->se; // 0 
			int nc=dp[w][1],cc=dp[w][0];
			if (dep[v[w]]!=dep[u]+1) cc=min(cc,dp[w][1]+1);
			// nc<=cc
			dp[i][2]=min(min(dp[i][2]+nc,dp[i][1]+nc),inf);
			dp[i][1]=min(min(dp[i][1]+cc,dp[i][0]+nc),inf);
			dp[i][0]=min(dp[i][0]+cc,inf);
			cv.erase(it);
		}
		cv[l[u]]=i;
		if (vis[u]==0) { // keyige
			dp[i][0]=min(dp[i][0],min(dp[i][1],dp[i][2])+1);
		} else {
			// bukeyi
			dp[i][1]=dp[i][0]; dp[i][0]=inf;
		}
		dp[i][1]=min(dp[i][0],dp[i][1]);
	}
	if (dp[0][1]>10000000) return -1;
	return dp[0][1];
}
int main() {
//	freopen("in","r",stdin);
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
//	puts("fff");
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	scanf("%d",&Q);
//	puts("fuck");
	rep(i,0,Q) {
		scanf("%d",&k);
		vc.clear();
		rep(j,0,k) {
			scanf("%d",&u);
			vc.pb(u);
		}
		printf("%d\n",solve(vc));
	}
}