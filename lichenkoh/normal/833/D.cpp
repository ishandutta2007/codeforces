#include <bits/stdc++.h>
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



const int mn=1e5+8;
vector<int> g[mn];
int vdest[2*mn],vval[2*mn],vc[2*mn];
bool iscentroid[mn];
int getCentroid(int u,int p,int n) {
    int cnt = 1;
    bool goodCenter = true;
    for (auto wi : g[u]) {
      int w=vdest[wi];
      int v=w;
      if (v == p||iscentroid[v]) continue;
      int res = getCentroid(v, u, n);
      if (res >= 0)
        return res;
      int size = -res;
      goodCenter &= size <= n / 2;
      cnt += size;
    }
    goodCenter &= n - cnt <= n / 2;
    return goodCenter ? u : -cnt;
  }
int getSubtreeSize(int x,int p) {
  int selfSubtreeSize=1;
  for (auto &wi:g[x]) {
    int w=vdest[wi];
    int y=w;
    if (y==p||iscentroid[y]) continue;
    int childSubtreeSize=getSubtreeSize(y,x);
    selfSubtreeSize+=childSubtreeSize;
  }
  return selfSubtreeSize;
}

/* Custom functions go here */
template <typename LST> struct LimitedVec  {
  LST a[mn];
  int sz;
  void push_back(LST val) {
    a[sz++]=val;
  }
  LST * begin()
  {
    return &a[0];
  }
  LST * end()
  {
    return &a[sz];
  }
  void clear() {
    sz=0;
  }
};
inline int mul(int x, int y) {
  return (x*(ll)y)%MOD;
}
const int mod=MOD;
int mod_pow(int a, int n) {
  int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret;
}
LimitedVec<pair<pii,int> > h;
void dfs(int x, int p, int prod, int e0, int e1) {
  h.PB(MP(MP(e0,e1),prod));
  for (auto &yi:g[x]) {
    int y=vdest[yi];
    if (y==p||iscentroid[y]) continue;
    int c=vc[yi],val=vval[yi];
    int ne0=e0,ne1=e1;
    if (c==0) ne0++; else ne1++;
    int nprod=mul(prod,val);
    dfs(y,x,nprod,ne0,ne1);
  }
}
const int MAXN=4*mn;
struct LimitedVecUniqueIteration  {
  int a[MAXN];
  int vts[MAXN];
  int sz;
  int ts=0;
  void push_back(int val) {
    a[sz++]=val;
  }
  int * begin()
  {
    return &a[0];
  }
  int * end()
  {
    return &a[sz];
  }
  bool use_x(int x) {
    if (vts[x]==ts) return false;
    vts[x]=ts;
    return true;
  }
  void init_iteration() {
    ts++;
  }
  void clear() {
    sz=0;
    init_iteration();
  }
};
class FenwickAdd{
// Fenwick with fast reset. Reset is O(number of unique indexes changed previously)
public:
int t[MAXN]; // MAXN = maxindex + 1
int fn,fn2;
LimitedVecUniqueIteration used;

/* Custom starts here */
int IDENTITY=0;
FenwickAdd() {
  if (IDENTITY!=0) for (int i=0;i<MAXN;i++) t[i]=IDENTITY;
}
inline int trans(int i) { // Transforms customer index into actual index in int t[].
  return fn+i;
}
inline int op(int x, int y) {
  return x+y;
}
inline int inv(int x) {
  return -x;
}
/* Custom ends here */

void init(int n) {
  fn=n;
  fn2=2*n;
  used.clear();
}
// T[i] += value
void rawadd(int i, int value) {
  used.PB(i);
  for (; i < fn2; i |= i + 1)
    t[i] = op(t[i],value);
}
// sum[0..i]
int rawsum(int i) {
  int res = IDENTITY;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = op(res, t[i]);
  return res;
}
void add(int k, int value) {
  rawadd(trans(k),value);
}
int sum(int k) {
  return rawsum(trans(k));
}
void sset(int i) {
  int invorig = op(rawsum(i-1),inv(rawsum(i)));
  rawadd(i,invorig);
}
void deinit() {
  for (auto &i:used) {
    if (used.use_x(i)) {
      sset(i);
    }
  }
}
};
FenwickAdd f[2];
class FenwickMul{
// Fenwick with fast reset. Reset is O(number of unique indexes changed previously)
public:
int t[MAXN]; // MAXN = maxindex + 1
int fn,fn2;
LimitedVecUniqueIteration used;

/* Custom starts here */
int IDENTITY=1;
FenwickMul() {
  if (IDENTITY!=0) for (int i=0;i<MAXN;i++) t[i]=IDENTITY;
}
inline int trans(int i) { // Transforms customer index into actual index in int t[].
  return fn+i;
}
inline int op(int x, int y) {
  return (x*(ll)y)%MOD;
}
inline int inv(int x) {
  return mod_pow(x,MOD-2);
}
/* Custom ends here */

void init(int n) {
  fn=n;
  fn2=2*n;
  used.clear();
}
// T[i] += value
void rawadd(int i, int value) {
  used.PB(i);
  for (; i < fn2; i |= i + 1)
    t[i] = op(t[i],value);
}
// sum[0..i]
int rawsum(int i) {
  int res = IDENTITY;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = op(res, t[i]);
  return res;
}
void add(int k, int value) {
  rawadd(trans(k),value);
}
int sum(int k) {
  return rawsum(trans(k));
}
void sset(int i) {
  int invorig = op(rawsum(i-1),inv(rawsum(i)));
  rawadd(i,invorig);
}
void deinit() {
  for (auto &i:used) {
    if (used.use_x(i)) {
      sset(i);
    }
  }
}
};
FenwickMul m[2];
int final=1;
/* Custom functions end here */

void fullCentroidDecomposition(int initv,int p,int n) {
  int centroid=getCentroid(initv,p,n);
  vector<pii> subtreeRootsWithSizes;
  int allsize=0;
  for (auto &wi:g[centroid]) {
    int w=vdest[wi];
    int y=w;
    if (y!=p&&(!iscentroid[y])) {
      int sz=getSubtreeSize(y,centroid);
      allsize+=sz;
      subtreeRootsWithSizes.PB(MP(y,sz));
    }
  }
  /* Custom code starts here. Should take linear time. Do not consider nodes with iscentroid=true, or nodes beyond them.*/
  for (int q=0;q<2;q++) {
    f[q].init(2*(allsize+1));
    f[q].add(0,1);
    m[q].init(2*(allsize+1));
  }
  int x=centroid;
  for (auto &yi:g[centroid]) {
    int y=vdest[yi];
    if (iscentroid[y]) continue;
    int c=vc[yi],yval=vval[yi];
    int e0=0,e1=0;
    int ne0=e0,ne1=e1;
    if (c==0) ne0++; else ne1++;
    int nprod=yval;
    h.clear();
    dfs(y,x,nprod,ne0,ne1);
    for (int q=0;q<2;q++) {
      for (auto &w:h) {
        int a0=w.fst.fst,a1=w.fst.snd;
        int delta=q?(2*a1-a0):2*a0-a1;
        int val=w.snd;
        int gotcnt=f[q].sum(-delta-1);
        int gotprod=m[q].sum(-delta-1);
        int powup=mod_pow(val,gotcnt);
        int prod=mul(powup, gotprod);
        //printf("x:%d y:%d q:%d delta:%d val:%d gotcnt:%d gotprod:%d powup:%d prod:%d\n",x,y,q,delta,val,gotcnt,gotprod,powup,prod);
        //assert(gotprod>0);
        //assert(powup>0);
        //assert(prod>0);
        final=mul(final, prod);
      }
      for (auto &w:h) {
        int a0=w.fst.fst,a1=w.fst.snd;
        int delta=q?(2*a1-a0):2*a0-a1;
        int val=w.snd;
        f[q].add(delta,1);
        m[q].add(delta,val);
      }
    }
  }
  for (int q=0;q<2;q++) {f[q].deinit(); m[q].deinit();}
  /* Custom code ends here. Continue decomposing subtree.*/
  iscentroid[centroid]=true;
  for (auto &got:subtreeRootsWithSizes) {
    fullCentroidDecomposition(got.first,centroid,got.second);
  }
}








typedef struct S {
  int x;
  S () {
    x=0;
  }
  S(const int _x) {
    x=_x;
  }
  S operator^(const S &b) const {
    // Must be commutative
    return x+b.x;
  }
  void upd(int _x) {
    // Includes the vertex itself
    x++;
  }
} S;
const int maxn=mn;
struct EulerEdge{
public:
S identity=0;
typedef struct VS {
  vector<S> prefix;
  vector<S> suffix;
} VS;
S t[maxn];
VS vt[maxn];

void init(int x, int p) {
  int numchildren=g[x].size() - ((p==-1)?0:1);
  for (auto &yi:g[x]) {
    int y=vdest[yi];
    if (y==p) continue;
    init(y,x);
    t[x]=t[x]^t[y];
  }
  t[x].upd(x);
  {
    S prefix=identity;
    vt[x].prefix.resize(numchildren);
    int id=0;
    for (auto &yi:g[x]) {
      int y=vdest[yi];
      if (y==p) continue;
      vt[x].prefix[id]=prefix;
      prefix=prefix^t[y];
      id++;
    }
  }
  {
    S suffix=identity;
    vt[x].suffix.resize(numchildren);
    int id=0;
    for (auto it=g[x].rbegin();it!=g[x].rend();++it) {
      int yi=*it;
      int y=vdest[yi];
      if (y==p) continue;
      vt[x].suffix[numchildren-1-id]=suffix;
      suffix=suffix^t[y];
      id++;
    }
  }
}
int allprod=1;
void euler_edge(int x, int p, int pei) {
  if (p!=-1) {
    // Start edge custom code. Handle the edge x<->p.
    int cnt=(t[x].x*(ll)t[p].x)%(MOD-1);
    allprod=mul(allprod,mod_pow(vval[pei],cnt));
    // End vertex custom code
  }
  int yid=0;
  for (auto &yi:g[x]) {
    int y=vdest[yi];
    if (y==p) continue;

    S old_tx=t[x];
    t[x]=vt[x].prefix[yid]^vt[x].suffix[yid];
    if (p!=-1) {
      t[x]=t[x]^t[p];
      //printf("x:%d p:%d yid:%d pre:%lld suf:%lld p:%lld\n",x,p,yid, vt[x].prefix[yid].sum,vt[x].suffix[yid].sum,t[p].sum);
    }
    t[x].upd(x);

    euler_edge(y,x,yi);
    t[x]=old_tx;

    yid++;
  }
}
};


int eid=0;
void ae(int x, int y, int val, int c) {
  g[x].PB(eid);
  vdest[eid]=y;
  vval[eid]=val;
  vc[eid]=c;
  eid++;
}
EulerEdge e;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n-1;i++) {
    int u=rint(),v=rint(),val=rint(),c=rint();
    ae(u,v,val,c);
    ae(v,u,val,c);
  }
  e.init(1,-1);
  e.euler_edge(1,-1,-1);
  //printf("allprod:%d\n",e.allprod);
  for (int q=0;q<2;q++) {
    for (int i=0;i<MAXN;i++) m[q].t[i]=1;
  }
  fullCentroidDecomposition(1,-1,n);
  //assert(final>0);
  //assert(e.allprod>0);
  int ans=mul(e.allprod,mod_pow(final,MOD-2));
  printf("%d\n",ans);
}