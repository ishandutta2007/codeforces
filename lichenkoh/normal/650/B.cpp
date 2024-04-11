#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll n,a,b,t;
const ll mn=5e5+2;
char s[mn];
ll pre[2*mn];
ll getsum(ll x, ll k) {
	return pre[x+k]-pre[x];
}
ll solve(ll k) {
	if (k==0) return 0;
	ll best=INF;
	for (ll s=n-k+1;s<=n;s++) {
		ll l=n-s,r=s+k-1-n;
		ll lo=min(l,r),hi=max(l,r);
		ll m=lo*2+hi;
		ll numh=getsum(s,k);
		ll cand=k+(k-numh)*b+m*a;
		//printf("s:%lld k:%lld cand:%lld numh:%lld m:%lld l:%lld r:%lld\n",s,k,cand,numh,m,l,r);
		chkmin(best,cand);
	}
	return best;
}
int main() {
	scanf("%lld%lld%lld%lld\n",&n,&a,&b,&t);
	scanf("%s",s);
	pre[0]=0;
	for (ll i=0;i<=2*n;i++) {
		pre[i+1]=pre[i]+((s[i%n]=='h')?1:0);
	}
	//printf("%lld\n",solve(3));
	//return 0;
	ll imin=0,imax=n+1;
	while(imin<imax) {
		//printf("imin:%lld imax:%lld imid:%lld\n",imin,imax,(imin+imax)/2);
		ll imid=(imin+imax)/2;
		ll got=solve(imid);
		if (got<=t) imin=imid+1;
		else imax=imid;
	}
	ll ans=imin-1;
	printf("%lld\n",ans);
}