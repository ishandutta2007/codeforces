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
VI s[N];
int mf[N][4],l[N],r[N],tot,Q,u,v,q,dep[N],rt[N];
int n,p[N][20],ty[N];
void dfs(int u) {
	l[u]=++tot;
	for (auto v:s[u]) {
		dep[v]=dep[u]+1;
		rt[v]=rt[u];
		if (ty[u]==ty[v]) {
			mf[v][ty[v]]=mf[u][ty[v]];
		} else {
			mf[v][ty[v]]=u;
		}
		mf[v][3-ty[v]]=v;
		dfs(v);
	}
	r[u]=tot;
}
bool issub(int u,int v) {
	return l[u]<=l[v]&&r[v]<=r[u];
}
#define LOGN 18
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d%d",&p[i][0],ty+i);
		if (ty[i]>=0) ++ty[i];
		if (p[i][0]==-1) p[i][0]=0;
		else s[p[i][0]].pb(i);
	}
	rep(i,1,n+1) if (dep[i]==0) {
		mf[i][1]=mf[i][2]=i; rt[i]=i;
		dep[i]=1; dfs(i);
	}
	scanf("%d",&q);
	rep(i,1,n+1) rep(j,1,LOGN) p[i][j]=p[p[i][j-1]][j-1];
	rep(i,0,q) {
		scanf("%d%d%d",&Q,&u,&v);
		if (rt[v]==v||u==v||rt[u]!=rt[v]) {
			puts("NO");
			continue;
		}
		if (Q==1) {
			puts(issub(u,v)&&issub(mf[v][1],u)?"YES":"NO");
		} else {
			int w=lca(u,v);
			if (v!=w&&issub(mf[u][1],w)&&issub(mf[v][2],w)) puts("YES");
			else puts("NO");
		}
	}
}