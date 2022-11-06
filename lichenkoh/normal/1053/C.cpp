#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define int ll
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T> int bins(vector<T> &v, T key) {
int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;
}
const int mn=2e5+4;

inline int _norm(int x) {
  if (x<0) x+=MOD;
  return x;
}
template<int MOD>
struct ModInt {
  static const int Mod = MOD;
  unsigned x;
  ModInt() : x(0) {}
  ModInt(signed sig) {sig=_norm(sig); x=sig;}
  ModInt(signed long long sig) {sig=_norm(sig); x=sig;}
  int get() const { return (int)x; }
 
  ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = ((unsigned long long)x * that.x) % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

  ModInt &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(int that) {that=_norm(that); x = ((unsigned long long)x * that) % MOD; return *this; }
  ModInt &operator/=(int that) {that=_norm(that); return *this *= ModInt(that).inverse(); }

  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

  ModInt operator+(int that) const { return ModInt(*this) += that; }
  ModInt operator-(int that) const { return ModInt(*this) -= that; }
  ModInt operator*(int that) const { return ModInt(*this) *= that; }
  ModInt operator/(int that) const { return ModInt(*this) /= that; }


  ModInt inverse() const {
    signed a = x, b = MOD, u = 1, v = 0;
    while(b) {
      signed t = a / b;
      a -= t * b; std::swap(a, b);
      u -= t * v; std::swap(u, v);
    }
    if(u < 0) u += Mod;
    ModInt res; res.x = (unsigned)u;
    return res;
  }
 
  bool operator==(ModInt that) const { return x == that.x; }
  bool operator!=(ModInt that) const { return x != that.x; }
  ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
  ModInt<MOD> r = 1;
  while(k) {
    if(k & 1) r *= a;
    a *= a;
    k >>= 1;
  }
  return r;
}
typedef ModInt<MOD> mint;


template<int _SEGSZ> class ModSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    int ans=lefts+rights;
    if (ans>=MOD) ans-=MOD;
    return ans;
  }
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const ll value) { // set value at position p
    int n=segn;
    for (t[p += n] = value%MOD; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  mint query(int l, int r) { // sum on interval [l, r]
    if (l>r) return identity;
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return mint(combine(resl, resr));
  }
};
/*
template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef ld S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S lefts, const S rights) {
    return lefts+rights;
  }
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    if (l>r) return identity;
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};
*/
class AtLeastSegTree {
public:
  static const int SEGSZ = 1<<18; // Must be power of 2
  const int MAXSEG = SEGSZ+1;  // limit for array size
  const int segn=SEGSZ;  // array size
  typedef ll S;
  S t[2 * SEGSZ + 2];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }
  S query(int l, int r) { // sum on interval [l, r]
    if (l>r) return identity;
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
  int _fatleast(S atleast, int l, int r, int p) {
    // Finds leftmost idx such that the sum seg[0...idx] inclusive is at least "atleast".
    if (l+1==r) return l;
    int m=(l+r)>>1;
    if (atleast <= t[p<<1]) {
      return _fatleast(atleast, l, m, p<<1);
    }
    else {
      return _fatleast(atleast-t[p<<1], m, r, (p<<1)|1);
    }
  }
  int fatleast(S atleast) {
    return _fatleast(atleast,0,segn,1);
  }
};

ModSegTree<mn> msegwx, msegw, msegwi;
AtLeastSegTree asegw;

int x[mn];
int w[mn];
int n;

mint mf(int l, int r, int s) {
  int imin=l,imax=r+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (x[imid] < s+imid-l) {
      imin=imid+1;
    }
    else imax=imid;
  }
  int mid=imin;
  mint ansR=msegwx.query(mid,r)-msegw.query(mid,r)*(s-l)-msegwi.query(mid,r);
  mint ansL=(msegw.query(l,mid-1)*(s-l)+msegwi.query(l,mid-1)-msegwx.query(l,mid-1));
  return ansL+ansR;
}

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint(); int q=rint();
  msegwx.init(n); msegw.init(n); msegwi.init(n);
  for (int i=0;i<n;i++) x[i]=rint();
  for (int i=0;i<n;i++) w[i]=rint();
  for (int i=0;i<n;i++) {
    ll wx=w[i]*(ll)x[i];
    ll wi=w[i]*(ll)i;
    asegw.t[asegw.segn+i]=w[i];
    msegw.t[n+i]=w[i]%MOD;
    msegwx.t[n+i]=wx%MOD;
    msegwi.t[n+i]=wi%MOD;
  }
  asegw.build();
  msegw.build();
  msegwx.build();
  msegwi.build();
  //printf("ans:%Lf\n",f(0,4,4));return 0;
  for (int qi=0;qi<q;qi++) {
    int q1=rint(),q2=rint();
    if (q1<0) {
      int i=-q1-1;
      int nw=q2;
      w[i]=nw;
      ll wx=w[i]*(ll)x[i];
      ll wi=w[i]*(ll)i;
      asegw.sset(i,w[i]);
      msegw.sset(i,w[i]);
      msegwx.sset(i,wx);
      msegwi.sset(i,wi);
    }
    else {
      int l=q1-1,r=q2-1;
      ll allw=asegw.query(l,r);
      int a,b=-1;
      {
        ll medw=asegw.query(0,l-1)+((allw+1)/2);
        int cand=asegw.fatleast(medw);
        assert(l<=cand&&cand<=r);
        a=cand;
        //printf("a:%lld allw:%lld medW:%lld\n",a,allw,medw);
      }
      if (allw%2==0) {
        ll medw=asegw.query(0,l-1)+((allw+2)/2);
        int cand=asegw.fatleast(medw);
        assert(l<=cand&&cand<=r);
        b=cand;
        //printf("b:%lld allw:%lld medW:%lld\n",a,allw,medw);
      }
      if (b!=-1) {
        if (w[b]>w[a]) swap(a,b);
        assert(w[a]>=w[b]);
      }
      int medS=x[a]-(a-l);
      //printf("a:%lld b:%lld medS:%lld\n",a,b,medS);
      //printf("a:%lld allw:%lld medS:%lld\n",a,allw,medS);
      mint ans=mf(l,r,medS);
      printf("%lld\n",ans.get());
      //printf("%.5f %.5f\n",(double)best.fst,(double)best.snd);
      /*for (int x=1;x<=10;x++) {
        printf("x:%d f:%.5Lf\n",x,f(l,r,x));
      }*/
    }
  }
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