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


const int mn=2e5+2;
int inp[mn];
const int maxd=31;
const int ODD=1U<<maxd;
typedef struct STTV {
  unsigned int a[maxd];
  int len;
  bool hz;
} STV;

/*
int gauss(int *a, int alen) {
  //O(alen * sizeof(int)) Binary gaussian elimination.
  //Returns the size of the basis.
  //Set maxd = sizeof(int)
  int st=0;
  for (int d=0;d<maxd;d++) {
    int msk=1<<d;
    for (int x=st;x<alen;x++) {
      if (a[x]&msk) {
        if (x!=st) swap(a[x],a[st]);
        for (int y=st+1;y<alen;y++) if (a[y]&msk) {
          a[y]^=a[st];
        }
        st++;
        break;
      }
    }
  }
  return st;
}
*/
pair<int,bool> gauss(unsigned int *a, int alen) {
  //O(alen * sizeof(int)) Binary gaussian elimination.
  //Returns MP(size of the basis, bool on existence of odd sized linear comb that sums to 0)
  //Set maxd = sizeof(int)
  int st=0;
  bool hz=0;
  for (int x=0;x<alen;x++) if(a[x]==ODD) hz=1;
  for (int d=0;d<maxd;d++) {
    int msk=1<<d;
    for (int x=st;x<alen;x++) {
      if (a[x]&msk) {
        if (x!=st) swap(a[x],a[st]);
        for (int y=st+1;y<alen;y++) if (a[y]&msk) {
          a[y]^=a[st];
          if (a[y]==ODD) hz=1;
        }
        st++;
        break;
      }
    }
  }
  return MP(st,hz);
}
typedef int STD;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    //for (int d=0;d<x.len;d++) printf("%d ",x.a[d]);
    //printf("\n");
    if (y==0) return x;
    STV ans=x;
    for (int d=0;d<ans.len;d++) {
      if (ans.a[d]&ODD) ans.a[d]^=y;
    }
    if (ans.hz) {
      ans.a[ans.len]=y|ODD;
      ans.len++;
    }
    //for (int d=0;d<ans.len;d++) printf("%d ",ans.a[d]);
    //printf("\n");
    auto got=gauss(ans.a,ans.len);
    ans.len=got.fst; ans.hz=got.snd;
    return ans;
  }

  // query (or combine) operation
  STV queryOperation(STV leftValue, STV rightValue) {
    unsigned int tmp[2*maxd];
    int idx=0;
    for (int d=0;d<leftValue.len;d++) tmp[idx++]=leftValue.a[d];
    for (int d=0;d<rightValue.len;d++) tmp[idx++]=rightValue.a[d];
    auto got=gauss(tmp,idx);
    STV ans;
    ans.len=got.fst;
    ans.hz=got.snd||leftValue.hz||rightValue.hz;
    for (int d=0;d<ans.len;d++) {
      ans.a[d]=tmp[d];
    }
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
    return 0;
  }

  bool isNeutralDelta(STD delta) {
    return delta==0;
  }

  STV getInitValue(int i) {
    STV ans;
    memset(ans.a,0,sizeof ans.a);
    ans.a[0]=ODD|inp[i];
    ans.len=(inp[i]==0)?0:1;
    ans.hz=(inp[i]==0)?1:0;
    return ans;
  }

  STV getNeutralValue() {
    STV ans;
    ans.len=0;
    ans.hz=0;
    return ans;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1^delta2;
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



int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),q=readInt();
  for (int i=0;i<n;i++) inp[i]=readInt();
  SegmentTreeFast segt = SegmentTreeFast(n);
  for (int i=0;i<q;i++) {
    int t=readInt(),l=readInt()-1,r=readInt()-1;
    if (t==1) {
      int k=readInt();
      //printf("MODIFY\n");
      segt.modify(l,r,k);
    }
    else {
      //printf("QUERY\n");
      STV got=segt.query(l,r);
      int ans=got.len;
      /*for (int d=0;d<got.len;d++) {
        assert (got.a[d]!=0);
        {
          printf("l:%d r:%d d:%d len:%d a:%d\n",l,r,d,got.len,got.a[d]);
        }
      }*/
      printf("%d\n",1<<ans);
    }
  }
}