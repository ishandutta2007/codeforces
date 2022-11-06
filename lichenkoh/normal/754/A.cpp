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
const ll mn=1000;
ll a[mn];
vector<pll> vans;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; cin>>n;
	for (ll x=1;x<=n;x++) cin>>a[x];
	bool has=false;
	ll last=1;
	for (ll x=1;x<=n;x++) {
		if (a[x]!=0) {
			if (!has) has=true;
			else {
				vans.PB(MP(last,x-1));
				last=x;
				has=true;
			}
		}
	}
	vans.PB(MP(last,n));
	if (!has) {
		printf("NO\n");
	}
	else {
		printf("YES\n%lld\n",(ll)vans.size());
		for (auto &w:vans) printf("%lld %lld\n",w.fst,w.snd);
	}
}