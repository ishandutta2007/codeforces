#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
//#define pb push_back
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

ll dp[1010][1010];
int k;
ll pa,pb,invb;
ll solve(ll rem,ll ca) {
	if (rem<=0) return 0;
	if (ca>=rem) return (ca+pa*invb)%mod;
	if (dp[rem][ca]!=-1) return dp[rem][ca];
	ll &r=dp[rem][ca]; r=0;
	r=(pa*solve(rem,ca+1)+pb*solve(rem-ca,ca)+pb*ca)%mod;
//	printf("%lld %lld %lld\n",rem,ca,r);
	return r;
}
int main() {
	scanf("%d%lld%lld",&k,&pa,&pb);
	pa=pa*powmod(pa+pb,mod-2)%mod;
	pb=(mod+1-pa)%mod;
	invb=powmod(pb,mod-2);
//	printf("%lld %lld\n",pa,pb);
	memset(dp,-1,sizeof(dp));
	printf("%lld\n",solve(k,1));
}