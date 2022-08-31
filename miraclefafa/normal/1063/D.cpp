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

ll n,l,r,k;
void add(ll a,ll b,ll &l,ll &r) {
	if (a==0) {
		if (b<0) { l=1, r=0; return; }
	} else if (a>0) {
		if (b<0) { l=1, r=0; return; }
		else r=min(r,b/a);
	} else {
		a*=-1;
		b*=-1;
		// a x >= b;
		l=max(l,(b+a-1)/a);
	}
}
int main() {
	scanf("%lld%lld%lld%lld",&n,&l,&r,&k);
	ll cnt=r-l+1;
	if (cnt<=0) cnt+=n;
	ll ans=-1;
	for (ll d1=1;d1<=2;d1++) {
		for (ll d2=0;d1+d2<=2;d2++) {
			for (ll l=1;;l++) {
				ll s=k/l;
				ll cl=max(n,l),cr=2*n;
				// cnt-1<=k-s*c-d1<=2*(cnt-1)
				add(-s,2*(cnt-1)+d1-k,cl,cr); // a x <= b
				add(s,k-d1-(cnt-1),cl,cr);
//					printf("%lld %lld %lld %lld %lld\n",d1,d2,cl,cr,l);
				// n-cnt <= c- (k-s*c) -d2 <= 2*(n-cnt)
				// n-cnt <= (s+1)*c - k-d2
				add(s+1,2*(n-cnt)+k+d2,cl,cr);
				add(-s-1,-k-d2-n+cnt,cl,cr);
				if (s>0) {
					ll r=k/s;
					cr=min(cr,r);
					l=r;
				}
//				printf("%lld %lld %lld %lld %lld\n",d1,d2,cl,cr,l);
				if (cl<=cr) ans=max(ans,cr-n);
				if (s==0) break;
			}
		}
	}
	if (cnt==n) {
		for (ll i=1;i*i<=k;i++) if (k%i==0) {
			if (n<=i&&i<=2*n) ans=max(ans,i-n);
			if (n<=k/i&&k/i<=2*n) ans=max(ans,k/i-n);
		}
	}
/*
	if (n<=10000000) {
		ll ans=-1;
		for (ll c=n;c<=2*n;c++) {
			for (int d=1;d<=2;d++) {
				ll p1=k%c-d;
				ll p2=c-k%c;
				if (p1>=cnt-1&&p1<=2*(cnt-1)&&p2>=n-cnt&&p2<=2*(n-cnt)) {
					ans=max(ans,c-n);
				}
			}
		}
		printf("%lld\n",ans);
	} else {

	}*/
	printf("%lld\n",ans);
}