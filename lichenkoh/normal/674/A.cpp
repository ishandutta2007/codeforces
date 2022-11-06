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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
ll a[5008];
ll c[5008];
ll sol[5008];
int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin>>n;
	for (ll i=0;i<n;i++) cin>>a[i];
	for (ll i=0;i<=n;i++) sol[i]=0;
	for (ll x=0;x<n;x++) {
		for (ll i=0;i<=n;i++) c[i]=0;
		map<ll, set<ll> > h;
		pair<ll,ll> best=MP(-1LL,-1LL);
		for (ll y=x;y<n;y++) {
			ll t=a[y];
			c[t]++;
			pair<ll,ll> cand=MP(c[t],-t);
			best=max(best,cand);
			sol[-best.second]++;
		}
	}
	for (ll x=1;x<=n;x++) {
		cout<<sol[x]<<" ";
	}
	cout<<endl;
}