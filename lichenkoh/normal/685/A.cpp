#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const ll MOD = 1000000007LL;
const ll INF = 1ULL<<60ULL;
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll getdigreq(ll x) {
	if (x==0) return 1;
	ll ans=0;
	while(x>0) {
		x/=7;
		ans++;
	}
	return ans;
}
void go(ll n, ll *f) {
	for (ll i=0;i<(1<<7);i++) f[i]=0;
	ll d=getdigreq(n-1);
	if (d>=7) return;
	ll a[7];
	for (ll i=0;i<7;i++) a[i]=0;
	for (ll i=0;i<d;i++) a[7-1-i]=1;
	sort(a,a+7);
	do {
		vector<ll> b;
		ll sig=0;
		for (ll i=6;i>=0;i--) {
			if (a[i]) {
				b.PB(i);
				sig|=(1<<i);
			}
		}
		sort(b.begin(),b.end());
		do {
			ll x=0;
			for (ll i=0;i<d;i++) {
				x*=7;
				x+=b[i];
			}
			if (x<n) {
				f[sig]++;
			}
		} while(next_permutation(b.begin(),b.end()));
	} while(next_permutation(a,a+7));
}
ll g[2][1<<7];
int main() {
	ll n,m; cin>>n>>m;
	go(n,g[0]);
	go(m,g[1]);
	ll ans=0;
	for (ll x=0;x<(1<<7);x++) {
		for (ll y=0;y<(1<<7);y++) {
			if (!(x&y)) {
				ll cand=g[0][x]*g[1][y];
				ans+=cand;
			}
		}
	}
	cout<<ans<<endl;
}