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

const int N=501000;
////// fuck
int n,u,v,par[N],ev[N],sz[N],ret[N];
PII dp[N],pd[N],fp[N],fs[N];
ll ans;
VI e[N];
PII gao(PII a,PII b) {
	if (a.fi>b.fi) return a;
	else if (a.fi<b.fi) return b;
	else return mp(a.fi,a.se+b.se);
}
void dfs(int u,int f) {
	par[u]=1;
	sz[u]=1;
	ev[u]=0;
	dp[u]=mp(0,1);
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		par[u]^=par[v];
		sz[u]+=sz[v];
		ev[u]+=ev[v];
		if (par[v]==0) {
			// even
			ev[u]++;
			dp[u]=gao(dp[u],mp(dp[v].fi-1,dp[v].se));
		} else {
			dp[u]=gao(dp[u],mp(dp[v].fi+1,dp[v].se));
		}
	}
	if (par[u]==1) {
		assert(ev[u]+dp[u].fi<=sz[u]/2);
		if (ev[u]+dp[u].fi!=sz[u]/2) ret[u]=0;
		else ret[u]=dp[u].se;
	}
}
void dfs2(int u,int f) {
	VI s; s.pb(u);
	for (auto v:e[u]) if (v!=f) {
		s.pb(v);
	}
	int m=SZ(s);
	fp[0]=gao(pd[u],mp(0,1));
	rep(i,1,m) {
		int v=s[i];
		if (par[v]==0) fp[i]=gao(fp[i-1],mp(dp[v].fi-1,dp[v].se));
		else fp[i]=gao(fp[i-1],mp(dp[v].fi+1,dp[v].se));
	}
	fs[m]=mp(-(1<<30),0);
	per(i,1,m) {
		int v=s[i];
		if (par[v]==0) fs[i]=gao(fs[i+1],mp(dp[v].fi-1,dp[v].se));
		else fs[i]=gao(fs[i+1],mp(dp[v].fi+1,dp[v].se));
	}
	rep(i,1,m) {
		int v=s[i];
		pd[v]=gao(fp[i-1],fs[i+1]);
//		printf("gg %d %d %d\n",v,pd[v].fi,pd[v].se);
		if (par[v]==1) {
			assert(ev[1]-ev[v]+pd[v].fi<=(n-sz[v])/2);
			if (ev[1]-ev[v]+pd[v].fi==(n-sz[v])/2) {
				ans+=(ll)pd[v].se*ret[v];
			}
		}
		if (par[v]==0) pd[v].fi--; else pd[v].fi++;
	}
	rep(i,1,m) {
		int v=s[i];
		dfs2(v,u);
	}

}
int main() {
	scanf("%d",&n);
	if (n%2==1) {
		puts("0");
		return 0;
	}
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	if (ev[1]==n/2-1) {
		rep(i,2,n+1) if (par[i]==0) ans=ans+(ll)sz[i]*(n-sz[i]);
	}
	dfs2(1,0);
	printf("%lld\n",ans);
}