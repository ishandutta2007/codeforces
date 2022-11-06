#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=31607;
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


struct mint {
  unsigned x;
  inline int _norm(int x) {
    if (x<0) x+=MOD;
    return x;
  }
  mint() : x(0) {}
  mint(signed sig) {sig=_norm(sig); x=sig;}
  int get() const { return (int)x; }
 
  mint &operator+=(mint that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
  mint &operator-=(mint that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  mint &operator*=(mint that) { x = (x * that.x) % MOD; return *this; }
  mint &operator/=(mint that) { return *this *= that.inverse(); }

  mint &operator+=(int that) {that=_norm(that); if((x += that) >= MOD) x -= MOD; return *this; }
  mint &operator-=(int that) {that=_norm(that); if((x += MOD - that) >= MOD) x -= MOD; return *this; }
  mint &operator*=(int that) {that=_norm(that); x = (x * that) % MOD; return *this; }
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
  mint operator^(int k) const {
    // 0^0 is 1. k must be taken modulo phi(MOD) (MOD-1 if prime) and NOT MOD itself
    mint a=(*this);
    if (k<0) {
      k=-k;
      a=a.inverse();
    }
    mint r = 1;
    while(k) {
      if(k & 1) r *= a;
      a *= a;
      k >>= 1;
    }
    return r;
  }
};
//using mint=double;

template<typename T> void InverseFastSubsetConvolution(vector<T> & f, int k) {
  // Reverse operation: f_out[S]=sum_{T \subseteq S} f_in[S]
  for (int i=0;i<k;i++) {
    for (int z=(1<<k)-1;z>=0;z--) {
      if (z&(1<<i)) {
        f[z]-=f[z^(1<<i)];
      }
    }
  }
}

mint solveRowCol(vector<vector<mint>> const& hit) {
  int n=hit.size();
  vector<vector<mint>> hitTranspose(n, vector<mint>(n));
  for (int r=0;r<n;r++) for (int c=0;c<n;c++) {
    hitTranspose[r][c]=hit[c][r];
  }
  vector<mint> colprod(n,mint(1));
  for (int r=0;r<n;r++) for (int c=0;c<n;c++) {
    colprod[c]*=hit[r][c];
  }
  vector<vector<mint>> winRowSub(1<<n, vector<mint>(n, mint(1)));
  vector<mint> colObeysZSub(1<<n, mint(1));
  for (int z=1;z<(1<<n);z++) {
    int bit=__builtin_ffs(z)-1;
    colObeysZSub[z] = colObeysZSub[z^(1<<bit)] * colprod[bit];
  }
  vector<mint> f(1<<n);
  for (int z=0;z<(1<<n);z++) {
    int bit=__builtin_ffs(z)-1;
    mint missAllRows=1;
    for (int r=0;r<n;r++) {
      if(z) winRowSub[z][r]=winRowSub[z^(1<<bit)][r] * hitTranspose[bit][r];
      missAllRows*=mint(1)-winRowSub[z][r];
    }
    mint hitSomeRow=mint(1)-missAllRows;
    f[z]=hitSomeRow * colObeysZSub[((1<<n)-1)^z];
    //printf("z0:%d z1:%d hitSomeRow:%f colObeysZ:%f f[z]:%f\n",z&1,z>>1,hitSomeRow,colObeysZ, f[z]);
  }
  InverseFastSubsetConvolution(f,n);
  mint hitSomeRowAndNoCols = f[(1<<n)-1];
  mint hitNoCols = 1;
  for (int c=0;c<n;c++) hitNoCols*=mint(1)-colprod[c];
  mint hitSomeCols=mint(1) - hitNoCols;
  mint ans = hitSomeCols + hitSomeRowAndNoCols;
  //printf("hitSomeCols:%f hitSomeRowAndNoCols:%f\n",hitSomeCols,hitSomeRowAndNoCols);
  return ans;
}

mint solveDiag(vector<vector<mint>> const& rawhit) {
  int n=rawhit.size();
  mint ans=0;
  for (int q=0;q<4;q++) {
    auto hit=rawhit;
    mint forceProb=1;
    if (q&1) {
      for (int x=0;x<n;x++) {
        forceProb*=hit[x][x];
        hit[x][x]=1;
      }
    }
    if (q&2) {
      for (int x=0;x<n;x++) {
        forceProb*=hit[x][n-1-x];
        hit[x][n-1-x]=1;
      }
    }
    mint got=solveRowCol(hit);
    mint res=got*forceProb;
    //printf("D:%d A:%d got:%f forceProb:%f res:%f\n",q&1,q>>1,got,forceProb,res);
    if (__builtin_popcount(q)%2) ans-=res;
    else ans+=res;
  }
  mint diagsum=0;
  for (int t=1;t<4;t++) {
    auto hit=rawhit;
    mint prod=1;
    if (t&1) {
      for (int x=0;x<n;x++) {
        prod*=hit[x][x];
        hit[x][x]=1;
      }
    }
    if (t&2) {
      for (int x=0;x<n;x++) {
        prod*=hit[x][n-1-x];
        hit[x][n-1-x]=1;
      }
    }
    //printf("t:%d diagsum:%f\n",t,diagsum);
    if (__builtin_popcount(t)%2) diagsum+=prod;
    else diagsum-=prod;
  }
  mint final=ans+diagsum;
  return final;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  mint inv=mint(1)/mint(10000);
  vector<vector<mint>> hit(n,vector<mint>(n));
  for (int r=0;r<n;r++) for (int c=0;c<n;c++) {
    int p=rint();
    hit[r][c]=mint(p)*inv;
  }

  //mint test=solveRowCol(hit);
  //printf("rowCol: %f\n",test);
  //return 0;

  mint final=solveDiag(hit);
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