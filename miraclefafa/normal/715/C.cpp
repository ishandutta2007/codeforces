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
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int q[N],f[N],vis[N],sz[N],ms[N];
vector<PII> e[N];
map<int,int> c2;
int n,u,v,d;
ll ret,pw[N],ipw[N],vv,M,r2;
int find(int u) {
	int t=1;q[0]=u;f[u]=-1;
	rep(i,0,t) {
		u=q[i];
		rep(j,0,e[u].size()) {
			int v=e[u][j].fi;
			if (!vis[v]&&v!=f[u]) f[q[t++]=v]=u;
		}
		ms[q[i]]=0;
		sz[q[i]]=1;
	}
	for (int i=t-1;i>=0;i--) {
		ms[q[i]]=max(ms[q[i]],t-sz[q[i]]);
		if (ms[q[i]]*2<=t) return q[i];
		sz[f[q[i]]]+=sz[q[i]];
		ms[f[q[i]]]=max(ms[f[q[i]]],sz[q[i]]);
	}
	return 0;
}
void dfs1(int u,int f,int w,int d) {
	if (w==0) ++r2;
	ret+=c2[(M-w)*ipw[d]%M];
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f||vis[v]) continue;
		dfs1(v,u,(10ll*w+p.se)%M,d+1);
	}
}
void dfs2(int u,int f,int w,int d) {
	if (w==0) ++r2;
	c2[w]++;
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f||vis[v]) continue;
		dfs2(v,u,(w+p.se*pw[d])%M,d+1);
	}
}

ll inv(ll q,ll m) {
	q%=m;if (q<0) q+=m;
	if (q==0) return 0;
	ll a1=m,b1=0,a2=q,b2=1,a3=0,b3=0,t=0;
	while (a2!=1) {	t=a1/a2,a3=a1-t*a2,b3=b1-t*b2%m,
		a1=a2,a2=a3,b1=b2,b2=b3;if (b2<0) b2+=m;}
	return b2;
}

void solve(int u) {
	u=find(u);
	c2.clear();
	for (auto p:e[u]) if (!vis[p.fi]) {
		int v=p.fi;
		dfs1(v,u,p.se%M,1);
		dfs2(v,u,p.se%M,1);
	}
	c2.clear();
	reverse(all(e[u]));
	for (auto p:e[u]) if (!vis[p.fi]) {
		int v=p.fi;
		dfs1(v,u,p.se%M,1);
		dfs2(v,u,p.se%M,1);
	}
	vis[u]=1;
	for (auto p:e[u]) if (!vis[p.fi]) solve(p.fi);
}
int main() {
	scanf("%d%lld",&n,&M);
	vv=inv(10,M);
	pw[0]=1; ipw[0]=1;
	rep(i,1,n+1) {
		pw[i]=pw[i-1]*10%M;
		ipw[i]=ipw[i-1]*vv%M;
	}
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,&d);
		e[u].pb(mp(v,d));
		e[v].pb(mp(u,d));
	}
	solve(0);
	printf("%lld\n",ret+r2/2);
}