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

const int N=101000;
int dep[N],vis[N],par[N];
int n,m,u,v,d,cnt[N];
VI e[N];
void dfs(int u) {
	vis[u]=1;
	for (auto v:e[u]) {
		if (vis[v]&&dep[v]-dep[u]>=d-1) {
			VI cyc;
			int x=v;
			while (x!=u) {
				cyc.pb(x); x=par[x];
			}
			cyc.pb(u);
			assert(SZ(cyc)>=d);
			puts("2");
			printf("%d\n",SZ(cyc));
			for (auto u:cyc) printf("%d ",u); puts("");
			exit(0);
		} else if (!vis[v]) {
			dep[v]=dep[u]+1;
			par[v]=u;
			dfs(v);
		}
	}
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	d=sqrt(n)-1;
	while (d*d<n) d+=1;
	dfs(1);
	rep(i,1,n+1) {
		cnt[dep[i]%(d-1)]++;
	}
	int p=max_element(cnt,cnt+d-1)-cnt;
	VI ind;
	rep(i,1,n+1) if (dep[i]%(d-1)==p) ind.pb(i);
	ind.resize(d);
	puts("1");
	for (auto x:ind) printf("%d ",x);
	puts("");
}