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
const ll INF=1e18+4;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
ll b; string s;ll n;
const ll mn=61;
ll f[mn],a[mn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>b>>s;
	n=s.length();
	for (ll x=0;x<n;x++) a[x]=s[x]-'0';
	for (ll x=0;x<=n;x++) f[x]=INF;
	f[0]=0;
	for (ll x=0;x<n;x++) {
		if (f[x]>=INF) continue;
		ll val;
		if (!__builtin_mul_overflow(f[x],b,&val)) {
			if (val>=INF) continue;
			ll now=0;
			for (ll y=x;y<n;y++) {
				ll res;
				if (__builtin_mul_overflow(now,10LL,&res)) break;
				now=res;
				if (now>=b) continue;
				now+=a[y];
				if (now>=b) continue;
				ll cand=val+now;
				if (cand<INF) {
					//for (ll i=x;i<=y;i++) printf("%lld",a[i]);
					//printf(" now:%lld x:%lld f[x]:%lld y+1:%lld cand:%lld\n",now,x,f[x],y+1,cand);
					chkmin(f[y+1],cand);
				}
				if (a[x]==0) break;
			}
		}
	}
	printf("%lld\n",f[n]);
}