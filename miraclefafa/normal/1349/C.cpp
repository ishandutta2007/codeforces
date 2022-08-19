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

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
const int N=1010;
int n,m,Q,g[N][N];
ll dis[N][N];
char s[N];
queue<PII> q;
int main() {
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,0,n) {
		scanf("%s",s);
		rep(j,0,m) {
			g[i][j]=(s[j]=='1')^((i+j)%2);
			dis[i][j]=2e18;
		}
	}
	rep(i,0,n) rep(j,0,m) {
		bool c=0;
		rep(k,0,4) {
			int px=i+dx[k],py=j+dy[k];
			if (px>=0&&px<n&&py>=0&&py<m) {
				if (g[i][j]!=g[px][py]) c=1;
			}
		}
		if (c) dis[i][j]=0,q.push(mp(i,j));
	}
	while (!q.empty()) {
		PII u=q.front(); q.pop();
		rep(k,0,4) {
			int px=u.fi+dx[k],py=u.se+dy[k];
			if (px>=0&&px<n&&py>=0&&py<m&&dis[px][py]>dis[u.fi][u.se]+1) {
				dis[px][py]=dis[u.fi][u.se]+1;
				q.push(mp(px,py));
			}
		}
	}
	rep(i,0,Q) {
		int u,v;
		ll t;
		scanf("%d%d%lld",&u,&v,&t);
		--u; --v;
		int r;

		if (dis[u][v]>=t) r=g[u][v];
		else r=g[u][v]^((t-dis[u][v])%2);
		r^=(u+v)%2;
		printf("%d\n",r);
	}
}