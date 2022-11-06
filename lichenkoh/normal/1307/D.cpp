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
const int mn=(2e5)+2;
vi g[mn];
void dij(int n, int init, int *vdist) {
    queue<pii> pq;
    for (int x=0;x<mn;x++) vdist[x]=1<<29;
    vdist[init]=0; pq.push(MP(0,init));
    while(!pq.empty()) {
      auto got=pq.front(); pq.pop();
      int dist=got.fst,x=got.snd;
      if (dist>vdist[x]) continue;
      for (auto &gg:g[x]) {
        int y=gg,cost=1;
        int ndist=dist+cost;
        if (ndist<vdist[y]) {
          vdist[y]=ndist;
          pq.push(MP(ndist,y));
        }
      }
    }
}

template<int _SEGSZ> class MaxSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  using S=int;
  S t[2 * SEGSZ];
  S identity = INT_MIN;
  S combine(const S& lefts, const S& rights) {
    return max(lefts,rights);
  }
  void init(int n) {segn=n; for (int i=0;i<2*n;i++) t[i]=identity;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
    if (l>r) return identity;
    r++;
    int n=segn;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = combine(resl, t[l++]);
      if (r&1) resr = combine(t[--r], resr);
    }
    return combine(resl, resr);
  }
};

vector<pii> vx,vy;
void presolve(vi const &a, vi const &b) {
  int n=a.size();
  assert(n==b.size());
  for (int k=0;k<n;k++) vx.PB(MP(a[k],k));
  for (int k=0;k<n;k++) vy.PB(MP(b[k],k));
  sort(vx.begin(),vx.end());
  sort(vy.begin(),vy.end());
}
MaxSegTree<mn> seg;
bool solve(vi const &a, vi const &b,int target) {
  int n=a.size();
  seg.init(n);
  int bi=n-1;
  for (int ai=0;ai<n;ai++) {
    int x=vx[ai].snd;
    while(bi>=0 && a[x]+vy[bi].fst >= target) {
      int y=vy[bi].snd;
      assert(a[x]+b[y]>=target);
      seg.sset(y,a[y]);
      //printf("Insert into seg y:%d a[y]:%d b[y]:%d\n",y,a[y],b[y]);
      bi--;
    }
    int maxay=max(seg.query(0,x-1),seg.query(x+1,n-1));
    //printf("x:%d a[x]:%d b[x]:%d maxby:%d\n",x,a[x],b[x],maxby);
    if (b[x] + maxay >= target) return true;
  }
  return false;
}

int aa[mn],bb[mn];
vi a,b;
vi spec;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); int m=rint();
  {
    int s=rint();
    for (int i=0;i<s;i++) spec.PB(rint()-1);
  }
  for (int i=0;i<m;i++) {
    int x=rint()-1,y=rint()-1;
    g[x].PB(y); g[y].PB(x);
  }
  dij(n,0,aa);
  dij(n,n-1,bb);
  for (auto &x:spec) {
    a.PB(aa[x]);
    b.PB(bb[x]);
    //printf("%d: %d %d\n",x,aa[x],bb[x]);
  }
  presolve(a,b);

  int imin=0,imax=aa[n-1]+1;
  while(imin<imax) {
    int imid=(imin+imax)/2;
    if (solve(a,b,imid)) {
      //printf("imid:%d True\n",imid);
      imin=imid+1;
    } else {
      //printf("imid:%d False\n",imid);
      imax=imid;
    }
  }
  int cand=imin;
  int final=min(cand, aa[n-1]);
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