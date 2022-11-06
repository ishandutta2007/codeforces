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
const int mn=1002;
int dp[mn][mn];
int stirling(int n, int k) {
  if (dp[n][k]!=-1) return dp[n][k];
  int ans;
  if (n==0&&k==0) ans=1;
  else if (n==0||k==0) ans=0;
  else {
    ans=(k*(ll)stirling(n-1,k) + stirling(n-1,k-1))%MOD;
  }
  return dp[n][k]=ans;
}

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

const int MAXFACT=1e6+4;
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

mint distinctObjectsDistinctNonemptyBins(int n, int bins) {
  mint ans=0;
  int sign=1;
  for (int k=bins;k>0;k--) {
    mint got=binom(bins,k)*(mint(k)^n);
    if (sign==1) ans+=got;
    else ans-=got;
    sign=-sign;
  }
  return ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init(); memset(dp,-1,sizeof dp);
  //mint zz=distinctObjectsDistinctNonemptyBins(5,3);
  //printf("%d\n",zz.get());
  //return 0;
  int r=rint(),c=rint(),klim=rint();
  mint final=0;
  if (c==1||c==2) {
    mint ans=0;
    for (int k=1;k<=min(r,klim);k++) {
      mint got=binom(klim,k)*stirling(r,k)*fact[k];
      //printf("k:%d got:%d\n",k,got.get());
      if (c==1) ans+=got;
      if (c==2) ans+=got*got;
    }
    final=ans;
  }
  else {
    mint ans=0;
    for (int k=1;k<=min(r,klim);k++) {
      mint inside=binom(klim,k)*distinctObjectsDistinctNonemptyBins((c-2)*r,k);
      //printf("k:%d got:%d inside:%d res:%d\n",k,got.get(),inside.get(),(got*inside).get());
      mint got=0;
      for (int d=0;d<=min(r,klim)-k;d++) {
        mint side=binom(klim-k,d)*(fact[k+d]*stirling(r,k+d));
        got+=side*side;
      }
      ans+=got*inside;
    }
    final=ans;
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