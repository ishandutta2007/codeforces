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

const int N=510;
int n,m;
int g[N][N];
array<int,3> e[N*N];
void solve() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) rep(j,1,n+1) g[i][j]=(i==j)?0:n+1;
	rep(i,0,m) {
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[i]={x,y,w};
		g[x][y]=g[y][x]=1;
	}
	rep(k,1,n+1) rep(i,1,n+1) rep(j,1,n+1)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	ll ans=1ll<<60;
	rep(i,0,m) {
		auto [x,y,w]=e[i];
		ans=min(ans,(ll)w*(min(g[1][x]+g[y][n]+1,g[1][y]+g[x][n]+1)));
		for (int j=1;j<=n;j++)
			ans=min(ans,(ll)w*(g[1][j]+g[j][n]+min(g[x][j],g[y][j])+2));
	}
	printf("%lld\n",ans);
}

int _;

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}