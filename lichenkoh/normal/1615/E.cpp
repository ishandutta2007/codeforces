#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,avx2")
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


using STV=pii;
using STD=int;
class SegmentTreeFast {
public:
  // Modify the following 5 methods to implement your custom operations on the tree.
  // This example implements Add/Sum operations. Operations like Add/Max, Set/Max can also be implemented.
  STV modifyOperation(STV x, STD y) {
    return MP(x.fst+y,x.snd);
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

  STV getNeutralValue() {
    return MP(-1,-1);
  }

  STD joinDeltas(STD delta1, STD delta2) {
    return delta1+delta2;
  }

  // generic code

  STD _cache_neutral_delta;

  STD getNeutralDelta() {
    return _cache_neutral_delta;
  }

  vector<STV> value;
  vector<STD> delta; // delta[i] affects value[i], delta[2*i+1] and delta[2*i+2]
  int gn;

  STV joinValueWithDelta(STV value, STD delta) {
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

  SegmentTreeFast() {}
  void init(vector<STV> const& initValues) {
    int n=initValues.size();
    _cache_neutral_delta = initNeutralDelta();
    gn=n;
    value.resize(2 * n);
    fill(value.begin(),value.begin()+n, getNeutralValue());
    for (int i = 0; i < n; i++) {
      value[i + n] = initValues[i];
    }
    for (int i = n - 1; i > 0; --i) value[i] = queryOperation(value[i<<1], value[i<<1|1]);
    delta.resize(2 * n);
    fill(delta.begin(), delta.end(), getNeutralDelta());
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

vvi g;
vi entrydfs, exitdfs;
vi dfsnum2x;
vpii initValues;
vi vpar;
int gdfsnum=-1;
void dfs(int x, int p, int depth) {
  vpar[x]=p;
  ++gdfsnum;
  entrydfs[x]=gdfsnum;
  dfsnum2x[gdfsnum]=x;
  initValues[gdfsnum]=MP(depth, gdfsnum);
  //printf("x:%d gdfsnum:%d depth:%d\n",x,gdfsnum,depth);
  for (auto &y:g[x]) {
    if (y!=p) dfs(y,x,depth+1);
  }
  exitdfs[x]=gdfsnum;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int k=rint();
  g.resize(n); entrydfs.resize(n); exitdfs.resize(n); dfsnum2x.resize(n); initValues.resize(n); vpar.resize(n);
  for (int i=1;i<n;i++) {
    int x=rint()-1; int y=rint()-1; g[x].PB(y); g[y].PB(x);
  }
  dfs(0,-1,0);
  assert(gdfsnum==n-1);
  SegmentTreeFast seg;
  seg.init(initValues);
  int numchild=0;
  for (int x=1;x<n;x++) if (g[x].size()==1) numchild++;
  int flow=min(k,numchild);
  int cost=0;
  vector<bool> used(n,false);
  for (int ii=0;ii<flow;ii++) {
    pii got=seg.query(0, n-1);
    int up=got.fst,dfsnum=got.snd; int x=dfsnum2x[dfsnum];
    cost+=up;
    int y=x;;
    while(y!=-1&&!used[y]) {
      //printf("x:%d up:%d y:%d entry:%d exit:%d\n",x,up,y,entrydfs[y], exitdfs[y]); fflush(stdout);
      seg.modify(entrydfs[y],exitdfs[y],-1);
      used[y]=true;
      y=vpar[y];
    }
  }
  ll red=k;
  ll extrared=red-flow;
  ll white=cost - extrared;
  ll blue=n-red-white;
  ll final=LLONG_MAX;
  //printf("flow:%d cost:%d red:%lld white:%lld blue:%lld\n",flow,cost,red,white,blue);
  for (ll trans=0;trans<=blue;trans++) {
    ll b=blue-trans;
    ll w=white+trans;
    ll r=red;
    ll ans=w*(r-b);
    chkmin(final,ans);
  }
  if (final>=0) {
    for (ll trans=0;trans<=extrared;trans++) {
      ll b=blue;
      ll w=white+trans;
      ll r=red-trans;
      ll ans=w*(r-b);
      chkmax(final,ans);
    }
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