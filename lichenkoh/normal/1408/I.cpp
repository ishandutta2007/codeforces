#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=998244353;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const bool DBG=0;

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

const int mk=16;
const int mb=16;
const int ml=4;
mint vfinal[1<<mb];
int a[1<<mb];

template<typename ST> void FastWalshHadamardTransform(ST *P, int deg, bool forward) {
  assert(__builtin_popcount(deg)==1);
  for (int len = 1; 2 * len <= deg; len <<= 1) {
    for (int i = 0; i < deg; i += 2 * len) {
      for (int j = 0; j < len; j++) {
          ST u = P[i + j];
          ST v = P[i + len + j];
          P[i + j] = u + v;
          P[i + len + j] = u - v;
      }
    }
  }
  
  if (!forward) {
    ST invdeg = ST(deg).inverse();
    for (int i = 0; i < deg; i++) P[i] *= invdeg;
  }
}


int K,B;

template<int MaxSB> struct S {
  mint P[mk][1<<MaxSB];
  int SB;
  bool transformed=false;
  S(): SB(MaxSB) {
    memset(P,0,sizeof P);
  }
  S(int _SB): SB(_SB) {
    memset(P,0,sizeof P);
  }
  void transform(bool forward) {
    assert(transformed!=forward);
    transformed=forward;
    for (int k=1;k<=K;k++) {
      FastWalshHadamardTransform(P[k-1], 1<<SB, forward);
    }
  }
  S<MaxSB> &operator*=(S<MaxSB> & that) {
    assert(transformed);
    assert(that.transformed);
    assert(SB==that.SB);
    for (int target=K;target>=1;target--) {
      for (int i=0;i<(1<<SB);i++) {
        P[target-1][i]+=that.P[target-1][i];
      }
      for (int x=1;x<target;x++) {
        for (int i=0;i<(1<<SB);i++) {
          P[target-1][i]+=that.P[x-1][i]*P[target-x-1][i];
        }
      }
    }
    return *this;
  }
  /*S<MaxSB> operator^(unsigned int k) const {
    assert(transformed);
    S<MaxSB> a=(*this);
    S<MaxSB> r(SB);
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }*/
};

const int MAXFACT=mk;
mint fact[MAXFACT+1],invfact[MAXFACT+1];
void initFact() {
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
vi hi2v[mb];

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  initFact();
  int n=rint(); K=rint(); B=rint();
  int xorsumall=0;
  for (int i=0;i<n;i++) {a[i]=rint(); xorsumall^=a[i];}
  for (int q=0;q<n;q++) {
    int inp=a[q];
    int hi=0;
    for (int d=1;d<=min(K,15);d++) {
      int prev=inp^(inp-(d-1));
      int cur=inp^(inp-d);
      chkmax(hi, 31-__builtin_clz(prev^cur));
    }
    if (hi<ml) hi=0;
    if (DBG) {
      for (int d=1;d<=min(K,15);d++) {
        int cur=inp^(inp-d);
        cout<<bitset<mb>(cur)<<endl<<flush;
        if (hi!=0) {
          for (int i=ml+1;i<=hi;i++) assert(((cur>>ml)&1) == ((cur>>i)&1));
          
        } else {
          for (int i=ml+1;i<mb;i++) assert(((cur>>ml)&1) == ((cur>>i)&1));
        }
      }
    }
    hi2v[hi].PB(inp);
  }
  S<mb> sfinal(ml);
  for (int hi=0;hi<B;hi++) {
    if (hi>0 && hi <ml) continue;
    if(DBG) printf("hi:%d\n",hi);
    S<ml+1> scum; scum.transformed=true;
    for (int inp: hi2v[hi]) {
      S<ml+1> s;
      for (int d=1;d<=min(K,15);d++) {
        int cur=inp^(inp-d);
        int val=cur&((1<<ml)-1);
        if (hi!=0) {
          val|=cur&(1<<ml);
        }
        if(DBG) printf("d:%d val:%d\n",d,val);
        s.P[d-1][val]+=invfact[d];
      }
      s.transform(true);
      scum*=s;
    }
    scum.transform(false);
    int nowb=max(ml,hi+1);
    S<mb> sme(nowb); // OPT: sme(nowb)?
    int hisig=(hi==0)?0:( (1<<(hi+1)) - (1<<(ml)) );
    if(DBG) printf("hi:%d hisig:%d\n",hi,hisig);
    for (int k=1;k<=K;k++) {
      for (int i=0;i<(1<<(ml+1));i++) {
        int sig=i; if (sig&(1<<ml)) sig|=hisig;
        if(DBG) if (scum.P[k-1][i].get()) {
          printf("k:%d i:%d P:%d\n",k,i,scum.P[k-1][i].get());
        }
        sme.P[k-1][sig]=scum.P[k-1][i];
      }
    }
    sme.transform(true);
    sfinal.SB=nowb;
    sfinal.transform(true);
    sfinal*=sme;
    sfinal.transform(false);
  }
  if (K==16) {
    for (int i=0;i<n;i++) {
      int inp=a[i];
      int val=inp^(inp-16);
      sfinal.P[K-1][val]+=invfact[K];
      //if(DBG) printf("Add val:%d fact[K]:%d\n",val,fact[K].get());
    }
  }
  mint normalizer=mint(fact[K])/(mint(n)^K);
  for (int x=0;x<(1<<B);x++) {
    mint got=sfinal.P[K-1][x^xorsumall];
    mint ans=normalizer*got;
    if (DBG) if (got.get()) printf("x:%d got:%d ans:%d\n",x,got.get(),ans.get());
    if(!DBG) printf("%d ",ans.get());
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