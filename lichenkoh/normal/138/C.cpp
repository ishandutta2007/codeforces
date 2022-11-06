#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
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

template<typename T> class RemapUnique {
public:
  vector<T> v;
  void sortmakeunique(vector<T> & myvector) {
    sort(myvector.begin(), myvector.end());
    auto it = std::unique (myvector.begin(), myvector.end());
    myvector.resize( std::distance(myvector.begin(),it) );
  }
  void init(vector<T> &_inp) { // Mutates the input!
    v=_inp;
    sortmakeunique(v);
    //for (auto &w:v) printf("%d ",w); printf("ENDDII\n");
  }
  int size() {
    return v.size();
  }
  int GTE(const T &key) {
    int imin=0,imax=v.size();
    while(imin<imax) {
      int imid=(imin+imax)>>1;
      if (v[imid]<key) imin=imid+1;
      else imax=imid;
    }
    //printf("key:%d imin:%d\n",key,imin);
    return imin;
  }
};

template<typename T, int _MAXSEG> class RangeSegTreeRemap {
public:
  static const int MAXSEG = _MAXSEG;  // limit for array size
  int segn=_MAXSEG;  // array size
  typedef ld STV;
  STV t[2 * MAXSEG];
  STV identity = 1;
  STV combine(const STV& a, const STV& b) {
    return a*b;
  }
  RemapUnique<T> remap;
  void init(vector<T> vt) {
    remap.init(vt);
    segn=remap.size()+1;
    fill(t,t+segn+segn, identity);
  }
  void modify(int _l, int _r, const STV& value) {
    int l=remap.GTE(_l),r=remap.GTE(_r+1)-1;
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

  STV query(STV *t, int _p) {
    int p=remap.GTE(_p);
    int n=segn;
    STV res = identity;
    for (p += n; p > 0; p >>= 1) res = combine(res, t[p]);
    return res;
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
const int mn=1e5+4;
const int mk=1e4+4;
RangeSegTreeRemap<int,mk> seg;
int va[mn],vh[mn],vl[mn],vr[mn];
int vb[mk],vz[mk];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(),m=rint();
  vector<int> vt;
  for (int i=0;i<n;i++) {
    va[i]=rint(),vh[i]=rint(),vl[i]=rint(),vr[i]=rint();
  }
  for (int i=0;i<m;i++) {
    vb[i]=rint(),vz[i]=rint();
    vt.PB(vb[i]);
  }
  seg.init(vt);
  for (int i=0;i<n;i++) {
    seg.modify(va[i]-vh[i],va[i]-1,(1-vl[i]/100.0L));
    seg.modify(va[i]+1,va[i]+vh[i],(1-vr[i]/100.0L));
  }
  seg.push();
  ld final=0;
  for (int i=0;i<m;i++) {
    int k=seg.remap.GTE(vb[i]);
    ld prob=seg.t[seg.segn+k];
    ld ans=prob*vz[i];
    final+=ans;
  }
  printf("%.16f\n",final);
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