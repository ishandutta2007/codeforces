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
const ll mn=2e5+4;
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=2*mn;
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
    assert(mul(fact[x],invfact[x])==1);
  }
}

ll vl[mn],vr[mn];
ll getf(ll l,ll r) {
	if (l<0||r<0) return 0;
	return mul(fact[l+r],mul(invfact[l],invfact[r]));
}
int main() 
{
	init();
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s;cin>>s;
	ll n=s.length();
	ll r=0;
	for (ll x=n-1;x>=0;x--) {
		vr[x]=r;
		if (s[x]==')') r++;
	}
	ll l=0;
	ll ans=0;
	for (ll x=0;x<n;x++) {
		if (s[x]=='(') {
			l++;
			ll r=vr[x];
			ll add=getf(l,r)-getf(l-1,r);
			if(add<0) add+=MOD;
			//printf("x:%d l:%d r:%d add:%d\n",x,l,r,add);
			ans+=add;
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
}