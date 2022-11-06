#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=3e5+4;
vi g[mn];
int inp[2][mn];

template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef ll S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void build(int n) {  // build the tree
    segn=n;
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
SegTree<mn> seg[2], oseg;
int r2seg[mn];
vector<pii> seg2r;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  for (int i=0;i<n;i++) {
    for (int t=0;t<2;t++) {
      int got=rint();
      inp[t][i]=got;
    }
    seg2r.PB(MP(inp[0][i]-inp[1][i],i));
  }
  sort(seg2r.begin(),seg2r.end());
  for (int i=0;i<n;i++) {
    r2seg[seg2r[i].snd]=i;
    oseg.t[n+i]=1;
  }
  oseg.build(n);
  for (int t=0;t<2;t++) {
    for (int i=0;i<n;i++) {
      seg[t].t[n+i]=inp[t][seg2r[i].snd];
    }
    seg[t].build(n);
  }
  for (int i=0;i<m;i++) {
    int a=rint()-1,b=rint()-1; g[a].PB(b); g[b].PB(a);
  }
  /*for (int r=0;r<n;r++) {
    printf("r:%d seg:%d\n",r,r2seg[r]);
  }*/
  for (int a=0;a<n;a++) {
    for (auto &b:g[a]) {
      int segb=r2seg[b];
      for (int t=0;t<2;t++) seg[t].sset(segb,0);
      //printf("Zero out segb:%d\n",segb);
      oseg.sset(segb,0);
    }

    int mexy=inp[0][a]-inp[1][a];

    int imin=0,imax=n;
    while(imin<imax) {int imid=(imin+imax)>>1;if (seg2r[imid].fst<mexy) imin=imid+1;else imax=imid;}
    ll ansL=inp[1][a]*oseg.query(0,imin-1)+seg[0].query(0,imin-1);
    ll ansR=inp[0][a]*oseg.query(imin,n-1)+seg[1].query(imin,n-1);
    ll final=ansR+ansL-(inp[0][a]+inp[1][a]);
    //printf("imin:%d ansL:%lld=%lld+%lld\n",imin,ansL,inp[1][a]*oseg.query(0,imin-1),seg[0].query(0,imin-1));
    printf("%lld ",final);
    for (auto &b:g[a]) {
      int segb=r2seg[b];
      for (int t=0;t<2;t++) seg[t].sset(segb,inp[t][b]);
      oseg.sset(segb,1);
    }
  }
  printf("\n");
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