#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
typedef struct _S {
  int l,h,lh,hl,d,ans;
  bool id;
} S;
/*void pr(S s) {
  printf("l:%d h:%d d:%d lh:%d hl:%d ans:%d id:%d\n",s.l,s.h,s.d,s.lh,s.hl,s.ans,s.id?1:0);
}*/
template<int _SEGSZ> class SegTree {
public:
  static const int SEGSZ = _SEGSZ;  // limit for array size
  int segn=_SEGSZ;  // array size
  S t[2 * SEGSZ];
  S identity;
  S combine(const S& a, S b) {
    if (a.id) return b;
    if (b.id) return a;
    b.l+=a.d; b.h+=a.d; b.lh-=a.d; b.hl-=a.d;
    S c;c.id=false;
    c.l=min(a.l,b.l); c.h=max(a.h,b.h); c.d=a.d+b.d;
    c.lh=max(max(a.lh,b.lh),b.h-2*a.l);
    c.hl=max(max(a.hl,b.hl),a.h-2*b.l);
    c.ans=max(c.h,max(max(a.ans,b.ans),max(
      a.hl+b.h,
      a.h+b.lh
      )));
    //printf("A\n");pr(a); printf("B\n"); pr(b); printf("C\n"); pr(c);
    return c;
  }
  void init(int n) {
    identity.id=true;
    for (int i=0;i<2*SEGSZ;i++) t[i].id=true;
    segn=n;
  }
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

const int mn=(2e5)+8;
SegTree<mn> seg;
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int _p,q;cin>>_p>>q; int n=2*(_p-1);
  string inp; cin>>inp;
  seg.init(n);
  S up;
  up.id=false,up.l=0,up.h=1,up.d=1,up.lh=1-2*0,up.hl=0;up.ans=1;
  S dn;
  dn.id=false,dn.l=-1,dn.h=0,dn.d=-1,dn.lh=0,dn.hl=0-2*(-1);dn.ans=1;
  for (int i=0;i<n;i++) {
    seg.t[n+i]=((inp[i]=='(')?up:dn);
  }
  seg.build();
  {
    S ans=seg.query(0,n-1);
    //pr(ans);
    printf("%d\n",max(ans.h,ans.ans));
  }
  for (int qi=0;qi<q;qi++) {
    int x,y; cin>>x>>y; --x;--y;
    swap(inp[x],inp[y]);
    seg.sset(x,((inp[x]=='(')?up:dn));
    seg.sset(y,((inp[y]=='(')?up:dn));
    S ans=seg.query(0,n-1);
    printf("%d\n",max(ans.h,ans.ans));
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