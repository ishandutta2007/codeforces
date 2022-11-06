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
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=4e3+4;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}


const ll mn=4002;
ll dp[mn][mn];
ll f(ll n, ll k) {
	if (dp[n][k]!=-1) return dp[n][k];
	if (n==0&&k==0) return dp[n][k]=1;
	if (n==0||k==0) return dp[n][k]=0;
	return dp[n][k]=(((long long)k)*f(n-1,k)+f(n-1,k-1))%MOD;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	memset(dp,-1,sizeof dp);
	ll n; cin>>n;
	ll final=0;
	for (ll k=0;k<=n-1;k++) {
		ll bin=binom(n,k);
		ll equiv=0;
		for (ll x=1;x<=k;x++) equiv+=f(k,x);
		equiv%=MOD;
		final+=(bin*equiv)%MOD;
	}
	final++;
	final%=MOD;
	printf("%lld\n",final);
}