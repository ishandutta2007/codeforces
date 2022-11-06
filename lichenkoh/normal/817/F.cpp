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
const int INF=1<<25;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

const int SET=1,RST=2,FLIP=3;

typedef pair<int,int> STV;
typedef pair<int,int> STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    if (y.fst==SET) return MP(x.snd,x.snd);
    else if (y.fst==RST) return MP(0,x.snd);
    else if (y.fst==FLIP) return MP(x.snd-x.fst,x.snd);
    else return x;
  }

  // query (or combine) operation
  STV queryOperation(STV leftValue, STV rightValue) {
    return MP(leftValue.fst+rightValue.fst,leftValue.snd+rightValue.snd);
  }

  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    if (isNeutralDelta(delta)) return delta;
    // Here you must write a fast equivalent of following slow code:
    // int result = delta;
    // for (int i = 1; i < segmentLength; i++) result = queryOperation(result, delta);
    // return result;
    //ans.val=delta.val*segmentLength;
    return delta;
  }

  STD initNeutralDelta() {
    return MP(0,0);
  }

  bool isNeutralDelta(STD delta) {
    return delta.fst==0;
  }

  STV getInitValue(int i) {
    return MP(0,1);
  }

  STV getNeutralValue() {
    return MP(0,0);
  }

  STD joinDeltas(STD delta1, STD delta2) {
    if (isNeutralDelta(delta1)) return delta2;
    if (isNeutralDelta(delta2)) return delta1;
    if (delta1.snd>delta2.snd) swap(delta1, delta2);
    // delta1 came first, delta2 came later
    if (delta2.fst==SET||delta2.fst==RST) return delta2;
    else if (delta2.fst==FLIP) {
      int ts=max(delta1.snd,delta2.snd);
      if (delta1.fst==FLIP) return MP(0, ts);
      else if (delta1.fst==SET) return MP(RST, ts);
      else if (delta1.fst==RST) return MP(SET, ts);
      else assert(0);
    }
    else assert(0);
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


const int mn=100004;
int vt[mn];
ll vl[mn],vr[mn];
ll vsrc[4*mn+1],vdest[4*mn+1];
int vdestsz;
void uniq(int n) {
  sort(vsrc,vsrc+n);
  vdest[0]=vsrc[0];
  int k=1;
  for (int i=1;i<n;i++) {
    if (vsrc[i]!=vsrc[i-1]) {
      vdest[k++]=vsrc[i];
    }
  }
  vdestsz=k;
}
int bins(ll key) {
  int imin=0,imax=vdestsz;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vdest[imid]<key) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; scanf("%d",&n);
  for (int i=0;i<n;i++) {
    int t; ll l,r; scanf("%d%lld%lld",&t,&l,&r);
    vt[i]=t;
    vl[i]=l;
    vr[i]=r;
    vsrc[i*4]=l;
    vsrc[i*4+1]=l+1;
    vsrc[i*4+2]=r;
    vsrc[i*4+3]=r+1;
  }
  vsrc[4*n]=1;
  uniq(4*n+1);
  SegmentTreeFast segt = SegmentTreeFast(vdestsz+1);
  for (int i=0;i<n;i++) {
    int t=vt[i],l=bins(vl[i]),r=bins(vr[i]);
    segt.modify(l,r,MP(t,i+1));
    int imin=0,imax=vdestsz;
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      auto got=segt.query(0,imid);
      int cnt=got.fst;
      int slots=got.snd;
      assert(slots==imid+1);
      assert(cnt<=imid+1);
      if (cnt==imid+1) imin=imid+1;
      else imax=imid;
    }
    assert(vdest[imin]>0);
    printf("%lld\n",vdest[imin]);
  }
}