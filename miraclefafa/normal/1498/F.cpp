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

const int N=101000,M=44;
int sg1[N][M],sg2[N][M],tmp[M];
int n,k,a[N],m;
VI e[N];
void dfs(int u,int f) {
	sg1[u][0]=a[u];
	for (auto v:e[u]) if (v!=f) {
		dfs(v,u);
		rep(i,0,m) sg1[u][(i+1)%m]^=sg1[v][i];
	}
}

void dfs2(int u,int f) {
	for (auto v:e[u]) {
		if (v==f) continue;
		rep(i,0,m) tmp[i]=sg2[u][i];
		rep(i,0,m) tmp[(i+1)%m]^=sg1[v][i];
		rep(i,0,m) sg2[v][i]=sg1[v][i]^tmp[(i+m-1)%m];
		dfs2(v,u);
	}
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	rep(i,1,n+1) scanf("%d",a+i);
	m=2*k;
	dfs(1,0);
	rep(i,0,m) sg2[1][i]=sg1[1][i];
	dfs2(1,0);
	rep(i,1,n+1) {
		int s=0;
		rep(j,k,m) s^=sg2[i][j];
		puts(s?"1":"0");
	}
}