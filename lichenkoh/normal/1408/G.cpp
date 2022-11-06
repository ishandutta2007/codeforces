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
const int mn=1508;
int a[mn][mn];
const int mw=(mn*(mn-1))/2;
pii w2xy[mw+1];
int w2jumpe[mw+1];
int w2combv[mw+1];
class UnionFind {
public:
  vi ufParent;
  vvi edges;
  vvi vtx;
  vi whi;
  inline void combine(int dest, int src) {
    int hi=max(whi[dest],whi[src]);
    for (auto &x:vtx[src]) for (auto &y:vtx[dest]) chkmax(hi, a[x][y]);
    whi[dest]=hi;

    for (auto &w:vtx[src]) {vtx[dest].PB(w);}
    vtx[src].clear();

    for (auto &w:edges[src]) {edges[dest].PB(w);}
    edges[src].clear();
  }
  inline void ufreset(int x) {
    ufParent[x]=x;
    vtx[x].PB(x);
  }
  void init(int n) {
    ufParent.resize(n); edges.resize(n); vtx.resize(n); whi.resize(n);
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
    int src = ffind(_x);
    int dest = ffind(_y);
    if (src==dest) return false;
    if (vtx[dest].size() < vtx[src].size()) {
      swap(dest,src);
    }
    ufParent[src] = dest;
    combine(dest,src);
    return true;
  }
  vi & getEdges(int x) {
    return edges[ffind(x)];
  }
  void addEdge(int x, int w) {
    int xr=ffind(x);
    if (w>=whi[xr]) {      
      whi[xr]=w;
      edges[xr].PB(w);
      w2jumpe[w]=edges[xr].size();
      w2combv[w]=((int)vtx[xr].size())-1;
      //printf("addEdge w:%d old_whi:%d jump:%d\n",w,whi[xr],w2jumpe[w]);
    }
  }
};
UnionFind uf;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  uf.init(n);
  for (int x=0;x<n;x++) {
    for (int y=0;y<n;y++) {
      int w=rint();
      a[x][y]=w;
      if (x<y) {
        w2xy[w]=MP(x,y);
      }
    }
  }
  int wlim=(n*(n-1))/2;
  for (int w=1;w<=wlim;w++) {
    int x=w2xy[w].fst,y=w2xy[w].snd;
    bool combined=uf.funion(x,y);
    /*if (combined) {
      printf("Real union %d %d w:%d\n",x,y,w);
    } else {
      printf("Fake union %d %d w:%d\n",x,y,w);
    }*/
    uf.addEdge(x,w);
  }
  vi ve=uf.getEdges(0);
  int esz=ve.size();
  reverse(ve.begin(),ve.end());
  vvi f(esz+1); f[0].resize(1);
  f[0][0]=1;
  //printf("esz:%d\n",esz);
  for (int e=0;e<esz;e++) {
    int w=ve[e];
    int jump=w2jumpe[w];
    int comb=w2combv[w];
    //printf("x:%d y:%d w:%d jump:%d comb:%d\n",w2xy[w].fst,w2xy[w].snd,w,jump,comb);
    size_t fsz=f[e].size();
    f[e+1].resize(max(f[e+1].size(), fsz));
    f[e+jump].resize(max(f[e+jump].size(), fsz+comb+1));
    for (int c=0;c<fsz;c++) {
      int now=f[e][c];
      if (now) {
        f[e+1][c]+=now;
        if (f[e+1][c]>=MOD) f[e+1][c]-=MOD;
        f[e+jump][c+comb]+=now;
        if (f[e+jump][c+comb]>=MOD) f[e+jump][c+comb]-=MOD;
      }
    }
  }
  {
    /*for (int c=0;c<f[esz].size();c++) {
      printf("f[%d][%d] = %d\n",esz,c,f[esz][c]);
    }*/
    f[esz].resize(n);
    for (int g=1;g<=n;g++) {
      int comb=n-g;
      printf("%d ",f[esz][comb]);
    }
    printf("\n");
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