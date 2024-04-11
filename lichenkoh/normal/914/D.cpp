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

const int MAXSZ=200*(1<<20);
char prealloc[MAXSZ];
int preidx=0;
void * operator new(size_t size) {
  int oldidx=preidx;
  preidx+=(((int)size) + 7) & ~0x07;
  return (void *)(&prealloc[oldidx]);
}
void free (void* ptr) {
  return;
}

typedef struct _S {
  int g;
  vi v;
} S;
inline void makeunique(vector<int> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}
template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  S t[2 * SEGSZ];
  S identity;
  S combine(const S& l, const S& r) {
    if (l.g==0) return r;
    if (r.g==0) return l;
    int lg=abs(l.g),rg=abs(r.g);
    S ans;
    ans.g=__gcd(lg,rg);
    if (l.g<0) {ans.v.PB(rg);}
    if (r.g<0) {ans.v.PB(lg);}
    for (auto &x:l.v) {
      ans.v.PB(__gcd(x,rg));
    }
    for (auto &x:r.v) {
      ans.v.PB(__gcd(x,lg));
    }
    makeunique(ans.v);
    /*for (auto &w:l.v) {
      printf("%d ",w);
    }
    printf(" and lg:%d\n",l.g);
    for (auto &w:r.v) {
      printf("%d ",w);
    }
    printf(" and rg:%d\n",r.g);
    for (auto &w:ans.v) {
      printf("%d ",w);
    }
    printf(" and g:%d\n",ans.g);*/
    return ans;
  }
  void init(int n) {segn=n;
    identity.g=0;
  }
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
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

bool bins(vector<int> &vx, int x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin<vx.size() && vx[imin]==x;
}

const int mn=500000;
SegTree<mn> seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  seg.init(n);
  for (int i=0;i<n;i++) {
    seg.t[n+i].g=-rint();
  }
  seg.build();
  int q=rint();
  for (int qi=0;qi<q;qi++) {
    int t=rint();
    if (t==1) {
      int l=rint()-1,r=rint()-1,x=rint();
      S got=seg.query(l,r);
      bool ans=(l==r||(got.g%x==0));
      if (!ans) {
        for (auto &y:got.v) {
          if (y%x==0) {ans=true; break;}
        }
      }
      if (ans) {
        printf("YES\n");
      }
      else printf("NO\n");
    }
    else {
      int idx=rint()-1,y=rint();
      S put; put.g=-y;
      seg.sset(idx,put);
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