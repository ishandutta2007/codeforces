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

const int N=55;
int n,k;
bool dp[N][N];
ll a[N],s[N],ans;
bool check(ll w) {
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	rep(i,0,n) rep(j,0,k+1) if (dp[i][j]) rep(l,i+1,n+1) 
		if (((s[l]-s[i])&w)==w) dp[l][j+1]=1;
	return dp[n][k];
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%lld",a+i),s[i]=s[i-1]+a[i];
	per(i,0,60) if (check(ans|(1ll<<i))) ans|=(1ll<<i);
	printf("%lld\n",ans);
}