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
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

const int mn=(2e5)+2;
typedef int STV;
typedef int STD;
STV seginit[mn];
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
    return seginit[i];
  }

  STV getNeutralValue() {
    return INT_MIN;
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
    if (from>to) return getNeutralValue();
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
    if (from>to) return;
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

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int na=rint(),nb=rint(),m=rint();
  map<int,int> ah;
  int amin=INF;
  for (int i=0;i<na;i++) {
    int p=rint(),c=rint();
    if (ah.count(p)) {
      chkmin(ah[p],c);
    } else {
      ah[p]=c;
    }
    chkmin(amin,c);
  }
  int bmin=INF;
  map<int,int> bh;
  for (int i=0;i<nb;i++) {
    int p=rint(),c=rint();
    if (bh.count(p)) {
      chkmin(bh[p],c);
    } else {
      bh[p]=c;
    }
    chkmin(bmin,c);
  }
  map<int,vpii> hm;
  for (int i=0;i<m;i++) {
    int a=rint(),b=rint(),c=rint();
    hm[b].PB(MP(a,c));
  }
  na=ah.size();
  nb=bh.size();
  vpii va,vb; vi vaonly;
  for (auto &w:ah) {
    va.PB(w);
    vaonly.PB(w.fst);
  }
  for (auto &w:bh) {
    vb.PB(w);
  }
  for (int a=0;a<na;a++) {
    seginit[a]=-va[a].snd;
  }
  SegmentTreeFast seg(na);
  auto it=hm.begin();
  ll final=-(amin+(ll)bmin);
  for (int b=0;b<nb;b++) {
    int bp=vb[b].fst,bc=vb[b].snd;
    //printf("bp:%d bc:%d\n",bp,bc);
    while(it!=hm.end()) {
      int mb=it->fst;
      if (mb>=bp) break;
      for (auto &ac:it->snd) {
        int ma=ac.fst,coins=ac.snd;
        //printf("Add monster mb:%d pa:%d coins:%d\n",mb,ma,coins);
        seg.modify(bins(vaonly,ma+1), na-1, coins);
      }
      ++it;
    }
    /*for (int a=0;a<na;a++) {
      printf("a:%d seg:%d\n",a,seg.query(a,a));
    }*/
    ll gota=seg.query(0,na-1);
    ll cand=gota-(ll)bc;
    //printf("Seg got:%d cand:%lld\n",gota,cand);
    chkmax(final,cand);
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