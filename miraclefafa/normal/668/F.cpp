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

const int M=310,N=10100;
int sta,id[11],gg[11];
map<VI,int> Hs;
map<VI,PII> hs;
int ff[11],n,k;
ll dp[N][M],tmp[M];
int rv[N];
PII f[N];
VI st[M],son[N];
void dfs(int u) {
	if (u==k) {
//		printf("%d: ",sta);
//		rep(i,0,k) printf("%d ",ff[i]); puts("");
		st[sta]=VI(ff,ff+k);
		Hs[st[sta]]=sta;
		sta++;
		return;
	}
	ff[u]=u;
	dfs(u+1);
	per(i,0,u) if (ff[i]==i) {
		ff[u]=i;
		dfs(u+1);
	}
}
int find(int u) { return ff[u]==u?u:ff[u]=find(ff[u]);}
void norm() {
	rep(i,0,k) ff[i]=find(i),id[i]=i;
	rep(i,0,k) id[ff[i]]=min(id[ff[i]],i);
	rep(i,0,k) gg[i]=id[ff[i]];
	rep(i,0,k) ff[i]=gg[i];	
}
int merge(int s,int t) {
	rep(i,0,k) ff[i]=st[s][i];
	rep(i,0,k) {
		if (st[t][i]!=i&&find(st[t][i])==find(i)) return -1;
		ff[find(st[t][i])]=find(i);
	}
	norm();
	return Hs[VI(ff,ff+k)];
}
int remov(int s,int v) {
	ff[v]=v;
	rep(i,0,k-1) {
		int u=st[s][i],w=i;
		if (u>=v) u++; if (w>=v) w++;
		ff[w]=u;
	}
	norm();
	return Hs[VI(ff,ff+k)];
}
int edge(int u,int v) {
	rep(i,0,k) ff[i]=i;
	ff[v]=u;
	return Hs[VI(ff,ff+k)];
}
int mg[M][M],eg[11][11],rov[M][11],da[M][110];
VI sk[M],ds[M];
void init() {
	rep(i,0,sta) rep(j,0,sta) {
		mg[i][j]=merge(i,j);
//		printf("Mg %d %d %d\n",i,j,mg[i][j]);
		if (mg[i][j]>=0) sk[i].pb(j);
	}
	rep(i,0,sta) rep(j,0,k) {
		rov[i][j]=remov(i,j);
//		printf("rov %d %d %d\n",i,j,rov[i][j]);
	}
	rep(i,0,k) rep(j,i+1,k) eg[i][j]=edge(i,j);
	rep(i,0,sta) rep(S,0,1<<(k-1)) {
		int ps=i;
		rep(j,0,k-1) if (S&(1<<j)) {
			if (ps!=-1) ps=mg[ps][eg[j][k-1]];
		}
		if (ps!=-1) {
			if (st[ps][k-1]==k-1) ps=-1;
		}
		da[i][S]=ps;
		if (ps!=-1) ds[i].pb(S);
	}
}
void gao(int u) {
	dp[u][0]=1;
	for (auto v:son[u]) {
		gao(v);
		rep(i,0,sta) tmp[i]=0;
		rep(j,0,sta) {
			int nj=rov[j][rv[v]];
			for (auto k:sk[nj]) {
				tmp[mg[nj][k]]=(tmp[mg[nj][k]]+dp[v][j]*dp[u][k])%mod;
			}
		}
		rep(i,0,sta) dp[u][i]=tmp[i];
	}
	rep(v,0,k-1) {
		rep(i,0,sta) tmp[i]=0;
		rep(i,0,sta) {
			tmp[i]+=dp[u][i];
			if (mg[i][eg[v][k-1]]>=0) tmp[mg[i][eg[v][k-1]]]+=dp[u][i];
		}
		rep(i,0,sta) dp[u][i]=tmp[i]%mod;
	}
	rep(i,0,sta) if (st[i][k-1]==k-1) dp[u][i]=0;
}
int v[20];
int main() {
	scanf("%d%d",&n,&k);
	if (n==k) {
		printf("%lld\n",powmod(n,max(n-2,0)));
		return 0;
	}
	++k;
	dfs(0);
	init();
	rep(i,k,n+1) {
		rep(j,0,k-1) scanf("%d",v+j);
		v[k-1]=i;
		sort(v,v+k);
		int id=i-k+1;
		if (i!=k) {
			f[id]=hs[VI(v,v+k-1)];
			rv[id]=f[id].se;
			son[f[id].fi].pb(id);
		}
		rep(j,0,k) {
			VI r;
			rep(l,0,k) if (l!=j) r.pb(v[l]);
			hs[r]=mp(id,j);
		}
	}
	gao(1);
	rep(u,0,k-1) rep(v,u+1,k-1) {
		rep(i,0,sta) tmp[i]=0;
		rep(i,0,sta) {
			tmp[i]+=dp[1][i];
			if (mg[i][eg[u][v]]>=0) tmp[mg[i][eg[u][v]]]+=dp[1][i];
		}
		rep(i,0,sta) dp[1][i]=tmp[i]%mod;
	}
	printf("%lld\n",dp[1][sta-1]);
}