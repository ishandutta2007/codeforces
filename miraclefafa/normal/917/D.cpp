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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=110;
int n,u,v,gg[N][N];
ll f[N][N],ff[N];
ll det() {
	ll ans=1;
	rep(i,1,n) {
		bool fg=0;
		rep(j,i,n) if (f[j][i]!=0) {
			rep(k,i,n) swap(f[i][k],f[j][k]);
			if (j!=i) ans=-ans;
			fg=1;
			break;
		}
		if (!fg) return 0;
		rep(j,i+1,n) {
			ll tmp=-f[j][i]*powmod(f[i][i],mod-2)%mod;
			rep(k,i,n) f[j][k]=(f[j][k]+tmp*f[i][k])%mod;
		}
		
	}
	rep(i,1,n) ans=ans*f[i][i]%mod;
	if (ans<0) ans+=mod;
	return ans;
}

ll inv[N],g[N],c[N],w[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n) {
		scanf("%d%d",&u,&v);
		--u; --v;
		gg[u][v]=gg[v][u]=1;
	}
	rep(x,0,n+1) {
		rep(i,0,n) f[i][i]=0;
		rep(i,0,n) rep(j,0,n) if (i!=j) {
			f[i][j]=-(gg[i][j]?x:1);
			f[i][i]-=f[i][j];
		}
		ff[x]=det();
	}
	inv[0]=inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=mod-(inv[mod%i]*(mod/i))%mod;
	g[0]=g[1]=1;
	for (int i=2;i<=n;i++) g[i]=g[i-1]*inv[i]%mod;
	for (int i=0;i<=n;i++) w[i]=powmod(i,n);
	for (int i=n;i>=0;i--) {
		for (int j=0;j<=i;j++) {
			if (j&1) {
				c[i]-=g[j]*g[i-j]%mod*ff[i-j]%mod;
				if (c[i]<0) c[i]+=mod;
			} else {
				c[i]+=g[j]*g[i-j]%mod*ff[i-j]%mod;
				if (c[i]>=mod) c[i]-=mod;
			}
		}
		for (int j=1;j<=n;j++) {
			ff[j]-=c[i]*w[j]%mod;
			if (ff[j]<0) ff[j]+=mod;
			w[j]=w[j]*inv[j]%mod;
		}
	}
	rep(i,0,n) printf("%lld ",c[i]); puts("");
}