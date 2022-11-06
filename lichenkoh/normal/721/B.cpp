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
ll v[200];
ll f(ll x, ll k) {
	ll ans=max(0ll,x+5*((x-1)/k));
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);
	ll n,k; cin>>n>>k;
	for (ll i=0;i<200;i++) v[i]=0;
	for (ll i=0;i<n;i++) {
		string s; cin>>s;
		v[s.length()]++;
	}
	string p; cin>>p;
	ll pn=p.length();
	ll lo=1;
	for (ll i=0;i<pn;i++) {
		lo+=v[i];
	}
	ll hi=0;
	for (ll i=0;i<=pn;i++) {
		hi+=v[i];
	}
	printf("%lld %lld\n",f(lo,k),f(hi,k));
}