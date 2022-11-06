#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();






#define PB push_back
#define sz(c) ((ll)(c).size())
typedef long long ll;
// FFT
typedef pair<ll, ll> Pii;

#define FOR(i,n) for(ll i = 0; i < (n); i++)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<ll mod, ll primitive_root>
class NTT {
public:
  ll get_mod() const { return mod; }
  void _ntt(vector<ll>& a, ll sign) {
    const ll n = sz(a);

    const ll g = primitive_root; //g is primitive root of mod
    ll h = (ll)mod_pow(g, (mod - 1) / n, mod); // h^n = 1
    if (sign == -1) h = (ll)mod_inv(h, mod); //h = h^-1 % mod

    ll i = 0;
    for (ll j = 1; j < n - 1; ++j) {
      for (ll k = n >> 1; k >(i ^= k); k >>= 1);
      if (j < i) swap(a[i], a[j]);
    }

    for (ll m = 1; m < n; m *= 2) {
      const ll m2 = 2 * m;
      const ll base = mod_pow(h, n / m2, mod);
      ll w = 1;
      FOR(x, m) {
        for (ll s = x; s < n; s += m2) {
          ll u = a[s];
          ll d = a[s + m] * w % mod;
          ll as=u+d;
          if (as>=mod) as-=mod;
          a[s]=as;
          ll sm=u-d;
          if (sm<0) sm+=mod;
          a[s+m]=sm;
        }
        w = w * base % mod;
      }
    }

    for (auto& x : a) if (x < 0) x += mod;
  }
  void ntt(vector<ll>& input) {
    _ntt(input, 1);
  }
  void intt(vector<ll>& input) {
    _ntt(input, -1);
    const ll n_inv = mod_inv(sz(input), mod);
    for (auto& x : input) x = x * n_inv % mod;
  }

  vector<ll> convolution(const vector<ll>& a, const vector<ll>& b){
    ll ntt_size = 1;
    while (ntt_size < sz(a) + sz(b)) ntt_size *= 2;

    vector<ll> _a = a, _b = b;
    _a.resize(ntt_size); _b.resize(ntt_size);

    ntt(_a);
    ntt(_b);

    FOR(i, ntt_size){
      (_a[i] *= _b[i]) %= mod;
    }

    intt(_a);
    return _a;
  }
  vector<ll> powup(const vector<ll>& a, ll exponent){
    ll ntt_size = 1;
    while (ntt_size < (sz(a)*exponent)) ntt_size *= 2;

    vector<ll> _a = a;
    _a.resize(ntt_size);

    ntt(_a);

    FOR(i, ntt_size){
      _a[i]=mod_pow(_a[i], exponent, mod);
    }

    intt(_a);
    return _a;
  }
};

typedef NTT<167772161, 3> NTT_1;
typedef NTT<469762049, 3> NTT_2;
typedef NTT<1224736769, 3> NTT_3;

vector<ll> mul(vector<ll> a, vector<ll> b,ll mod){
  for (auto& x : a) x %= mod;
  for (auto& x : b) x %= mod;
  
  NTT_1 ntt1; NTT_2 ntt2; NTT_3 ntt3;
  auto x = ntt1.convolution(a, b);
  auto y = ntt2.convolution(a, b);
  auto z = ntt3.convolution(a, b);

  const ll m1 = ntt1.get_mod(), m2 = ntt2.get_mod(), m3 = ntt3.get_mod();
  const ll m1_inv_m2 = mod_inv<ll>(m1, m2);
  const ll m12_inv_m3 = mod_inv<ll>(m1 * m2, m3);
  const ll m12_mod = m1 * m2 % mod;
  vector<ll> ret(sz(x));
  FOR(i, sz(x)){
    ll v1 = (y[i] - x[i]) *  m1_inv_m2 % m2;
    if (v1 < 0) v1 += m2;
    ll v2 = (z[i] - (x[i] + m1 * v1) % m3) * m12_inv_m3 % m3;
    if (v2 < 0) v2 += m3;
    ll constants3 = (x[i] + m1 * v1 + m12_mod * v2) % mod;
    if (constants3 < 0) constants3 += mod;
    ret[i] = constants3;
  }
  return ret;
}





const int mn=2e5+2;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll inpsz=rint(), t=rint();
  vector<ll> f;
  {
    int sum=0;
    for (int i=0;i<inpsz;i++) {
      int x=rint();
      if (x<t) {
        f.PB(sum+1);
        sum=0;
      }
      else ++sum;
    }
    f.PB(sum+1);
  }
  ll fsz=f.size();
  vector<ll> g=f;
  reverse(g.begin(),g.end());
  vector<ll> res=mul(f,g,((inpsz*(inpsz+1))/2)+1);
  ll zero=0;
  for (auto &w:f) zero+=(w*(w-1))/2;
  printf("%lld ",zero);
  for (int x=1;x<=inpsz;x++) {
    ll e=fsz-1+x;
    if (e<res.size()) printf("%lld ",res[e]);
    else printf("0 ");
  }
  printf("\n");
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}