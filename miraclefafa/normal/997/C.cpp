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

const int N=1010000;
ll fac[N],fnv[N],dp[N],ans,ans2;
ll n;
ll comb(int x,int y) {
	if (y<0||y>x) return 0;
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
	fac[0]=fnv[0]=1;
	rep(i,1,1000001) fac[i]=fac[i-1]*i%mod;
	fnv[1000000]=powmod(fac[1000000],mod-2);
	per(i,1,1000001) fnv[i-1]=fnv[i]*i%mod;
	scanf("%lld",&n);
	rep(p1,1,n+1) {
		ans2=(ans2+comb(n,p1)*powmod(mod-1,p1)%mod*(
			powmod(powmod(3,n-p1)-1,n)-powmod(3,(n-p1)*n)))%mod;
	}
	if (ans2<0) ans2+=mod;
	ans2=ans2*3%mod;
	ans=(powmod(3,n*n)-powmod(powmod(3,n)-3,n))%mod;
	ans=ans*2%mod;
	ans=(ans-ans2)%mod;
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
}