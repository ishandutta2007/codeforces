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
const int mn=(1e6)+4;

struct Seg {
  int l,r;
  ll water;
  Seg() {}
  Seg(int _l,int _r,ll _water): l(_l),r(_r),water(_water) {}
  int len() const {
    return r-l+1;
  }
  bool operator< (Seg const & b) const {
    ll lhs = water * b.len();
    ll rhs = b.water * len();
    // Return greater so priority queue gets the lowest one.
    return (lhs>rhs) || (lhs==rhs && l>b.l);
  }
  bool operator== (Seg const & b) const {
    return (l==b.l) && (r==b.r) && (water==b.water);
  }
};
class UnionFind {
public:
  static const int mx=mn;
  using UFTYPE=Seg;
  inline UFTYPE combine(UFTYPE x, UFTYPE y) {
    return Seg(min(x.l,y.l),max(x.r,y.r),x.water+y.water);
  }
  /*inline UFTYPE getInitialValue(int x) {
    return x;
  }*/
  int ufParent[mx];
  int rank[mx];
  UFTYPE ufData[mx];
  inline void ufreset(int x) {
    ufParent[x]=x;
    //ufData[x]=getInitialValue(x);
    rank[x]=0;
  }
  void init(int n) {
    for (int x=0;x<n;x++) {
      ufreset(x);
    }
  }
  int ffind(int x) {
    if (ufParent[x] != x) {
      ufParent[x] = ffind(ufParent[x]);
    }
    return ufParent[x];
  }
  void funion(int _x, int _y) {
    int xr = ffind(_x);
    int yr = ffind(_y);
    if (xr==yr) return;
    if (rank[xr] > rank[yr]) swap(xr,yr);
    if (rank[xr]==rank[yr]) rank[yr]++;
    ufParent[xr] = yr;
    ufData[yr]=combine(ufData[xr],ufData[yr]);
  }
  UFTYPE getData(int x) {
    return ufData[ffind(x)];
  }
};
double vans[mn];
UnionFind uf;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  uf.init(n+1);
  uf.ufData[0]=Seg(0,0,0);
  priority_queue<Seg> pq;
  for (int x=1;x<=n;x++) {
    int water = rint();
    pq.push(Seg(x,x,water));
    uf.ufData[x]=Seg(x,x,water);
  }
  
  while(!pq.empty()) {
    Seg top=pq.top(); pq.pop();
    Seg top2=uf.getData(top.l);
    if (!(top2 == top)) continue;
    Seg prev=uf.getData(top.l-1);
    if (prev.l == 0) {
      double avg=top.water/((double)(top.len()));
      for (int x=top.l;x<=top.r;x++) {
        vans[x]=avg;
      }
      uf.funion(prev.l, top.l);
    } else {
      uf.funion(prev.l, top.l);
      pq.push(uf.getData(top.l));
    }
  }
  for (int x=1;x<=n;x++) printf("%.10f\n",vans[x]);
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