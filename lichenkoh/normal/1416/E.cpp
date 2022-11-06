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
const int INF=1<<30;
const int UNDEF = INF;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;typedef vector<pll> vpll;
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=(int)v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
template<typename T> void makeunique(vector<T> &vx) {sort(vx.begin(),vx.end());auto it=unique(vx.begin(),vx.end());vx.resize(std::distance(vx.begin(),it));}
template<typename Key> class PreSet {
public:
  vector<Key> vkey;
  void addKey(Key key) {
    vkey.PB(key);
  }
  void buildKeys() {
    makeunique(vkey);
  }
  int getFirstGeq(Key key) {
    return bins(vkey,key);
  }
  int getLastLeq(Key key) {
    int pos=bins(vkey,key);
    if (pos==vkey.size() || vkey[pos]>key) --pos;
    return pos;
  }
  int size() {
    return vkey.size();
  }
};

const int mn=(5e5)+4;

using STV=int;
struct STD {
  STD() {}
  STD(int _ts, int _force, int _add): ts(_ts),force(_force),add(_add) {}
  int ts;
  int force;
  int add;
};
template<typename Key> class SegTree {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    int ans=x+y.add;
    if (y.force!=UNDEF) chkmin(ans, y.force);
    return ans;
  }
 
  // query (or combine) operation
  STV queryOperation(STV l, STV r) {
    return min(l,r);
  }
 
  STD deltaEffectOnSegment(STD delta, int segmentLength) {
    return delta;
  }
 
  STD initNeutralDelta() {
    return STD(-1,UNDEF,0);
  }
 
  bool isNeutralDelta(STD delta) {
    return delta.ts==-1;
  }
 
  STV getInitValue(int i) {
    return 0;
  }
 
  STV getNeutralValue() {
    return INT_MAX;
  }
 
  STD joinDeltas(STD x, STD y) {
    if (x.ts > y.ts) swap(x, y);
    int maxts=y.ts;
    int force=UNDEF;
    if (y.force != UNDEF) chkmin(force, y.force);
    if (x.force != UNDEF) chkmin(force, x.force+y.add);
    return STD(maxts, force, x.add+y.add);
  }
 
  // generic code
 
  STD _cache_neutral_delta;
 
  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }
 
  STV *value;
  STD *delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int segn;
 
  STV joinValueWithDelta(STV value, STD delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }
 
 
  void pushDelta(int root, int left, int right) {
    value[root] = joinValueWithDelta(value[root], deltaEffectOnSegment(delta[root], right - left + 1));
    delta[2 * root + 1] = joinDeltas(delta[2 * root + 1], delta[root]);
    delta[2 * root + 2] = joinDeltas(delta[2 * root + 2], delta[root]);
    delta[root] = getNeutralDelta();
  }
 
  PreSet<Key> preset;
  void addKey(Key key) {preset.addKey(key);}
  SegTree() {
  }
 
  void init() {
    preset.buildKeys();
    int n=preset.size();
    _cache_neutral_delta = initNeutralDelta();
    segn = n;
    value = new STV[4 * n];
    delta = new STD[4 * n];
    initR(0, 0, n - 1);
  }
 
  void initR(int root, int left, int right) {
    if (left == right) {
      value[root] = getInitValue(left);
      delta[root] = getNeutralDelta();
    } else {
      int mid = (left + right) >> 1;
      initR(2 * root + 1, left, mid);
      initR(2 * root + 2, mid + 1, right);
      value[root] = queryOperation(value[2 * root + 1], value[2 * root + 2]);
      delta[root] = getNeutralDelta();
    }
  }
 
  STV query(int from, int to) {
    if (from>to) return getNeutralValue();
    int n=segn;
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
    if (from>to) return;
    modify(from, to, delta, 0, 0, segn - 1);
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
 
  STV queryKey(Key const & from, Key const & to) {
    return query(preset.getFirstGeq(from), preset.getLastLeq(to));
  }
  void modifyKey(Key const & from, Key const & to, STD const & delta) {
    modify(preset.getFirstGeq(from), preset.getLastLeq(to), delta);
  }
};


/*
typedef int STV;
struct STD {
  int forceMin=INF;
  int add=0;
  STD() {}
  STD(int f, int a): forceMin(f),add(a) {};
  bool operator==(STD const & b) {return forceMin == b.forceMin && add==b.add;}
  bool operator!=(STD const & b) {return !(*this == b);}
};
const STD NEUTRAL_STD(INF,0);
const STV NEUTRAL_STV=INF;


template<typename Key> class SegTree {
public:
  vi minval,maxval; vector<STD> tag; int segn;
  PreSet<Key> preset;
  void addKey(Key key) {preset.addKey(key);}
  void init() {
    preset.buildKeys();
    segn=preset.size();
    minval.clear();
    maxval.clear();
    tag.clear();
    minval.resize(segn*4);
    maxval.resize(segn*4);
    tag.resize(segn*4);
  }
  bool break_condition(int node, int l, int r, int ql, int qr, STD delta) {
    if (delta==NEUTRAL_STD) return true;
    if (maxval[node] <= delta.forceMin && delta.add==0) return true;
    return l>qr||r<ql;
  }
 
  bool tag_condition(int node, int l, int r, int ql, int qr, STD delta) {
    assert(delta!=NEUTRAL_STD);
    if (!(ql<=l && r<=qr)) return false;
    if (delta.forceMin == UNDEF) return true;
    if (minval[node]==maxval[node]) return true;
    if (maxval[node] <= delta.forceMin) return true;
    if (minval[node] >= delta.forceMin) return true;
    return false;
  }
 
  void puttag(int node, int l, int r, int ql, int qr, STD delta) {
    assert(delta!=NEUTRAL_STD);
    maxval[node]+=delta.add;
    chkmin(maxval[node],delta.forceMin);
    minval[node]+=delta.add;
    chkmin(minval[node],delta.forceMin);
    tag[node].forceMin+=delta.add;
    chkmin(tag[node].forceMin, delta.forceMin);
    tag[node].add += delta.add;
  }
 
  void pushdown(int node, int l, int r, int ql, int qr) {
    if (tag[node]==NEUTRAL_STD||l==r) return;
    int mid = (l + r) >> 1;
    puttag(node * 2, l, mid, ql,qr,tag[node]);
    puttag(node * 2 + 1, mid + 1, r, ql,qr,tag[node]);
    tag[node] = NEUTRAL_STD;
  }
 
  void update(int node) {
    int nodeL=node*2,nodeR=node*2+1;
    minval[node]=min(minval[nodeL],minval[nodeR]);
    maxval[node]=max(maxval[nodeL],maxval[nodeR]);
  }
 
  void modify(int node, int l, int r, int ql, int qr, STD delta) {
    if (break_condition(node,l,r,ql,qr,delta)) return;
    pushdown(node,l,r,ql,qr);
    if (tag_condition(node,l,r,ql,qr,delta)) {
      puttag(node, l, r, ql, qr, delta);
      return;
    }
    int mid = (l + r) >> 1;
    modify(node * 2, l, mid, ql,qr,delta);
    modify(node * 2 + 1, mid + 1, r, ql,qr,delta);
    update(node);
  }
 
  STV query(int node, int l, int r, int ql, int qr) {
    if (l>qr||r<ql) return NEUTRAL_STV;
    if (ql<=l && r<=qr) return minval[node];
    int mid = (l + r) >> 1;
    pushdown(node,l,r,ql,qr);
    return query(node * 2, l, mid, ql,qr) + query(node * 2 + 1, mid + 1, r, ql,qr);
  }
 
  void modify(int l, int r, STD delta) {
    modify(1,0,segn-1,l,r,delta);
  }
  STV query(int l, int r) {
    STV ans=query(1,0,segn-1,l,r);
    return ans;
  }

  STV queryKey(Key const & from, Key const & to) {
    return query(preset.getFirstGeq(from), preset.getLastLeq(to));
  }
  void modifyKey(Key const & from, Key const & to, STD const & delta) {
    modify(preset.getFirstGeq(from), preset.getLastLeq(to), delta);
  }
 
};
*/
/*
template<typename Key> class SegTree {
public:
  vi a; int segn;
  PreSet<Key> preset;
  void addKey(Key key) {preset.addKey(key);}
  void init() {
    preset.buildKeys();
    segn=preset.size();
    a.resize(segn);
  } 
  void modify(int l, int r, STD delta) {
    for (int x=l;x<=r;x++) {
      a[x]+=delta.add;
      chkmin(a[x],delta.forceMin);
    }
  }
  STV query(int l, int r) {
    STV ans=INF;
    for (int x=l;x<=r;x++) chkmin(ans,a[x]);
    return ans;
  }

  STV queryKey(Key const & from, Key const & to) {
    return query(preset.getFirstGeq(from), preset.getLastLeq(to));
  }
  void modifyKey(Key const & from, Key const & to, STD const & delta) {
    modify(preset.getFirstGeq(from), preset.getLastLeq(to), delta);
  }
};
*/

int a[mn];
int n;
ll c[mn];
ll vlo[mn],vhi[mn],vhalf[mn];
void go() {
  n=rint();
  for (int p=1;p<=n;p++) a[p]=rint();
  {
    c[1]=0;
    // t, a[1]-t, a[2]-(a[1]-t), a[3]-(a[2]-(a[1]-t))
    // t  5-t     6-(5-t)=1+t    6-(1+t)=5-t
    for (int p=2;p<=n;p++) {
      c[p]=a[p-1]-c[p-1];
    }
    for (int p=1;p<=n;p++) {
      ll lo,hi; ll half=LLONG_MAX;
      if (p&1) {
        // c[p]+t>=1
        lo=1-c[p];
        // c[p]+t<=a[p]-1
        hi=(a[p]-1)-c[p];
        // c[p]+t==a[p]/2
        if (a[p]%2==0) {
          half=a[p]/2-c[p];
        }
      } else {
        // c[p]-t>=1
        hi=c[p]-1;
        // c[p]-t<=a[p]-1
        lo=c[p]-(a[p]-1);
        // c[p]-t==a[p]/2
        if (a[p]%2==0) {
          half=c[p]-a[p]/2;
        }
      }
      assert(lo<=hi);
      if (half!=LLONG_MAX && (lo<=half && half<=hi)) {
        vhalf[p]=half;
      } else {
        vhalf[p]=LLONG_MAX;
      }
      vlo[p]=lo; vhi[p]=hi;
    }
  }
  SegTree<ll> seg;
  for (int p=1;p<=n;p++) {
    ll half=vhalf[p];
    if (half!=LLONG_MAX) seg.addKey(half);
    seg.addKey(vlo[p]);
    seg.addKey(vhi[p]);
  }
  seg.init();
  int ts=0;
  for (int p=1;p<=n;p++) {
    seg.modify(0,seg.segn-1,STD(ts++,INF,2));
    seg.modifyKey(vlo[p],vhi[p],STD(ts++,INF,-1));
    ll half=vhalf[p];
    if (half!=LLONG_MAX) {
      seg.modifyKey(half,half,STD(ts++,INF,-1));
    }
    int cand=seg.query(0,seg.segn-1);
    seg.modify(0,seg.segn-1,STD(ts++,cand+1,0));
  }
  printf("%d\n",seg.query(0,seg.segn-1)+1);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t=rint(); for (int i=0;i<t;i++) go();
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