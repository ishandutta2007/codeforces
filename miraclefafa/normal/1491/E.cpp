#include <bits/stdc++.h>
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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,sz[N],par[N];
ll fib[50];
map<ll,int> cnt;
PII E[N];
VI e[N],vec;
void dfs(int u,int f) {
	vec.pb(u);
	sz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		par[v]=u;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs1(int u,int f,vector<PII> &E) {
	for (auto v:e[u]) if (v!=f) {
		E.pb(mp(v,u));
		dfs1(v,u,E);
	}
}

bool solve(vector<PII> E) {
	if (!cnt.count(SZ(E)+1)) return 0;
	if (SZ(E)==0) return 1;
	int d=cnt[SZ(E)+1];
	vec.clear();
	for (auto p:E) {
		e[p.fi].clear();
		e[p.se].clear();
	}
	for (auto p:E) {
		e[p.fi].pb(p.se);
		e[p.se].pb(p.fi);
	}
	dfs(E[0].fi,-1);
	for (auto x:vec) {
		if (sz[x]==fib[d-2]||sz[x]==fib[d-1]) {
			int y=par[x];
			vector<PII> E1,E2;
			dfs1(x,y,E1);
			dfs1(y,x,E2);
			return solve(E1)&&solve(E2);
		}
	}
	return 0;
}


int main() {
	scanf("%d",&n);
	fib[0]=fib[1]=1;
	rep(i,2,31) {
		fib[i]=fib[i-1]+fib[i-2];
		//printf("%d\n",fib[i]);
		cnt[fib[i]]=i;
	}
	cnt[1]=1;
	rep(i,1,n) {
		scanf("%d%d",&E[i].fi,&E[i].se);
	}
	puts(solve(vector<PII>(E+1,E+n))?"YES":"NO");
}