#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
vector<ll> reversechoose(ll x) {
	vector<ll> final;
	if (x==0) {
		final.PB(0);final.PB(1);
		return final;
	}
	ll imin=0,imax=1e8;
	while(imin<imax) {
		ll imid=imin+(imax-imin)/2;
		ll got=(imid*(imid-1))/2;
		if (got<x) imin=imid+1;
		else imax=imid;
	}
	ll ans=imin;
	if ((ans*(ans-1))/2==x) final.PB(ans);
	return final;
}
ll arith(ll a, ll b) {
	if (a>b) return 0;
	ll num=(b-a+1);
	return ((a+b)*num)/2;
}
int main() {
	vector<int> ans;
	ios_base::sync_with_stdio(false);
	ll a00,a01,a10,a11; cin>>a00>>a01>>a10>>a11;
	vector<ll> gzeros=reversechoose(a00);
	vector<ll> gones=reversechoose(a11);
	for (auto &zeros:gzeros) {
		for (auto &ones:gones) {
	if (ones+zeros==0) {
		continue;
	}
	ll all=ones*zeros;
	if (a01+a10!=all) {
		continue;
	}
	if (zeros==0) {
		for (ll i=0;i<ones;i++) ans.PB(1);
	}
	else if (ones==0) {
		for (ll i=0;i<zeros;i++) ans.PB(0);
	}
	else {
		ll pushend=a01/zeros;
		ll left=a01%zeros;
		ll initone=ones-pushend;
		if (left>0) initone--;
		for (ll i=0;i<initone;i++) {
			ans.PB(1); ones--;
		}
		if (left>0) {
			for (ll i=0;i<left;i++) {
				ans.PB(0); zeros--;
			}
			ans.PB(1); ones--;
		}
		for (ll i=0;i<zeros;i++) ans.PB(0);
		for (ll i=0;i<ones;i++) ans.PB(1);
	}
	for (auto &c:ans) printf("%d",c);
	printf("\n"); return 0;

		}
	}
	printf("Impossible\n");
}