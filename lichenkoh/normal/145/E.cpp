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

const int mn=1e6+2;
string inp;
typedef struct STTV {
  int x,y,xy,yx;
} STV;
typedef bool STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    STV ans=x;
    if (y) {
      swap(ans.x,ans.y); swap(ans.xy,ans.yx);
    }
    return ans;
  }

  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
    STV ans;
    ans.x=l.x+r.x;
    ans.y=l.y+r.y;
    int gen=max(ans.x,ans.y);
    ans.xy=max(gen,max(l.xy+r.y,l.x+r.xy));
    ans.yx=max(gen,max(l.yx+r.x,l.y+r.yx));
    //ans.xy=max(max(gen,l.x+r.y),max(l.xy,r.xy));
    //ans.yx=max(max(gen,l.y+r.x),max(l.yx,r.yx));
    //printf("l:%d %d r:%d %d xy:%d\n",l.x,l.y,r.x,r.y,ans.xy);
    return ans;
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    return delta;
  }

  STD initNeutralDelta() {
    return false;
  }

  bool isNeutralDelta(STD delta) {
    return !delta;
  }

  STV getInitValue(int i) {
    STV ans;
    if (inp[i]=='4') {
      ans.x=1; ans.y=0;
    }
    else {
      ans.x=0; ans.y=1;
    }
    //printf("i:%d x:%d y:%d\n",i,ans.x,ans.y);
    ans.xy=ans.yx=1;
    return ans;
  }

  STV getNeutralValue() {
    STV ans;ans.x=ans.y=ans.xy=ans.yx=0;
    return ans;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1!=delta2;
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


int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; cin>>n>>m;
  cin>>inp;
  SegmentTreeFast segt = SegmentTreeFast(n);
  for (int i=0;i<m;i++) {
    string t; cin>>t;
    if (t[0]=='c') {
      //int l,r; cin>>l>>r;
      int l=1,r=n;
      int ans=segt.query(l-1,r-1).xy;
      printf("%d\n",ans);
    }
    else {
      int l,r; cin>>l>>r;
      segt.modify(l-1,r-1,true);
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