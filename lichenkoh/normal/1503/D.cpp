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
const int INF=1<<29;
const int UNDEF=-INF;
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


using STV=int;
const int NONE=0,ADD=1,SETMIN=2,SET=3;
struct S {
  S() {}
  S(int _add, int _setMin, int _setVal):add(_add),setMin(_setMin),setVal(_setVal) {}
  int add=0,setMin=INF,setVal=UNDEF;
};
using STD=S;
template<int n> class SegmentTree {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD const& y) {
    x+=y.add;
    chkmin(x,y.setMin);
    if (y.setVal!=UNDEF) x=y.setVal;
    return x;
  }

  // query (or combine) operation
  STV queryOperation(STV const& l, STV const& r) {
    return min(l,r);
  }

  STD deltaEffectOnSegment(STD const& delta, int segmentLength) {
    return delta;
  }

  STD initNeutralDelta() {
    STD neutral;
    return neutral;
  }

  bool isNeutralDelta(STD const& delta) {
    return delta.add==0&&delta.setMin>=INF&&delta.setVal==UNDEF;
  }

  STV getInitValue(int i) {
    if (i==0) return 0;
    return INF;
  }

  STV getNeutralValue() {
    return INF;
  }

  STD joinDeltas(STD delta1, STD delta2) {
    if (isNeutralDelta(delta2)) return delta1;
    if (isNeutralDelta(delta1)) return delta2;
    if (delta2.setVal!=UNDEF) return delta2;
    if (delta1.setVal!=UNDEF) return STD(UNDEF,UNDEF,modifyOperation(delta1.setVal, delta2));
    int newAdd=delta1.add+delta2.add;
    int newSetMin=min(delta1.setMin+delta2.add, delta2.setMin);
    //printf("%d %d\n",res.op,res.val);
    return STD(newAdd,newSetMin,UNDEF);
  }

  STD randSTD() {
    return S(
      rand()%4,
      (rand()%2)?INF:rand()%4,
      (rand()%2)?UNDEF:rand()%5
      );
  }
  void commuteTest() {
    for (int k=0;k<1000;k++) {
      STD a=randSTD(),b=randSTD(),c=randSTD();
      STD res1=joinDeltas(joinDeltas(a,b),c);
      STD res2=joinDeltas(a,joinDeltas(b,c));
      assert(res1.add == res2.add);
      assert(res1.setMin == res2.setMin);
      assert(res1.setVal == res2.setVal);
    }
    printf("Passed commute test\n"); exit(0);
  }

  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  STV *value;
  STD *delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int gn;

  STV joinValueWithDelta(STV const& value, STD const& delta) {
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

  SegmentTree() {
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

  void modify(int from, int to, STD const& delta) {
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
  void add(int l, int r, int val) {
    S s; s.add=val;
    modify(l,r,s);
  }
  void setMin(int l, int r, int val) {
    S s; s.setMin=val;
    modify(l,r,s);
  }
  void setVal(int l, int r, int val) {
    S s; s.setVal=val;
    modify(l,r,s);
  }
};


pii norm(pii q) {
  return MP(min(q.fst,q.snd),max(q.fst,q.snd));
}
bool contains(pii inL, pii inS) {
  pii Ln=norm(inL),Sn=norm(inS);
  return Ln.fst<=Sn.fst && Sn.snd <= Ln.snd;
}
bool separate(pii inp, pii inq) {
  pii p=norm(inp),q=norm(inq);
  return p.fst>q.snd || q.fst>p.snd;
}
const int mn=int(4e5)+8;
const bool DBG=0;
SegmentTree<mn> seg[2];
int go() 
{
  //seg[0].commuteTest();
  int n=rint();
  vector<pair<int,pii> > v(n);
  for (int i=0;i<n;i++) {
    int a=rint(); int b=rint();
    v[i]=MP(-min(a,b),MP(a,b));
  }
  sort(v.begin(),v.end());

  for (int x=0;x<n;x++) {
    pii p=v[x].snd;
    if (separate(p, v[0].snd)) return -1;
    int pl=p.fst,pr=p.snd,o=0;
    if (pl>pr) {swap(pl,pr); o=1;}
    bitset<2> bad; bad.reset();
    pii setMinOp[2];  setMinOp[0].fst=setMinOp[1].fst=UNDEF;
    if(DBG)printf("x:%d a:%d b:%d\n",x,p.fst,p.snd);
    for (int last=0;last<2;last++) {
      if (x>0) { // Case 1: Add to last^1
        int best=seg[last].query(0,pr);
        if (best<INF) {
          int prevr=max(v[x-1].snd.fst,v[x-1].snd.snd);
          //printf("last:%d best:%d prevr:%d best+(o^last^1):%d\n",last,best,prevr,best+(o^last^1));
          setMinOp[last^1]=MP(prevr,best+(o^last^1));
        }
      }
      if (x==0||contains(p, v[x-1].snd)) {
        // Case 2: Add to last
        if(DBG)printf("add last:%d val:%d\n",last,o^last);
        seg[last].add(0,mn-1,o^last);
      } else {
        // Entire seg is bad
        if(DBG)printf("Mark INF last:%d\n",last);
        seg[last].setVal(0,mn-1,INF);
      }
    }
    for (int last=0;last<2;last++) {
      if (setMinOp[last].fst != UNDEF) {
        int prevr=setMinOp[last].fst,val=setMinOp[last].snd;
        if(DBG)printf("setMin last:%d upto:%d val:%d\n",last,prevr,val);
        seg[last].setMin(prevr,prevr,val);
      }
    }
    if(DBG)for (int last=0;last<2;last++) {
      printf("last:%d\n",last);
      for (int x=0;x<=2*n;x++) {
        printf("%d ",seg[last].query(x,x));
      }
      printf("\n");
    }
  }
  int final=INF;
  for (int last=0;last<2;last++) {
    int ans=seg[last].query(0,mn-1);
    //printf("ans:%d\n",ans);
    chkmin(final,ans);
  }
  //printf("final%d\n",final);
  if (final>=INF/2) final=-1;
  return final;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int final=go();
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