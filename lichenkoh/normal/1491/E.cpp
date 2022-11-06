#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
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


void fail(string s) {
  printf("NO\n");
  exit(0);
}


vvi g;
const int mn=(2e5)+4;
int gid;
int vid[mn];
vi vfib;

void getSubtree(int x, int p, vi & out) {
  if(vid[x]!=gid) return;
  out.PB(x);
  for (auto &y:g[x]) {
    if (y==p) continue;
    getSubtree(y,x,out);
  }
}

int desiredSize1,desiredSize2;
pii ret1,ret2;
int getCnt(int x, int p) {
  if (vid[x]!=gid) return 0;
  int ans=1;
  for (auto &y:g[x]) {
    if (y==p) continue;
    ans+=getCnt(y,x);
  }
  if (ans==desiredSize1) ret1=MP(x,p);
  else if (ans==desiredSize2) ret2=MP(x,p);
  return ans;
}

void go(vi const & a, int k) {
  if (vfib[k]<=3) return;
  assert(a.size()==vfib[k]);
  ++gid;
  for (auto &x:a) vid[x]=gid;
  desiredSize1=vfib[k-1];
  desiredSize2=vfib[k-2];
  ret1.fst=ret2.fst=-1;
  getCnt(a[0],-1);
  bool swapped=false;
  vi b1,b2;
  if (ret1.fst==-1) {swap(ret1,ret2); swapped=true;}
  if (ret1.fst==-1) {
    fail("ret not found");
  }
  getSubtree(ret1.fst,ret1.snd,b1);
  getSubtree(ret1.snd,ret1.fst,b2);
  if (swapped) swap(b1,b2);
  go(b1,k-1);
  go(b2,k-2);
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint();
  g.resize(n+1);
  for (int i=1;i<n;i++) {
    int x=rint(); int y=rint(); g[x].PB(y); g[y].PB(x);
  }
  vfib.PB(1); vfib.PB(1);
  while(vfib.back()<n) {
    int fsz=vfib.size();
    int got=vfib[fsz-2]+vfib[fsz-1];
    vfib.PB(got);
  }
  if (vfib.back()!=n) fail("n is not fib");
  vi a(n);
  for (int x=0;x<n;x++) a[x]=x+1;
  int fsz=vfib.size();
  go(a,fsz-1);
  printf("YES\n");
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