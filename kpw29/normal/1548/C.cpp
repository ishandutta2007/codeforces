#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf 1000000000
#define inf64 1000000000000000000
#define mod 1000000007
#define X first
#define Y second
#define ll long long
using namespace std;
const int maxn=3030303;
ll n,q,inv[maxn],inv_fac[maxn],fac[maxn],dp[maxn][3];
ll C(ll x,ll y){return(x<y||x<0||y<0)?0:(fac[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;}
int main(){
	fac[0]=inv_fac[0]=fac[1]=inv_fac[1]=inv[1]=1;
	for(int i=2;i<maxn;i++){
		fac[i]=(fac[i-1]*i)%mod;
		inv[i]=((mod-(mod/i))*inv[mod%i])%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	scanf("%lld %lld",&n,&q);
	dp[0][0]=dp[0][1]=dp[0][2]=n;
	for(int i=1;i<=3*n;i++){
		ll sum=C(3*n,i+1),x1=dp[i-1][0],y1=dp[i-1][1];
		dp[i][0]=(((sum+mod*2-x1*2+mod-y1)%mod)*inv[3])%mod;
		dp[i][1]=(dp[i][0]+x1)%mod;
		dp[i][2]=(dp[i][1]+y1)%mod;
	}
	for(int testcase=0;testcase<q;testcase++){
		ll x;
		scanf("%lld",&x);
		printf("%lld\n",(C(3*n,x)+dp[x][0])%mod);
	}
	return 0;
}