#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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

const int mn=int(2e5)+4;
vi g[2][mn];

int adist[mn][2];
int kdist[mn];
void gok(int n, int init) {
  using QQ=pair<int,pii>;
  priority_queue<QQ,vector<QQ>,greater<QQ> > pq;
  for (int x=1;x<=n;x++) for (int k=0;k<2;k++) adist[x][k]=1<<29;
  adist[init][0]=0;
  pii tmp=MP(init,0);
  QQ tmp2=MP(0,tmp);
  pq.push(tmp2);
  while(!pq.empty()) {
    auto got=pq.top(); pq.pop();
    int dist=got.fst; int x=got.snd.fst,k=got.snd.snd;
    if (dist>adist[x][k]) continue;
    for (int y:g[k][x]) {
      int ndist=dist;
      if (ndist<adist[y][k]) {
        adist[y][k]=ndist;
        pq.push(MP(ndist,MP(y,k)));
      }
    }
    {
      int ndist=dist+1;
      if (ndist<adist[x][k^1]) {
        adist[x][k^1]=ndist;
        pq.push(MP(ndist,MP(x,k^1)));
      }
    }
  }
  for (int x=1;x<=n;x++) kdist[x]=min(adist[x][0],adist[x][1]);
}


const int mk=32;
struct S {
  int v,k,a,b;
  S(): a(INF),b(INF) {}
  S(int _a,int _b): a(_a),b(_b) {}
  S &operator+=(S const& that) { a+=that.a; b+=that.b; return *this; }
  S operator+(S const & that) const { return S(*this) += that; }
  bool operator<(S const& that) const {
    int c=that.a,d=that.b;
    if (max(d,b)>=mk) {
      if (b==d) return a<c;
      return b<d;
    }
    ll L=ll(a)+(1LL<<b);
    ll R=ll(c)+(1LL<<d);
    return L<R;
  }
  bool operator>(S const& that) const {
    int c=that.a,d=that.b;
    if (max(d,b)>=mk) {
      if (b==d) return a>c;
      return b>d;
    }
    ll L=ll(a)+(1LL<<b);
    ll R=ll(c)+(1LL<<d);
    return L>R;
  }
};
S sdist[mn][mk];
void gos(int n, int init) {
  using QQ=pair<S,pii>;
  priority_queue<QQ,vector<QQ>,greater<QQ> > pq[mk];
  for (int x=1;x<=n;x++) for (int k=0;k<2;k++) sdist[x][k]=S(INF,INF);
  sdist[init][0]=S(0,0); pq[0].push(MP(sdist[init][0],MP(init,0)));
  while(1) {
    pair<S,int> least=MP(S(INF,INF),INF);
    for (int ck=0;ck<mk;ck++) {
      if (!pq[ck].empty()) {
        chkmin(least,MP(pq[ck].top().fst,ck));
      }
    }
    if (least.snd==INF) break;
    int ck=least.snd;
    auto got=pq[ck].top(); pq[ck].pop();
    S dist=got.fst; int x=got.snd.fst,k=got.snd.snd;
    if (dist>sdist[x][k-kdist[x]]) continue;
    //printf("x:%d k:%d a:%d b:%d\n",x,k,dist.a,dist.b);
    for (int y:g[k&1][x]) {
      if (k-kdist[y]<mk) {
        S ndist=dist+S(1,0);
        if (ndist<sdist[y][k-kdist[y]]) {
          sdist[y][k-kdist[y]]=ndist;
          pq[k-kdist[y]].push(MP(ndist,MP(y,k)));
        }
      }
    }
    if (k+1-kdist[x]<mk) {
      S ndist=dist+S(0,1);
      if (ndist<sdist[x][k+1-kdist[x]]) {
        sdist[x][k+1-kdist[x]]=ndist;
        pq[k+1-kdist[x]].push(MP(ndist,MP(x,k+1)));
      }
    }
  }
}



int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  for (int i=0;i<m;i++) {
    int x=rint(); int y=rint();
    g[0][x].PB(y); g[1][y].PB(x);
  }
  gok(n,1);
  gos(n,1);
  S ans=S(INF,INF);
  for (int k=0;k<mk;k++) {
    //printf("F n:%d k:%d a:%d b:%d\n",n,k,sdist[n][k].a,sdist[n][k].b);
    chkmin(ans,sdist[n][k]);
  }
  //printf("F n:%d a:%d b:%d\n",n,ans.a,ans.b);
  mint final=mint(ans.a) + (mint(2)^(ans.b)) - mint(1);
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