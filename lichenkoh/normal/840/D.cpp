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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int mn=3e5+2;


vi v2i[mn];
int ask(int l, int r, int val) {
  auto &v=v2i[val];
  int ansl,ansr;
  {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<l) imin=imid+1;
      else imax=imid;
    }
    ansl=imin;
  }
  {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<=r) imin=imid+1;
      else imax=imid;
    }
    ansr=imin;
  }
  return ansr-ansl;
}

bool cmp(const pii &a, const pii &b) {
  return a.fst>b.fst;
}

template <typename LST, int _MAXSIZE> struct LimitedVec  {
  static const int mn=_MAXSIZE;
  LST a[_MAXSIZE];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
  int size() {
    return sz;
  }
  LST operator [](int i) const    {return a[i];}
  LST & operator [](int i) {return a[i];}
};

typedef struct _S {
  int a[5];
  int l,r;
} S;

template<int _MAXSEG> class SegTree {
public:
  static const int MAXSEG = _MAXSEG;  // limit for array size
  int segn=_MAXSEG;  // array size
  S t[2 * MAXSEG];
  S identity;
  LimitedVec<int,10> b;
  LimitedVec<pii,10> have;
  LimitedVec<int,20*2*5> vans;
  void combine(S & res, const S& lefts, const S& rights) {
    b.clear();
    for (int i=0;i<5;i++) {
      if (lefts.a[i]==UNDEF) break;
      b.PB(lefts.a[i]);
    }
    for (int i=0;i<5;i++) {
      if (rights.a[i]==UNDEF) break;
      b.PB(rights.a[i]);
    }
    sort(b.begin(),b.end(),greater<int>());
    auto it=unique(b.begin(),b.end());
    b.sz=it-b.begin();
    res.l=lefts.l; res.r=rights.r;
    memset(res.a,-1,sizeof res.a);
    if (b.sz<=5) {
      for (int i=0;i<b.sz;i++) {res.a[i]=b[i];}
    }
    else {
      have.clear();
      for (int i=0;i<b.sz;i++) {
        have.PB(MP(ask(lefts.l,rights.r,b[i]),b[i]));
      }
      sort(have.begin(),have.end(), cmp);
      for (int i=0;i<min(have.sz,5);i++) {
        res.a[i]=have[i].snd;
      }
    }
  }
  void init(int n) {segn=n; memset(identity.a, 0, sizeof identity.a);}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) combine(t[i], t[i<<1], t[i<<1|1]);
  }

  void query(int l, int r) { // sum on interval [l, r]
    r++;
    int n=segn;
    vans.clear();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        for (int i=0;i<5;i++) {
          if (t[l].a[i]==UNDEF) break;
          vans.PB(t[l].a[i]);
        }
        l++;
      }
      if (r&1) {
        --r;
        for (int i=0;i<5;i++) {
          if (t[r].a[i]==UNDEF) break;
          vans.PB(t[r].a[i]);
        }
      }
    }
    sort(vans.begin(),vans.end());
    auto it=unique(vans.begin(),vans.end());
    vans.sz=it-vans.begin();
  }
};
SegTree<mn> seg;


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),q=rint();
  seg.init(n+1);
  for (int i=1;i<=n;i++) {
    int x=rint();
    v2i[x].PB(i);
    S &s=seg.t[seg.segn+i];
    memset(s.a,-1,sizeof s.a);
    s.a[0]=x;
    s.l=i; s.r=i;
  }
  seg.build();
  for (int i=0;i<q;i++) {
    int l=rint(),r=rint(),k=rint();
    seg.query(l,r);
    int need=(r-l+1+1+k-1)/k;
    int ans=-1;
    for (auto &x:seg.vans) {
      if (ask(l,r,x)>=need) {
        ans=x;
        break;
      }
    }
    printf("%d\n",ans);
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