#include <bits/stdc++.h>
#include <assert.h>
#define PB push_back
#define sz(c) ((ll)(c).size())
using namespace std;
typedef long long ll;
// FFT
typedef pair<ll, ll> Pii;

#define FOR(i,n) for(ll i = 0; i < (n); i++)

template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

template<ll mod, ll primitive_root>
class NTTWrongDontUse {
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
          a[s] = u + d;
          if (a[s] >= mod) a[s] -= mod;
          a[s + m] = u - d;
          if (a[s + m] < 0) a[s + m] += mod;
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

typedef NTTWrongDontUse<167772161, 3> NTTWrongDontUse_1;
typedef NTTWrongDontUse<469762049, 3> NTTWrongDontUse_2;
typedef NTTWrongDontUse<1224736769, 3> NTTWrongDontUse_3;

vector<ll> mul(vector<ll> a, vector<ll> b){
  NTTWrongDontUse_1 ntt1; NTTWrongDontUse_2 ntt2; NTTWrongDontUse_3 ntt3;
  auto x = ntt1.convolution(a, b);
  auto y = ntt2.convolution(a, b);
  auto z = ntt3.convolution(a, b);

  vector<ll> ret(sz(x));
  FOR(i, sz(x)){
    ret[i] = (x[i]==0&&y[i]==0&&z[i]==0)?0:1;
  }
  return ret;
}

vector<ll> exppoly(vector<ll> base, ll e) {
  NTTWrongDontUse_1 ntt1; NTTWrongDontUse_2 ntt2; NTTWrongDontUse_3 ntt3;
  auto x = ntt1.powup(base, e);
  auto y = ntt2.powup(base, e);
  auto z = ntt3.powup(base, e);

  vector<ll> ret(sz(x));
  FOR(i, sz(x)){
    ret[i] = (x[i]==0&&y[i]==0&&z[i]==0)?0:1;
  }
  return ret;
}

int main() {
	int n,k; scanf("%d %d",&n,&k);
	vector<ll> v;
	v.resize(1001);
	for (ll i=0;i<n;i++) {
		int tmp;
		scanf("%d",&tmp);
		v[tmp]=1;
	}
	vector<ll> ans=exppoly(v, k);
	ll anssz=ans.size();
	for (int i=0;i<anssz;i++) {
		if (ans[i]!=0) {
			printf("%d ",i);
		}
	}
	printf("\n");
}