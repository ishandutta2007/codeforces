#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
#define assert(XXX) XXX
#else
#define DEBUG_CAT
#endif
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

const int BASE=100000+10;
const int mn=4*BASE+100;

template<int _SEGSZ> class MinSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int STV;
  STV t[2 * SEGSZ];
  STV identity = INT_MAX;
  STV combine(const STV& lefts, const STV& rights) {
    return min(lefts,rights);
  }
  void init(int n) {
    segn=n;
    fill(t,t+2*segn,identity);
  }
  void modify(int l, int r, const STV& value) {
    l+=mn/2; r+=mn/2;
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

  STV query(int p) {
    p+=mn/2;
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


template<int _SEGSZ> class MaxSegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  typedef int STV;
  STV t[2 * SEGSZ];
  STV identity = INT_MIN;
  STV combine(const STV& lefts, const STV& rights) {
    return max(lefts,rights);
  }
  void init(int n) {
    segn=n;
    fill(t,t+2*segn,identity);
  }
  void modify(int l, int r, const STV& value) {
    l+=mn/2; r+=mn/2;
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

  STV query(int p) {
    p+=mn/2;
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


int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
const int mk=4;

MinSegTree<mn> seglo[4];
MaxSegTree<mn> seghi[4];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  vector<pii> v[2];
  for (int i=0;i<n;i++) {
    int ox=rint(),oy=rint();
    v[abs(ox+oy)&1].PB(MP(ox,oy));
  }
  ll ans=0;
  for (int o=0;o<2;o++) {
    for (int k=0;k<4;k++) {
      seglo[k].init(mn);seghi[k].init(mn);
    }
    for (auto &pt:v[o]) {
      int ox=pt.fst,oy=pt.snd;
      //printf("ox:%d oy:%d\n",ox,oy);
      for (int k=0;k<4;k++) {
        int px=ox+dx[k];
        int py=oy+dy[k];
        int x=px-py;
        int y=py+px;
        //printf("k:%d px:%d py:%d   x:%d y:%d\n",k,px,py,x,y);
        if (k==0) {
          seglo[k].modify(x,mn/2-1,y);
        }
        else if (k==2) {
          seghi[k].modify(-mn/2,x,y);
        }
        else if (k==1) {
          /* V */
          seglo[k].modify(-mn/2,x,y);
        }
        else if (k==3) {
          seghi[k].modify(x,mn/2-1,y);
        }
      }
    }
    for (int x=-mn/2;x<mn/2;x++) {
      if ((x&1) != o) {
        int lo=max(seglo[0].query(x),seglo[1].query(x));
        int hi=min(seghi[2].query(x),seghi[3].query(x));
        //if (abs(x)<=10) printf("x:%d lo:%d hi:%d\n",x,lo,hi);
        if (lo<=hi) {
          ans+=(hi-lo)/2+1;
        }
      }
    }
  }
  printf("%lld\n",ans);
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