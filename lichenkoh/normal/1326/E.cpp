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
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
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

template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int S;
  S t[2 * SEGSZ];
  S identity = 0;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void init(int n) {segn=n; for (int i=0;i<=2*n;i++) t[i]=identity;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void modify_combine(int p, const S& value) { // modify value at position p
    int n=segn;
    sset(p,combine(t[p+n],value));
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

struct P {
  int s2e;
  int l2e;
  int lo;
};

void pr(char c,P gotb) {
  printf("%c: neg:%d pos:%d res:%d\n",c,gotb.s2e,gotb.l2e,gotb.lo);
}
bool TRI=false;
template<int _SEGSZ> class SegTreeB {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  using S=P;
  S t[2 * SEGSZ];
  S identity = {0,false,0};
  S combine(const S& l, const S& r) {
    P ans;
    ans.lo=min(l.lo,l.s2e+r.lo);
    ans.s2e=l.s2e+r.s2e;
    ans.l2e=max(r.l2e,l.l2e+r.s2e);
    return ans;
  }
  void init(int n) {segn=n; for (int i=0;i<=2*n;i++) t[i]=identity;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void modify_combine(int p, int value) { // modify value at position p
    int n=segn;
    P ans;
    if (value==-1) {
      ans=combine(t[p+n],{-1,0,-1});
    } else if (value==1) {
      ans=combine({1,1,0},t[p+n]);
    }
    sset(p,ans);
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


const int mn=(3e5)+4;

int f[mn],r[mn],q[mn];

SegTree<mn> segsum;
SegTreeB<mn> segb;

/*P genrand() {
  return (rand()%2)?P({-1,0,-1}):P({1,1,0});
}
void bf() {
  P a=genrand();
  P b=genrand();
  P c=genrand();
  P ab=segb.combine(a,b);
  P bc=segb.combine(b,c);
  P d=segb.combine(ab,c);
  P e=segb.combine(a,bc);
  if (d.lo != e.lo || d.s2e != e.s2e || d.l2e != e.l2e) {
    pr('a',a);
    pr('b',b);
    pr('c',c);
    printf("\n");
    pr('x',ab);
    pr('y',bc);
    printf("\n");
    pr('d',d);
    pr('e',e);
    exit(0);
  }
}
*/
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  segb.init(n+1);
  segsum.init(n+1);
  for (int x=1;x<=n;x++) f[x]=rint();
  for (int x=1;x<=n;x++) q[x]=rint();
  for (int x=1;x<=n;x++) {
    r[f[x]]=x;
  }
  vi vans; vans.reserve(n);
  int ans=n; vans.PB(ans);
  for (int t=1;t<n;t++) {
    segsum.modify_combine(q[t],-1);
    segb.modify_combine(q[t],-1);
    while(ans>1) {
      int x=r[ans];
      P gotb=segb.query(1,x-1);
      int bval=gotb.l2e;
      
      int got=segsum.query(x,n);
      
      int finalgot=got+max(0,bval);
      if (finalgot<0) {
        segsum.modify_combine(x,1);
        segb.modify_combine(x,1);
        --ans;
      } else break;
    }
    vans.PB(ans);
  }
  for (auto &w:vans) printf("%d ",w);
  printf("\n");
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