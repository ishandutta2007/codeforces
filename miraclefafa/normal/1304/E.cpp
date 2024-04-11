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
int p[N][20];
int dep[N];
int u,v,q,kk,g[10][10],n;
VI e[N];

void dfs(int u,int f) {
	dep[u]=dep[f]+1;
	p[u][0]=f;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
	}
}

#define LOGN 18
int lca(int u,int v) {
	if (dep[u]>dep[v]) swap(u,v);
	per(i,0,LOGN) if (dep[p[v][i]]>=dep[u]) v=p[v][i];
	if (u==v) return u;
	per(i,0,LOGN) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}

int dis(int u,int v) {
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	rep(j,1,LOGN) rep(i,1,n+1) p[i][j]=p[p[i][j-1]][j-1];
	scanf("%d",&q);
	rep(qq,0,q) {
		static int p[10];
		scanf("%d%d%d%d%d",p+0,p+1,p+2,p+3,&kk);
		rep(i,0,4) rep(j,i+1,4) {
			g[i][j]=g[j][i]=dis(p[i],p[j]);
			//printf("dd %d %d %d\n",i,j,g[i][j]);
		}
		//rep(k,0,4) rep(i,0,4) rep(j,0,4) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		if (dep[p[0]]%2!=dep[p[1]]%2) {
			int mid=min({g[2][0]+1+g[1][3],g[2][1]+1+g[0][3],g[2][3]});
			puts((kk>=mid&&kk%2==g[2][3]%2)?"YES":"NO");
		} else {
			int d1=min(g[2][0]+1+g[1][3],g[2][1]+1+g[0][3]);
			//printf("%d %d\n",d1,g[2][3]);
			if (kk>=d1&&kk%2==d1%2) puts("YES");
			else if (kk>=g[2][3]&&kk%2==g[2][3]%2) puts("YES");
			else puts("NO");
		}
	}
}