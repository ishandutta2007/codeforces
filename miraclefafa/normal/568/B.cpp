#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=4010;
ll dp[N];
int comb[N][N],n;
int main() {
	dp[0]=1;
	scanf("%d",&n);
	comb[0][0]=1;
	rep(i,1,n+1) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	rep(i,1,n+1) {
		rep(j,2,i+1) dp[i]=(dp[i]+dp[i-j]*comb[i-1][j-1])%mod;
	}
	ll ans=0;
	rep(i,0,n+1) {
		ans=(ans+dp[i]*comb[n][i]%mod*(powmod(2,n-i)-1))%mod;
	}
	printf("%I64d\n",ans);
}