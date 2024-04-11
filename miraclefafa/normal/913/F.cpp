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

const int N=2010;
int n,a,b;
ll p,dp[N][N],pw0[N],pw1[N],e[N],pr[N];
int main() {
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	p=a*powmod(b,mod-2)%mod;
	dp[0][0]=1;
	pw0[0]=pw1[0]=1;
	rep(i,1,n+1) {
		pw0[i]=pw0[i-1]*p%mod;
		pw1[i]=pw1[i-1]*(mod+1-p)%mod;
	}
	rep(i,0,n) rep(j,0,i+1) {
		dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*pw1[i-j])%mod;
		dp[i+1][j]=(dp[i+1][j]+dp[i][j]*pw0[j])%mod;
	}
	e[1]=0;
	pr[1]=1;
	rep(i,2,n+1) {
		ll prob=0;
		rep(j,1,i) {
			e[i]=(e[i]+dp[i][j]*pr[j]%mod*(j*(j-1)/2+j*(i-j)+e[j]+e[i-j]))%mod;
			prob=(prob+dp[i][j]*pr[j])%mod;
		}
		pr[i]=(1-prob)%mod;
		e[i]=(e[i]+(i*(i-1)/2)*pr[i])%mod*powmod(prob,mod-2)%mod;
		if (e[i]<0) e[i]+=mod;
	}
	printf("%lld\n",e[n]);
}