#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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
const bool DBG=0;
string dest;
using STV=int;
using STD=int;
template<size_t MAXSIZE> class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV const& x, STD const& y) {
    return y;
  }

  // query (or combine) operation
  STV queryOperation(STV const& l, STV const& r) {
    return l+r;
  }

  STD deltaEffectOnSegmentUser(STD const& delta, int segmentLength) {
    return delta*segmentLength;
  }

  STD initNeutralDelta() {
    return INT_MIN;
  }

  bool isNeutralDelta(STD const& delta) {
    return delta==INT_MIN;
  }

  STV getInitValue(int i) {
    return dest[i]-'0';
  }

  STV getNeutralValue() {
    return 0;
  }

  STD joinDeltasUser(STD const& earlydelta, STD const& laterdelta) {
    return laterdelta;
  }

  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  STV value[MAXSIZE*4];
  STD delta[MAXSIZE*4]; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int gn;

  STD deltaEffectOnSegment(STD const& delta, int segmentLength) {
    if (isNeutralDelta(delta)) return delta;
    return deltaEffectOnSegmentUser(delta, segmentLength);
  }

  STD joinDeltas(STD const& earlydelta, STD const& laterdelta) {
    if (isNeutralDelta(laterdelta)) return earlydelta;
    return joinDeltasUser(earlydelta,laterdelta);
  }

  STV joinValueWithDelta(STV const& value, STD const& delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }


  void pushDelta(int root, int left, int right) {
    value[root] = joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
    delta[2 * root + 1] = joinDeltas(delta[2 * root + 1], delta[root]);
    delta[2 * root + 2] = joinDeltas(delta[2 * root + 2], delta[root]);
    delta[root] = getNeutralDelta();
  }

  void init(int n) {
    _cache_neutral_delta = initNeutralDelta();
    gn = n;
    init(0, 0, n - 1);
  }

  void init(int root, int left, int right) {
    if (left == right) {
      value[root] = getInitValue(left);
      delta[root] = getNeutralDelta();
    } else {
      int mid = (left + right) >> 1;
      init(2 * root + 1, left, mid);
      init(2 * root + 2, mid + 1, right);
      value[root] = queryOperation(value[2 * root + 1], value[2 * root + 2]);
      delta[root] = getNeutralDelta();
    }
  }

  STV query(int from, int to) {
    int n=gn;
    return query(from, to, 0, 0, n - 1);
  }

  STV query(int from, int to, int root, int left, int right) {
    if (from == left && to == right)
      return joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
    pushDelta(root, left, right);
    int mid = (left + right) >> 1;
    if (from <= mid && to > mid)
      return queryOperation(
          query(from, min(to, mid), root * 2 + 1, left, mid),
          query(max(from, mid + 1), to, root * 2 + 2, mid + 1, right));
    else if (from <= mid)
      return query(from, min(to, mid), root * 2 + 1, left, mid);
    else if (to > mid)
      return query(max(from, mid + 1), to, root * 2 + 2, mid + 1, right);
    else
      assert(0);
  }

  void modify(int from, int to, STD delta) {
    //printf("from:%d to:%d\n",from,to);
    modify(from, to, delta, 0, 0, gn - 1);
  }

  void modify(int from, int to, STD delta, int root, int left, int right) {
    if (from == left && to == right) {
      this->delta[root] = joinDeltas(this->delta[root], delta);
      return;
    }
    pushDelta(root, left, right);
    int mid = (left + right) >> 1;
    if (from <= mid)
      modify(from, min(to, mid), delta, 2 * root + 1, left, mid);
    if (to > mid)
      modify(max(from, mid + 1), to, delta, 2 * root + 2, mid + 1, right);
    value[root] = queryOperation(
        joinValueWithDelta(value[2 * root + 1], deltaEffectOnSegment(this->delta[2 * root + 1], mid - left + 1)),
        joinValueWithDelta(value[2 * root + 2], deltaEffectOnSegment(this->delta[2 * root + 2], right - mid)));
  }
};



const int mn=(2e5)+4;
SegmentTreeFast<mn> seg;
bool go() {
  int n,qn; string s; cin>>n>>qn>>s>>dest;
  vpii vq(qn);
  for (int i=0;i<qn;i++) cin>>vq[i].fst>>vq[i].snd;
  seg.init(n);
  for (int qi=qn-1;qi>=0;qi--) {
    int l=vq[qi].fst-1,r=vq[qi].snd-1;
    int ones=seg.query(l,r);
    if (DBG)printf("qi:%d l:%d r:%d ones:%d\n",qi,l,r,ones);
    int len=r-l+1;
    if (len%2==0 && ones == len/2) return false;
    if (ones <= len/2) {
      seg.modify(l,r,0);
      if (DBG)printf("Set to 0\n");
    } else {
      seg.modify(l,r,1);
      if (DBG)printf("Set to 1\n");
    }
  }
  for (int x=0;x<n;x++) {
    int got=seg.query(x,x);
    if (got!=s[x]-'0') return false;
  }
  return true;
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin>>t; for (int i=0;i<t;i++) {
    bool ans=go();
    printf(ans?"YES\n":"NO\n");
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