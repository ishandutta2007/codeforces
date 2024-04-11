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
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1e5+4;
const ll MAXX=2e9;
ll a[MAXN];
map<ll,ll> h;
int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%I64d",&n);
	for (ll i=0;i<n;i++) scanf("%I64d",&a[i]);
	ll ans=0;
	for (ll i=0;i<n;i++) {
		ll x=a[i];
		for (ll j=2;j<=MAXX;j=j<<1) {
			if ((j-x)>=1) {
				auto it=h.find(j-x);
				if (it!=h.end()) ans+=it->second;
			}
		}
		h[x]++;
	}
	printf("%I64d\n",ans);
}