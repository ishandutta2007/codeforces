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
const int MOD=1000000007;
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
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

class UnionFind {
public:
  vi ufParent;
  vi rank;
  int live;
  inline void ufreset(int x) {
    ufParent[x]=x;
    rank[x]=0;
  }
  void init(int n) {
    ufParent.resize(n);
    rank.resize(n);
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  bool funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return false;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    live--;
    return true;
  }
};
const int mn=int(2e5)+4;
vector<set<int> > g;
vector<pair<int,pii> > ve;
const int mk=4096;
bitset<mk> h[mk];
vvi id2v;
UnionFind uf;
int comp[mn],invcomp[mn];

pair<ll,bool> solveUnsetFirst(int n, int allw) {
  int m=ve.size();
  vi sortedv(n); for (int x=1;x<=n;x++) sortedv[x-1]=x;
  sort(sortedv.begin(),sortedv.end(),[&](int x,int y) {return g[x].size()<g[y].size();});
  uf.init(n+1);
  uf.live=n;
  mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
  while(uf.live>=mk) {
    int b=uniform_int_distribution<int>(1,n-1)(rng);
    int a=uniform_int_distribution<int>(0,b-1)(rng);
    int x=sortedv[a],y=sortedv[b];
    if (x>y) swap(x,y);
    if (!g[x].count(y)) {
      uf.funion(x,y);
      sortedv.pop_back();
    }
  }
  {
    int id=0;
    for (int x=1;x<=n;x++) {
      if (x==uf.ffind(x)) {
        comp[x]=id;
        invcomp[id]=x;
        ++id;
      }
    }
  }
  id2v.resize(uf.live);
  for (int x=1;x<=n;x++) {
    int r=comp[uf.ffind(x)];
    id2v[r].PB(x);
  }
  for (int r=0;r<id2v.size();r++) {
    if (id2v[r].size()==0) continue;
    map<int,int> cnt;
    for (auto &x:id2v[r]) {
      for (auto &y:g[x]) {
        int ry=comp[uf.ffind(y)];
        ++cnt[ry];
      }
    }
    for (auto &w:cnt) {
      if (w.snd==id2v[r].size()*ll(id2v[w.fst].size())) {
        h[r][w.fst]=true;
        h[w.fst][r]=true;
      } 
    }
  }
  for (int x=0;x<id2v.size();x++) for (int y=0;y<x;y++) {
    if (!h[x][y]) {
      uf.funion(invcomp[x],invcomp[y]);
    }
  }
  bool mustUseAllUnset=false;
  //printf("Shrunk:%d unset:%lld\n",n-uf.live,(n*ll(n-1))/2 - m);
  if (n-uf.live == (n*ll(n-1))/2 - m) mustUseAllUnset=true;
  ll final=0;
  if (mustUseAllUnset) final+=allw;
  for (auto &we:ve) {
    int w=we.fst,x=we.snd.fst,y=we.snd.snd;
    if (uf.funion(x,y)) {
      final+=w;
    }
  }
  assert(uf.live==1);
  return MP(final,mustUseAllUnset);
}

ll solveSetOne(int n, int allw) {
  vpii unsetEdges;
  for (int x=1;x<=n;x++) for (int y=x+1;y<=n;y++) {
    if (g[x].count(y)==0) unsetEdges.PB(MP(x,y));
  }
  ll bigfinal=LLONG_MAX;
  for (int si=0;si<unsetEdges.size();si++) {
    uf.init(n+1);
    uf.live=n;
    for (int i=0;i<si;i++) uf.funion(unsetEdges[i].fst,unsetEdges[i].snd);
    for (int i=si+1;i<unsetEdges.size();i++) uf.funion(unsetEdges[i].fst,unsetEdges[i].snd);
    ll final=0;
    for (auto &we:ve) {
      int w=we.fst,x=we.snd.fst,y=we.snd.snd;
      if (w>allw) {
        if (uf.funion(unsetEdges[si].fst, unsetEdges[si].snd)) final+=allw;
      }
      if (uf.funion(x,y)) {
        final+=w;
      }
    }
    if (uf.funion(unsetEdges[si].fst, unsetEdges[si].snd)) final+=allw;
    assert(uf.live==1);
    chkmin(bigfinal,final);
  }
  return bigfinal;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  g.resize(n+1);
  int allw=0;
  for (int i=0;i<m;i++) {
    int x=rint(); int y=rint(); int w=rint();
    allw^=w;
    ve.PB(MP(w,MP(x,y)));
    g[x].insert(y);
    g[y].insert(x);
  }
  sort(ve.begin(),ve.end());
  auto got=solveUnsetFirst(n,allw);
  ll final=got.fst;
  if (got.snd) {
    chkmin(final, solveSetOne(n,allw));
  }
  printf("%lld\n",final);
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