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
  typedef ll S;
  S t[2 * SEGSZ];
  S identity = LLONG_MIN/4;
  S combine(const S& lefts, const S& rights) {
    return lefts+rights;
  }
  void init(int n) {segn=n; for (int i=n;i<2*n;i++) t[i]=identity;}
  void modify(int l, int r, const S& value) {
    if (l>r) return;
    r++;
    int n=segn;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) {
        t[l] = combine(t[l], value);
        l++;
      }
      if (r&1) {
        --r;
        t[r] = combine(t[r], value);
      }
    }
  }

  S query(int p) {
    int n=segn;
    S res = identity;
    for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
    return res;
  }


  void sset(int p, const S& value) {
     modify(p,p,value-query(p));
  }

  void push() {
    int n=segn;
    for (int i = 1; i < n; ++i) {
      t[i<<1] = combine(t[i<<1], t[i]);
      t[i<<1|1] = combine(t[i<<1|1], t[i]);
      t[i] = identity;
    }
  }
};

template<typename T> void makeunique(vector<T> &vx) {
  sort(vx.begin(),vx.end());
  auto it=unique(vx.begin(),vx.end());
  vx.resize(std::distance(vx.begin(),it));
}

template<typename T> int bins(vector<T> &vx, T x) {
  int imin=0,imax=vx.size();
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vx[imid]<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}

const int mn=(5e5)+4;
vi v;
SegTree<mn> seg;
int a[mn],p[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  ll sump=0;
  for (int i=0;i<n;i++) {p[i]=rint(); sump+=p[i];}
  int mm=rint();
  v.resize(mm);
  for (int i=0;i<mm;i++) v[i]=rint();
  for (int i=1;i<mm;i++) if (v[i-1]>=v[i]) {
    printf("NO\n"); exit(0);
  }
  v.PB(-INF);
  int vsz=v.size();
  seg.init(vsz);
  makeunique(v);
  seg.sset(0,0);
  for (int apos=0;apos<n;apos++) {
    int aval=a[apos];
    int idx=bins(v,aval);
    int gain=p[apos];
    if (idx<vsz) {
      assert(v[idx]>=aval);
      if (gain>0) {
        seg.modify(idx, vsz-1, gain);
      }
      if (v[idx]==aval) {
        ll now=seg.query(idx);
        ll cand=seg.query(idx-1) + gain;
        if (cand>now) {
          seg.sset(idx,cand);
        }
      }
    }
  }
  ll final=seg.query(vsz-1);
  if (final > LLONG_MIN/8) {
    printf("YES\n%lld\n",sump-final);
  } else {
    printf("NO\n");
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