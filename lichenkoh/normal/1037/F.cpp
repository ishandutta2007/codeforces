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
const int mn=1e6+1;


typedef ll STV;
typedef ll STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return max(x,y);
  }

  // query (or combine) operation
  STV queryOperation(STV leftValue, STV rightValue) {
    return leftValue+rightValue;
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    if (isNeutralDelta(delta)) return getNeutralDelta();
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    //ans.val=delta.val*segmentLength;
    return delta;
  }

  STD initNeutralDelta() {
    return LLONG_MIN;
  }

  bool isNeutralDelta(STD delta) {
    return delta==LLONG_MIN;
  }

  STV getInitValue(int i) {
    return 0;
  }

  STV getNeutralValue() {
    return 0;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return max(delta1,delta2);
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
    for (int i = 2 * n - 1; i > 1; i -= 2) {
      value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
    }
    delta = new STD[2 * n];
    fill(delta, delta + (2*n), getNeutralDelta());
  }

  void clear(int n) {
    for (int i = 0; i < n; i++) {
      value[i + n] = getInitValue(i);
    }
    for (int i = 2 * n - 1; i > 1; i -= 2) {
      value[i >> 1] = queryOperation(value[i], value[i ^ 1]);
    }
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
    STV res = getNeutralValue();
    bool found = false;
    for (int len = 1; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        res = found ? queryOperation(res, joinNodeValueWithDelta(from, len)) : joinNodeValueWithDelta(from, len);
        found = true;
      }
      if ((to & 1) == 0) {
        res = found ? queryOperation(res, joinNodeValueWithDelta(to, len)) : joinNodeValueWithDelta(to, len);
        found = true;
      }
    }
    if (!found) assert(0);
    return res;
  }

  void modify(int from, int to, STD delta) {
    printf("from:%d to:%d delta:%lld\n",from,to,delta);
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
      value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
    }
    for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
      value[i >> 1] = queryOperation(joinNodeValueWithDelta(i, len), joinNodeValueWithDelta(i ^ 1, len));
    }
  }
};





template <typename E>
std::vector<E> computeSlidingWindowMinOrMax(const std::vector<E> &array, std::size_t window, bool maximize) {
  if (window == 0)
    throw std::domain_error("Window size must be positive");
  
  std::vector<E> result;
  std::deque<E> deque;
  std::size_t countdown = window - 1;
  typename std::vector<E>::const_iterator tail = array.cbegin();
  for (const E &val : array) {
    while (!deque.empty() && ((!maximize && val < deque.back()) || (maximize && val > deque.back())))
      deque.pop_back();
    deque.push_back(val);
    
    if (countdown > 0)
      countdown--;
    else {
      result.push_back(deque.front());
      if (*tail == deque.front())
        deque.pop_front();
      ++tail;
    }
  }
  return result;
}


class MaxGo {
public:
  vector<pll> v;
  ll sum=0;
  void push_back(ll x) {
    sum+=x;
    v.PB(MP(x,1));
  }
  void setmax(ll x) {
    ll cnt=0;
    while(v.size()>0) {
      if (v.back().fst<=x) {
        sum+=v.back().snd * (x-v.back().fst);
        cnt+=v.back().snd;
        v.pop_back();
      }
      else break;
    }
    v.PB(MP(x,cnt));
  }
};


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),k=rint();
  vi inp(n);
  for (int i=0;i<n;i++) inp[i]=rint();
  int t=k-1; assert(t>=1);
  vi slidingT=computeSlidingWindowMinOrMax(inp,t,true);
  //for (auto &w:slidingT) printf("%d ",w); printf("\n");
  int segn=((n+t-1)/t) + 1;
  
  int final=0;
  for (int sp=n-1;sp>=n-t;sp--) {
    //printf("sp:%d\n",sp);
    MaxGo g;
    //int segl=segn-1;
    g.PB(inp[sp]);
    int ans=0;
    for (int p=sp-t;p>=0;p-=t) {
      g.setmax(slidingT[p]);
      ll got=g.sum;
      //printf("p:%d got:%lld slidingT[p]:%d\n",p,got,slidingT[p]);
      //printf("Modify: %d %d %d\n",segl-1,segl-1,inp[p]);
      g.PB(inp[p]);
      ans=(ans+got)%MOD;
    }
    final+=ans;
    if (final>=MOD) final-=MOD;
  }
  printf("%d\n",final);
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