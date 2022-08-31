#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
vector<PII> e[N];
int w[N], w2[N];
int p,n,t;
void dfs(int u,int f,int val) {
	for (auto [v,id]:e[u]) {
		if (v==f) continue;
		++t;
		if (val) w[id]=t+n,w2[v]=t;
		else w[id]=t,w2[v]=t+n;
		dfs(v,u,val?0:n);
	}
}
void solve() {
	scanf("%d",&p);
	n=1<<p;
	rep(i,1,n+1) e[i].clear();
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb({v,i});
		e[v].pb({u,i});
	}
	t=0;
	dfs(1,0,n);
	puts("1");
	w2[1]=n;
	rep(i,1,n+1) printf("%d%c",w2[i]," \n"[i==n]);
	rep(i,1,n) printf("%d%c",w[i]," \n"[i==n-1]);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}