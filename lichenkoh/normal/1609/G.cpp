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

struct S {
  S() {}
  S(ll sum_,ll delta_,int sz_):sum(sum_),delta(delta_),sz(sz_) {}
  ll sum=0,delta=0;
  int sz=0;
};
struct SegAtLeast {
  int mn,segn;  // array size
  SegAtLeast(int logn) {
    segn = 1<<logn;
    t.resize(2*segn);
  }
  vector<S> t;
  S identity;
  S combine(const S& l, const S& r) {
    S res(
      l.sum+r.sum+l.delta*r.sz,
      l.delta+r.delta,
      l.sz+r.sz
    );
    return res;
  }

  void initpos(int p, ll value) { // set value at position p before build()
    int n=segn;
    t[p+n]=S(value,value,1);
  }

  void build() {  // build the tree
    int n=segn;
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
  }

  void sset(int p, const S& value) { // set value at position p
    int n=segn;
    p+=n;
    t[p] = value;
    for (; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
  }

  void modify(int p, ll value) { // add value to position p
    int n=segn;
    p+=n;
    t[p].sum += value;
    t[p].delta += value;
    for (; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
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

  int fatleast(ll atleast, int l, int r, int p) {
    while(l+1!=r) {
      int m=(l+r)>>1;
      if (atleast <= t[p<<1].delta) {
        r=m;
        p<<=1;
      } else {
        atleast-=t[p<<1].delta;
        l=m;
        p=(p<<1)|1;
      }
    }
    return l;
  }

  int gatleast(ll atleast) {
    return fatleast(atleast,0,segn,1);
  }
};
SegAtLeast seg(17);
vll A,B;

ll arith(ll l, ll r, ll d) {
  return d*(((l+r)*(r-l+1))/2);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int R=rint(); int C=rint(); int Q=rint();
  A.resize(R);
  for (int r=0;r<R;r++) A[r]=rlong();
  B.resize(C);
  ll Bs=0;
  for (int c=0;c<C;c++) {
    B[c]=rlong();
    Bs+=B[c];
  }
  ll B0=B[0];
  ll od1 = 0;
  for (int c=1;c<C;c++) {
    ll d1=B[c]-B[c-1];
    ll d2=d1-od1;
    od1=d1;
    seg.initpos(c,d2);
    //printf("c:%d d:%d\n",c,d2);
  }
  seg.build();
  for (int q=0;q<Q;q++) {
    int type=rint(); int k=rint(); int d=rint();
    if (type==1) {
      int dk=d;
      for (int idx=R-k;idx<R;idx++) {
        A[idx]+=dk;
        dk+=d;
      }
    } else {
      Bs += arith(1,k,d);
      if (k==C) {
        B0+=d;
      }
      seg.modify(max(1,C-k), d);
    }
    ll myA=0, myB=Bs;
    int prevBpos = 0;
    for (int r=1;r<R;r++) {
      ll adiff=A[r]-A[r-1];
      int Bpos = min(C,seg.gatleast(adiff))-1;
      myA+=(Bpos-prevBpos+1) * A[r-1];
      myB+=B0+seg.query(1,Bpos).sum;
      prevBpos = Bpos;
    }
    myA+=A[R-1]*(C-prevBpos);
    ll final=myA + myB;
    printf("%lld\n",final);
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