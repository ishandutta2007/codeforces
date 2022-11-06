#ifdef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#pragma GCC optimize("Ofast")
#endif
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

void fail() {
  printf("NO\n"); exit(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,en; cin>>n>>en;
  vi vx(en),vy(en),vb(en);
  vi vans(n+1),vdist(n+1);
  for (int i=0;i<en;i++) {
    cin>>vx[i]>>vy[i]>>vb[i];
  }
  int bestdist=-INF;
  for (int initv=1;initv<=n;initv++) {
    for (int x=1;x<=n;x++) vdist[x]=INF;
    vdist[initv]=0;
    for (int k=1;k<n;k++) {
      for (int ei=0;ei<en;ei++) {
        int x=vx[ei],y=vy[ei],b=vb[ei];
        if (b==1) {
          chkmin(vdist[y],vdist[x]+1);
          chkmin(vdist[x],vdist[y]-1);
        } else {
          chkmin(vdist[y],vdist[x]+1);
          chkmin(vdist[x],vdist[y]+1);
        }
      }
    }
    int lo=vdist[1],hi=vdist[1];
    for (int x=1;x<=n;x++) {
      chkmin(lo,vdist[x]);
      chkmax(hi,vdist[x]);
    }
    int canddist=hi-lo;
    //printf("init:%d lo:%d hi:%d\n",init,lo,hi);
    if (canddist > bestdist) {
      bestdist=canddist;
      vans=vdist;
    }
  }
  for (int ei=0;ei<en;ei++) {
    int x=vx[ei],y=vy[ei]; int b=vb[ei];
    if (b) {
      if (vans[y]!=vans[x]+1) fail();
    } else {
      if (abs(vans[x]-vans[y]) != 1) fail();
    }
  }
  {
    int lo=vans[1];
    for (int x=2;x<=n;x++) chkmin(lo, vans[x]);
    printf("YES\n%d\n", bestdist);
    for (int x=1;x<=n;x++) {
      printf("%d ", vans[x]-lo);
    }
    printf("\n");
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