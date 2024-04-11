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

namespace polysum {
	const int D=101000;
	ll a[D],f[D],g[D],p[D],p1[D],p2[D],b[D],h[D][2],C[D];
	ll calcn(int d,ll *a,ll n) {
		if (n<=d) return a[n];
		p1[0]=p2[0]=1;
		rep(i,0,d+1) {
			ll t=(n-i+mod)%mod;
			p1[i+1]=p1[i]*t%mod;
		}
		rep(i,0,d+1) {
			ll t=(n-d+i+mod)%mod;
			p2[i+1]=p2[i]*t%mod;
		}
		ll ans=0;
		rep(i,0,d+1) {
			ll t=g[i]*g[d-i]%mod*p1[i]%mod*p2[d-i]%mod*a[i]%mod;
			if ((d-i)&1) ans=(ans-t+mod)%mod;
			else ans=(ans+t)%mod;
		}
		return ans;
	}
	void init(int M) {
		f[0]=f[1]=g[0]=g[1]=1;
		rep(i,2,M+5) f[i]=f[i-1]*i%mod;
		g[M+4]=powmod(f[M+4],mod-2);
		per(i,1,M+4) g[i]=g[i+1]*(i+1)%mod;
	}
	ll polysum(ll n,ll *a,ll m) { // a[0].. a[m] \sum_{i=0}^{n-1} a[i]
//		a[m+1]=calcn(m,a,m+1);
		rep(i,1,m+2) a[i]=(a[i-1]+a[i])%mod;
		return calcn(m+1,a,n-1);
	}
}

ll k,ret,a[20];
ll solve(ll x,ll y) {
	ll r=(x*x+y*y)%mod;
	ll z=k%mod,c=(z+2)*(z+1)%mod*z%mod-(r+1)*r%mod*(r-1)%mod-(z-r+1)*r%mod*(r-1)*3%mod;
	if (c<0) c+=mod;
	return c;
}

int main() {
	scanf("%lld",&k);
	polysum::init(100);
	ll y=sqrt(k)+10;
	for (ll x=0;x*x<=k;x++) {
		while (x*x+y*y>k) y--;
//		printf("%lld %lld\n",x,y);
		ll s=0;
		if (y<10) {
			rep(i,0,y+1) s=(s+solve(x,i)*(i==0?1:2))%mod;
		} else {
			s+=solve(x,0);
			rep(i,1,9) a[i-1]=solve(x,i); // 0...7
			s+=2*polysum::polysum(y,a,6);
		}
		s%=mod;
		ret=(ret+s*(x==0?1:2))%mod;
	}
	if (ret<0) ret+=mod;
	printf("%lld\n",ret*powmod(6,mod-2)%mod);
}