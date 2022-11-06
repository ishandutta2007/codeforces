#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e15;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll lmax[2],rmin[2];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll i=0;i<2;i++) {
		lmax[i]=-INF;
		rmin[i]=INF;
	}
	for (ll i=0;i<n;i++) {
		ll l,r; cin>>l>>r;
		chkmax(lmax[0],l);
		chkmin(rmin[0],r);
	}
	ll m; cin>>m;
	for (ll i=0;i<m;i++) {
		ll l,r; cin>>l>>r;
		chkmax(lmax[1],l);
		chkmin(rmin[1],r);
	}
	ll ans=0;
	for (ll x=0;x<2;x++) {
		chkmax(ans, lmax[x]-rmin[x^1]);
	}
	cout<<ans<<endl;
}