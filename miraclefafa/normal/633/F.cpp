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
pair<ll,int> dep[N][5],Dia[N][3];
ll dia[N],gdia[N],gdep[N],Dep[5],ret;
int a[N],u,v,n;
VI e[N];
void dfs(int u,int f) {
	dia[u]=0;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		dep[u][3]=mp(dep[v][0].fi+a[v],v);
		sort(dep[u],dep[u]+4);
		reverse(dep[u],dep[u]+4);
		Dia[u][2]=mp(dia[v],v);
		sort(Dia[u],Dia[u]+3);
		reverse(Dia[u],Dia[u]+3);
	}
	dia[u]=max(Dia[u][0].fi,a[u]+dep[u][0].fi+dep[u][1].fi);
}
void dfs2(int u,int f) {
	for (auto v:e[u]) if (v!=f) {
		Dep[0]=gdep[u];
		if (dep[u][0].se==v) Dep[1]=dep[u][1].fi,Dep[2]=dep[u][2].fi;
		else if (dep[u][1].se==v) Dep[1]=dep[u][0].fi,Dep[2]=dep[u][2].fi;
		else Dep[1]=dep[u][0].fi,Dep[2]=dep[u][1].fi;
		sort(Dep,Dep+3);
		gdep[v]=Dep[2]+a[u];
		gdia[v]=max(gdia[u],Dep[2]+Dep[1]+a[u]);
		if (Dia[u][0].se==v) gdia[v]=max(gdia[v],Dia[u][1].fi);
		else gdia[v]=max(gdia[v],Dia[u][0].fi);
		ret=max(ret,dia[v]+gdia[v]);
		dfs2(v,u);
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n) scanf("%d%d",&u,&v),e[u].pb(v),e[v].pb(u);
	dfs(1,0);
	dfs2(1,0);
	printf("%lld\n",ret);
}