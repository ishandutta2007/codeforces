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
const ll mod2=mod*mod;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
VI e[N];
ll dp[N][2][3],tmp[10][10];
int n;
// 0 
// 1 
// 2 

void upd(ll &a,ll b) {
	a+=b; if (a>=mod2) a-=mod2;
}

void dfs(int u,int f) {
	dp[u][0][0]=1;
	dp[u][0][1]=1;
	dp[u][0][2]=1;
	for (auto v:e[u]) {
		if (v==f) continue;
		dfs(v,u);
		for (int p=0;p<=1;p++) for (int q=0;q<=2;q++) tmp[p][q]=0;
		for (int p=0;p<=1;p++) for (int q=0;q<=2;q++) if (dp[u][p][q])
			for (int r=0;r<=1;r++) for (int s=0;s<=2;s++) for (int cc=0;cc<=1;cc++) {
				if (r==0&&s>=1&&cc==0) continue;
				if (cc==0) {
					upd(tmp[p][q],dp[u][p][q]*dp[v][r][s]);
				} else {
					if (q==2&&s==2) continue;
					if (q==0||s==0) continue;
					upd(tmp[1][q],dp[u][p][q]*dp[v][r][s]);
				}
			}
		for (int p=0;p<=1;p++) for (int q=0;q<=2;q++) dp[u][p][q]=tmp[p][q]%mod;
	}
	//for (int p=0;p<=1;p++) for (int q=0;q<=2;q++) printf("u : %d p : %d q : %d dp : %lld\n",u,p,q,dp[u][p][q]);
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	ll ans=mod-1;
	for (int p=0;p<=1;p++) for (int q=0;q<=2;q++) {
		if (p==0&&q>=1) continue;
		upd(ans,dp[1][p][q]);
	}
	ans%=mod;
	printf("%lld\n",ans);
}