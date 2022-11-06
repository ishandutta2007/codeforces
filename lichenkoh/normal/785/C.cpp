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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
ll n,m;
bool ok(ll k) {
	return ((2*(n-m)<=k*(k+1)));
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m;
	ll ans=n;
	ll C=2*(m-n);
	ll discr=1-4*C;
	if (discr>=0) {
		ll x=(-1+sqrt(discr))/2;
		for (ll k=max(0ll,x-3);k<=x+3;k++) {
			if (ok(k)) chkmin(ans,k+m);
		}
	}
	cout<<min(ans,n)<<endl;
}