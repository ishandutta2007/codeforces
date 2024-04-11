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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
const ll mn=1e5+4;
ll t[mn];
map<ll,ll,greater<ll> > h;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	t[0]=-INF;
	for (ll i=1;i<=n;i++) {
		scanf("%lld",&t[i]);
	}
	h[t[0]]=0;
	ll prev=0;
	for (ll i=1;i<=n;i++) {
		ll ans=prev+20;
		{
			auto it=h.lower_bound(t[i]-90);
			if (it!=h.end()) {
				ll cand=it->second+50;
				chkmin(ans,cand);
			}
		}
		{
			auto it=h.lower_bound(t[i]-1440);
			if (it!=h.end()) {
				ll cand=it->second+120;
				chkmin(ans,cand);
			}
		}
		h[t[i]]=ans;
		ll final=ans-prev;
		printf("%lld\n",final);
		prev=ans;
	}
}