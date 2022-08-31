#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int sz[N],w[N],n,u,v,m;
vector<PII> e[N];
double prob[N],ret;
void dfs(int u,int f,int id) {
	sz[u]=1;
	rep(j,0,SZ(e[u])) {
		int v=e[u][j].fi;
		if (v==f) continue;
		dfs(v,u,e[u][j].se);
		sz[u]+=sz[v];
	}
	prob[id]=6.*sz[u]*(n-sz[u])/n/(n-1);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,w+i);
		e[u].pb(mp(v,i));
		e[v].pb(mp(u,i));
	}
	dfs(1,0,0);
	rep(i,1,n) ret+=w[i]*prob[i];
	scanf("%d",&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		v=w[u]-v;
		ret-=v*prob[u];
		printf("%.10f\n",ret);
		w[u]-=v;
	}
}