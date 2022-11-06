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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}


class UnionFind {
public:
typedef int UFTYPE;
UFTYPE ufIdentity = 0;
inline UFTYPE combine(UFTYPE x, UFTYPE y) {
  return x^y;
}
inline UFTYPE getInitialValue(int x) {
  return 0;
}
vi ufParent;
vi rank;
vector<UFTYPE> ufData;
map<int,int> h;
void reset() {
  ufParent.clear();
  rank.clear();
  ufData.clear();
  h.clear();
}
inline void ufreset(int x) {
  ufParent[x]=x;
  ufData[x]=getInitialValue(x);
}
int getid(int x) {
  auto it=h.find(x);
  if (it!=h.end()) {
    return it->snd;
  }
  int id=rank.size();
  ufParent.PB(id);
  rank.PB(0);
  ufData.PB(getInitialValue(x));
  h[x]=id;
  return id;
}
pii ffind(int x) {
  if (ufParent[x] != x) {
    auto got=ffind(ufParent[x]);
    ufParent[x] = got.fst;
    ufData[x] = combine(ufData[x],got.snd);
  }
  return MP(ufParent[x],ufData[x]);
}
void funion(int xr, int yr, int val) {
  assert(ufParent[xr]==xr);
  assert(ufParent[yr]==yr);
  assert(ufData[xr]==0);
  assert(ufData[yr]==0);
  if (xr==yr) return;
  if (rank[xr] > rank[yr]) swap(xr,yr);
  if (rank[xr]==rank[yr]) rank[yr]++;
  ufParent[xr] = yr;
  ufData[xr]=val;
  }
};
UnionFind uf;
bool handleNewSeg(int _l, int _r, int val) {
  int l=uf.getid(_l),r=uf.getid(_r);
  int c[2]; c[0]=l,c[1]=r;
  int p[2],v[2];
    for (int t=0;t<2;t++) {
    pii got=uf.ffind(c[t]);
    p[t]=got.fst; v[t]=got.snd;
      }
  if (p[0]==p[1]) {
    return (v[0]^v[1]) == val;
  }
  else {
    uf.funion(p[0],p[1],v[0]^v[1]^val);
    return true;
  }
}
int query(int _l, int _r) {
  int l=uf.getid(_l),r=uf.getid(_r);
  int c[2]; c[0]=l,c[1]=r;
  int p[2],v[2];
    for (int t=0;t<2;t++) {
    pii got=uf.ffind(c[t]);
    p[t]=got.fst; v[t]=got.snd;
      }
  if (p[0]==p[1]) {
    return v[0]^v[1];
  }
  else {
    return -1;
  }
}

void go() {
  uf.reset();
  int n=rint(); int m=rint();
  bool finalok=true;
  vector<pair<pii,int> > ve;
  for (int i=1;i<n;i++) {
    int x=rint(); int y=rint(); int v=rint();
    ve.PB(MP(MP(x,y),v));
    if (v!=-1) {
      bool ok=handleNewSeg(x,y,__builtin_popcount(v)%2);
            if (!ok) {
                finalok=false;
      }
    }
  }
  for (int i=0;i<m;i++) {
    int x=rint(); int y=rint(); int v=rint();
        bool ok=handleNewSeg(x,y,v);
    if (!ok) {
      finalok=false;
          }
  }
  if (finalok) {
    printf("YES\n");
    for (auto &e:ve) {
      int x=e.fst.fst,y=e.fst.snd,v=e.snd;
      if (v==-1) {
        int got=query(x,y);
        if (got==-1) {
          handleNewSeg(x,y,0);
          printf("%d %d %d\n",x,y,0);
        } else {
          printf("%d %d %d\n",x,y,got);
        }
      } else {
        printf("%d %d %d\n",x,y,v);
      }
    }
  } else {
    printf("NO\n");
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint(); for (int i=0;i<t;i++) go();
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