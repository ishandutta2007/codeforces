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

int n,m,k;
int dp[5010][5010];
ll z[5010];

int main() {
	scanf("%d%d%d",&n,&m,&k);
	dp[0][0]=1;
	for (int i=1;i<=k;i++) {
		dp[i][0]=0;
		for (int j=1;j<=i;j++)
			dp[i][j]=((ll)j*dp[i-1][j]+dp[i-1][j-1])%mod;
	}
	ll fac=1;
	for (int i=1;i<=k;i++) {
		fac=fac*i%mod;
		dp[k][i]=dp[k][i]*fac%mod;
	}
	z[0]=1;
	for (int i=1;i<=k;i++) {
		z[i]=z[i-1]*(n+1-i)%mod*powmod(i,mod-2)%mod;
	}
	ll invm=powmod(m,mod-2),ans=0;
	for (int i=1;i<=k;i++) {
		ans=(ans+z[i]*powmod(invm,i)%mod*dp[k][i])%mod;
	}
	printf("%lld\n",ans);
	// fac[n] *fac[k]
}