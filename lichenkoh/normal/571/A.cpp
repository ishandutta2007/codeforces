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
ll getrange(ll l, ll r) {
	chkmax(l,0ll);
	if (l<=r) return (r-l+1);
	else return 0;
}
ll f(ll A,ll B,ll C, ll l) {
	ll X=C-A-B;
	ll Y=l;
	ll ans=0;
	for (ll d=0;d<=(X+Y)/2;d++) {
		ll got=(d+1)*getrange(d-X,Y-d);
		ans+=got;
	}
	return ans;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b,c,l; cin>>a>>b>>c>>l;
	ll all=((l+3)*(l+2)*(l+1))/6;
	//printf("all:%lld\n",all);
	ll comple=f(a,b,c,l)+f(a,c,b,l)+f(b,c,a,l);
	ll final=all-comple;
	printf("%lld\n",final);
}