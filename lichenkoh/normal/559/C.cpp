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
const ll MAXFACT=3e5+4;
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


const ll maxn=2002;
ll f[maxn];
ll getnum(ll x, ll y) {
	if (x<0||y<0) return 0;
	return binom(x+y,y);
}
vector<pair<ll,pll> > v;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	init();
	ll h,w,n;
	scanf("%lld%lld%lld",&h,&w,&n);
	for (ll i=0;i<n;i++) {
		ll x,y; scanf("%lld%lld",&x,&y);
		--x;--y;
		v.PB(MP(x+y,MP(x,y)));
	}
	v.PB(MP(h+w-1-1,MP(h-1,w-1)));
	sort(v.begin(),v.end());
	for (ll i=0;i<=n;i++) {
		ll px=v[i].snd.fst,py=v[i].snd.snd;
		ll full=getnum(px,py);
		//printf("px:%lld py:%lld full:%lld\n",px,py,full);
		for (ll j=0;j<i;j++) {
			ll sx=v[j].snd.fst,sy=v[j].snd.snd;
			ll dx=px-sx,dy=py-sy;
			ll comp=(f[j]*getnum(dx,dy))%MOD;
			//printf("sx:%lld sy:%lld comp:%lld %lld %lld %lld=%lld\n",sx,sy,comp,f[j],dx,dy,getnum(dx+dy,dy));
			full=(full+MOD-comp)%MOD;
		}
		full%=MOD;
		if (full<0) full+=MOD;
		f[i]=full;
	}
	printf("%lld\n",f[n]%MOD);
}