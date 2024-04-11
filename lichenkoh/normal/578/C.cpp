#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
const ll mn=2e5+4;
ld eps=1e-10;
ld a[mn];
ll n;
pair<ld,ld> f(ld x) {
	ld anslo=0;
	ld anshi=0;
	ld lo=0,hi=0;
	ld sum=0;
	for (ll i=0;i<n;i++) {
		sum+=(a[i]-x);
		chkmin(lo,sum);
		chkmax(hi,sum);
		chkmax(anslo,sum-lo);
		chkmax(anshi,hi-sum);
	}
	return MP(anslo,anshi);
}
int main() {
	scanf("%lld",&n);
	for (ll i=0;i<n;i++) {
		ll x; scanf("%lld",&x);
		a[i]=x;
	}
	ld best=std::numeric_limits<ld>::infinity();
	ld imin=-10000*2,imax=10000*2;
	for (ll t=0;t<100;t++) {
		ld imid=(imin+imax)/2;
		pair<ld,ld> get=f(imid);
		ld anslo=get.first,anshi=get.second;
		chkmin(best,max(anslo,anshi));
		if (anslo>anshi) imin=imid;
		else imax=imid;
	}
	printf("%.9f\n",(double)best);
}