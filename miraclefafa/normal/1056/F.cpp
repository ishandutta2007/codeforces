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

typedef double db;

const int N=110;
int n,a,p,_;
db c,t;
PII prob[N];
db dp[N][1010],pd[N][1010],pw[N];
void solve() {
	scanf("%d",&n);
	scanf("%lf%lf",&c,&t);
	int sp=0;
	rep(i,0,n) {
		scanf("%d%d",&a,&p);
		prob[i]=mp(a,p);
	}
	sort(prob,prob+n);
	reverse(prob,prob+n);
	sp=0;
	dp[0][0]=0;
	rep(i,0,n) {
		rep(j,0,i+1) rep(k,0,sp+1) pd[j][k]=dp[j][k];
		rep(j,0,i+2) rep(k,0,sp+prob[i].se+1) {
			dp[j][k]=1e30;
		}
		rep(j,0,i+1) rep(k,0,sp+1) {
			dp[j][k]=min(dp[j][k],pd[j][k]);
			dp[j+1][k+prob[i].se]=min(dp[j+1][k+prob[i].se],pd[j][k]+prob[i].fi*pw[j+1]);
		}
		sp+=prob[i].se;
	}
	int sco=0;
	for (int j=0;j<=n;j++) for (int k=0;k<=sp;k++) if (dp[j][k]<1e20) {
		// dp[j][k]/(1+c*x)+x+1/c<=t-j*10+1/c
		db x=sqrt(dp[j][k]/c)-1/c;
		x=max(x,0.0);
		if (dp[j][k]/(1+c*x)+x+10*j<=t) {
			sco=max(sco,k);
		}
	}
	printf("%d\n",sco);
}

int main() {
	pw[0]=1;
	rep(i,1,101) pw[i]=pw[i-1]/0.9;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}