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


template<int _SEGSZ> class MinSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef pii S;
  S t[2 * SEGSZ];
  const S identity = MP(INF,INF);
  S combine(const S& lefts, const S& rights) {
    return min(lefts,rights);
  }
  S & operator[] (int idx) {return t[segn+idx];}
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  int query(int l, int r) { // sum on interval [l, r]
    if (l>r) return identity.snd;
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr).snd;
  }
};

typedef int STV;
typedef int STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return x+y;
  }

  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
    return max(l,r);
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    return delta;
  }

  STD initNeutralDelta() {
    return 0;
  }

  bool isNeutralDelta(STD delta) {
    return delta==0;
  }

  STV getInitValue(int i) {
    return 0;
  }

  STV getNeutralValue() {
    return 0;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1+delta2;
  }

  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  STV *value;
  STD *delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int gn;

  STV joinValueWithDelta(STV value, STD delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }

  void pushDelta(int i) {
    int d = 0;
    for (; (i >> d) > 0; d++) {
    }
    for (d -= 2; d >= 0; d--) {
      int x = i >> d;
      value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
      delta[x] = joinDeltas(delta[x], delta[x >> 1]);
      delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
      delta[x >> 1] = getNeutralDelta();
    }
  }

  SegmentTreeFast(int n) {
    _cache_neutral_delta = initNeutralDelta();
    gn=n;
    value = new STV[2 * n];
    for (int i = 0; i < n; i++) {
      value[i + n] = getInitValue(i);
    }
    for (int i = n - 1; i > 0; --i) value[i] = queryOperation(value[i<<1], value[i<<1|1]);
    delta = new STD[2 * n];
    fill(delta, delta + (2*n), getNeutralDelta());
  }

  STV joinNodeValueWithDelta(int i, int len) {
    return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
  }

  STV query(int from, int to) {
    from += gn;
    to += gn;
    pushDelta(from);
    pushDelta(to);
    STV resl = getNeutralValue(); STV resr = getNeutralValue();
    bool found = false;
    for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        resl = found ? queryOperation(resl, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
        found = true;
      }
      if ((to & 1) == 0) {
        resr = found ? queryOperation(joinNodeValueWithDelta(to, len), resr) : joinNodeValueWithDelta(to, len);
        found = true;
      }
    }
    STV res=queryOperation(resl,resr);
    if (!found) assert(0);
    return res;
  }

  void modify(int from, int to, STD delta) {
    from += gn;
    to += gn;
    pushDelta(from);
    pushDelta(to);
    int a = from;
    int b = to;
    for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
      if ((from & 1) != 0) {
        this->delta[from] = joinDeltas(this->delta[from], delta);
      }
      if ((to & 1) == 0) {
        this->delta[to] = joinDeltas(this->delta[to], delta);
      }
    }
    for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
      int k=i>>1;
      value[k] = queryOperation(joinNodeValueWithDelta(k<<1, len), joinNodeValueWithDelta((k<<1)|1, len));
    }
    for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
      int k=i>>1;
      value[k] = queryOperation(joinNodeValueWithDelta(k<<1, len), joinNodeValueWithDelta((k<<1)|1, len));
    }
  }
};

const int mn=(4e5)+8;
int a[mn];
int vl[mn],vr[mn];
MinSegTree<mn> segmin;


int initdepth[mn];
void fdepth(int p, int L, int R, int d) {
  initdepth[p]=d;
  int pl=segmin.query(L,p-1);
  int pr=segmin.query(p+1,R);
  if (pl!=segmin.identity.snd) fdepth(pl,L,p-1,d+1);
  if (pr!=segmin.identity.snd) fdepth(pr,p+1,R,d+1);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<n;i++) a[n+i]=a[i];
  {
    vector<pii> v; v.PB(MP(-INF,-1));
    for (int p=0;p<2*n;p++) {
      int imin=0,imax=v.size();
      while(imin<imax) {
        int imid=(imin+imax)/2;
        if (v[imid].fst < a[p]) imin=imid+1;
        else imax=imid;
      }
      v.resize(imin);
      vl[p]=v.back().snd;
      v.PB(MP(a[p],p));
    }
  }
  {
    vector<pii> v; v.PB(MP(-INF,2*n));
    for (int p=2*n-1;p>=0;p--) {
      int imin=0,imax=v.size();
      while(imin<imax) {
        int imid=(imin+imax)/2;
        if (v[imid].fst < a[p]) imin=imid+1;
        else imax=imid;
      }
      v.resize(imin);
      vr[p]=v.back().snd;
      v.PB(MP(a[p],p));
    }
  }

  segmin.init(n);
  for (int p=0;p<n;p++) {
    segmin[p]=MP(a[p],p);
  }
  segmin.build();
  {
    int p1=segmin.query(0,n-1);
    fdepth(p1, 0, n-1, 0);
  }



  SegmentTreeFast segmax(2*n);
  for (int p=0;p<n;p++) {
    segmax.modify(p,p,initdepth[p]);
  }
  pii ans=MP(segmax.query(0,n-1),0);
  /*  for (int x=0;x<n;x++) {
      printf("%d ",segmax.query(x,x));
    }
  printf("\norig cand:%d\n",ans.fst);
  */
  for (int p=0;p<n-1;p++) {
    // Remove p
    {
      int R=p+n-1;
      int r=vr[p];
      //printf("Decrease: %d %d\n",p+1,min(R,r-1));
      segmax.modify(p+1,min(R,r-1),-1);
    }
    // Add p+n
    {
      int l=vl[p+n];
      int pdepth=0;
      if (l>p) {
        pdepth=1+segmax.query(l,l);
      }
      //printf("Set position %d to %d\n",p+n,pdepth);
      segmax.modify(p+n,p+n,pdepth);
      //printf("Increase: %d %d\n",l+1,p+n-1);
      segmax.modify(l+1,p+n-1,1);
    }
    /*printf("Moved position %d to the back\n",p);
    for (int x=p+1;x<=p+1+n-1;x++) {
      printf("%d ",segmax.query(x,x));
    }
    printf("\n");*/
    int cand=segmax.query(p+1,p+1+n-1);
    //printf("p:%d cand:%d\n",p,cand);
    chkmin(ans,MP(cand,p+1));
  }
  ans.fst++;
  printf("%d %d\n",ans.fst,ans.snd);

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