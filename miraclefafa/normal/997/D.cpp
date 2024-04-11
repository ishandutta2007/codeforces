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
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int M=40,N=4010;

ll fac[N],fnv[N],inv[N];
struct Tree {
	int n;
	VI e[N];
	ll soncyc[N][M+10],dp[N][M+10];
	ll tmp[M+10][M+10];
	ll ans[M+10];

	int g[N][N],gg[N][N];
	void dfs(int u,int f) {
		for (auto v:e[u]) if (v!=f) {
			dfs(v,u);
			rep(j,0,M) {
				soncyc[u][j+1]=(soncyc[u][j+1]+dp[v][j])%mod;
			}
		}
		dp[u][0]=1;
		rep(j,1,M+1) rep(k,0,j) {
			dp[u][j]=(dp[u][j]+dp[u][k]*soncyc[u][j-k])%mod;
		}
		memset(tmp,0,sizeof(tmp));
		tmp[0][0]=1;
		rep(j,1,M+1) rep(p1,j,M+1) rep(p2,j-1,p1) {
			tmp[j][p1]=(tmp[j][p1]+tmp[j-1][p2]*soncyc[u][p1-p2])%mod;
		}
		rep(j,1,M+1) for (int p1=j;p1<=M;p1++) for (int d=2;d<=j;d++) if (j%d==0&&p1%d==0) {
			tmp[j][p1]=(tmp[j][p1]-tmp[j/d][p1/d])%mod;
		}
		rep(j,1,M+1) rep(p1,j,M+1) {
			tmp[j][p1]=tmp[j][p1]*inv[j]%mod;
			if (tmp[j][p1]<0) tmp[j][p1]+=mod;
			ans[p1]=(ans[p1]+tmp[j][p1]*2*p1)%mod;
		}
	}

	void gao() {
		int u,v;
		rep(i,1,n) {
			scanf("%d%d",&u,&v);
//			u=rand()%i+1;
//			v=i+1;
			e[u].pb(v);
			e[v].pb(u);
		}
/*		rep(i,1,n+1) g[i][i]=1;
		rep(k,1,M*2+1) {
			rep(i,1,n+1) rep(j,1,n+1) gg[i][j]=g[i][j],g[i][j]=0;
			rep(u,1,n+1) rep(v,1,n+1) for (auto w:e[v]) {
				g[u][w]=(g[u][w]+gg[u][v])%mod;
			}
			if (k%2==0) {
				int tmp=0;
				rep(i,1,n+1) tmp=(tmp+g[i][i])%mod;
				printf("%d ",tmp);
			}
		}
		puts("");*/
		dfs(1,0);
		ans[0]=n;
		per(i,1,M+1) rep(j,1,i) if (i%j==0) ans[i]=(ans[i]+ans[j])%mod;
//		rep(i,1,M+1) printf("%lld ",ans[i]); puts("");
	}
}t1,t2;
int k;
ll comb(int x,int y) {
	if (y<0||y>x) return 0;
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
	fac[0]=fnv[0]=1;
	rep(i,1,101) {
		fac[i]=fac[i-1]*i%mod;
		fnv[i]=powmod(fac[i],mod-2);
		inv[i]=powmod(i,mod-2);
	}
	scanf("%d%d%d",&t1.n,&t2.n,&k);
	t1.gao();
	t2.gao();
	if (k%2==1) {
		puts("0");
		return 0;
	}
	k/=2;
	ll ans=0;
	rep(s,0,k+1) {
		ans=(ans+t1.ans[s]*t2.ans[k-s]%mod*comb(2*k,2*s))%mod;
	}
	printf("%lld\n",ans);
}