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
const ll mn=2e5+4;
ll p[mn],b[mn];
bool seen[mn];
void dfs(ll x) {
	if (seen[x]) return;
	seen[x]=true;
	dfs(p[x]);
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) {scanf("%lld",&p[i]); --p[i];}
	for (ll i=0;i<n;i++) scanf("%lld",&b[i]);
	ll sumb=0;
	for (ll i=0;i<n;i++) {
		sumb+=b[i];
	}
	memset(seen,0,sizeof seen);
	ll numc=0;
	for (ll x=0;x<n;x++) {
		if (!seen[x]) {
			dfs(x);
			numc++;
		}
	}
	ll ans=0;
	if (numc>1) ans+=numc;
	if (0==(sumb%2)) ans++;
	printf("%lld\n",ans);
}