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
const ll mn=1e5+4;
ll a[mn];
const ll LIM=1000000000000000LL;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	map<ll,ll> h;
	ll n,k; scanf("%lld %lld",&n,&k);
	for (ll i=0;i<n;i++) {
		scanf("%lld",&a[i]);
	}
	vector<ll> gen;
	if (k==1) {
		gen.PB(k);
	}
	else if (k==-1) {
		gen.PB(k);
		gen.PB(k*k);
	}
	else {
		ll t=1;
		while(1) {
			gen.PB(t);
			t*=k;
			if (abs(t)>LIM) break;
		}
	}
	h[0]++;
	ll final=0;
	ll sum=0;
	for (ll i=0;i<n;i++) {
		sum+=a[i];
		for (auto &w:gen) {
			ll last=sum-w;
			auto it=h.find(last);
			if (it!=h.end()) {
				ll ans=it->second;
				final+=ans;
			}
		}
		h[sum]++;
	}
	printf("%lld\n",final);
}