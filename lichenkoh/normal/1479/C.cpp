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
const int mn=100;
vpii g[mn];
int vhi[mn];
const int DBG=0;
int make(int want) {
  assert(want>=1);
  g[2].PB(MP(1,1));
  vhi[1]=0; vhi[2]=1;
  if (want==1) return 2;
  for (int x=3;;x++) {
    g[x].PB(MP(1,1));
    int xhi=1;
    vhi[x]=xhi;
    for (int y=2;y<x;y++) {
      if (want<=vhi[x-1]*2) {
        int bit=want-1;
        //printf("x:%d want:%d vhi[x-1]:%d bit:%d y-2:%d\n",x,want,vhi[x-1],bit,y-2);
        if (0==(bit & (1<<(y-2)) )) continue;
      }
      int yhi=vhi[y];
      int maxhi=xhi+yhi;
      int needhi=min(maxhi,want);
      assert(needhi==maxhi);
      int cost=needhi-yhi;
      //printf("x:%d y:%d cost:%d xhi:%d yhi:%d needhi:%d\n",x,y,cost,xhi,yhi,needhi);
      if (cost>0) {
        g[x].PB(MP(y,cost));
        vhi[x]=xhi=needhi;
      }
    }
    if (vhi[x]>=want) {
      assert(vhi[x]==want);
      return x;
    }
  }
  assert(0);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int L,R; cin>>L>>R;
  int want=R-L+1;
  int n=make(want);
  int base=L-1;
  if (base>0) {
    g[n+1].PB(MP(n,base));
    n++;
  }
  int m=0; for (int x=1;x<=n;x++) m+=g[x].size();
  printf("YES\n");
  printf("%d %d\n",n,m);
  for (int x=1;x<=n;x++) {
    //printf("len:%d\n",int(g[x].size()));
    for (auto &w:g[x]) {
      int y=w.fst;
      int a=1+n-x,b=1+n-y;
      if (DBG) printf("%d %d %d\n",x,y,w.snd);
      else printf("%d %d %d\n",a,b,w.snd);
    }
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