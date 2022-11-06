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

typedef mint ST;
void FastWalshHadamardTransform(vector<ST> &P, bool inverse) {
  // deg MUST be a power of 2
  int deg=P.size();
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
  ST inverted=mint(deg).inverse();
  if (inverse) {
    for (int i = 0; i < deg; i++) P[i] = P[i] *inverted;
  }
}

typedef mint SU;
void AndTransform(vector<SU> &P, bool inverse) {
  // deg MUST be a power of 2
  int deg=P.size();
  assert(__builtin_popcount(deg)==1);
    for (int len = 1; 2 * len <= deg; len <<= 1) {
        for (int i = 0; i < deg; i += 2 * len) {
            for (int j = 0; j < len; j++) {
                SU u = P[i + j];
                SU v = P[i + len + j];
                
                if (!inverse) {
                    P[i + j] = v;
                    P[i + len + j] = u + v;
                } else {
                    P[i + j] = -u + v;
                    P[i + len + j] = u;
                }
            }
        }
    }
}


const int mn=1<<17;
vector<mint> P(mn);
vector<mint> AB(mn);
int fib[mn];
// // Nonempty subset increasing
#define FORNESI(sub, full) for(int sub = 0 ;(sub = (sub - (full)) & (full))  ; )
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int inpn=rint();
  for (int i=0;i<inpn;i++) {
    int x=rint();
    P[x]+=1;
  }
  fib[0]=0; fib[1]=1;
  for (int i=2;i<mn;i++) {
    int sum=fib[i-1]+fib[i-2];
    if (sum>=MOD) sum-=MOD;
    fib[i]=sum;
  }
  vector<mint> DE=P;
  FastWalshHadamardTransform(DE,false);
  for (int x=0;x<mn;x++) DE[x]=DE[x]*DE[x];
  FastWalshHadamardTransform(DE,true);
  for (int x=0;x<mn;x++) DE[x]*=fib[x];

  for (int z=0;z<mn;z++) {
    mint res=P[0]*P[z];
    FORNESI(x,z) {
      res+=P[x]*P[z^x];
    }
    AB[z]=res;
  }
  for (int x=0;x<mn;x++) AB[x]*=fib[x];

  vector<mint> C=P; // Optimize by adding &
  for (int x=0;x<mn;x++) C[x]*=fib[x];

  AndTransform(AB,false);
  AndTransform(C,false);
  AndTransform(DE,false);
  for (int x=0;x<mn;x++) C[x]*=(AB[x]*DE[x]);
  AndTransform(C,true);
  mint ans=0;
  for (int i=0;i<17;i++) {
    ans+=C[1<<i];
  }
  printf("%d\n",ans.get());


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