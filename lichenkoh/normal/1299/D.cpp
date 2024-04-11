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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
using uint=unsigned int;
struct mint {
  unsigned x;
  inline int _norm(int y) {
    if (y<0) y+=MOD;
    return y;
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

const int mt=5;
const int mk=1<<mt;
 
template<typename T, size_t sz> class PreQ {
public:
  T q[sz];
  int l=0,r=0;
  void push(T const & t) {
    q[r]=t; r++;
  }
  T const & front() {
    return q[l];
  }
  void pop() {
    l++;
  }
  void reset() {
    l=0;r=0;
  }
  bool empty() {
    return l>=r;
  }
};
PreQ<int,mk> q;
uint completeMat(uint inp) {
  inp|=1;
  q.reset();
  for (int x=1;x<mk;x++) {
    if (inp&(1U<<x)) {
      q.push(x);
    }
  }
  while(!q.empty()) {
    int x=q.front(); q.pop();
    for (int y=1;y<mk;y++) {
      if (inp&(1U<<y)) {
        int z=x^y;
        if (0==(inp&(1U<<z))) {
          q.push(z);
          inp|=(1U<<z);
        }
      }
    }
  }
  return inp;
}

const int mn=100000;

vector<int> g[mn];
int spec[mn];
 
const int INIT=0;
 
inline int encode(int x, int w) {
  return (x<<5)|w;
}
inline int getv(int p) {
  return p>>5;
}
inline int getw(int p) {
  return p&(mk-1);
}
using uchar=unsigned char;
const int W=0,G=1,B=2;
int col[mn];
uchar seen[mn];
uint ansdfs=0U;
set<pii> sp;
void dfs(int xk, int p) {
  int x=getv(xk); uchar k=getw(xk);
  assert(col[x]==W);
  col[x]=G;
  seen[x]=k;
  for (auto &ye:g[x]) {
    int y=getv(ye);
    if (y!=p) {
      uchar w=getw(ye);
      if (col[y]==W) {
        dfs(encode(y,k^w),x);
      } else if (col[y]==G) {
        uchar bit=(k^w^seen[y]);
        uint msk=1U<<bit;
        if (msk&ansdfs) {
          ansdfs|=1U;
        } else {
          ansdfs|=msk;
        }
      }
    }
  }
  col[x]=B;
}
 
void rst() {
  ansdfs=0U;
}

uint ask(int x) {
  rst();
  dfs(encode(x,0),-1);
  uint completed=completeMat(ansdfs);
  if (0==(ansdfs&1)) {
    uint z=0;
    for (int k=1;k<mk;k++) {
      uint nz=z;
      if (ansdfs&(1U<<k)) {
        for (int t=1;t<mk;t++) {
          if (z&(1U<<t)) {
            nz|=(1U<<(t^k));
          }
        }
        nz|=(1U<<k);
      }
      z=nz;
    }
    if (0==(z&1)) {
      completed &= (~1U);
    }
  }
  return completed;
}
 
 
template<typename T> void makeunique(vector<T> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
 
vector<uint> vmat;
 
template<typename T> int bins(T const & x) {
  int imin=0,imax=vmat.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vmat[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

 
void genIncomplete(uint mat, int t) {
  if (t>=0) {
    for (int z=0;z<(1<<t);z++) {
      genIncomplete(mat|(1U<<z),t-1);
    }
  } else {
    vmat.PB(mat);
  }
}
 
bool inter(uint x, uint y) {
  return 0!=((x&y)&(~1U));
}
 
const int nmat=374;
vpii tab[nmat];
int mulSingle[mk][nmat];
void genComplete() {
  vmat.reserve(32768);
  genIncomplete(0U, mt);
  makeunique(vmat);
  for (auto &mat: vmat) {
    mat = completeMat(mat);
  }
  makeunique(vmat);
  assert(vmat.size()==nmat);
  for (int s=0;s<nmat;s++) {
    for (int x=nmat-1;x>=0;x--) {
      if (!inter(vmat[s],vmat[x])) {
        int sx=bins(completeMat(vmat[s]|vmat[x]));
        tab[s].PB(MP(x,sx));
      }
    }
  }
  for (int k=0;k<mk;k++) {
    for (int s=0;s<nmat;s++) {
      mulSingle[k][s]=bins(completeMat(vmat[s]|(1U<<k)));
    }
  }
}
 
 
mint f[2][nmat];
int loneCnt[nmat];
int pairCntL[nmat];
int pairCnt[nmat][mk];
mint pow3[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  genComplete();
  {
    mint p3=1;
    for (int i=0;i<mn;i++) {
      pow3[i]=p3;
      p3=(p3+p3+p3);
    }
  }
  int n=rint();
  int m=rint();
  {
  for (int j=0;j<m;j++) {
    int x=rint()-1; int y=rint()-1; int w=rint();
    if (y!=INIT) {
      g[x].PB(encode(y,w));
    }
    if (x!=INIT) {
      g[y].PB(encode(x,w));
    }
  }}
  vpii spairs;
  vi slone;
  {
    // Triangles with INIT
    for (auto &xe:g[INIT]) {
      int x=getv(xe);
      spec[x]=1+xe;
    }
    for (auto &xw:g[INIT]) {
      bool haspair=false;
      int x=getv(xw);
      if (!spec[x]) continue;
      for (auto &yw:g[x]) {
        int y=getv(yw);
        if (!spec[y]) continue;
        if (spec[y]) {
          spairs.PB(MP(x,getw(xw)^getw(yw)^getw(spec[y]-1)));
          spec[x]=0; spec[y]=0;
          haspair=true;
          break;
        }
      }
      if (!haspair) {
        slone.PB(x);
        spec[x]=0;
      }
    }
  }
 
  /*
  for (auto &p:spairs) { printf("(%d %d) ",getv(p.fst),getv(p.snd));}
  for (auto &l:slone) {printf("%d ",getv(l));}
  printf("end pairs lone\n");
  */
  
  for (auto &p:spairs) {
    int x=p.fst, roundw=p.snd;

    uint lone=ask(x);
    if (0==(lone&1)) {
      uint logpairs=0;
      if (!((lone&1)||(roundw==0)||(inter(lone,1U<<roundw)))) {
        logpairs=roundw;
      }
      int li=bins(lone|1);
      ++pairCntL[li];
      ++pairCnt[li][logpairs];
    }
  }
 
  int cur=0,nxt=1;
  f[cur][0]=1;
 
  {
    int lone=0;
    for (int logpairs=0;logpairs<mk;logpairs++) {
      int cnt=pairCnt[lone][logpairs];
      if (cnt) {
        memset(f[nxt],0,sizeof f[0]);
        for (int s=0;s<nmat;s++) {
          f[nxt][s]+=f[cur][s] * pow3[cnt];
        }
        if (logpairs > 0) {
          int s=bins(1U|(1U<<logpairs));
          for (auto &w:tab[s]) {
            int x=w.fst,sx=w.snd;
            f[nxt][sx]+=f[cur][x] * pow3[cnt-1] * cnt;
          }
        }
        swap(cur,nxt);
      }
    }
  }
  for (int lone=1;lone<nmat;lone++) {
    int lcnt=pairCntL[lone];
    if (lcnt) {
      memcpy(f[nxt],f[cur],sizeof f[0]);
      {
        int s=lone;
        for (auto &w:tab[s]) {
          int x=w.fst,sx=w.snd;
          f[nxt][sx]+=(f[cur][x]*(2*lcnt));
        }
      }
      for (int logpairs=1;logpairs<mk;logpairs++) {
        int pcnt=pairCnt[lone][logpairs];
        int s=mulSingle[logpairs][lone];
        for (auto &w:tab[s]) {
          int x=w.fst,sx=w.snd;
          f[nxt][sx]+=f[cur][x]*pcnt;
        }
      }
      swap(cur,nxt);
    }
  }
 
  for (auto &x:slone) {
    uint ma=ask(x);
    //printf("x:%d ma:%u\n",x,ma);
    if (0==(ma&1)) {
      ++loneCnt[bins(ma|1)];
    }
  }
  for (int s=1;s<nmat;s++) {
    if (loneCnt[s]) {
      memcpy(f[nxt],f[cur],sizeof f[0]);
      for (auto &w:tab[s]) {
        int x=w.fst,sx=w.snd;
        f[nxt][sx]+=f[cur][x]*loneCnt[s];
      }
      swap(cur,nxt);
    }
  }
 
 
  mint final=0;
  for (int s=0;s<nmat;s++) {
    final+=f[cur][s];
    //if (f[cur][s].get()) printf("s:%d f:%d\n",s,f[cur][s].get());
  }
  for (int i=0;i<loneCnt[0];i++) {
    final=(final+final);
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