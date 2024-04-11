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

const int N=301000;
int n,u,v,vis[N],sg[N],par[N];
VI e[N];
void dfs(int u,int f) {
	par[u]=f;
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		sg[u]^=sg[v]+1;
	}
	//printf("%d %d\n",u,sg[u]);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	putchar('1'+!sg[1]);
	vis[1]=1;
	int ans=sg[1];
	rep(i,2,n+1) {
		int y=i;
		while (!vis[y]) {
			vis[y]=1;
			ans^=sg[y]^(sg[y]+1)^1;
			y=par[y];
		}
		putchar('1'+!ans);
	}
	puts("");
}