#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
const ll mn=2e5+4;
const ll N = mn;  // limit for array size
ll n;  // array size
ll t[2 * N];

void build() {  // build the tree
  for (ll i = n - 1; i > 0; --i) t[i] = t[i<<1] | t[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] | t[p^1];
}

ll query(ll l, ll r) {  // sum on interval [l, r]
  if (l>r) return 0;
  r++;
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res |= t[l++];
    if (r&1) res |= t[--r];
  }
  return res;
}

int main() {
	ll klim,c; scanf("%lld%lld%lld",&n,&klim,&c);
	ll d=1;
	for (ll k=0;k<klim;k++) d*=c;
	for (ll i=0;i<n;i++) {
		scanf("%lld",t+n+i);
	}
	build();
	ll best=0;
	for (ll x=0;x<n;x++) {
		ll ans=query(0,x-1)|query(x+1,n-1)|(t[x+n]*d);
		chkmax(best,ans);
	}
	printf("%lld\n",best);
}