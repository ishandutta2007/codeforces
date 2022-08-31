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

const int N=66,M=260,T=2000;
int _,n,m;
int g[N][N],id[N][N],ans[M],sol[M];
int a[T][M],b[T],row[M];
PII E[M];

bool gauss(int mo,int n,int m) {
	int p=0;
	rep(i,0,m) {
		int fg=0;
		rep(j,p,n) if (a[j][i]) {
			rep(k,0,m) swap(a[p][k],a[j][k]); swap(b[p],b[j]); fg=1;
			break;
		}
		if (!fg) continue;
		int inv=a[p][i];
		row[p]=i;
		rep(k,0,m) a[p][k]=a[p][k]*inv%mo; b[p]=b[p]*inv%mo;
		rep(j,p+1,n) if (a[j][i]) {
			int r=a[j][i];
			rep(k,0,m) {
				a[j][k]=(a[j][k]+30-r*a[p][k])%mo;
			}
			b[j]=(b[j]+30-r*b[p])%mo;
		}
		++p;
	}
	
	rep(j,0,n) {
		bool emp=1;
		rep(k,0,m) if (a[j][k]) emp=0;
		if (emp&&b[j]) return 0;
	}
	rep(i,0,m) sol[i]=0;
	per(i,0,p) {
		sol[row[i]]=b[i];
		rep(j,0,p) b[j]=(b[j]-a[j][row[i]]*b[i]+30)%mo;
	}
	return 1;
}

void solve() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,n) g[i][j]=-2;
	int t=0;
	rep(i,0,m) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		--a; --b;
		g[a][b]=g[b][a]=c;
		E[i]=mp(a,b);
		ans[i]=c;
		if (c==-1) id[a][b]=id[b][a]=t++;
	}
	int t2=0;
	rep(i,0,n) rep(j,i+1,n) rep(k,j+1,n) {
		if (g[i][j]!=-2&&g[i][k]!=-2&&g[j][k]!=-2) {
			rep(l,0,t) a[t2][l]=0; b[t2]=0;
			vector<PII> p{{i,j}, {i,k},{k,j}};
			for (auto pr:p) {
				if (g[pr.fi][pr.se]==-1) {
					a[t2][id[pr.fi][pr.se]]=1;
				} else {
					b[t2]=(b[t2]+3-g[pr.fi][pr.se])%3;
				}
			}
			++t2;
		}
	}
	if (!gauss(3,t2,t)) { puts("-1"); return; }
	rep(i,0,m) {
		if (ans[i]==-1) ans[i]=sol[id[E[i].fi][E[i].se]];
	}
	rep(i,0,m) printf("%d ",ans[i]==0?3:ans[i]);
	puts("");
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}