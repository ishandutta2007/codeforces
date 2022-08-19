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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
VI e[N];
int n,u,v;
int q[N],f[N],sz[N],ms[N];
ll ans,cc;

void dfs(int u,int f) {
	sz[u]=1;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		sz[u]+=sz[v];
	}
	cc+=sz[u];
}

void dfs2(int u,int f,ll r) {
	ans=max(ans,r);
	for (auto v:e[u]) if (v!=f) {
		dfs2(v,u,r+(n-2*sz[v]));
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0);
	dfs2(1,0,cc);
	printf("%lld\n",ans);
}