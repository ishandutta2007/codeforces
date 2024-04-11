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

struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  mint(signed long long sig) {sig=_norm(sig%MOD); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  mint &operator/=(int that) {that=_norm(that); return *this *= mint(that).inverse(); }

  mint operator+(mint that) const { return mint(*this) += that; }
  mint operator-(mint that) const { return mint(*this) -= that; }
  mint operator*(mint that) const { return mint(*this) *= that; }
  mint operator/(mint that) const { return mint(*this) /= that; }

  mint operator+(int that) const { return mint(*this) += that; }
  mint operator-(int that) const { return mint(*this) -= that; }
  mint operator*(int that) const { return mint(*this) *= that; }
  mint operator/(int that) const { return mint(*this) /= that; }


  mint inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += MOD;
    mint res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(mint that) const { return x == that.x; }
  bool operator!=(mint that) const { return x != that.x; }
  mint operator-() const { mint t; t.x = x == 0 ? 0 : MOD - x; return t; }
  mint operator^(unsigned long long k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};
const int MAXFACT=3000+4;
mint fact[MAXFACT+1],invfact[MAXFACT+1];
void init() {
  mint got=1;
  for (int x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got*=(x+1);
  }
  got=got.inverse();
  for (int x=MAXFACT;x>=0;x--) {
    got*=(x+1);
    invfact[x]=got;
  }
}
mint binom(int n,int k) {
  if (n<k) return mint(0);
  if (n<0||k<0) return mint(0);
  return fact[n]*invfact[k]*invfact[n-k];
}

mint starbar(int stars, int parts) {
  if (parts==0) {
    return mint((stars==0)?1:0);
  }
  if (parts<=0||stars<0) return mint(0);
  return binom(stars+parts-1,parts-1);
}

mint geom(int r, int n) {
  // 1+r+...+r^n. Note 0^0 is 1
  if (r==1) return mint(n+1);
  return (mint(r)^(n+1)-1)/(r-1);
}


template<class T> T extgcd(T a, T b, T& x, T& y) {
  for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b;
}
struct poly {
  vector<mint> v;
  poly() {}
  poly(vector<mint> _v) {v=_v;}
  vector<mint> get() const { return v; }
  void pr() {for (auto &w:v) printf("%d ",w.get()); printf("\n");}

/*inline void solve(int x, int y, int& a, int& b) {extgcd(x,y,a,b); assert(a*x==b*y);}
inline vi remove_leading_zero(vi v) {
  vi vans;
  bool ok=0;
  for (auto &w:v) {
    if (ok||(w!=0)) {
      ok=1; vans.PB(w);
    }
  }
  return vans;
} // 00002342 -> 2343; 0 -> 0
// polynomial coefficients are in decreasing order of exponents
poly operator% (const vi& p, const vi& q) {
  vi copy(p.begin(), p.end()); int diff = p.size()-q.size(), a, b;
  for (int i = 0; i <= diff; ++i) {
    solve(q[0], copy[i], a, b);
    for (auto j = 0u; j < p.size(); ++j) copy[j] *= b;
    for (auto j = 0u; j < q.size(); ++j) copy[i+j] -= a*q[j];
  }
  return remove_leading_zero(copy); }

poly gcd(const vi &p, const vi &q){
  return (q.size()==0||(q.size()==1 && !q[0])) ? p : gcd(q,p%q);
}*/

poly &operator*= (const mint c) {
  for (auto &w:v) w*=c;
  return *this;
}
poly &operator/= (const mint c) {
  const mint d=c.inverse();
  for (auto &w:v) w*=d;
  return *this;
}
poly &operator+= (const poly &b) {
  size_t sz=max(v.size(),b.v.size());
  v.resize(sz);
  for (int i=0;i<sz;i++) v[i]+=b.v[i];
  return *this;
}
poly &operator-= (const poly &b) {
  size_t sz=max(v.size(),b.v.size());
  v.resize(sz);
  for (int i=0;i<sz;i++) v[i]-=b.v[i];
  return *this;
}
poly &operator*= (const poly &b) {
  size_t sz=v.size()+b.v.size()-1;
  vector<mint> vans(sz);
  for (int i=0;i<v.size();i++) {
    for (int j=0;j<b.v.size();j++) {
      vans[i+j]+=v[i]*b.v[j];
    }
  }
  v=vans;
  return *this;
}

  poly operator+(poly that) const { return poly(*this) += that; }
  poly operator-(poly that) const { return poly(*this) -= that; }
  poly operator*(poly that) const { return poly(*this) *= that; }

  poly operator*(mint that) const { return poly(*this) *= that; }
  poly operator/(mint that) const { return poly(*this) /= that; }

  bool operator==(const poly &that) const { return v == that.v; }
  bool operator!=(const poly &that) const { return v != that.v; }
};
const int mn=1002;
int dp[mn];
int dfs(int x) {
  if (x==1) return dp[x]=0;
  return dp[x]=dfs(__builtin_popcount(x))+1;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  string s; int inp; cin>>s>>inp;
  int slen=s.length();
  if (inp==0) {
    printf("%d\n",1);
    return 0;
  }
  int sones=0;
  for (auto &w:s) if (w=='1') sones++;
  mint final=0;
  if (dfs(sones)+1==inp) final+=1;
  for (int b=1;b<mn;b++) {
    if (dfs(b)+1==inp) {
      mint contrib=0;
      int pre1=0;
      for (int x=0;x<slen;x++) {
        if (s[x]=='1') {
          int tail=slen-x-1;
          mint got=binom(tail,b-pre1);
          //if (got.get()) printf("b:%d x:%d got:%d\n",b,x,got.get());
          contrib+=got;
          pre1++;
        }
      }
      if (b==1) contrib-=1;
      final+=contrib;
    }
  }
  printf("%d\n",final.get());
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