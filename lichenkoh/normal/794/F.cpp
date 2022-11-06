#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

const int mn=1e5+2;
int inp[mn];
const int maxd=10;
typedef struct STTV {
  ll a[maxd];
  bool operator== (const STTV &c1) {
    for (int i=0;i<10;i++) if (a[i]!=c1.a[i]) return false;
    return true;
  }
  bool operator!= (const STTV &c1) {
   return !(*this == c1);
  }
} STV;
typedef struct STTD {
  int a[maxd];
  int ts;
  bool operator== (const STTD &c1) {
    for (int i=0;i<maxd;i++) if (a[i]!=c1.a[i]) return false;
    return true;
  }
  bool operator!= (const STTD &c1) {
   return !(*this == c1);
  }
} STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    STV ans;
    //ans.val=x.val + y.val;
    memset(ans.a,0,sizeof ans.a);
    for (int d=0;d<maxd;d++) ans.a[y.a[d]]+=x.a[d];
    return ans;
  }

  // query (or combine) operation
  STV queryOperation(STV leftValue, STV rightValue) {
    STV ans;
    //ans.val=leftValue.val + rightValue.val;
    for (int d=0;d<maxd;d++) ans.a[d]=leftValue.a[d]+rightValue.a[d];
    return ans;
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
    STD ans;
    ans.ts=-1;
    for (int d=0;d<maxd;d++) ans.a[d]=d;
    return ans;
  }

  bool isNeutralDelta(STD delta) {
    return delta.ts==-1;
  }

  STV getInitValue(int i) {
    STV ans;
    memset(ans.a,0,sizeof ans.a);
    ll x=inp[i];
    int pten=1;
    while(x>0) {
      int d=x%10;
      ans.a[d]+=pten;
      x/=10;
      pten*=10;
    }
    return ans;
  }

  STV getNeutralValue() {
    STV ans;
    memset(ans.a,0,sizeof ans.a);
    return ans;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    if (isNeutralDelta(delta1)) return delta2;
    if (isNeutralDelta(delta2)) return delta1;
    if (delta1.ts>delta2.ts) swap(delta1, delta2);
    STD ans;
    memset(ans.a,0,sizeof ans.a);
    for (int d=0;d<maxd;d++) {
      ans.a[d]=delta2.a[delta1.a[d]];
    }
    ans.ts=max(delta1.ts, delta2.ts);
    return ans;
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

int readInt()
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

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),q=readInt();
  for (int i=0;i<n;i++) inp[i]=readInt();
  SegmentTreeFast segt = SegmentTreeFast(n);
  for (int ts=1;ts<=q;ts++) {
    int t=readInt(),l=readInt()-1,r=readInt()-1;
    if (t==1) {
      int x=readInt(),y=readInt();
      STD delta;
      delta.ts=ts;
      for (int d=0;d<maxd;d++) delta.a[d]=d;
      delta.a[x]=y;
      segt.modify(l,r,delta);
    }
    else {
      STV ans=segt.query(l,r);
      ll final=0;
      for (int d=1;d<maxd;d++) {
        final+=d*ans.a[d];
      }
      printf("%lld\n",final);
    }
  }
}