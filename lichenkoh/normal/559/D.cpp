#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int gcd(int x, int y) {
	x=abs(x); y=abs(y);
	if (x==0) return y;
	if (y==0) return x;
	return __gcd(x,y);
}
const ll maxn=1e5+2;
ll px[maxn],py[maxn];
int n;
ld cachetwo[100];
ld getmultipler(int rem) {
	if (n<=61) {
		ll denom=(1LL<<n)-1-n-(n*(n-1))/2;
		ld invdenom=1.0L/denom;
		ll times=(1LL<<rem) - 1;
		ld multiplier=times*invdenom;
		return multiplier;
	}
	else {
		return cachetwo[(n-rem)];
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	{
		ld p=1.0L;
		for (int i=0;i<100;i++) {
			cachetwo[i]=p;
			p/=2;
		}
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%lld%lld",&px[i],&py[i]);
	}
	int klim=min(n-2,61);
	ld ans=0;
	for (int i=0;i<n;i++) {
		for (int k=1;k<=klim;k++) {
			int t=(i+k)%n;
			ll gain2=(px[i]*py[t]-py[i]*px[t]) - (gcd(px[t]-px[i],py[t]-py[i]));
			int rem=n-1-k;
			ans+=gain2*getmultipler(rem);
		}
	}
	ans/=2;
	ans++;
	printf("%.10f\n",(double)ans);
}