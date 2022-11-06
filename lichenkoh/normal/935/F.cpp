#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
#define fst first
#define snd second
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
const int MOD=1000000007;
int extgcd(int a, int b, int& x, int& y) { for (int u = y = 1, v = x = 0; a;) { int q = b / a; swap(x -= q *(ll) u, u); swap(y -= q *(ll) v, v); swap(b -= q *(ll) a, a); } return b; }
int mod_inv(int a, int m) { int x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
int mod_pow(int a, int n, int mod) { int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }

template<int _MAXSEG> class MinSegTree {
public:
  static const int MAXSEG = _MAXSEG;  // limit for array size
  int segn=_MAXSEG;  // array size
  typedef ll S;
  S t[2 * MAXSEG];
  S identity = LLONG_MAX;
  S combine(const S& lefts, const S& rights) {
    return min(lefts,rights);
  }
  void init(int n) {segn=n;}
  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  S query(int l, int r) { // sum on interval [l, r]
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


const int mn=100000+4;
int inp[mn];
ll vdiff[mn];
int n;

MinSegTree<mn> at,abt;
pll getab(int x) {
  ll l=max(0ll,-vdiff[x-1]);
  ll r=max(0ll,vdiff[x]);
  //printf("x:%d l:%lld r:%lld\n",x,l,r);
  return MP(l,r);
}
void change(int x) {
  pll got=getab(x);
  ll a=min(got.fst,got.snd),b=max(got.fst,got.snd);
  at.sset(x,a);
  abt.sset(x,a+b);
}
void place(int x) {
  pll got=getab(x);
  ll a=min(got.fst,got.snd),b=max(got.fst,got.snd);
  at.t[x+at.segn]=a;
  abt.t[x+abt.segn]=a+b;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  n=rint();
  int segn=n+1;
  at.init(segn); abt.init(segn);
  for (int x=1;x<=n;x++) inp[x]=rint();
  ll allsum=0;
  for (int x=1;x<=n-1;x++) {
    vdiff[x]=inp[x+1]-inp[x];
    allsum+=abs(vdiff[x]);
  }
  for (int x=1;x<=n;x++) {
    place(x);
  }
  at.build(); abt.build();
  int qlim=rint();
  for (int qi=0;qi<qlim;qi++) {
    int t=rint(),l=rint(),r=rint(),val=rint();
    if (t==1) {
      ll mina=at.query(l,r);
      ll minsum=abt.query(l,r);
      //printf("mina:%lld minab:%lld\n",mina,minsum);
      ll ansleft=max(-2*mina,-2LL*val);
      ll ansright=2*(val-minsum);
      //ll ansll=abs(val-vdiff[1])-abs(vdiff[1]);
      //ll ansrr=abs(val+vdiff[n-1])-abs(vdiff[n-1]);
      //printf("%lld %lld %lld %lld\n",ansleft,ansright,ansll,ansrr);
      ll ans=max(ansleft,ansright);
      ll final=allsum+ans;
      printf("%lld\n",final);
    }
    else {
      {
        allsum-=abs(vdiff[l-1]);
        vdiff[l-1]+=val;
        allsum+=abs(vdiff[l-1]);
        change(l);
        if (l-1>=1) change(l-1);
      }
      if (r!=n) {
        allsum-=abs(vdiff[r]);
        vdiff[r]-=val;
        allsum+=abs(vdiff[r]);
        change(r);
        if (r+1<=n) change(r+1);
      }
    }
    //for (int x=1;x<=n-1;x++) printf("%lld ",vdiff[x]);
    //printf(" end vdiff\n");
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