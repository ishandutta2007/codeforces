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
const int INF=INT_MAX-50;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi; typedef vector<pii> vpii;
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


class wavelet_tree{
public:
  #define vi vector<int>
  #define pb push_back
  int lo, hi;
  wavelet_tree *l, *r;
  vi b;

  wavelet_tree() {}

  wavelet_tree(int *from, int *to, int x, int y) {
    init(from,to,x,y);
  }

  //nos are in range [x,y]. 0<=x<=y
  //array indices are [from, to)
  void init(int *from, int *to, int x, int y){
    lo = x, hi = y;
    if(lo == hi or from >= to) return;
    int mid = (lo+hi)/2;
    auto f = [mid](int x){
      return x <= mid;
    };
    b.reserve(to-from+1);
    b.pb(0);
    for(auto it = from; it != to; it++)
      b.pb(b.back() + f(*it));
    //see how lambda function is used here  
    auto pivot = stable_partition(from, to, f);
    l = new wavelet_tree(from, pivot, lo, mid);
    r = new wavelet_tree(pivot, to, mid+1, hi);
  }
 
  int _kth(int l, int r, int k){
    if(l > r) return 0;
    if(lo == hi) return lo;
    int inLeft = b[r] - b[l-1];
    int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
    int rb = b[r]; //amt of nos in first (r) nos that go in left
    if(k <= inLeft) return this->l->_kth(lb+1, rb , k);
    return this->r->_kth(l-lb, r-rb, k-inLeft);
  }

  //kth smallest element in [l, r]. WARNING: untested!!
  int kth(int l, int r, int k){
    return _kth(l+1,r+1,k);
  }

  int _MINGTE(int l, int r, int k){
    if(l > r) return INF;
    if (hi<k) return INF;
    if(lo == hi) return lo;
    int inLeft = b[r] - b[l-1];
    int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left 
    int rb = b[r]; //amt of nos in first (r) nos that go in left
    int got=this->l->_MINGTE(lb+1, rb , k);
    if (got<INF) return got;
    return this->r->_MINGTE(l-lb, r-rb, k);
  }

  //kth smallest element in [l, r].
  int MINGTE(int l, int r, int k){
    return _MINGTE(l+1,r+1,k);
  }

  //count of nos in [l, r] Less than or equal to k
  int _LTE(int l, int r, int k) {
    if(l > r or k < lo) return 0;
    if(hi <= k) return r - l + 1;
    int lb = b[l-1], rb = b[r];
    return this->l->_LTE(lb+1, rb, k) + this->r->_LTE(l-lb, r-rb, k);
  }

  int LTE(int l, int r, int k) {
    return _LTE(l+1,r+1,k);
  }

  int _GTE(int l, int r, int k) {
    if(l > r or k > hi) return 0;
    if(lo >= k) return r - l + 1;
    int lb = b[l-1], rb = b[r];
    return this->l->_GTE(lb+1, rb, k) + this->r->_GTE(l-lb, r-rb, k);
  }

  int GTE(int l, int r, int k) {
    return _GTE(l+1,r+1,k);
  }

  int _count(int l, int r, int k) {
    if(l > r or k < lo or k > hi) return 0;
    if(lo == hi) return r - l + 1;
    int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
    if(k <= mid) return this->l->_count(lb+1, rb, k);
    return this->r->_count(l-lb, r-rb, k);
  }
  //count of nos in [l, r] equal to k
  int count(int l, int r, int k) {
    return _count(l+1,r+1,k);
  }
};

int rint();char rch();long long rlong();
const int mn=1e5+4;
pii vp[2][mn];
int gn,gk;
const int D=0,S=1;
int getxle(int x) {
  int imin=0,imax=gk;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    if (vp[S][imid].fst<x) imin=imid+1;
    else imax=imid;
  }
  return imin;
}
const int MAXO=1e8+4;
const int MAXC=4*MAXO;
vector<pii> s2i;
int gdistmax=0;
int tmpb[mn];
wavelet_tree T;
void sub() {
  const int MIN=0;
  int n=gn,k=gk;
  vi vx; for (int i=0;i<k;i++) vx.PB(vp[S][i].fst);
  for (int i=0;i<k;i++) tmpb[i]=vp[S][i].snd;
  T.init(tmpb, tmpb+k, MIN, MAXC);
  s2i.reserve(n);
  for (int i=0;i<n;i++) {
    int px=vp[D][i].fst,py=vp[D][i].snd;
    int imin=0,imax=MAXC;
    while(imin<imax) {
      int imid=(imin+imax)/2;
      int xl=getxle(px-imid),xr=getxle(px+imid+1)-1;
      int yl=max(MIN,py-imid),yr=py+imid;
      int goty=T.MINGTE(xl,xr,yl);
      if (goty>yr) imin=imid+1;
      else imax=imid;
    }
    s2i.PB(MP(imin,i));
    chkmax(gdistmax,imin);
  }
  sort(s2i.begin(),s2i.end(),greater<pii>());
}

bool f(int h) {
  if (h>=gdistmax) return true;
  int oxl=-INF,oxh=INF,oyl=-INF,oyh=INF;
  int lasts=gdistmax;
  for (auto &w:s2i) {
    int s=w.fst;
    int i=w.snd;
    if (s!=lasts) {
      int d=h-s;
      if (d>=0) {
        int xl=oxl-d,xh=oxh+d;
        int yl=oyl-d,yh=oyh+d;
        int ygot=T.MINGTE(getxle(xl),getxle(xh+1)-1,yl);
        if (ygot<=yh) return true;
      }
      lasts=s;
    }
    int x=vp[D][i].fst,y=vp[D][i].snd;
    //printf("i:%d x:%d y:%d\n",i,x,y);
    int d=h;
    chkmax(oxl,x-d);
    chkmin(oxh,x+d);
    chkmax(oyl,y-d);
    chkmin(oyh,y+d);
    if (!(oxl<=oxh&&oyl<=oyh)) return false;
  }
  return true;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  gn=rint();gk=rint();
  int n=gn,k=gk;
  for (int i=0;i<n;i++) {
    int px=rint(),py=rint();
    int x=px-py+2*MAXO;
    int y=py+px+2*MAXO;
    vp[D][i]=MP(x,y);
    //printf("x:%d y:%d px:%d py:%d\n",x,y,px,py);
  }
  //sort(vp[D],vp[D]+n);
  for (int i=0;i<k;i++) {
    int px=rint(),py=rint();
    int x=px-py+2*MAXO;
    int y=py+px+2*MAXO;
    vp[S][i]=MP(x,y);
    //printf("x:%d y:%d sx:%d sy:%d\n",x,y,px,py);
  }
  sort(vp[S],vp[S]+k);
  //for (int i=0;i<n;i++) printf("%d %d\n",vp[D][i].fst,vp[D][i].snd);
  //printf("S\n");
  //for (int i=0;i<k;i++) printf("%d %d\n",vp[S][i].fst,vp[S][i].snd);
  //printf("end input\n");
  sub();
  //return 0;
  int imin=0,imax=(MAXO+MAXO)+4;
  //printf("final: %d\n",f(4));
  //return 0;
  //f(1); return 0;
  //printf("F %d\n",f(7));return 0;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    bool got=f(imid);
    //printf("imid:%d got:%d\n",imid,got);
    if (!got) imin=imid+1;
    else imax=imid;
  }
  printf("%d\n",imin);
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