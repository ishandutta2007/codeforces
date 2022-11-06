#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

const ll MAXN = 1e6+4;  // limit for array size
ll gn;  // array size
ll t[2 * MAXN];

void build() {  // build the tree
  for (ll i = gn - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(ll p, ll value) {  // set value at position p
  for (t[p += gn] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(ll l, ll r) {  // sum on interval [l, r]
	r++;
  ll res = 0;
  for (l += gn, r += gn; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
ll q[MAXN];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,k; scanf("%lld %lld",&n,&k);
	chkmin(k,n-k);
	gn=n;
	memset(q,0,sizeof q);
	memset(t,0,sizeof t);
	ll ans=1;
	ll x=0;
	for (ll i=0;i<n;i++) {
		ll l=(x+1)%n;
		ll r=(x+k-1)%n;
		ll sum;
		if (l<=r) {
			sum=query(l,r);
		}
		else {
			sum=query(l,n-1)+query(0,r);
		}
		ll adder=sum+1;
		ans+=adder;
		printf("%lld ",ans);
		ll y=(x+k)%n;
		q[x]++; q[y]++;
		modify(x,q[x]);
		modify(y,q[y]);
		x=y;
	}
	printf("\n");
}