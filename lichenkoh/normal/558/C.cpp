#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll mn=1e5+4;
ll cnt[mn];
ll cost[mn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	memset(cost,0,sizeof cost);
	memset(cnt,0,sizeof cnt);
	for (ll i=0;i<n;i++) {
		ll x; scanf("%lld",&x);
		ll old_x=-1;
		ll outer_cost=0;
		while(1) {
			if (x==0) break;
			ll inner_cost=outer_cost;
			cnt[x]++;
			cost[x]+=inner_cost;
			if (x*2!=old_x) {
				ll y=x;
				while(1) {
					y*=2;
					if (y>=mn) break;
					inner_cost++;
					cnt[y]++;
					cost[y]+=inner_cost;
				}
			}
			old_x=x;
			x/=2;
			outer_cost++;
		}
	}
	ll final=INF;
	for (ll x=1;x<mn;x++) {
		if (cnt[x]==n) {
			chkmin(final,cost[x]);
		}
	}
	printf("%lld\n",final);
}