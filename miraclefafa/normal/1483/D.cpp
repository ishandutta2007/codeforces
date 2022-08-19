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
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=610;
int n,m,q,E[N][N],mark[N][N];
VI e[N];
ll g[N][N],maxd[N][N];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) rep(j,1,n+1) {
		g[i][j]=(1ll<<60);
		if (i==j) g[i][j]=0;
	}
	for (int i=0;i<m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(v);
		e[v].pb(u);
		g[u][v]=g[v][u]=w;
		E[u][v]=E[v][u]=w;
	}
	rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	
	rep(i,1,n+1) rep(j,1,n+1) maxd[i][j]=0;
	scanf("%d",&q);
	rep(i,0,q) {
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		rep(j,1,n+1) maxd[j][v]=max(maxd[j][v],l-g[u][j]);
	}
	rep(i,1,n+1) rep(v,1,n+1) for (auto u:e[i]) if (E[i][u]+g[u][v]<=maxd[i][v])
		mark[i][u]=mark[u][i]=1;
	int cnt=0;
	rep(i,1,n+1) rep(j,1,n+1) if (mark[i][j]) cnt++;
	printf("%d\n",cnt/2);
}