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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
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

template<int mx> class UnionFind {
  typedef int UFTYPE;
public:
  int ufParent[mx];
  int rank[mx];
  int indir[mx];
  vi ufData[mx];
  inline void combine(int dest, int src) {
    int di=indir[dest],si=indir[src];
    if (ufData[indir[dest]].size() < ufData[indir[src]].size()) {
      swap(di,si);
      swap(indir[dest], indir[src]);
    }
    for (auto &w:ufData[si]) {
      ufData[di].PB(w);
    }
    ufData[si].clear();
  }
  inline void ufreset(int x) {
    ufParent[x]=x;
    indir[x]=x;
    ufData[x].PB(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=1;x<=n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    combine(yr,xr);
  }
  vi getData(int x) {
    return ufData[indir[ffind(x)]];
  }
  int getLoV(int x) {
    return ufData[indir[ffind(x)]][0];
  }
  int getHiV(int x) {
    return ufData[indir[ffind(x)]].back();
  }
};

template<int _SEGSZ> class MaxSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef pii S;
  S t[2 * SEGSZ];
  S identity = MP(-INF,-INF);
  S combine(const S& lefts, const S& rights) {
    return max(lefts,rights);
  }
  void init(int n) {segn=n;}
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
};


const int mv=(2e5)+4;
const int me=(3e5)+4;
const int mq=(5e5)+4;

UnionFind<mv> uf;
MaxSegTree<mv> seg;

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int nv=rint(),ne=rint(),qn=rint();
  uf.init(nv);
  vi v2label(nv+1);
  for (int x=1;x<=nv;x++) {
    v2label[x]=rint();
  }
  vpii ve(ne+1);
  for (int ei=1;ei<=ne;ei++) {
    ve[ei]=MP(rint(),rint());
  }
  vi qt(qn+1),qv(qn+1);
  for (int qi=1;qi<=qn;qi++) {
    qt[qi]=rint();qv[qi]=rint();
  }
  vi lov(qn+1),hiv(qn+1);
  {
    bitset<me> bei; bei.set();
    for (int qi=qn;qi>=1;qi--) {
      if (qt[qi]==2) {
        int ei=qv[qi]; bei[ei]=false;
      }
    }
    for (int ei=1;ei<=ne;ei++) {
      if (bei[ei]) uf.funion(ve[ei].fst,ve[ei].snd);
    }
    for (int qi=qn;qi>=1;qi--) {
      if (qt[qi]==2) {
        int ei=qv[qi];
        uf.funion(ve[ei].fst,ve[ei].snd);
      } else {
        int v=qv[qi];
        lov[qi]=uf.getLoV(v);
        hiv[qi]=uf.getHiV(v);
      }
    }
    vi remv;
    for (int v=1;v<=nv;v++) {
      if (uf.ffind(v)==v) remv.PB(v);
    }
    int sz=remv.size();
    for (int i=1;i<sz;i++) {
      uf.funion(remv[i-1],remv[i]);
    }
  }
  vi pos2v=uf.getData(1);
  vi v2pos(nv+1);
  seg.init(nv);
  for (int pos=0;pos<nv;pos++) {
    int v=pos2v[pos];
    v2pos[v]=pos;
    seg.t[nv+pos]=MP(v2label[v],v);
  }
  seg.build();
  for (int qi=1;qi<=qn;qi++) {
    if (qt[qi]==1) {
      pii pans=seg.query(v2pos[lov[qi]],v2pos[hiv[qi]]);
      int label=pans.fst,v=pans.snd;
      printf("%d\n",label);
      seg.sset(v2pos[v],MP(0,v));
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