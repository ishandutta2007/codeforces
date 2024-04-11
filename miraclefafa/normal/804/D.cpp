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
vector<double> cnt[N],cnt2[N];
int n,m,q,u,v,vis[N],s[N],d1[N],d2[N],md,mv,comp,dia[N];
VI e[N],vec[N];
map<PII,double> ret;
void dfs(int u,int f,int dep,int *d) {
	s[u]=comp; d[u]=dep; vec[comp].pb(u); vis[u]=1;
	if (dep>md) md=dep,mv=u;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u,dep+1,d);
	}
}
double query(int u,int v) {
	if (SZ(vec[u])<SZ(vec[v])) swap(u,v);
	double ret=0;
	md=max(dia[u],dia[v]);
	rep(d2,0,dia[v]+1) {
		double t1=cnt[v][d2]-(d2==0?0:cnt[v][d2-1]);
		double t2=0; 
		if (md-1-d2>0) {
			int md2=min(md-1-d2,dia[u]);
			t2=cnt[u][md2];
			ret+=t1*t2*md;
			ret+=t1*(cnt2[u][dia[u]]-cnt2[u][md2]+(cnt[u][dia[u]]-t2)*(d2+1));
		} else {
			ret+=t1*(cnt2[u][dia[u]]+cnt[u][dia[u]]*(d2+1));
		}
	}
/*	double r2=0;
	for (auto p1:vec[u]) for (auto p2:vec[v]) {
		r2+=max(max(dia[u],dia[v]),d1[p1]+d1[p2]+1);
	}
	printf("%.10f %.10f\n",ret,r2);*/
	return ret/SZ(vec[u])/SZ(vec[v]);
}
int main() {
	scanf("%d%d%d",&n,&m,&q);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n+1) if (!vis[i]) {
		comp++;
		md=-1;
		dfs(i,0,0,d1);
		md=-1;
		dfs(mv,0,0,d2);
		vec[comp].clear();
		dfs(mv,0,0,d1);
		dia[comp]=md;
		cnt[comp].resize(dia[comp]+1,0);
		cnt2[comp].resize(dia[comp]+1,0);
		for (auto u:vec[comp]) {
			d1[u]=max(d1[u],d2[u]);
			cnt[comp][d1[u]]+=1;
			cnt2[comp][d1[u]]+=d1[u];
		}
		rep(i,1,dia[comp]+1) cnt[comp][i]+=cnt[comp][i-1],cnt2[comp][i]+=cnt2[comp][i-1];
	}
	rep(i,0,q) {
		scanf("%d%d",&u,&v);
		if (s[u]==s[v]) {
			puts("-1");
			continue;
		}
		if (!ret.count(mp(s[u],s[v]))) ret[mp(s[u],s[v])]=ret[mp(s[v],s[u])]=query(s[u],s[v]);
		printf("%.10f\n",ret[mp(s[u],s[v])]);
	}
}