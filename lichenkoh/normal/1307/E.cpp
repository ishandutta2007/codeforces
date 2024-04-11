#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
 
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=5004;
const int L=0,R=1,B=2;
int g[mn][3];
 
pii f(int s) {
  int l=g[s][L],r=g[s][R],b=g[s][B];
  int msk=0;
  for (int k=0;k<3;k++) if (g[s][k]) msk|=(k+1);
  if (msk==0) {
    return MP(0,1);
  } else if (msk==1) {
    return MP(1,l);
  } else if (msk==2) {
    return MP(1,r);
  } else {
    if (l+r+b==1) {
      return MP(1,2);
    } else {
      int ans=(
        (l*r) +
        (l*b) +
        (b*r) +
        (b*(b-1))
        );
      return MP(2,ans);
    }
  }
  assert(0);
}
int a[mn],b[2][mn];
 
int askz(int c, int hl, int hr) {
  int z=0;
  int h[2]; h[L]=hl; h[R]=hr;
  for (int k=0;k<2;k++) {
    if (b[k][c] <= h[k]) z|=1<<k;
  }
  return z-1;
}
 
int fav[mn];
 
pair<int,mint> askp(int n, int C, int hl, int hr) {
  memset(g,0,sizeof g);
  for (int c=0;c<C;c++) {
    int s=fav[c];
    int z=askz(c,hl,hr);
    if (z>=0) ++g[s][z];
  }
  int cows=0;
  mint ways=1;
  for (int s=1;s<=n;s++) {
    pii got=f(s);
    cows+=got.fst;
    ways*=got.snd;
  }
  return MP(cows,ways);
}
 
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int C=rint();
  for (int x=0;x<n;x++) a[x]=rint();
  for (int c=0;c<C;c++) {
    fav[c]=rint(); int h=rint();
    for (int k=0;k<2;k++) {
      b[k][c]=n+1;
      int ate=0;
      for (int t=0;t<n;t++) {
        int x=k?(n-1-t):t;
        if (a[x]==fav[c]) {
          ++ate;
          if (ate == h) {
            b[k][c]=t+1;
            //printf("k:%d c:%d b:%d\n",k,c,b[k][c]);
            break;
          }
        }
      }
    }
  }
 
  int fcows=0; mint fways=0;
  for (int hl=n;hl>=0;hl--) {
    int hr=n-hl;
    pair<int,mint> ans=askp(n,C,hl,hr);
    if (hl>0) {
      pair<int,mint> lt=askp(n,C,hl-1,hr);
      if (ans.fst==lt.fst) {
        ans.snd-=lt.snd;
      }
    }
    //printf("hl:%d hr:%d cows:%d ways:%d\n",hl,hr,ans.fst,ans.snd.get());
    if (ans.fst==fcows) {
      fways+=ans.snd;
    } else if (ans.fst > fcows) {
      fcows=ans.fst; fways=ans.snd;
    }
 
  }
  printf("%d %d\n",fcows,fways.get());
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