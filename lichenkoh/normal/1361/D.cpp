#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
//typedef long double ld;
using ld=double;
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

// There exists a constant C st if (0,0) is has weight C, and remaining points have weight 1
// then the points closest to "center of mass" should be eliminated.
// Ternary search for the constant C.

const int mn=(5e5)+4;
int gcd(int x, int y) {
  x=abs(x); y=abs(y);
  if (x==0) return y;
  else if (y==0) return x;
  return __gcd(x,y);
}
pii normv(int x, int y) {
  int g=gcd(x,y);
  return MP(x/g,y/g);
}

ld sumvec(vector<ld> const & v) {
  ld sum= 0; for (auto &w:v) sum+=w;
  return sum;
}

ld distbranch(vector<ld> const & v) {
  int n=v.size();
  ld before=0;
  ld ans=0;
  for (int i=0;i<n;i++) {
    auto w=v[i];
    ld sbefore = w*i - before;
    ans+=sbefore;
    before+=w;
  }
  return ans;
}

const bool DBG=false;

ld distg(vector<vector<ld> > a, bool origin_undamaged) {
  for (auto &b:a) {
    sort(b.begin(),b.end());
  }
  if(DBG) {
      for (auto &b:a) {
      for (auto x:b) printf("%f ",(double)x);
      printf("\n");
    }
    printf("\n\n");
  }
  int nodes=0;
  for (auto &b:a) nodes+=b.size();
  vector<ld> s; s.reserve(a.size());
  for (auto &b:a) s.PB(sumvec(b));
  ld inbranch = 0;
  for (int i=0;i<a.size();i++) inbranch += distbranch(a[i]);
  ld sumall = 0;
  for (int i=0;i<a.size();i++) sumall += s[i];
  ld cross = 0;
  for (int i=0;i<a.size();i++) {
    int bsz=a[i].size();
    ld other=sumall - s[i];
    ld origin2other = bsz * other;
    ld b2origin = s[i] * (nodes-bsz);
    if (DBG) printf("origin2other:%f b2origin:%f\n",origin2other, b2origin);
    ld contrib = b2origin + origin2other;
    cross += contrib;
  }
  cross/=2; // double-count
  if (DBG) printf("inbranch:%f cross:%f\n",inbranch,cross);
  ld ans=inbranch + cross;
  if (origin_undamaged) {
    ans+=sumall;
  }
  return ans;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int _n=rint(); int G=rint(); int R=_n-G;
  vector<vector<ld> > a;
  {
    map<pii,vector<ld> > h;
    for (int _i=0;_i<_n;_i++) {
      int x=rint(),y=rint();
      if (x==0&&y==0) continue;
      ld d=sqrt(x*(ld)x + y*(ld)y);
      pii sig=normv(x,y);
      h[sig].PB(d);
    }
    for (auto &w:h) {
      sort(w.snd.begin(),w.snd.end());
      a.PB(w.snd);
    }
  }
  if (G==_n) {
    ld final=distg(a,true);
    printf("%.12f\n",(double)final);
    exit(0);
  }
  // Case 1: Damaged vertix contains origin (0,0) base
  ld ans1;
  {
    vector<pair<ld,pair<int,ld> > > v;
    for (int b=0;b<a.size();b++) {
      int sz=a[b].size();
      for (int i=0;i<sz;i++) {
        ld d=a[b][i];
        int u=sz-i-1;
        ld C=d * (G - 2*u - 1);
        if (DBG) printf("d:%f u:%d C:%f\n",d,u,C);
        v.PB(MP(-C,MP(b,d)));
      }
    }
    sort(v.begin(),v.end());
    map<int,vector<ld> > h;
    for (int i=0;i<G;i++) {
      auto w=v[i];
      h[w.snd.fst].PB(w.snd.snd);
    }
    vector<vector<ld> > g;
    for (auto &w:h) g.PB(w.snd);
    ans1=distg(g,false);
  }
  if (DBG) printf("ans1:%f\n",ans1);

  // Case 2: Damaged vertices are all contained in 1 branch
  // The removed vertices should split the remainder into half
  ld ans2=0;
  {
    pii big=MP(-1,-1);
    for (int i=0;i<a.size();i++) {
      chkmax(big,MP((int)a[i].size(),i));
    }
    int bi=big.snd;
    int bs=a[bi].size();
    if (DBG) printf("bi:%d bs:%d\n",bi,bs);
    int guesshi = bs-G/2;
    vector<vector<ld> > g=a;
    for (int hi=guesshi-2; hi<=guesshi+2;hi++) {
      int lo=hi-R+1;
      if (DBG) printf("guesshi:%d lo:%d hi:%d\n",guesshi,lo,hi);
      if (0<=lo && hi<bs) {
        g[bi].clear();
        for (int x=0;x<lo;x++) g[bi].PB(a[bi][x]);
        for (int x=hi+1;x<bs;x++) g[bi].PB(a[bi][x]);
        ld cand=distg(g,true);
        chkmax(ans2,cand);
        if (DBG) printf("cand:%f\n",cand);
      }
    }
  }
  ld final=max(ans1,ans2);
  printf("%.12f\n",(double)final);
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