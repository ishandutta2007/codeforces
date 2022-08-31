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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=1010000;
ll fac[N],fnv[N],inv[N];
int n,m;
int main() {
	fac[0]=fnv[0]=fnv[1]=1;
	rep(i,1,1000001) fac[i]=fac[i-1]*i%mod;
	inv[1]=1;
	rep(i,2,1000001) {
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
		assert(i*inv[i]%mod==1);
		fnv[i]=fnv[i-1]*inv[i]%mod;
	}
	scanf("%d%d",&n,&m);
	ll ans=0;
	rep(i,1,n) {
		// i+1 vertex
		// i seg
		if (i>m) continue;
		ll c1=fac[m-1]*fnv[i-1]%mod*fnv[m-i]%mod;
		c1=c1*powmod(m,n-1-i)%mod;
		c1=c1*fac[n-2]%mod*fnv[n-i-1]%mod;
//		printf("%lld\n",c1);
		if (i<n-1) {
			c1=c1*(i+1)%mod*powmod(n,n-i-2)%mod;
		}
//		printf("%d %lld\n",i,c1);
		ans=(ans+c1)%mod;
	}
	printf("%lld\n",ans);
}